#ifndef __GL_POLYGON_WINDOW_H__
#define __GL_POLYGON_WINDOW_H__ 1

#include <QGLWidget>
#include <QMenuBar>
#include <QSlider>
#include <QTimer>
#include <QBoxLayout>
#include "FractalTerrain.h"

class DisplayWindow: public QWidget
	{
	public:


	DisplayWindow(QWidget *parent);
	~DisplayWindow();

	// visual hierarchy
	// menu bar
	QMenuBar *menuBar;
		// file menu
		QMenu *fileMenu;
			// quit action
			QAction *actionQuit;


	QBoxLayout *windowLayout;

	FractalTerrain *terrainWidget;

	QTimer* timer;

	void ResetInterface();
	};

#endif
