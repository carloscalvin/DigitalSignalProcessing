#ifndef FILTER_H
#define FILTER_H

#include <vector>
#include <complex>

// Clase Filter:
// Esta clase se encarga de aplicar diferentes tipos de filtros a la señal IQ,
// como filtros pasa-banda, que permiten aislar la señal de interés eliminando
// el ruido o señales no deseadas en otras bandas de frecuencia.

class Filter {
public:
    // Aplica un filtro pasa-banda a la señal IQ, dentro del rango de frecuencias especificado.
    std::vector<std::complex<float>> applyBandpassFilter(const std::vector<std::complex<float>>& iqData, float lowFreq, float highFreq);
};

#endif // FILTER_H
