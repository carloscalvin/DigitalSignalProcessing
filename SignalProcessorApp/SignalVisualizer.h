#ifndef SIGNALVISUALIZER_H
#define SIGNALVISUALIZER_H

#include <QtCharts/QChartView>
#include <QtCharts/QLineSeries>
#include <QtWidgets/QMainWindow>
#include <vector>
#include <complex>

QT_CHARTS_USE_NAMESPACE

class SignalVisualizer {
public:
    // Constructor: Inicializa la ventana principal y las series de datos
    SignalVisualizer();

    // Establecer la señal IQ para visualización
    void setSignal(const std::vector<std::complex<float>>& iqData);

    // Establecer título del gráfico
    void setTitle(const QString& title);

    // Mostrar la señal
    void show();

private:
    QMainWindow window;
    QChart* chart;
    QLineSeries* seriesI;
    QLineSeries* seriesQ;
    QChartView* chartView;
};

#endif // SIGNALVISUALIZER_H
