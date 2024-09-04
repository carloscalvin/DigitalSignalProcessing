// SignalReader.h

#ifndef SIGNALREADER_H
#define SIGNALREADER_H

#include <vector>
#include <complex>
#include <string>

// Clase SignalReader:
// Esta clase se encarga de leer el archivo IQ desde el disco y mapearlo en memoria
// para un acceso eficiente. Proporciona m�todos para obtener segmentos (chunks) de
// datos IQ, lo que permite procesar la se�al en partes manejables.

class SignalReader {
public:
    // Constructor que inicializa la clase con la ruta del archivo IQ.
    SignalReader(const std::string& filePath);

    // Retorna el siguiente segmento de datos IQ del archivo.
    std::vector<std::complex<float>> getNextChunk(size_t chunkSize);

private:
    // Vector que almacena los datos IQ le�dos del archivo.
    std::vector<std::complex<float>> iqData;

    // Posici�n actual en el archivo IQ.
    size_t currentPosition;

    // M�todo privado que carga todo el archivo IQ en memoria.
    void loadFile(const std::string& filePath);
};

#endif // SIGNALREADER_H
