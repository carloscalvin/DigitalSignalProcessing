#ifndef MODULATOR_H
#define MODULATOR_H

#include <vector>
#include <complex>

// Clase Modulator:
// Este m�dulo se encarga de aplicar diferentes tipos de modulaci�n y demodulaci�n
// a las se�ales, como AM (modulaci�n en amplitud), FM (modulaci�n en frecuencia),
// y otros tipos de modulaci�n necesarios en el procesamiento de se�ales.

class Modulator {
public:
    // Modula una se�al en amplitud (AM)
    // - carrier: Se�al portadora.
    // - modulatingSignal: Se�al moduladora.
    std::vector<std::complex<float>> modulateAM(const std::vector<std::complex<float>>& carrier, const std::vector<std::complex<float>>& modulatingSignal);

    // Demodula una se�al en amplitud (AM)
    // - modulatedSignal: Se�al modulada en AM.
    std::vector<std::complex<float>> demodulateAM(const std::vector<std::complex<float>>& modulatedSignal);

    // Modula una se�al en frecuencia (FM)
    // - modulatingSignal: Se�al moduladora.
    // - carrierFreq: Frecuencia de la se�al portadora.
    // - sampleRate: Tasa de muestreo.
    std::vector<std::complex<float>> modulateFM(const std::vector<std::complex<float>>& modulatingSignal, float carrierFreq, float sampleRate);

    // Demodula una se�al en frecuencia (FM)
    // - modulatedSignal: Se�al modulada en FM.
    // - sampleRate: Tasa de muestreo.
    std::vector<float> demodulateFM(const std::vector<std::complex<float>>& modulatedSignal, float sampleRate);
};

#endif // MODULATOR_H
