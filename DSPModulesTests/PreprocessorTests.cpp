#include <gtest/gtest.h>
#include <vector>
#include <complex>
#include "../DSPModules/Preprocessor.h"
#include "../DSPModules/SignalGenerator.h"

TEST(PreprocessorTests, ApplyDCOffsetCorrection) {
    SignalGenerator generator;

    // Arrange: Generar una señal senoidal con un offset DC
    auto sineWave = generator.generateSineWave(1.0f, 1000.0f, 0.0f, 48000.0f, 1024);
    for (auto& sample : sineWave) {
        sample += std::complex<float>(1.0f, 1.0f); // Añadir offset DC
    }

    // Act: Crear el preprocesador y aplicar la corrección de offset DC.
    Preprocessor preprocessor;
    preprocessor.applyDCOffsetCorrection(sineWave);

    // Assert: Verificar que el offset DC ha sido eliminado
    std::complex<float> mean(0.0f, 0.0f);
    for (const auto& sample : sineWave) {
        mean += sample;
    }
    mean /= static_cast<float>(sineWave.size());

    ASSERT_NEAR(mean.real(), 0.0f, 1e-5);
    ASSERT_NEAR(mean.imag(), 0.0f, 1e-5);
}

TEST(PreprocessorTests, Normalize) {
    // Arrange: Crear un pequeño vector de datos IQ con diferentes amplitudes.
    std::vector<std::complex<float>> iqData = {
        {1.0f, 1.0f}, {2.0f, 2.0f}, {3.0f, 3.0f}, {4.0f, 4.0f}
    };

    // Act: Crear el preprocesador y aplicar la normalización.
    Preprocessor preprocessor;
    preprocessor.normalize(iqData);

    // Assert: Después de la normalización, la mayor magnitud debe ser 1.0.
    float maxAmplitude = 0.0f;
    for (const auto& sample : iqData) {
        float amplitude = std::abs(sample);
        if (amplitude > maxAmplitude) {
            maxAmplitude = amplitude;
        }
    }
    EXPECT_NEAR(maxAmplitude, 1.0f, 1e-5);

    // También podemos verificar que la relación entre muestras se mantenga proporcional
    EXPECT_NEAR(std::abs(iqData[0]), 0.25f, 1e-5);
    EXPECT_NEAR(std::abs(iqData[1]), 0.5f, 1e-5);
    EXPECT_NEAR(std::abs(iqData[2]), 0.75f, 1e-5);
    EXPECT_NEAR(std::abs(iqData[3]), 1.0f, 1e-5);
}
