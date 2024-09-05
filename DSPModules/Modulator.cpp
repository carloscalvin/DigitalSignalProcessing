#include "Modulator.h"

std::vector<std::complex<float>> Modulator::modulateAM(const std::vector<std::complex<float>>& carrier, const std::vector<std::complex<float>>& modulatingSignal) {
    std::vector<std::complex<float>> modulatedSignal(carrier.size());
    for (size_t i = 0; i < carrier.size(); ++i) {
        modulatedSignal[i] = carrier[i] * (1.0f + modulatingSignal[i]);
    }
    return modulatedSignal;
}
