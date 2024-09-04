# Digital Signal Processing Project

Este proyecto implementa una solución modular para el procesamiento de señales digitales (DSP), específicamente señales IQ capturadas desde un receptor SDR. La aplicación permite leer, preprocesar, filtrar, demodular y visualizar señales digitales.

## Estructura del Proyecto

- **DSPModules**: Biblioteca estática que contiene los módulos de procesamiento de señales, como `SignalReader`, `Preprocessor`, `Filter`, y `Visualizer`.
- **SignalProcessorApp**: Aplicación de consola que utiliza la biblioteca `DSPModules` para procesar y visualizar señales IQ.
- **DSPModulesTests**: Proyecto de pruebas unitarias para validar los módulos en `DSPModules`.

## Requisitos

- **Lenguaje**: C++
- **Compilador**: Microsoft Visual Studio 2022 (o superior)
- **Framework de Pruebas**: Google Test

## Licencia

Este proyecto está licenciado bajo la [MIT License](LICENSE).
