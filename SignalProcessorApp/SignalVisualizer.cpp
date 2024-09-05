#include "SignalVisualizer.h"

SignalVisualizer::SignalVisualizer() {
    // Crear el gráfico y las series de datos
    chart = new QChart();
    seriesI = new QLineSeries();
    seriesQ = new QLineSeries();

    // Configurar el gráfico
    chart->legend()->show();
    chart->addSeries(seriesI);
    chart->addSeries(seriesQ);
    chart->createDefaultAxes();

    // Crear el QChartView para mostrar el gráfico en la ventana
    chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);

    // Establecer el gráfico en la ventana principal
    window.setCentralWidget(chartView);
    window.resize(800, 600);
}

void SignalVisualizer::setSignal(const std::vector<std::complex<float>>& iqData) {
    // Limpiar las series existentes
    seriesI->clear();
    seriesQ->clear();

    // Rellenar las series con los datos IQ
    for (int i = 0; i < iqData.size(); ++i) {
        seriesI->append(i, iqData[i].real());
        seriesQ->append(i, iqData[i].imag());
    }
}

void SignalVisualizer::setTitle(const QString& title) {
    chart->setTitle(title);
}

void SignalVisualizer::show() {
    window.show();
}
