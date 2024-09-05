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

    // Establecer la se�al IQ para visualizaci�n
    void setSignal(const std::vector<std::complex<float>>& iqData);

    // Establecer t�tulo del gr�fico
    void setTitle(const QString& title);

    // Mostrar la se�al
    void show();

private:
    QMainWindow window;
    QChart* chart;
    QLineSeries* seriesI;
    QLineSeries* seriesQ;
    QChartView* chartView;
};

#endif // SIGNALVISUALIZER_H
