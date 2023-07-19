#include "DisplayWindow.h"
#include <iostream>

DisplayWindow::DisplayWindow(QWidget *parent)
	: QWidget(parent)
	{
		
	terrainWidget = new FractalTerrain(this);
	windowLayout->addWidget(terrainWidget);
	// create menu bar
	menuBar = new QMenuBar(this);
	
	// create file menu
	fileMenu = menuBar->addMenu("&File");

	// create the action
	actionQuit = new QAction("&Quit", this);

	// leave signals & slots to the controller
	
	// add the item to the menu
	fileMenu->addAction(actionQuit);

	windowLayout = new QBoxLayout(QBoxLayout::TopToBottom, this);

	terrainWidget = new FractalTerrain(this);
	windowLayout->addWidget(terrainWidget);

		timer = new QTimer(this);
        connect(timer, SIGNAL(timeout()),  terrainWidget, SLOT(updateAngle()));
		timer->start(1);
	}

DisplayWindow::~DisplayWindow()
	{
	delete timer;
	delete terrainWidget;
	delete windowLayout;
	}

void DisplayWindow::ResetInterface()
	{

	terrainWidget->update();
	update();
	} 
