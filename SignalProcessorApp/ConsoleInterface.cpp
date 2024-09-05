#include "ConsoleInterface.h"
#include <iostream>

void ConsoleInterface::start() {
    int selection = 0;
    do {
        showMainMenu();
        std::cin >> selection;
        handleMainMenuSelection(selection);
    } while (selection != 0);
}

void ConsoleInterface::showMainMenu() {
    std::wcout << "\nMenú Principal" << std::endl;
    std::wcout << "1. Leer señal de disco" << std::endl;
    std::wcout << "2. Generar señal senoidal" << std::endl;
    std::wcout << "3. Generar señal cuadrada" << std::endl;
    std::wcout << "4. Generar ruido gaussiano" << std::endl;
    std::wcout << "5. Aplicar normalización" << std::endl;
    std::wcout << "6. Aplicar corrección de offset DC" << std::endl;
    std::wcout << "7. Añadir ruido a la señal" << std::endl;
    std::wcout << "8. Aplicar filtro pasa-banda" << std::endl;
    std::wcout << "9. Modulación AM" << std::endl;
    std::wcout << "10. Visualizar señal en el dominio del tiempo" << std::endl;
    std::wcout << "11. Visualizar señal en el dominio de la frecuencia" << std::endl;
    std::wcout << "0. Salir" << std::endl;
    std::wcout << "Selecciona una opción: ";
}

void ConsoleInterface::handleMainMenuSelection(int selection) {
    switch (selection) {
    case 1: {
        std::string filePath;
        size_t length;
        std::wcout << "Introduce la ruta del archivo WAV: ";
        std::cin >> filePath;
        std::wcout << "Introduce el número de muestras: ";
        std::cin >> length;
        SignalReader reader(filePath);
        currentSignal = reader.getNextChunk(length);
        std::wcout << "Señal cargada" << std::endl;
        break;
    }
    case 2: {
        float amplitude, frequency, phase;
        size_t length;
        std::wcout << "Introduce la amplitud: ";
        std::cin >> amplitude;
        std::wcout << "Introduce la frecuencia (Hz): ";
        std::cin >> frequency;
        std::wcout << "Introduce la fase inicial (radianes): ";
        std::cin >> phase;
        std::wcout << "Introduce la tasa de muestreo en Hz: ";
        std::cin >> sampleRate;
        std::wcout << "Introduce el número de muestras: ";
        std::cin >> length;
        currentSignal = signalGenerator.generateSineWave(amplitude, frequency, phase, sampleRate, length);
        std::wcout << "Señal senoidal generada" << std::endl;
        break;
    }
    case 3: {
        float amplitude, frequency;
        size_t length;
        std::wcout << "Introduce la amplitud: ";
        std::cin >> amplitude;
        std::wcout << "Introduce la frecuencia (Hz): ";
        std::cin >> frequency;
        std::wcout << "Introduce el número de muestras: ";
        std::cin >> length;
        currentSignal = signalGenerator.generateSquareWave(amplitude, frequency, sampleRate, length);
        std::wcout << "Señal cuadrada generada" << std::endl;
        break;
    }
    case 4: {
        float mean, stddev;
        size_t length;
        std::wcout << "Introduce la media del ruido: ";
        std::cin >> mean;
        std::wcout << "Introduce la desviación estándar del ruido: ";
        std::cin >> stddev;
        std::wcout << "Introduce el número de muestras: ";
        std::cin >> length;
        currentSignal = signalGenerator.generateGaussianNoise(mean, stddev, length);
        std::wcout << "Ruido gaussiano generado" << std::endl;
        break;
    }
    case 5: {
        preprocessor.normalize(currentSignal);
        std::wcout << "Señal normalizada" << std::endl;
        break;
    }
    case 6: {
        preprocessor.applyDCOffsetCorrection(currentSignal);
        std::wcout << "Corrección de offset DC aplicada" << std::endl;
        break;
    }
    case 7: {
        float mean, stddev;
        size_t length = currentSignal.size();
        std::wcout << "Introduce la media del ruido: ";
        std::cin >> mean;
        std::wcout << "Introduce la desviación estándar del ruido: ";
        std::cin >> stddev;
        auto noise = signalGenerator.generateGaussianNoise(mean, stddev, length);
        currentSignal = signalGenerator.addNoise(currentSignal, noise);
        std::wcout << "Ruido añadido a la señal" << std::endl;
        break;
    }
    case 8: {
        float lowFreq, highFreq;
        std::wcout << "Introduce la tasa de muestreo en Hz: ";
        std::cin >> sampleRate;
        std::wcout << "Introduce la frecuencia baja (Hz): ";
        std::cin >> lowFreq;
        std::wcout << "Introduce la frecuencia alta (Hz): ";
        std::cin >> highFreq;
        Filter filter(sampleRate);
        filter.applyBandpassFilter(currentSignal, lowFreq, highFreq);
        std::wcout << "Filtro pasa-banda aplicado" << std::endl;
        break;
    }
    case 9: {
        float carrierFrequency, amplitude;
        size_t length;
        std::wcout << "Introduce la tasa de muestreo en Hz: ";
        std::cin >> sampleRate;
        std::wcout << "Introduce la frecuencia de la portadora (Hz): ";
        std::cin >> carrierFrequency;
        std::wcout << "Introduce la amplitud de la portadora: ";
        std::cin >> amplitude;
        std::wcout << "Introduce el número de muestras: ";
        std::cin >> length;
        auto carrier = signalGenerator.generateSineWave(amplitude, carrierFrequency, 0.0f, sampleRate, length);
        Modulator modulator;
        currentSignal = modulator.modulateAM(carrier, currentSignal);
        std::wcout << "Modulación AM aplicada" << std::endl;
        break;
    }
    case 10: {
        visualizer.showTimeDomain(currentSignal);
        break;
    }
    case 11: {
        visualizer.showFrequencyDomain(currentSignal);
        break;
    }
    case 0:
        std::wcout << "Saliendo..." << std::endl;
        break;
    default:
        std::wcout << "Opción no válida. Inténtalo de nuevo." << std::endl;
        break;
    }
}
