#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QGLWidget>
#include <QMainWindow>
#include <QGridLayout>
#include <QSlider>
#include <QTimer>
#include <QLabel>
#include <QBoxLayout>
#include <QDockWidget>
#include <QComboBox>
#include <QGroupBox>
#include <QToolBar>
#include <QPushButton>
#include <QRadioButton>
#include <QDoubleSpinBox>
#include "FractalTerrain.h"


class TerrainWindow: public QMainWindow
{
    Q_OBJECT

public:

    explicit TerrainWindow(QWidget *parent); 
    ~TerrainWindow();

    FractalTerrain *terrainWidget;
    QDockWidget *controls;
    QDockWidget *sliderDock;

    QGroupBox *controlBox;

	QSlider *waterSlider;
    QSlider *rotationSlider;

    QRadioButton *DSradio;
    QRadioButton *FFTradio;
    QLabel *featureSizeLabel;
    QComboBox *featureSize;
    QLabel *changeSizeLabel;
    QComboBox *changeSize;
    QLabel *roughnessLabel;
    QDoubleSpinBox *roughness;
    QPushButton *generateButton;
    QPushButton *exportButton;
    QPushButton *importButton;
    QLabel *waterLabel;

};

#endif 