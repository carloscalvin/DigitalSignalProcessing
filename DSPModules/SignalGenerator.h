#ifndef SIGNALGENERATOR_H
#define SIGNALGENERATOR_H
#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif
#include <vector>
#include <complex>

// Clase SignalGenerator:
// Este módulo se encarga de generar señales sintéticas, como ondas senoidales,
// cuadradas, y ruido, que pueden ser utilizadas para probar y validar los
// algoritmos de procesamiento de señales. Además, permite aplicar modulación
// a las señales y añadir ruido para simular capturas reales con un receptor SDR.

class SignalGenerator {
public:
    // Genera una señal sinusoidal
    // - amplitude: Amplitud de la señal.
    // - frequency: Frecuencia de la señal en Hz.
    // - phase: Fase inicial de la señal en radianes.
    // - sampleRate: Tasa de muestreo en Hz.
    // - length: Número de muestras de la señal a generar.
    std::vector<std::complex<float>> generateSineWave(float amplitude, float frequency, float phase, float sampleRate, size_t length);

    // Genera una señal cuadrada
    // - amplitude: Amplitud de la señal.
    // - frequency: Frecuencia de la señal en Hz.
    // - sampleRate: Tasa de muestreo en Hz.
    // - length: Número de muestras de la señal a generar.
    std::vector<std::complex<float>> generateSquareWave(float amplitude, float frequency, float sampleRate, size_t length);

    // Genera ruido blanco gaussiano
    // - mean: Media del ruido.
    // - stddev: Desviación estándar del ruido.
    // - length: Número de muestras de ruido a generar.
    std::vector<std::complex<float>> generateGaussianNoise(float mean, float stddev, size_t length);

    // Añade ruido a una señal
    // - signal: Señal original a la que se le añadirá ruido.
    // - noise: Señal de ruido que se añadirá a la señal original.
    std::vector<std::complex<float>> addNoise(const std::vector<std::complex<float>>& signal, const std::vector<std::complex<float>>& noise);
};

#endif // SIGNALGENERATOR_H
