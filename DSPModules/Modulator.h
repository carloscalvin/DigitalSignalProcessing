#ifndef MODULATOR_H
#define MODULATOR_H

#include <vector>
#include <complex>

// Clase Modulator:
// Este m�dulo se encarga de aplicar diferentes tipos de modulaci�n a las se�ales,
// como AM (modulaci�n en amplitud), FM (modulaci�n en frecuencia), y otros tipos
// de modulaci�n necesarios en el procesamiento de se�ales.

class Modulator {
public:
    // Modula una se�al en amplitud (AM)
    // - carrier: Se�al portadora.
    // - modulatingSignal: Se�al moduladora.
    std::vector<std::complex<float>> modulateAM(const std::vector<std::complex<float>>& carrier, const std::vector<std::complex<float>>& modulatingSignal);
};

#endif // MODULATOR_H
