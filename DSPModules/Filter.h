#ifndef FILTER_H
#define FILTER_H

#include <vector>
#include <complex>

// Clase Filter:
// Esta clase se encarga de aplicar diferentes tipos de filtros a la se�al IQ,
// como filtros pasa-banda, que permiten aislar la se�al de inter�s eliminando
// el ruido o se�ales no deseadas en otras bandas de frecuencia.

class Filter {
public:
    // Aplica un filtro pasa-banda a la se�al IQ, dentro del rango de frecuencias especificado.
    std::vector<std::complex<float>> applyBandpassFilter(const std::vector<std::complex<float>>& iqData, float lowFreq, float highFreq);
};

#endif // FILTER_H
