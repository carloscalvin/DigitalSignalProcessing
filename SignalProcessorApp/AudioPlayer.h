#ifndef AUDIOPLAYER_H
#define AUDIOPLAYER_H

#include <vector>

class AudioPlayer {
public:
    // Reproduce una señal de audio real (float) con una determinada tasa de muestreo
    void play(const std::vector<float>& signal, float sampleRate);
};

#endif // AUDIOPLAYER_H
