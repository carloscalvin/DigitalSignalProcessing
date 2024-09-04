#include <iostream>
#include "../DSPModules/SignalReader.h"
#include "../DSPModules/Preprocessor.h"

int main() {
    // Ruta del archivo WAV que contiene los datos IQ
    std::string filePath = "393.763_2024-09-02_19-42-53.wav";

    // Inicializar el lector de señales
    SignalReader reader(filePath);

    // Leer un chunk de datos IQ
    auto iqData = reader.getNextChunk(1024);

    // Inicializar el preprocesador
    Preprocessor preprocessor;

    // Aplicar corrección de offset DC
    preprocessor.applyDCOffsetCorrection(iqData);

    // Aplicar normalización
    preprocessor.normalize(iqData);

    // Visualización del resultado en el dominio del tiempo (por ejemplo)
    for (const auto& sample : iqData) {
        std::cout << sample.real() << " + " << sample.imag() << "i" << std::endl;
    }

    return 0;
}
