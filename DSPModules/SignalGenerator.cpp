#include "SignalGenerator.h"
#include <cmath>
#include <random>

std::vector<std::complex<float>> SignalGenerator::generateSineWave(float amplitude, float frequency, float phase, float sampleRate, size_t length) {
    std::vector<std::complex<float>> signal(length);
    for (size_t i = 0; i < length; ++i) {
        float t = static_cast<float>(i) / sampleRate;
        signal[i] = amplitude * std::exp(std::complex<float>(0, 2 * M_PI * frequency * t + phase));
    }
    return signal;
}

std::vector<float> SignalGenerator::generateRealSineWave(float amplitude, float frequency, float phase, float sampleRate, size_t length) {
    std::vector<float> signal(length);
    for (size_t i = 0; i < length; ++i) {
        signal[i] = amplitude * sin(2 * M_PI * frequency * i / sampleRate + phase);
    }
    return signal;
}

std::vector<std::complex<float>> SignalGenerator::generateSquareWave(float amplitude, float frequency, float sampleRate, size_t length) {
    std::vector<std::complex<float>> signal(length);
    for (size_t i = 0; i < length; ++i) {
        float t = static_cast<float>(i) / sampleRate;
        signal[i] = (std::fmod(frequency * t, 1.0f) < 0.5f) ? amplitude : -amplitude;
    }
    return signal;
}

std::vector<float> SignalGenerator::generateRealSquareWave(float amplitude, float frequency, float sampleRate, size_t length) {
    std::vector<float> signal(length);
    for (size_t i = 0; i < length; ++i) {
        float t = static_cast<float>(i) / sampleRate;
        signal[i] = (std::fmod(frequency * t, 1.0f) < 0.5f) ? amplitude : -amplitude;
    }
    return signal;
}

std::vector<std::complex<float>> SignalGenerator::generateGaussianNoise(float mean, float stddev, size_t length) {
    std::default_random_engine generator;
    std::normal_distribution<float> distribution(mean, stddev);

    std::vector<std::complex<float>> noise(length);
    for (size_t i = 0; i < length; ++i) {
        float real = distribution(generator);
        float imag = distribution(generator);
        noise[i] = std::complex<float>(real, imag);
    }
    return noise;
}

std::vector<float> SignalGenerator::generateRealGaussianNoise(float mean, float stddev, size_t length) {
    std::default_random_engine generator;
    std::normal_distribution<float> distribution(mean, stddev);

    std::vector<float> noise(length);
    for (size_t i = 0; i < length; ++i) {
        noise[i] = distribution(generator);
    }
    return noise;
}

std::vector<std::complex<float>> SignalGenerator::addNoise(const std::vector<std::complex<float>>& signal, const std::vector<std::complex<float>>& noise) {
    std::vector<std::complex<float>> noisySignal(signal.size());
    for (size_t i = 0; i < signal.size(); ++i) {
        noisySignal[i] = signal[i] + noise[i];
    }
    return noisySignal;
}

std::vector<float> SignalGenerator::addRealNoise(const std::vector<float>& signal, const std::vector<float>& noise) {
    std::vector<float> noisySignal(signal.size());
    for (size_t i = 0; i < signal.size(); ++i) {
        noisySignal[i] = signal[i] + noise[i];
    }
    return noisySignal;
}
