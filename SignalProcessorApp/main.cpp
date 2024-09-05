#include "ConsoleInterface.h"
#include <iostream>
#include <io.h>   // Para _setmode()
#include <fcntl.h>  // Para _O_U8TEXT
#include <stdio.h>

int main() {
    // Cambia la salida estándar a UTF-8
    _setmode(_fileno(stdout), _O_U8TEXT);
    ConsoleInterface console;
    console.start();  // Inicia la interfaz de consola interactiva
    return 0;
}
