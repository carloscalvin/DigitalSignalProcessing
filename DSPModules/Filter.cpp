#include "Filter.h"
#include <fftw3.h>
#include <cmath>
#include "KalmanFilter.h"

Filter::Filter(float sampleRate) : sampleRate(sampleRate) {}

void Filter::applyBandpassFilter(std::vector<std::complex<float>>& iqData, float lowFreq, float highFreq) {
    size_t N = iqData.size();

    // Preparar entrada y salida para FFTW
    fftwf_complex* in = (fftwf_complex*)fftwf_malloc(sizeof(fftwf_complex) * N);
    fftwf_complex* out = (fftwf_complex*)fftwf_malloc(sizeof(fftwf_complex) * N);

    // Copiar iqData a la entrada de FFTW
    for (size_t i = 0; i < N; ++i) {
        in[i][0] = iqData[i].real();
        in[i][1] = iqData[i].imag();
    }

    // Crear un plan FFTW para la transformada
    fftwf_plan forwardPlan = fftwf_plan_dft_1d(N, in, out, FFTW_FORWARD, FFTW_ESTIMATE);
    fftwf_execute(forwardPlan);  // Ejecutar la FFT

    // Crear un plan FFTW para la transformada inversa
    fftwf_plan backwardPlan = fftwf_plan_dft_1d(N, out, in, FFTW_BACKWARD, FFTW_ESTIMATE);

    // Aplicar el filtro pasa-banda en el dominio de la frecuencia
    float freqResolution = sampleRate / N;

    for (size_t i = 0; i < N; ++i) {
        float freq = i * freqResolution;
        if (freq < lowFreq || freq > highFreq) {
            out[i][0] = 0.0;  // Eliminar la componente real
            out[i][1] = 0.0;  // Eliminar la componente imaginaria
        }
    }

    // Ejecutar la FFT inversa para regresar al dominio del tiempo
    fftwf_execute(backwardPlan);

    // Normalizar la salida y copiarla de vuelta a iqData
    for (size_t i = 0; i < N; ++i) {
        iqData[i] = std::complex<float>(in[i][0] / N, in[i][1] / N);
    }

    // Limpiar los recursos de FFTW
    fftwf_destroy_plan(forwardPlan);
    fftwf_destroy_plan(backwardPlan);
    fftwf_free(in);
    fftwf_free(out);
}

void Filter::applyLowPassFilter(std::vector<float>& signal, float cutoffFreq) {
    // Coeficientes del filtro
    float RC = 1.0f / (2.0f * M_PI * cutoffFreq);
    float dt = 1.0f / sampleRate;
    float alpha = dt / (RC + dt);

    // Aplicar el filtro
    for (size_t i = 1; i < signal.size(); ++i) {
        signal[i] = signal[i - 1] + alpha * (signal[i] - signal[i - 1]);
    }
}

void Filter::applyKalmanFilter(std::vector<float>& signal) {
    KalmanFilter kf(0.1, 1.0, 1.0, signal[0]);  // Inicializar el filtro de Kalman con parámetros iniciales

    std::vector<float> filteredSignal;
    for (float sample : signal) {
        filteredSignal.push_back(kf.update(sample));  // Actualizar el filtro con cada muestra y almacenar el resultado
    }

    for (size_t i = 0; i < signal.size(); ++i) {
        signal[i] = filteredSignal[i];
    }
}
