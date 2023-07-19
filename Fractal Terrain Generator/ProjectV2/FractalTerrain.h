#ifndef __GL_POLYGON_WIDGET_H__
#define __GL_POLYGON_WIDGET_H__ 1

#include <QGLWidget>
#include <GL/glut.h>

class FractalTerrain: public QGLWidget
	{

	Q_OBJECT

	public:

	FractalTerrain(QWidget *parent);
	~FractalTerrain();

	//The slots used by qt
	public slots:
		void updateAngle();

	protected:

	float getRand(float min, float max);
	void writeMap(int x, int z, float value);
  	float readMap(int x, int z);
	void initializeGL();
	void resizeGL(int w, int h);
	void paintGL();
	void GenerateDSMap(int size);
	void Square(int x, int z, int nearby, float range);
	void Diamond(int x, int z, int nearby, float range);
	void DiamondSquare(int arraysize, float range);
	void DrawTerrain(int size);
	private:

	int angle;

	};

#endif
