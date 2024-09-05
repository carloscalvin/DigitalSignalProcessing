#include <gtest/gtest.h>
#include "../DSPModules/SignalGenerator.h"
#include "../DSPModules/Modulator.h"

TEST(ModulatorTests, ModulateAMTest) {
    SignalGenerator generator;
    Modulator modulator;

    // Parámetros para la señal portadora
    float carrierFrequency = 10000.0f;  // Frecuencia de la portadora en Hz
    float carrierAmplitude = 1.0f;      // Amplitud de la portadora
    float sampleRate = 48000.0f;        // Tasa de muestreo en Hz
    size_t length = 1024;               // Número de muestras

    // Parámetros para la señal moduladora (una onda senoidal)
    float modulatingFrequency = 1000.0f;  // Frecuencia de la moduladora en Hz
    float modulatingAmplitude = 0.5f;     // Amplitud de la moduladora
    float modulatingPhase = 0.0f;         // Fase de la moduladora

    // Generar la señal portadora (senoidal)
    auto carrier = generator.generateSineWave(carrierAmplitude, carrierFrequency, 0.0f, sampleRate, length);

    // Generar la señal moduladora (senoidal)
    auto modulatingSignal = generator.generateSineWave(modulatingAmplitude, modulatingFrequency, modulatingPhase, sampleRate, length);

    // Aplicar la modulación AM
    auto modulatedSignal = modulator.modulateAM(carrier, modulatingSignal);

    // Verificación básica de la señal modulada
    ASSERT_EQ(modulatedSignal.size(), length);  // Asegurarse de que la señal modulada tenga la longitud correcta

    // Verificar que la amplitud de la señal modulada varía de acuerdo a la señal moduladora
    // Aquí simplemente verificamos que la amplitud de las muestras varía, lo que indicaría que se ha aplicado la modulación
    float maxAmplitude = 0.0f;
    float minAmplitude = std::numeric_limits<float>::max();
    for (const auto& sample : modulatedSignal) {
        float amplitude = std::abs(sample);
        if (amplitude > maxAmplitude) maxAmplitude = amplitude;
        if (amplitude < minAmplitude) minAmplitude = amplitude;
    }

    ASSERT_GT(maxAmplitude, carrierAmplitude);  // La amplitud máxima debe ser mayor que la amplitud de la portadora
    ASSERT_LT(minAmplitude, carrierAmplitude);  // La amplitud mínima debe ser menor que la amplitud de la portadora
}
