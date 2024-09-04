#ifndef PREPROCESSOR_H
#define PREPROCESSOR_H

#include <vector>
#include <complex>

// Clase Preprocessor:
// Esta clase realiza el preprocesamiento de la se�al, que incluye operaciones como
// la eliminaci�n de offset DC y la normalizaci�n de los datos IQ. Estas operaciones
// son necesarias para preparar la se�al antes de aplicar filtros o demodulaci�n.

class Preprocessor {
public:
    // Aplica correcci�n del offset DC a los datos IQ.
    void applyDCOffsetCorrection(std::vector<std::complex<float>>& iqData);

    // Normaliza los valores de la se�al IQ para que tengan un rango consistente.
    void normalize(std::vector<std::complex<float>>& iqData);
};

#endif // PREPROCESSOR_H
