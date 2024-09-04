#include "Preprocessor.h"
#include <numeric> // Para std::accumulate

// Aplica corrección del offset DC a los datos IQ.
void Preprocessor::applyDCOffsetCorrection(std::vector<std::complex<float>>& iqData) {
    if (iqData.empty()) {
        return; // No hay datos para procesar
    }

    // Calcular el valor promedio (DC offset)
    std::complex<float> dcOffset = std::accumulate(iqData.begin(), iqData.end(), std::complex<float>(0.0, 0.0)) / static_cast<float>(iqData.size());

    // Restar el offset a cada muestra
    for (auto& sample : iqData) {
        sample -= dcOffset;
    }
}

// Normaliza los valores de la señal IQ para que tengan un rango consistente.
void Preprocessor::normalize(std::vector<std::complex<float>>& iqData) {
    if (iqData.empty()) {
        return; // No hay datos para procesar
    }

    // Calcular la amplitud máxima
    float maxAmplitude = 0.0f;
    for (const auto& sample : iqData) {
        float amplitude = std::abs(sample);
        if (amplitude > maxAmplitude) {
            maxAmplitude = amplitude;
        }
    }

    // Evitar división por cero
    if (maxAmplitude == 0.0f) {
        return;
    }

    // Normalizar todas las muestras
    for (auto& sample : iqData) {
        sample /= maxAmplitude;
    }
}
