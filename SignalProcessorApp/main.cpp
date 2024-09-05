#include <iostream>
#include "../DSPModules/SignalReader.h"
#include "../DSPModules/Preprocessor.h"
#include "SignalVisualizer.h"

int main() {
    // Ruta del archivo WAV que contiene los datos IQ
    std::string filePath = "393.763_2024-09-02_19-42-53.wav";

    // Inicializar el lector de señales
    SignalReader reader(filePath);

    // Inicializar el visualizador de gráficos
    SignalVisualizer visualizer;

    // Leer un chunk de datos IQ
    auto iqData = reader.getNextChunk(1024);
    visualizer.setTitle("Raw IQ");
    visualizer.setSignal(iqData);
    visualizer.show();

    // Inicializar el preprocesador
    Preprocessor preprocessor;

    // Aplicar corrección de offset DC
    preprocessor.applyDCOffsetCorrection(iqData);
    visualizer.setTitle("Corregido offset DC");
    visualizer.setSignal(iqData);
    visualizer.show();

    // Aplicar normalización
    preprocessor.normalize(iqData);
    visualizer.setTitle("Normalizada");
    visualizer.setSignal(iqData);
    visualizer.show();

    return 0;
}
