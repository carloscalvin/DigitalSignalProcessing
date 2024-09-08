#ifndef VISUALIZER_H
#define VISUALIZER_H

#include <vector>
#include <complex>

// Clase Visualizer:
// Esta clase proporciona métodos para visualizar la señal en distintos dominios,
// como el dominio del tiempo y el dominio de la frecuencia. Esto es útil para
// analizar la señal y verificar el impacto de los diferentes pasos de procesamiento.

class Visualizer {
public:
    // Muestra la señal IQ en el dominio del tiempo
    void showTimeDomain(const std::vector<std::complex<float>>& iqData);

    // Muestra la señal real en el dominio del tiempo
    void showRealTimeDomain(const std::vector<float>& realData);

    // Realiza la FFT y muestra el espectro en el dominio de la frecuencia para señales IQ
    void showFrequencyDomain(const std::vector<std::complex<float>>& iqData);

    // Realiza la FFT y muestra el espectro en el dominio de la frecuencia para señales reales
    void showRealFrequencyDomain(const std::vector<float>& realData);
};

#endif // VISUALIZER_H
