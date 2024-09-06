#ifndef CONSOLEINTERFACE_H
#define CONSOLEINTERFACE_H

#include "../DSPModules/SignalReader.h"
#include "../DSPModules/SignalGenerator.h"
#include "../DSPModules/Preprocessor.h"
#include "../DSPModules/Filter.h"
#include "../DSPModules/Visualizer.h"
#include "../DSPModules/Modulator.h"

class ConsoleInterface {
public:
    void start();  // Inicia la interfaz de la consola

private:
    void showMainMenu();  // Muestra el menú principal
    void handleMainMenuSelection(int selection);  // Gestiona la selección del usuario

    // Variables para almacenar la señal actual y la tasa de muestreo
    std::vector<std::complex<float>> currentSignalIQ;
    std::vector<float> currentSignalReal;
    float sampleRate;

    // Instancias de las clases de la librería DSP
    SignalGenerator signalGenerator;
    Preprocessor preprocessor;
    Visualizer visualizer;
    Modulator modulator;
};

#endif // CONSOLEINTERFACE_H
