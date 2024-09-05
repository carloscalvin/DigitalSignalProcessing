#ifndef MODULATOR_H
#define MODULATOR_H

#include <vector>
#include <complex>

// Clase Modulator:
// Este módulo se encarga de aplicar diferentes tipos de modulación a las señales,
// como AM (modulación en amplitud), FM (modulación en frecuencia), y otros tipos
// de modulación necesarios en el procesamiento de señales.

class Modulator {
public:
    // Modula una señal en amplitud (AM)
    // - carrier: Señal portadora.
    // - modulatingSignal: Señal moduladora.
    std::vector<std::complex<float>> modulateAM(const std::vector<std::complex<float>>& carrier, const std::vector<std::complex<float>>& modulatingSignal);
};

#endif // MODULATOR_H
