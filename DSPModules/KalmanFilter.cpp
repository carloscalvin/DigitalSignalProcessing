#include "KalmanFilter.h"

KalmanFilter::KalmanFilter(
    float processNoise, 
    float measurementNoise, 
    float estimationError, 
    float initialEstimate) : 
    processNoise(processNoise),
    measurementNoise(measurementNoise), 
    estimationError(estimationError), 
    estimate(initialEstimate) {
}

float KalmanFilter::update(float measurement) {
    // Predicción: el estado no cambia
    estimationError += processNoise;

    // Cálculo de la ganancia de Kalman
    gain = estimationError / (estimationError + measurementNoise);

    // Corrección: ajusta la estimación basándose en la medición
    estimate = estimate + gain * (measurement - estimate);

    // Actualización de la covarianza del error
    estimationError = (1 - gain) * estimationError;

    return estimate;  // Devuelve la estimación actualizada
}
