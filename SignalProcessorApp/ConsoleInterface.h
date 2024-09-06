#ifndef CONSOLEINTERFACE_H
#define CONSOLEINTERFACE_H

#include "../DSPModules/SignalReader.h"
#include "../DSPModules/SignalGenerator.h"
#include "../DSPModules/Preprocessor.h"
#include "../DSPModules/Filter.h"
#include "../DSPModules/Visualizer.h"
#include "../DSPModules/Modulator.h"
#include "AudioPlayer.h"

class ConsoleInterface {
public:
    void start();  // Inicia la interfaz de la consola

private:
    void showMainMenu();  // Muestra el men� principal
    void handleMainMenuSelection(int selection);  // Gestiona la selecci�n del usuario

    // Variables para almacenar la se�al actual y la tasa de muestreo
    std::vector<std::complex<float>> currentSignalIQ;
    std::vector<float> currentSignalReal;
    float sampleRate;

    // Instancias de las clases de la librer�a DSP
    SignalGenerator signalGenerator;
    Preprocessor preprocessor;
    Visualizer visualizer;
    Modulator modulator;
    AudioPlayer audioPlayer;
};

#endif // CONSOLEINTERFACE_H
