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
    // Muestra la señal IQ en el dominio del tiempo, representando su evolución temporal.
    void showTimeDomain(const std::vector<std::complex<float>>& iqData);

    // Realiza la transformada de Fourier en la señal IQ y muestra su espectro en el dominio de la frecuencia.
    void showFrequencyDomain(const std::vector<std::complex<float>>& iqData);
};

#endif // VISUALIZER_H
