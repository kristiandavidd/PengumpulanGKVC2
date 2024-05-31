#include <GL/glut.h>
#include <math.h>

void drawLingkaran() {
	#define PI 3.145926535898
	glClear(GL_COLOR_BUFFER_BIT);
	
    glColor4f(0.0, 0.0, 0.0, 1.0);
	    
	GLfloat radiusLuar = 0.5;
	GLint circle_points = 100;
	GLfloat angle;
	int i;
		
	glBegin(GL_POLYGON);
		for (i = 0; i < circle_points; i++){
		   	angle = 2*PI*i/circle_points;
		   	GLfloat x = radiusLuar * cos(angle);
		   	GLfloat y = radiusLuar * sin(angle);
		    glVertex2f(x,y);
	    }
	glEnd();
    
    glFlush();
}

void init() {
    glClearColor(1, 1, 1, 1);
    gluOrtho2D(-1, 1, -1, 1);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitWindowSize(480, 480);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
    glutCreateWindow("Lingkaran");
    glutDisplayFunc(drawLingkaran);
    glClearColor(1.0f, 0.0f, 0.0f, 1.0f);
    glutMainLoop();
    return 0;
}

