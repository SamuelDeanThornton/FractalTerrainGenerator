#include "TerrainWindow.h"

#include <QGridLayout>
#include <QGroupBox>
#include <QVBoxLayout>
#include <QLayout>
#include <QStatusBar>
#include <QFile>
#include <QDataStream>
#include <QFileDialog>
#include <QApplication>
#include <QLineEdit>
#include <QComboBox>
#include <QLabel>
#include <QDoubleSpinBox>
#include <QPushButton>
#include <QRadioButton>
#include <QInputDialog>
#include <QTextEdit>
#include <QDebug>

TerrainWindow::TerrainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    //Defining a new widget from the FractalTerrain Class to serve as a display
    terrainWidget = new FractalTerrain(this);
    //Setting the central Widget of the main window as the terrain display
	setCentralWidget(terrainWidget);

    /////////////////////////////////////////////////////////////////////////

    //Initilaising all the widgets.
    QDockWidget *controls = new QDockWidget(tr("Menu"), this);
    QDockWidget *sliderDock = new QDockWidget(tr("Rotation"), this);
    QGroupBox *controlBox = new QGroupBox();


    QVBoxLayout *layout = new QVBoxLayout();

    QRadioButton *DSradio = new QRadioButton(tr("Diamond-Square Algorithm"));
    QRadioButton *FFTradio = new QRadioButton(tr("Fast Fourier Transform"));

    QLabel *featureSizeLabel = new QLabel(tr("Feature Size"));
    QComboBox *featureSize = new QComboBox();

    QLabel *changeSizeLabel = new QLabel(tr("Heightmap Size"));
    QComboBox *changeSize = new QComboBox();

    QLabel *roughnessLabel = new QLabel(tr("Roughness"));
    QDoubleSpinBox *roughness = new QDoubleSpinBox();

    QLabel *waterLabel = new QLabel(tr("Water Level"));
    waterSlider = new QSlider(Qt::Vertical);

    QPushButton *generateButton = new QPushButton(tr("Generate"));
    QPushButton *exportButton = new QPushButton(tr("Export"));
    QPushButton *importButton = new QPushButton(tr("Import"));

    rotationSlider = new QSlider(Qt::Horizontal);

    /////////////////////////////////////////////////////////////////////////

    //Sets the paramters for the roughness spin box; range, step size and default value.
    roughness->setRange(0, 50);
    roughness->setSingleStep(0.1);
    roughness->setValue(8);

    //Checks the radio button for the DS Algortihm initially.
    DSradio->setChecked(true);

    //Adds the options the the combo boxes.
    featureSize->insertItem(0, "2");
    featureSize->insertItem(1, "4");
    featureSize->insertItem(2, "8");
    featureSize->insertItem(3, "16");
    featureSize->insertItem(4, "32");
    featureSize->insertItem(5, "64");
    featureSize->insertItem(6, "128");
    featureSize->insertItem(7, "256");
    featureSize->insertItem(8, "512");

    featureSize->setCurrentIndex(4);

    changeSize->insertItem(0, "16");
    changeSize->insertItem(1, "32");
    changeSize->insertItem(2, "64");
    changeSize->insertItem(3, "128");
    changeSize->insertItem(4, "256");
    changeSize->insertItem(5, "512");

    changeSize->setCurrentIndex(3);

    /////////////////////////////////////////////////////////////////////////

    //Adding the widgets to the layout of the dock widget, connecting their signals to the appropriate slots as we do so.
    connect(DSradio, SIGNAL(pressed()), terrainWidget, SLOT(changeModeDS()));
    layout->addWidget(DSradio);
    connect(FFTradio, SIGNAL(pressed()), terrainWidget, SLOT(changeModeFFT()));
    layout->addWidget(FFTradio);

    layout->addStretch(1);
    layout->addWidget(changeSizeLabel);

    connect(changeSize, SIGNAL(currentIndexChanged(QString)), terrainWidget, SLOT(changeSize(QString)));
    layout->addWidget(changeSize);

    layout->addStretch(1);
    layout->addWidget(featureSizeLabel);

    connect(featureSize, SIGNAL(currentIndexChanged(QString)), terrainWidget, SLOT(changeFeature(QString)));
    layout->addWidget(featureSize);

    layout->addStretch(1);
    layout->addWidget(roughnessLabel);
    
    connect(roughness, SIGNAL(valueChanged(double)), terrainWidget, SLOT(changeRoughness(double)));
    layout->addWidget(roughness);
    layout->addStretch(1);

    layout->addWidget(waterLabel);
    waterSlider->setRange(0, 100);
    connect(waterSlider, SIGNAL(valueChanged(int)), terrainWidget, SLOT(changeWater(int)));
    layout->addWidget(waterSlider);
    layout->addStretch(1);

    connect(exportButton, SIGNAL(clicked()), terrainWidget, SLOT(exportMap()));
    layout->addWidget(exportButton);
    connect(importButton, SIGNAL(clicked()), terrainWidget, SLOT(importMap()));
    layout->addWidget(importButton);

    connect(generateButton, SIGNAL(clicked()), terrainWidget, SLOT(generate()));
    layout->addWidget(generateButton);



    //Adds the completed layout to the control box
    controlBox->setLayout(layout);

    /////////////////////////////////////////////////////////////////////////

    //Setting corners so that the menu reaches the bottom of the window while the rotation slider does not.
    setCorner(Qt::BottomRightCorner, Qt::RightDockWidgetArea);

    //Adding the controls to the dockwidget and nesting the dock widget in the right dock area.
    controls->setAllowedAreas(Qt::RightDockWidgetArea);
    controls->setFeatures(QDockWidget::NoDockWidgetFeatures);
    controls->setWidget(controlBox);
    addDockWidget(Qt::RightDockWidgetArea, controls);

    //Connects the rotation slider to the approriate slot in the terrain widget
    connect(rotationSlider, SIGNAL(valueChanged(int)), terrainWidget, SLOT(updateAngle(int)));

    //Adding the rotation slider to a dock widget and adding that dckwidget to the bottom area.
    sliderDock->setAllowedAreas(Qt::BottomDockWidgetArea);
    sliderDock->setFeatures(QDockWidget::NoDockWidgetFeatures);
    sliderDock->setWidget(rotationSlider);
    addDockWidget(Qt::BottomDockWidgetArea, sliderDock);


}

// Destructor for the window, destroying all the widgets when the window is closed.
TerrainWindow::~TerrainWindow()
	{
    delete terrainWidget;
    delete controls;
    delete sliderDock;
    delete controlBox;
	delete waterSlider;
    delete rotationSlider;
    delete DSradio;
    delete FFTradio;
    delete featureSizeLabel;
    delete featureSize;
    delete changeSizeLabel;
    delete changeSize;
    delete roughnessLabel;
    delete roughness;
    delete generateButton;
    delete exportButton;
    delete importButton;
    delete waterLabel;
	}



