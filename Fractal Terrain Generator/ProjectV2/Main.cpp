#include <QApplication>
#include <QVBoxLayout>
#include "DisplayWindow.h"
#include "ControlWindow.h"

int main(int argc, char *argv[])
	{ // main()
	// create the application
	QApplication app(argc, argv);
	glutInit(&argc,argv);

	// create model (polygon) as a triangle
	//	GLPolygon *polygon = new GLPolygon();

	// create a master widget
       	DisplayWindow *TerrainWindow = new DisplayWindow(NULL);
		//DisplayWindow *Control= new DisplayWindow(NULL);


	// resize the window
	//Control->resize(400, 800);
	TerrainWindow->resize(800, 800);

	// show the label
	TerrainWindow->show();
	//Control->show();

	// start it running
	app.exec();

	// clean up
	//	delete controller;
	//delete Control;
	delete TerrainWindow;

	// return to caller
	return 0;
	} // main()
