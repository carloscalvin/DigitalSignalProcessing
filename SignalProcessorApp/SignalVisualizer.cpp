#include "SignalVisualizer.h"

SignalVisualizer::SignalVisualizer() {
    // Constructor vacío, inicializamos las líneas para las señales I y Q.
}

void SignalVisualizer::setSignal(const std::vector<std::complex<float>>& iqData) {
    // Limpiar datos previos
    lineI.clear();
    lineQ.clear();

    // Rellenar las líneas con los datos IQ
    for (size_t i = 0; i < iqData.size(); ++i) {
        lineI.push_back(sf::Vertex(sf::Vector2f(static_cast<float>(i), 300 + iqData[i].real() * 100), sf::Color::Red));
        lineQ.push_back(sf::Vertex(sf::Vector2f(static_cast<float>(i), 300 + iqData[i].imag() * 100), sf::Color::Blue));
    }
}

void SignalVisualizer::show() {
    sf::RenderWindow window(sf::VideoMode(800, 600), title);

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear(sf::Color::Black);

        // Dibujar las señales I (rojo) y Q (azul)
        window.draw(&lineI[0], lineI.size(), sf::LinesStrip);
        window.draw(&lineQ[0], lineQ.size(), sf::LinesStrip);

        window.display();
    }
}
