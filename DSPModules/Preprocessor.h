#ifndef PREPROCESSOR_H
#define PREPROCESSOR_H

#include <vector>
#include <complex>

// Clase Preprocessor:
// Esta clase realiza el preprocesamiento de la señal, que incluye operaciones como
// la eliminación de offset DC y la normalización de los datos IQ. Estas operaciones
// son necesarias para preparar la señal antes de aplicar filtros o demodulación.

class Preprocessor {
public:
    // Aplica corrección del offset DC a los datos IQ.
    void applyDCOffsetCorrection(std::vector<std::complex<float>>& iqData);

    // Normaliza los valores de la señal IQ para que tengan un rango consistente.
    void normalize(std::vector<std::complex<float>>& iqData);
};

#endif // PREPROCESSOR_H
