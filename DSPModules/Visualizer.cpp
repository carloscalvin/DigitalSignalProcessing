#include "Visualizer.h"
#include <SFML/Graphics.hpp>
#include <fftw3.h>
#include <cmath>
#include <vector>

// Muestra la señal IQ en el dominio del tiempo
void Visualizer::showTimeDomain(const std::vector<std::complex<float>>& iqData) {
    std::vector<sf::Vertex> lineI;
    std::vector<sf::Vertex> lineQ;

    for (size_t i = 0; i < iqData.size(); ++i) {
        lineI.push_back(sf::Vertex(sf::Vector2f(static_cast<float>(i), 300 + iqData[i].real() * 100), sf::Color::Red));
        lineQ.push_back(sf::Vertex(sf::Vector2f(static_cast<float>(i), 300 + iqData[i].imag() * 100), sf::Color::Blue));
    }

    sf::RenderWindow window(sf::VideoMode(800, 600), "Dominio del Tiempo");

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear(sf::Color::Black);
        window.draw(&lineI[0], lineI.size(), sf::LinesStrip);
        window.draw(&lineQ[0], lineQ.size(), sf::LinesStrip);
        window.display();
    }
}

// Realiza la transformada de Fourier y muestra el espectro en el dominio de la frecuencia
void Visualizer::showFrequencyDomain(const std::vector<std::complex<float>>& iqData) {
    size_t N = iqData.size();

    // Preparar entrada y salida para FFTW
    fftwf_complex* in = (fftwf_complex*)fftwf_malloc(sizeof(fftwf_complex) * N);
    fftwf_complex* out = (fftwf_complex*)fftwf_malloc(sizeof(fftwf_complex) * N);

    for (size_t i = 0; i < N; ++i) {
        in[i][0] = iqData[i].real();
        in[i][1] = iqData[i].imag();
    }

    // Crear y ejecutar el plan FFT
    fftwf_plan plan = fftwf_plan_dft_1d(N, in, out, FFTW_FORWARD, FFTW_ESTIMATE);
    fftwf_execute(plan);

    // Calcular la magnitud del espectro de frecuencia
    std::vector<float> magnitude(N / 2);
    for (size_t i = 0; i < N / 2; ++i) {
        magnitude[i] = std::sqrt(out[i][0] * out[i][0] + out[i][1] * out[i][1]);
    }

    // Crear la ventana para mostrar el espectro
    sf::RenderWindow window(sf::VideoMode(800, 600), "Dominio de la Frecuencia");
    std::vector<sf::Vertex> spectrum;

    for (size_t i = 0; i < N / 2; ++i) {
        spectrum.push_back(sf::Vertex(sf::Vector2f(static_cast<float>(i), 600 - magnitude[i] * 1000), sf::Color::Green));
    }

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear(sf::Color::Black);
        window.draw(&spectrum[0], spectrum.size(), sf::LinesStrip);
        window.display();
    }

    // Limpiar recursos de FFTW
    fftwf_destroy_plan(plan);
    fftwf_free(in);
    fftwf_free(out);
}
