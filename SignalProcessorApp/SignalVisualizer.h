#ifndef SIGNALVISUALIZER_H
#define SIGNALVISUALIZER_H

#include <SFML/Graphics.hpp>
#include <vector>
#include <complex>

class SignalVisualizer {
public:
    SignalVisualizer();

    // Establecer la se�al IQ para visualizaci�n
    void setSignal(const std::vector<std::complex<float>>& iqData);

    // Mostrar la se�al
    void show();

private:
    std::vector<sf::Vertex> lineI;
    std::vector<sf::Vertex> lineQ;
    std::string title;
};

#endif // SIGNALVISUALIZER_H
