#include <QApplication>
#include "TerrainWindow.h"

int main(int argc, char *argv[])
	{ 
	
	// Create a new QApplication
	QApplication app(argc, argv);

	// Create a new terrain window	
	TerrainWindow *Main= new TerrainWindow(NULL);

	// resize the window to a standard size
	Main->resize(1200, 800);

	// Show the window from its default not shown state
	Main->show();

	// Execute the application
	app.exec();

	//Delete the window when the app has finished running
	delete Main;

	// Return
	return 0;
	} 
