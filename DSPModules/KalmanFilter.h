#ifndef KALMANFILTER_H
#define KALMANFILTER_H

// Clase KalmanFilter:
// Este filtro de Kalman se utiliza para estimar y corregir una se�al ruidosa bas�ndose en un modelo din�mico del sistema.
// El filtro ajusta sus estimaciones de acuerdo con el ruido de proceso (Q) y el ruido de medici�n (R), proporcionando
// una estimaci�n �ptima de la se�al en presencia de ruido.

class KalmanFilter {
public:
    // Constructor del filtro de Kalman:
    // - processNoise: El ruido de proceso (Q), representa la incertidumbre en el modelo din�mico.
    // - measurementNoise: El ruido de medici�n (R), representa el nivel de ruido en las observaciones.
    // - estimationError: El error inicial de estimaci�n (P), indica cu�nta confianza tenemos en la estimaci�n inicial.
    // - initialEstimate: La estimaci�n inicial del estado de la se�al.
    KalmanFilter(float processNoise, float measurementNoise, float estimationError, float initialEstimate);

    // Actualiza el filtro de Kalman con una nueva medici�n y devuelve la estimaci�n
    float update(float measurement);

private:
    float processNoise;      // Ruido del proceso (Q)
    float measurementNoise;  // Ruido de la medici�n (R)
    float estimationError;   // Error en la estimaci�n (P)
    float estimate;          // Estado estimado (x)

    float gain;              // Ganancia de Kalman (K)
};

#endif // KALMANFILTER_H
