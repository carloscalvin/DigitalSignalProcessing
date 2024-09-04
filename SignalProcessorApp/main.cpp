// main.cpp

#include <iostream>
#include "../DSPModules/SignalReader.h"

int main() {
    // Inicializa el lector de se�ales con la ruta al archivo IQ
    SignalReader reader("393.763_2024-09-02_19-42-53.wav");

    // Lee un chunk de datos y muestra el tama�o le�do
    auto chunk = reader.getNextChunk(1024);
    std::cout << "Tama�o del chunk le�do: " << chunk.size() << std::endl;

    return 0;
}
