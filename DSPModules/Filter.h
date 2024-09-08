#ifndef FILTER_H
#define FILTER_H
#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif
#include <vector>
#include <complex>

// Clase Filter:
// Esta clase se encarga de aplicar diferentes tipos de filtros a la señal IQ,
// como filtros pasa-banda, que permiten aislar la señal de interés eliminando
// el ruido o señales no deseadas en otras bandas de frecuencia.

class Filter {
public:
    // Constructor que acepta la tasa de muestreo
    Filter(float sampleRate);

    // Aplica un filtro pasa-banda a la señal IQ, dentro del rango de frecuencias especificado.
    void applyBandpassFilter(std::vector<std::complex<float>>& iqData, float lowFreq, float highFreq);

    // Aplica un filtro pasa-bajos a una señal real
    void applyLowPassFilter(std::vector<float>& signal, float cutoffFreq);

    // Aplica un filtro de Kalman a una señal real
    void applyKalmanFilter(std::vector<float>& signal);

private:
    float sampleRate;  // Tasa de muestreo en Hz
};

#endif // FILTER_H
