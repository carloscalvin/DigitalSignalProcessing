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
    // Predicci�n: el estado no cambia
    estimationError += processNoise;

    // C�lculo de la ganancia de Kalman
    gain = estimationError / (estimationError + measurementNoise);

    // Correcci�n: ajusta la estimaci�n bas�ndose en la medici�n
    estimate = estimate + gain * (measurement - estimate);

    // Actualizaci�n de la covarianza del error
    estimationError = (1 - gain) * estimationError;

    return estimate;  // Devuelve la estimaci�n actualizada
}
