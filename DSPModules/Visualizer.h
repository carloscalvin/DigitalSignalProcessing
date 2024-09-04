#ifndef VISUALIZER_H
#define VISUALIZER_H

#include <vector>
#include <complex>

// Clase Visualizer:
// Esta clase proporciona m�todos para visualizar la se�al en distintos dominios,
// como el dominio del tiempo y el dominio de la frecuencia. Esto es �til para
// analizar la se�al y verificar el impacto de los diferentes pasos de procesamiento.

class Visualizer {
public:
    // Muestra la se�al IQ en el dominio del tiempo, representando su evoluci�n temporal.
    void showTimeDomain(const std::vector<std::complex<float>>& iqData);

    // Realiza la transformada de Fourier en la se�al IQ y muestra su espectro en el dominio de la frecuencia.
    void showFrequencyDomain(const std::vector<std::complex<float>>& iqData);
};

#endif // VISUALIZER_H
