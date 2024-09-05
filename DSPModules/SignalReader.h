#ifndef SIGNALREADER_H
#define SIGNALREADER_H

#include <vector>
#include <complex>
#include <string>

// Incluir la cabecera de libsndfile
#include <sndfile.h>

// Clase SignalReader:
// Esta clase se encarga de leer el archivo IQ desde un archivo WAV y mapearlo en memoria
// para un acceso eficiente. Proporciona métodos para obtener segmentos (chunks) de
// datos IQ, lo que permite procesar la señal en partes manejables.

class SignalReader {
public:
    // Constructor que inicializa la clase con la ruta del archivo WAV.
    SignalReader(const std::string& filePath);

    // Retorna el siguiente segmento de datos IQ del archivo.
    std::vector<std::complex<float>> getNextChunk(size_t chunkSize);

private:
    // Vector que almacena los datos IQ leídos del archivo.
    std::vector<std::complex<float>> iqData;

    // Posición actual en el archivo IQ.
    size_t currentPosition;

    // Método privado que carga todo el archivo IQ desde un archivo WAV en memoria.
    void loadFile(const std::string& filePath);
};

#endif // SIGNALREADER_H
