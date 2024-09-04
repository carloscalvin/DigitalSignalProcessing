// main.cpp

#include <iostream>
#include "../DSPModules/SignalReader.h"

int main() {
    // Inicializa el lector de señales con la ruta al archivo IQ
    SignalReader reader("393.763_2024-09-02_19-42-53.wav");

    // Lee un chunk de datos y muestra el tamaño leído
    auto chunk = reader.getNextChunk(1024);
    std::cout << "Tamaño del chunk leído: " << chunk.size() << std::endl;

    return 0;
}
