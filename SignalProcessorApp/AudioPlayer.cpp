#include "AudioPlayer.h"
#include <iostream>
#include <portaudio.h>

void AudioPlayer::play(const std::vector<float>& signal, float sampleRate) {
    Pa_Initialize();  // Inicializa PortAudio

    // Definir la configuración del stream de audio
    PaStream* stream;
    Pa_OpenDefaultStream(&stream, 0, 1, paFloat32, sampleRate, 256, nullptr, nullptr);

    // Abrir el stream de audio
    Pa_StartStream(stream);

    // Enviar las muestras de la señal al stream de audio
    Pa_WriteStream(stream, signal.data(), signal.size());

    // Detener y cerrar el stream
    Pa_StopStream(stream);
    Pa_CloseStream(stream);

    Pa_Terminate();  // Termina PortAudio
}
