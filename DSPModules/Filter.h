#ifndef FILTER_H
#define FILTER_H
#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif
#include <vector>
#include <complex>

// Clase Filter:
// Esta clase se encarga de aplicar diferentes tipos de filtros a la se�al IQ,
// como filtros pasa-banda, que permiten aislar la se�al de inter�s eliminando
// el ruido o se�ales no deseadas en otras bandas de frecuencia.

class Filter {
public:
    // Constructor que acepta la tasa de muestreo
    Filter(float sampleRate);

    // Aplica un filtro pasa-banda a la se�al IQ, dentro del rango de frecuencias especificado.
    void applyBandpassFilter(std::vector<std::complex<float>>& iqData, float lowFreq, float highFreq);

    // Aplica un filtro pasa-bajos a una se�al real
    void applyLowPassFilter(std::vector<float>& signal, float cutoffFreq);

    // Aplica un filtro de Kalman a una se�al real
    void applyKalmanFilter(std::vector<float>& signal);

private:
    float sampleRate;  // Tasa de muestreo en Hz
};

#endif // FILTER_H
