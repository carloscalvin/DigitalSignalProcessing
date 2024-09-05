#ifndef SIGNALGENERATOR_H
#define SIGNALGENERATOR_H
#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif
#include <vector>
#include <complex>

// Clase SignalGenerator:
// Este m�dulo se encarga de generar se�ales sint�ticas, como ondas senoidales,
// cuadradas, y ruido, que pueden ser utilizadas para probar y validar los
// algoritmos de procesamiento de se�ales. Adem�s, permite aplicar modulaci�n
// a las se�ales y a�adir ruido para simular capturas reales con un receptor SDR.

class SignalGenerator {
public:
    // Genera una se�al sinusoidal
    // - amplitude: Amplitud de la se�al.
    // - frequency: Frecuencia de la se�al en Hz.
    // - phase: Fase inicial de la se�al en radianes.
    // - sampleRate: Tasa de muestreo en Hz.
    // - length: N�mero de muestras de la se�al a generar.
    std::vector<std::complex<float>> generateSineWave(float amplitude, float frequency, float phase, float sampleRate, size_t length);

    // Genera una se�al cuadrada
    // - amplitude: Amplitud de la se�al.
    // - frequency: Frecuencia de la se�al en Hz.
    // - sampleRate: Tasa de muestreo en Hz.
    // - length: N�mero de muestras de la se�al a generar.
    std::vector<std::complex<float>> generateSquareWave(float amplitude, float frequency, float sampleRate, size_t length);

    // Genera ruido blanco gaussiano
    // - mean: Media del ruido.
    // - stddev: Desviaci�n est�ndar del ruido.
    // - length: N�mero de muestras de ruido a generar.
    std::vector<std::complex<float>> generateGaussianNoise(float mean, float stddev, size_t length);

    // A�ade ruido a una se�al
    // - signal: Se�al original a la que se le a�adir� ruido.
    // - noise: Se�al de ruido que se a�adir� a la se�al original.
    std::vector<std::complex<float>> addNoise(const std::vector<std::complex<float>>& signal, const std::vector<std::complex<float>>& noise);
};

#endif // SIGNALGENERATOR_H
