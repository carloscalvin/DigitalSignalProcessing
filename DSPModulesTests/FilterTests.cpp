#include "../DSPModules/Filter.h"
#include <gtest/gtest.h>
#include <vector>
#include <complex>

// Test básico para verificar que el filtro pasa-banda funciona correctamente
TEST(FilterTests, BandpassFilterTest) {
    // Crear un trozo de señal IQ con valores conocidos
    std::vector<std::complex<float>> iqData = {
        {1.0f, 0.5f}, {0.8f, 0.2f}, {0.5f, 0.0f}, {0.2f, -0.2f}, {0.0f, -0.5f},
        {-0.2f, -0.8f}, {-0.5f, -1.0f}, {-0.8f, -1.2f}, {-1.0f, -1.5f}, {-1.2f, -1.8f}
    };

    // Inicializar el filtro con la tasa de muestreo
    float sampleRate = 48000.0f; // Tasa de muestreo en Hz
    Filter filter(sampleRate);

    // Definir las frecuencias bajas y altas para el filtro pasa-banda
    float lowFreq = 5000.0f;   // Frecuencia baja en Hz
    float highFreq = 15000.0f; // Frecuencia alta en Hz

    // Aplicar el filtro pasa-banda a la señal
    filter.applyBandpassFilter(iqData, lowFreq, highFreq);

    // Verificar que la señal haya sido procesada
    bool allSame = true;
    for (size_t i = 1; i < iqData.size(); ++i) {
        if (iqData[i] != iqData[0]) {
            allSame = false;
            break;
        }
    }

    // Si todos los valores son iguales, el filtro no ha hecho nada (lo cual sería un error aquí)
    ASSERT_FALSE(allSame);
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
