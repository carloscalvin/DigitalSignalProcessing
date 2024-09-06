#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif
#include "Modulator.h"
#include <cmath>

// Modulación AM
std::vector<std::complex<float>> Modulator::modulateAM(const std::vector<std::complex<float>>& carrier, const std::vector<std::complex<float>>& modulatingSignal) {
    std::vector<std::complex<float>> modulatedSignal(carrier.size());
    for (size_t i = 0; i < carrier.size(); ++i) {
        modulatedSignal[i] = carrier[i] * (1.0f + modulatingSignal[i]);
    }
    return modulatedSignal;
}

// Demodulación AM
std::vector<std::complex<float>> Modulator::demodulateAM(const std::vector<std::complex<float>>& modulatedSignal) {
    std::vector<std::complex<float>> demodulatedSignal(modulatedSignal.size());
    for (size_t i = 0; i < modulatedSignal.size(); ++i) {
        demodulatedSignal[i] = std::abs(modulatedSignal[i]); // Se toma el valor absoluto de la señal modulada
    }
    return demodulatedSignal;
}

// Modulación FM
std::vector<std::complex<float>> Modulator::modulateFM(const std::vector<std::complex<float>>& modulatingSignal, float carrierFreq, float sampleRate) {
    std::vector<std::complex<float>> modulatedSignal(modulatingSignal.size());
    float phase = 0.0f;
    float freqDev = 2.0f * M_PI * carrierFreq / sampleRate;

    for (size_t i = 0; i < modulatingSignal.size(); ++i) {
        float modulatingAmplitude = std::abs(modulatingSignal[i]); // Usamos la magnitud de la señal modulante
        phase += freqDev * modulatingAmplitude;
        modulatedSignal[i] = std::polar(1.0f, phase); // Genera la señal FM compleja
    }
    return modulatedSignal;
}

// Demodulación FM
std::vector<float> Modulator::demodulateFM(const std::vector<std::complex<float>>& modulatedSignal, float sampleRate) {
    std::vector<float> demodulatedSignal(modulatedSignal.size() - 1);
    for (size_t i = 1; i < modulatedSignal.size(); ++i) {
        std::complex<float> diff = std::conj(modulatedSignal[i - 1]) * modulatedSignal[i];
        demodulatedSignal[i - 1] = std::arg(diff) * sampleRate / (2.0f * M_PI); // Frecuencia instantánea
    }
    return demodulatedSignal;
}
