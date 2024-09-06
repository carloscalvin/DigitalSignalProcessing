#ifndef MODULATOR_H
#define MODULATOR_H

#include <vector>
#include <complex>

// Clase Modulator:
// Este módulo se encarga de aplicar diferentes tipos de modulación y demodulación
// a las señales, como AM (modulación en amplitud), FM (modulación en frecuencia),
// y otros tipos de modulación necesarios en el procesamiento de señales.

class Modulator {
public:
    // Modula una señal en amplitud (AM)
    // - carrier: Señal portadora.
    // - modulatingSignal: Señal moduladora.
    std::vector<std::complex<float>> modulateAM(const std::vector<std::complex<float>>& carrier, const std::vector<std::complex<float>>& modulatingSignal);

    // Demodula una señal en amplitud (AM)
    // - modulatedSignal: Señal modulada en AM.
    std::vector<std::complex<float>> demodulateAM(const std::vector<std::complex<float>>& modulatedSignal);

    // Modula una señal en frecuencia (FM)
    // - modulatingSignal: Señal moduladora.
    // - carrierFreq: Frecuencia de la señal portadora.
    // - sampleRate: Tasa de muestreo.
    std::vector<std::complex<float>> modulateFM(const std::vector<std::complex<float>>& modulatingSignal, float carrierFreq, float sampleRate);

    // Demodula una señal en frecuencia (FM)
    // - modulatedSignal: Señal modulada en FM.
    // - sampleRate: Tasa de muestreo.
    std::vector<float> demodulateFM(const std::vector<std::complex<float>>& modulatedSignal, float sampleRate);
};

#endif // MODULATOR_H
