#include <gtest/gtest.h>
#include <vector>
#include <complex>
#include "../DSPModules/Filter.h"
#include "../DSPModules/SignalGenerator.h"

// Test básico para verificar que el filtro pasa-banda funciona correctamente
TEST(FilterTests, BandpassFilterTest) {
    SignalGenerator generator;

    // Generar una señal senoidal con frecuencia de 5000 Hz
    auto sineWave = generator.generateSineWave(1.0f, 5000.0f, 0.0f, 48000.0f, 1024);

    // Generar ruido de fondo
    auto noise = generator.generateGaussianNoise(0.0f, 0.1f, 1024);

    // Añadir ruido a la señal
    auto noisySignal = generator.addNoise(sineWave, noise);

    // Inicializar el filtro con la tasa de muestreo
    float sampleRate = 48000.0f; // Tasa de muestreo en Hz
    Filter filter(sampleRate);

    // Definir las frecuencias bajas y altas para el filtro pasa-banda
    float lowFreq = 5000.0f;   // Frecuencia baja en Hz
    float highFreq = 15000.0f; // Frecuencia alta en Hz

    // Aplicar el filtro pasa-banda a la señal
    filter.applyBandpassFilter(noisySignal, lowFreq, highFreq);

    // Verificar que la señal filtrada tiene componentes significativas en torno a 5000 Hz
    float maxAmplitude = 0.0f;
    for (const auto& sample : noisySignal) {
        maxAmplitude = std::max(maxAmplitude, std::abs(sample));
    }

    ASSERT_GT(maxAmplitude, 0.5f);  // Asegurarse de que la señal útil no fue filtrada
}
