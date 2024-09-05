#include "SignalReader.h"
#include <stdexcept>
#include <iostream>

SignalReader::SignalReader(const std::string& filePath) : currentPosition(0) {
    loadFile(filePath);
}

void SignalReader::loadFile(const std::string& filePath) {
    // Estructura para almacenar la información del archivo WAV
    SF_INFO sfinfo;
    SNDFILE* file = sf_open(filePath.c_str(), SFM_READ, &sfinfo);

    if (!file) {
        throw std::runtime_error("No se pudo abrir el archivo: " + filePath);
    }

    // Verificar que el archivo tenga dos canales (IQ)
    if (sfinfo.channels != 2) {
        sf_close(file);
        throw std::runtime_error("El archivo WAV debe contener exactamente 2 canales (I y Q).");
    }

    // Leer los datos del archivo en un buffer
    std::vector<float> buffer(sfinfo.frames * sfinfo.channels);
    sf_readf_float(file, buffer.data(), sfinfo.frames);

    // Cerrar el archivo después de la lectura
    sf_close(file);

    // Convertir el buffer de intercalado de I/Q en un vector de std::complex<float>
    iqData.reserve(sfinfo.frames);
    for (sf_count_t i = 0; i < sfinfo.frames; ++i) {
        iqData.emplace_back(buffer[i * 2], buffer[i * 2 + 1]);  // (I, Q)
    }
}

std::vector<std::complex<float>> SignalReader::getNextChunk(size_t chunkSize) {
    // Retorna un segmento de datos IQ
    std::vector<std::complex<float>> chunk;
    if (currentPosition + chunkSize <= iqData.size()) {
        chunk.assign(iqData.begin() + currentPosition, iqData.begin() + currentPosition + chunkSize);
        currentPosition += chunkSize;
    }
    return chunk;
}
