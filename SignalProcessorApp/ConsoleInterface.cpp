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
    std::wcout << "\nMen� Principal" << std::endl;
    std::wcout << "1. Leer se�al de disco" << std::endl;
    std::wcout << "2. Generar se�al senoidal" << std::endl;
    std::wcout << "3. Generar se�al cuadrada" << std::endl;
    std::wcout << "4. Generar ruido gaussiano" << std::endl;
    std::wcout << "5. Aplicar normalizaci�n" << std::endl;
    std::wcout << "6. Aplicar correcci�n de offset DC" << std::endl;
    std::wcout << "7. A�adir ruido a la se�al" << std::endl;
    std::wcout << "8. Aplicar filtro pasa-banda" << std::endl;
    std::wcout << "9. Modulaci�n AM" << std::endl;
    std::wcout << "10. Demodulaci�n AM" << std::endl;
    std::wcout << "11. Modulaci�n FM" << std::endl;
    std::wcout << "12. Demodulaci�n FM" << std::endl;
    std::wcout << "13. Visualizar se�al en el dominio del tiempo" << std::endl;
    std::wcout << "14. Visualizar se�al en el dominio de la frecuencia" << std::endl;
    std::wcout << "0. Salir" << std::endl;
    std::wcout << "Selecciona una opci�n: ";
}

void ConsoleInterface::handleMainMenuSelection(int selection) {
    switch (selection) {
    case 1: {
        std::string filePath;
        size_t length;
        std::wcout << "Introduce la ruta del archivo WAV: ";
        std::cin >> filePath;
        std::wcout << "Introduce el n�mero de muestras: ";
        std::cin >> length;
        SignalReader reader(filePath);
        currentSignalIQ = reader.getNextChunk(length);
        std::wcout << "Se�al cargada" << std::endl;
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
        std::wcout << "Introduce el n�mero de muestras: ";
        std::cin >> length;
        currentSignalIQ = signalGenerator.generateSineWave(amplitude, frequency, phase, sampleRate, length);
        std::wcout << "Se�al senoidal generada" << std::endl;
        break;
    }
    case 3: {
        float amplitude, frequency;
        size_t length;
        std::wcout << "Introduce la amplitud: ";
        std::cin >> amplitude;
        std::wcout << "Introduce la frecuencia (Hz): ";
        std::cin >> frequency;
        std::wcout << "Introduce el n�mero de muestras: ";
        std::cin >> length;
        currentSignalIQ = signalGenerator.generateSquareWave(amplitude, frequency, sampleRate, length);
        std::wcout << "Se�al cuadrada generada" << std::endl;
        break;
    }
    case 4: {
        float mean, stddev;
        size_t length;
        std::wcout << "Introduce la media del ruido: ";
        std::cin >> mean;
        std::wcout << "Introduce la desviaci�n est�ndar del ruido: ";
        std::cin >> stddev;
        std::wcout << "Introduce el n�mero de muestras: ";
        std::cin >> length;
        currentSignalIQ = signalGenerator.generateGaussianNoise(mean, stddev, length);
        std::wcout << "Ruido gaussiano generado" << std::endl;
        break;
    }
    case 5: {
        preprocessor.normalize(currentSignalIQ);
        std::wcout << "Se�al normalizada" << std::endl;
        break;
    }
    case 6: {
        preprocessor.applyDCOffsetCorrection(currentSignalIQ);
        std::wcout << "Correcci�n de offset DC aplicada" << std::endl;
        break;
    }
    case 7: {
        float mean, stddev;
        size_t length = currentSignalIQ.size();
        std::wcout << "Introduce la media del ruido: ";
        std::cin >> mean;
        std::wcout << "Introduce la desviaci�n est�ndar del ruido: ";
        std::cin >> stddev;
        auto noise = signalGenerator.generateGaussianNoise(mean, stddev, length);
        currentSignalIQ = signalGenerator.addNoise(currentSignalIQ, noise);
        std::wcout << "Ruido a�adido a la se�al" << std::endl;
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
        filter.applyBandpassFilter(currentSignalIQ, lowFreq, highFreq);
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
        std::wcout << "Introduce el n�mero de muestras: ";
        std::cin >> length;
        auto carrier = signalGenerator.generateSineWave(amplitude, carrierFrequency, 0.0f, sampleRate, length);
        Modulator modulator;
        currentSignalIQ = modulator.modulateAM(carrier, currentSignalIQ);
        std::wcout << "Modulaci�n AM aplicada" << std::endl;
        break;
    }
    case 10: {
        Modulator modulator;
        currentSignalIQ = modulator.demodulateAM(currentSignalIQ);
        std::wcout << "Demodulaci�n AM aplicada" << std::endl;
        break;
    }
    case 11: {
        float carrierFrequency;
        std::wcout << "Introduce la tasa de muestreo en Hz: ";
        std::cin >> sampleRate;
        std::wcout << "Introduce la frecuencia de la portadora (Hz): ";
        std::cin >> carrierFrequency;
        Modulator modulator;
        currentSignalIQ = modulator.modulateFM(currentSignalIQ, carrierFrequency, sampleRate);
        std::wcout << "Modulaci�n FM aplicada" << std::endl;
        break;
    }
    case 12: { // Demodulaci�n FM
        Modulator modulator;
        currentSignalReal = modulator.demodulateFM(currentSignalIQ, sampleRate);
        std::wcout << "Demodulaci�n FM aplicada" << std::endl;
        break;
    }
    case 13: {
        visualizer.showTimeDomain(currentSignalIQ);
        break;
    }
    case 14: {
        visualizer.showFrequencyDomain(currentSignalIQ);
        break;
    }
    case 0:
        std::wcout << "Saliendo..." << std::endl;
        break;
    default:
        std::wcout << "Opci�n no v�lida. Int�ntalo de nuevo." << std::endl;
        break;
    }
}
