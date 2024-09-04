#include <gtest/gtest.h>
#include <vector>
#include <complex>
#include "../DSPModules/Preprocessor.h"

TEST(PreprocessorTests, ApplyDCOffsetCorrection) {
    // Arrange: Crear un peque�o vector de datos IQ con un offset DC artificial.
    std::vector<std::complex<float>> iqData = {
        {2.0f, 3.0f}, {2.0f, 3.0f}, {2.0f, 3.0f}, {2.0f, 3.0f}
    };

    // Act: Crear el preprocesador y aplicar la correcci�n de offset DC.
    Preprocessor preprocessor;
    preprocessor.applyDCOffsetCorrection(iqData);

    // Assert: Despu�s de la correcci�n, todos los valores deber�an estar centrados en torno a cero.
    for (const auto& sample : iqData) {
        EXPECT_NEAR(sample.real(), 0.0f, 1e-5);
        EXPECT_NEAR(sample.imag(), 0.0f, 1e-5);
    }
}

TEST(PreprocessorTests, Normalize) {
    // Arrange: Crear un peque�o vector de datos IQ con diferentes amplitudes.
    std::vector<std::complex<float>> iqData = {
        {1.0f, 1.0f}, {2.0f, 2.0f}, {3.0f, 3.0f}, {4.0f, 4.0f}
    };

    // Act: Crear el preprocesador y aplicar la normalizaci�n.
    Preprocessor preprocessor;
    preprocessor.normalize(iqData);

    // Assert: Despu�s de la normalizaci�n, la mayor magnitud debe ser 1.0.
    float maxAmplitude = 0.0f;
    for (const auto& sample : iqData) {
        float amplitude = std::abs(sample);
        if (amplitude > maxAmplitude) {
            maxAmplitude = amplitude;
        }
    }
    EXPECT_NEAR(maxAmplitude, 1.0f, 1e-5);

    // Tambi�n podemos verificar que la relaci�n entre muestras se mantenga proporcional
    EXPECT_NEAR(std::abs(iqData[0]), 0.25f, 1e-5);
    EXPECT_NEAR(std::abs(iqData[1]), 0.5f, 1e-5);
    EXPECT_NEAR(std::abs(iqData[2]), 0.75f, 1e-5);
    EXPECT_NEAR(std::abs(iqData[3]), 1.0f, 1e-5);
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
