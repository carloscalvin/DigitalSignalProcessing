#include <gtest/gtest.h>
#include "../DSPModules/SignalGenerator.h"
#include "../DSPModules/Modulator.h"

TEST(ModulatorTests, ModulateAMTest) {
    SignalGenerator generator;
    Modulator modulator;

    // Par�metros para la se�al portadora
    float carrierFrequency = 10000.0f;  // Frecuencia de la portadora en Hz
    float carrierAmplitude = 1.0f;      // Amplitud de la portadora
    float sampleRate = 48000.0f;        // Tasa de muestreo en Hz
    size_t length = 1024;               // N�mero de muestras

    // Par�metros para la se�al moduladora (una onda senoidal)
    float modulatingFrequency = 1000.0f;  // Frecuencia de la moduladora en Hz
    float modulatingAmplitude = 0.5f;     // Amplitud de la moduladora
    float modulatingPhase = 0.0f;         // Fase de la moduladora

    // Generar la se�al portadora (senoidal)
    auto carrier = generator.generateSineWave(carrierAmplitude, carrierFrequency, 0.0f, sampleRate, length);

    // Generar la se�al moduladora (senoidal)
    auto modulatingSignal = generator.generateSineWave(modulatingAmplitude, modulatingFrequency, modulatingPhase, sampleRate, length);

    // Aplicar la modulaci�n AM
    auto modulatedSignal = modulator.modulateAM(carrier, modulatingSignal);

    // Verificaci�n b�sica de la se�al modulada
    ASSERT_EQ(modulatedSignal.size(), length);  // Asegurarse de que la se�al modulada tenga la longitud correcta

    // Verificar que la amplitud de la se�al modulada var�a de acuerdo a la se�al moduladora
    // Aqu� simplemente verificamos que la amplitud de las muestras var�a, lo que indicar�a que se ha aplicado la modulaci�n
    float maxAmplitude = 0.0f;
    float minAmplitude = std::numeric_limits<float>::max();
    for (const auto& sample : modulatedSignal) {
        float amplitude = std::abs(sample);
        if (amplitude > maxAmplitude) maxAmplitude = amplitude;
        if (amplitude < minAmplitude) minAmplitude = amplitude;
    }

    ASSERT_GT(maxAmplitude, carrierAmplitude);  // La amplitud m�xima debe ser mayor que la amplitud de la portadora
    ASSERT_LT(minAmplitude, carrierAmplitude);  // La amplitud m�nima debe ser menor que la amplitud de la portadora
}
