# Digital Signal Processing Project

Este proyecto implementa una soluci�n modular para el procesamiento de se�ales digitales (DSP), espec�ficamente se�ales IQ capturadas desde un receptor SDR. La aplicaci�n permite leer, preprocesar, filtrar, demodular y visualizar se�ales digitales.

## Estructura del Proyecto

- **DSPModules**: Biblioteca est�tica que contiene los m�dulos de procesamiento de se�ales, como `SignalReader`, `Preprocessor`, `Filter`, y `Visualizer`.
- **SignalProcessorApp**: Aplicaci�n de consola que utiliza la biblioteca `DSPModules` para procesar y visualizar se�ales IQ.
- **DSPModulesTests**: Proyecto de pruebas unitarias para validar los m�dulos en `DSPModules`.

## Requisitos

- **Lenguaje**: C++
- **Compilador**: Microsoft Visual Studio 2022 (o superior)
- **Framework de Pruebas**: Google Test

## Licencia

Este proyecto est� licenciado bajo la [MIT License](LICENSE).
