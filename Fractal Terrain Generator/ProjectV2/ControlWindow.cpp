#include "ControlWindow.h"
#include <iostream>

ControlWindow::ControlWindow(QWidget *parent)
	: QWidget(parent)
	{
	windowLayout = new QBoxLayout(QBoxLayout::TopToBottom, this);
	
	menuBar = new QMenuBar(this);
	
	// create file menu
	fileMenu = menuBar->addMenu("&File");

	// create the action
	actionQuit = new QAction("&Quit", this);

	// leave signals & slots to the controller
	
	// add the item to the menu
	fileMenu->addAction(actionQuit);
	

	//terrainWidget = new FractalTerrain(this);
	//windowLayout->addWidget(terrainWidget);

	}

ControlWindow::~ControlWindow()
	{
	delete timer;
	//delete terrainWidget;
	delete windowLayout;
	}

void ControlWindow::ResetInterface()
	{

	//terrainWidget->update();
	update();
	} 
