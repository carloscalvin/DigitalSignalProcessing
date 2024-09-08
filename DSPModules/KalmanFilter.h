#ifndef KALMANFILTER_H
#define KALMANFILTER_H

// Clase KalmanFilter:
// Este filtro de Kalman se utiliza para estimar y corregir una señal ruidosa basándose en un modelo dinámico del sistema.
// El filtro ajusta sus estimaciones de acuerdo con el ruido de proceso (Q) y el ruido de medición (R), proporcionando
// una estimación óptima de la señal en presencia de ruido.

class KalmanFilter {
public:
    // Constructor del filtro de Kalman:
    // - processNoise: El ruido de proceso (Q), representa la incertidumbre en el modelo dinámico.
    // - measurementNoise: El ruido de medición (R), representa el nivel de ruido en las observaciones.
    // - estimationError: El error inicial de estimación (P), indica cuánta confianza tenemos en la estimación inicial.
    // - initialEstimate: La estimación inicial del estado de la señal.
    KalmanFilter(float processNoise, float measurementNoise, float estimationError, float initialEstimate);

    // Actualiza el filtro de Kalman con una nueva medición y devuelve la estimación
    float update(float measurement);

private:
    float processNoise;      // Ruido del proceso (Q)
    float measurementNoise;  // Ruido de la medición (R)
    float estimationError;   // Error en la estimación (P)
    float estimate;          // Estado estimado (x)

    float gain;              // Ganancia de Kalman (K)
};

#endif // KALMANFILTER_H
