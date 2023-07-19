#include <GL/glu.h>
#include <QGLWidget>
#include <QSlider>
#include <vector>
#include <stdlib.h>
#include <cmath>
#include <ctime>
#include <iostream>
#include "FractalTerrain.h"


using namespace std;

// struct for materials
typedef struct materialStruct {
  GLfloat ambient[4];
  GLfloat diffuse[4];
  GLfloat specular[4];
  GLfloat shininess;
} materialStruct;

static materialStruct Rock = {
  {0, 0, 0, 0  },
  {0.427451f, 0.470588f, 0.541176f, 1.0f },
  {0,0,0,0},
  0
};
static materialStruct green = {
{0.0f,0.0f,0.0f,1.0f },
{0.1f,0.35f,0.1f,1.0f},
{0.45f,0.55f,0.45f,1.0f},
32.0f
};
static materialStruct whiteShinyMaterials = {
  { 1.0, 1.0, 1.0, 1.0},
  { 1.0, 1.0, 1.0, 1.0},
  { 1.0, 1.0, 1.0, 1.0},
  100.0
};

int mastersize = 128;
float DSMAP[128][128] = {0, 0};
vector<double> midpoints;
vector<double> newmap;
vector<int>::iterator it;


FractalTerrain::FractalTerrain(QWidget *parent)
  : QGLWidget(parent), angle(0)
	{
	srand(unsigned(time(NULL)));
	GenerateDSMap(mastersize);
	DiamondSquare(16, 1);
	}

void FractalTerrain::updateAngle(){
  angle += 1;
  this->repaint();
}
// called when OpenGL context is set up
void FractalTerrain::initializeGL()
	{
	srand(unsigned(time(NULL)));
	GenerateDSMap(mastersize);
	DiamondSquare(16, 1);
	//Background colour is black
	glClearColor(1, 1, 1, 1.0);
		glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        glOrtho(-40.0, 40.0, -40.0, 40.0, -40.0, 40.0);
		glMatrixMode(GL_MODELVIEW);
 	}

//Make sure to delete all the quadrics
FractalTerrain::~FractalTerrain()
{

}


float FractalTerrain::getRand(float min, float max){
	//srand(unsigned(time(NULL)));
	if (min > max){
		std::swap(min, max);
	}
	return min + (float)rand() * (max - min) / (float)RAND_MAX;
}

void FractalTerrain::writeMap(int x, int z, float value){
	while (x >= mastersize){
		x -= mastersize;
	}
	while (x < 0){
		x += mastersize;
	}
	while (z >= mastersize){
		z -= mastersize;
	}
	while (z < 0){
		z += mastersize;
	}
	DSMAP[x][z] = value;
}
float FractalTerrain::readMap(int x, int z){
	while (x >= mastersize){
		x -= mastersize;
	}
	while (x < 0){
		x += mastersize;
	}
	while (z >= mastersize){
		z -= mastersize;
	}
	while (z < 0){
		z += mastersize;
	}
	return DSMAP[x][z];
}

void FractalTerrain::GenerateDSMap(int size){

	writeMap(0,0, getRand(-3, 3));
	writeMap(0,size-1, getRand(-3, 3));
	writeMap(size-1,0, getRand(-3, 3));
	writeMap(size-1,size-1, 3);

	/*
	for( int x = 0; x < mastersize; x += featuresize){
    	for (int z = 0; z < mastersize; z += featuresize){
			double value = ((double) rand() / (RAND_MAX));
			int dir = (float)(rand() % 100);
			if (dir > 49){
				value = -value;
			}
        	writeMap(x, z, value);
		}
	}
	*/
}

void FractalTerrain::Square(int x, int z, int step, float range){
	int count = 0;
	float value = 0;
	float average = 0;
	float shift;
	int bounds = mastersize - 1;
	//Looking for the four corners of the square 
	//Also checking that they aren't outside of the bounds of the array
	if (((x-step) >= 0) && (((z - step) >= 0))){
		average += readMap(x-step, z-step);
		count++;
	}
	if (((x-step) >= 0) && (((z + step) <= bounds))){
		average += readMap(x-step, z+step);
		count++;
	}
	if (((x+step) <= bounds) && (((z - step) >= 0))){
		average += readMap(x+step, z-step);
		count++;
	}
	if (((x+step) <= bounds) && (((z + step) <= bounds))){
		average += readMap(x+step, z+step);
		count++;
	}

	shift = getRand(-range, range);

	value = (average/count)+shift;
	cout << "square";
	cout << x << ", "<< z << ": " << value << "\n";
	writeMap(x, z, value);
}

void FractalTerrain::Diamond(int x, int z, int step, float range){
	int count = 0;
	float value = 0;
	float average = 0;
	float shift;
	int bounds = mastersize -1;
	//Looking for the four corners of the diamond 
	//the access functions wrap so no need to check for outside of the array
	if (((x - step) >= 0)){
		average += readMap(x-step, z);
		count++;
	}
	if (((z - step) >= 0)){
		average += readMap(x,z-step);
		count++;
	}
	if (((x+step) <= bounds)){
		average += readMap(x+step, z);
		count++;
		
	}
	if (((z + step) <= bounds)){
		average += readMap(x, z+step);
		count++;
	}

	shift = getRand(-range, range);
	value = (average/4)+shift;
	cout << "diamond";
	cout << x << ", "<< z << ": " << value << "\n";
	writeMap(x, z, value);
}

//Recursive function to calculate heightmap
void FractalTerrain::DiamondSquare(int step, float range){
	int half= step/2;
	
	if (half < 1){
		return;
	}

	for (int x = half; x < mastersize+half; x+=step){
		for (int z = half; z < mastersize+half; z+=step){
			Square(x, z, half, range);
		}
	}
	for (int x = 0; x < mastersize; x+= step){
		for (int z = 0; z<mastersize; z+= step){
				Diamond(x+half , z, half, range);
				Diamond(x, z+half, half, range);
		}
	}

	cout << "next";
	DiamondSquare(half, range/2);

}

void FractalTerrain::DrawTerrain(int size){	
	materialStruct* p_front = &green;
	tuple <float, float, float> V1;
	tuple <float, float, float> V2;
	float scale = 10/size;
	
	glMaterialfv(GL_FRONT, GL_AMBIENT,    p_front->ambient);
	glMaterialfv(GL_FRONT, GL_DIFFUSE,    p_front->diffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR,   p_front->specular);
	glMaterialf(GL_FRONT, GL_SHININESS,   p_front->shininess);
	for (int x=0;x<=size-2; x++){
		for (int z=0;z<=size-2; z++){
	
			/*
			float xcoor = x/20;
			float zcoor = z/20;

			V1 = make_tuple(1, DSMAP[x][z] - DSMAP[x+1][z], 0);
			V2 = make_tuple(1, DSMAP[x][z] - DSMAP[x][z+1], 1);

			glNormal3f((get<1>(V1) * get<2>(V2)) - (get<2>(V1) * get<1>(V2)),
			(get<2>(V1) * get<0>(V2)) - (get<0>(V1) * get<2>(V2)),
			(get<0>(V1) * get<2>(V2)) - (get<2>(V1) * get<0>(V2)));
			glBegin(GL_POLYGON);
				glVertex3f(x/20, DSMAP[x][z], z/20);
  				glVertex3f((x+1)/20, DSMAP[x+1][z], z/20);
				glVertex3f(x/20, DSMAP[x][z+1], (z+1)/20);
			glEnd();

			V1 = make_tuple(0, DSMAP[x+1][z+1] - DSMAP[x][z+1], 1);
			V2 = make_tuple(1, DSMAP[x+1][z+1] - DSMAP[x+1][z], 1);

			glNormal3f((get<1>(V1) * get<2>(V2)) - (get<2>(V1) * get<1>(V2)),
			(get<2>(V1) * get<0>(V2)) - (get<0>(V1) * get<2>(V2)),
			(get<0>(V1) * get<2>(V2)) - (get<2>(V1) * get<0>(V2)));
			glBegin(GL_POLYGON);
				glVertex3f((x+1)/20, DSMAP[x+1][z+1], (z+1)/20);
  				glVertex3f(x/20, DSMAP[x][z+1], (z+1)/20);
				glVertex3f((x+1)/20, DSMAP[x+1][z], z/20);
			glEnd();

			/*
			if (((x - 1) >= 0)){
				glVertex3f(x/10, DSMAP[x][z], z/10);
  				glVertex3f((x-1)/10, DSMAP[x][z], z/10);
			}
			if (((z - 1) >= 0)){
				glVertex3f(x/10, DSMAP[x][z], z/10);
  				glVertex3f(x/10, DSMAP[x][z], (z-1)/10);
			}
			if (((x+1) < 17)){
				glVertex3f(x/10, DSMAP[x][z], z/10);
  				glVertex3f((x+1)/10, DSMAP[x][z], z/10);
				
			}
			if (((z + 1) < 17)){
				glVertex3f(x/10, DSMAP[x][z], z/10);
  				glVertex3f(x/10, DSMAP[x][z], (z+1)/10);
			}*/
			

			
		}
	
	}

	
}

// called every time the widget is resized
void FractalTerrain::resizeGL(int w, int h)
	{
	// set the viewport
	glViewport(0, 0, 2, h);

	glEnable(GL_LIGHTING); // enable lighting
  	glEnable(GL_LIGHT0);   //enable light 1

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

  	glOrtho(-4.0, 4.0, -4.0, 4.0, -4.0, 4.0);
	//glFrustum(-1.0,1.0, -1.0, 1.0, 1.5, 10.0);

	}

// paints the widget
void FractalTerrain::paintGL(){
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	//glViewport(0, 0, 1000, 1000);
	glShadeModel(GL_SMOOTH);


	glMatrixMode(GL_MODELVIEW);
	glEnable(GL_DEPTH_TEST);

	glLoadIdentity();
		GLfloat light_pos[] = {3, 0, 3, 0};
		glLightfv(GL_LIGHT0, GL_POSITION, light_pos);
  		glLightf (GL_LIGHT0, GL_SPOT_CUTOFF,100.);
    glPopMatrix();
	glLoadIdentity();
	//glScalef(0.5f, 0.5f, 0.5f);
	//DrawTerrain(mastersize);
	glRotatef(angle, 0, 1, 0);
	//glTranslatef(-8, 0, -8);
	glutSolidCube(1);
	//DrawTerrain(mastersize);
	glPopMatrix();

	glLoadIdentity();
       	gluLookAt(3.,5.,3., 0,0.0,0, 0.0,1.0,0.0);

	glFlush();

	}
