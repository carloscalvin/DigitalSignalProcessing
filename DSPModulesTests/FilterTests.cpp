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

// Test básico para verificar que el filtro pasa-bajos funciona correctamente
TEST(FilterTests, LowPassFilterTest) {
    // Señal de prueba (señal compuesta por varias frecuencias)
    std::vector<float> testSignal = { 0, 1, 0, -1, 0, 1, 0, -1 };  // Señal con frecuencias altas y bajas
    float sampleRate = 48000.0f;  // Tasa de muestreo en Hz
    float cutoffFreq = 5000.0f;   // Frecuencia de corte en Hz (pasa-bajos)

    Filter filter(sampleRate);
    filter.applyLowPassFilter(testSignal, cutoffFreq);

    // Verificación básica: después de aplicar el filtro pasa-bajos, la señal debe estar más suavizada
    for (size_t i = 1; i < testSignal.size(); ++i) {
        ASSERT_LE(std::abs(testSignal[i] - testSignal[i - 1]), 1.0f); // Diferencias entre muestras deben ser menores
    }
}

// Test para el filtro de Kalman utilizando el módulo SignalGenerator
TEST(FilterTests, ApplyKalmanFilterTest) {
    Filter filter(48000.0f);  // Tasa de muestreo de 48 kHz
    SignalGenerator signalGenerator;  // Módulo para generar señales

    // Parámetros de la señal de prueba
    size_t length = 1000;
    float amplitude = 1.0f;
    float frequency = 1000.0f;  // Frecuencia de 1 kHz
    float sampleRate = 48000.0f;

    // Generar la señal real senoidal
    auto realSignal = signalGenerator.generateRealSineWave(amplitude, frequency, 0.0f, sampleRate, length);

    // Generar ruido gaussiano real con media 0 y desviación estándar de 0.5
    auto noise = signalGenerator.generateRealGaussianNoise(0.0f, 0.5f, length);

    // Añadir ruido a la señal original
    auto noisyRealSignal = signalGenerator.addRealNoise(realSignal, noise);

    // Aplicar el filtro de Kalman a la señal ruidosa
    filter.applyKalmanFilter(noisyRealSignal);

    // Verificar que la señal filtrada esté más cerca de la señal original
    for (size_t i = 0; i < length; ++i) {
        ASSERT_LT(std::abs(realSignal[i] - noisyRealSignal[i]), std::abs(realSignal[i] - (realSignal[i] + noise[i])));
    }

    // Verificación básica: las muestras consecutivas en la señal filtrada deberían ser más suaves
    for (size_t i = 1; i < noisyRealSignal.size(); ++i) {
        ASSERT_LE(std::abs(noisyRealSignal[i] - noisyRealSignal[i - 1]), 0.5f);  // Suavizado
    }
}
