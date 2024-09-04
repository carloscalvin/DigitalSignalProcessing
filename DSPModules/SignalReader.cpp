// SignalReader.cpp

#include "SignalReader.h"
#include <fstream>
#include <stdexcept>

SignalReader::SignalReader(const std::string& filePath) : currentPosition(0) {
    loadFile(filePath);
}

void SignalReader::loadFile(const std::string& filePath) {
    // Implementación básica para cargar un archivo IQ
    std::ifstream file(filePath, std::ios::binary);
    if (!file) {
        throw std::runtime_error("No se pudo abrir el archivo: " + filePath);
    }

    // Leer todo el archivo en iqData
    std::complex<float> sample;
    while (file.read(reinterpret_cast<char*>(&sample), sizeof(sample))) {
        iqData.push_back(sample);
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
