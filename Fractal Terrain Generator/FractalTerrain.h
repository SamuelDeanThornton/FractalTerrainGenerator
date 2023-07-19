#ifndef __GL_POLYGON_WIDGET_H__
#define __GL_POLYGON_WIDGET_H__ 1

#include <QGLWidget>

class FractalTerrain: public QGLWidget
	{

	Q_OBJECT

	public:

	FractalTerrain(QWidget *parent);
	~FractalTerrain();

	public slots:
		void updateAngle(int i);
		void changeWater(int i);
		void changeRoughness(double i);
		void changeFeature(QString  i);
		void changeSize(QString i);
		void changeModeDS();
		void changeModeFFT();
		void generate();
		void exportMap();
		void importMap();

	protected:

	double getRand(double min, double max);
	void writeMap(int x, int z, double value);
  	double readMap(int x, int z);
	void GenerateFFTMap(int size);
	void initializeGL();
	void FFTMethod(double r);
	void resizeGL(int w, int h);
	void paintGL();
	void GenerateDSMap(int size, int featuresize);
	void Square(int x, int z, int nearby, double range);
	void Diamond(int x, int z, int nearby, double range);
	void DiamondSquare(int arraysize, double range);
	void DrawTerrain(int size, int waterlevel);
	private:

	int angle;
	int mode;
	int waterlevel;
	float roughness;
	int featuresize;
	int mastersize;
	double scale;

	};

#endif
