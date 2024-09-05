#include <iostream>
#include "../DSPModules/SignalReader.h"
#include "../DSPModules/Preprocessor.h"
#include "../DSPModules/Filter.h"
#include "../DSPModules/Visualizer.h"

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

    // Inicializar el filtro con la tasa de muestreo
    float sampleRate = 48000.0f; // Tasa de muestreo en Hz
    Filter filter(sampleRate);

    // Aplicar el filtro pasa-banda
    float lowFreq = 5000.0f;   // Frecuencia baja en Hz
    float highFreq = 15000.0f; // Frecuencia alta en Hz
    filter.applyBandpassFilter(iqData, lowFreq, highFreq);
    
    Visualizer visualizer;
    visualizer.showFrequencyDomain(iqData); // Visualizar en el dominio de la frecuencia
    preprocessor.normalize(iqData);
    visualizer.showTimeDomain(iqData);    // Visualizar en el dominio del tiempo

    return 0;
}
