/*
 * FreeGLUT Shapes Demo
 *
 * Written by Nigel Stewart November 2003
 *
 * This program is test harness for the sphere, cone 
 * and torus shapes in FreeGLUT.
 *
 * Spinning wireframe and smooth shaded shapes are
 * displayed until the ESC or q key is pressed.  The
 * number of geometry stacks and slices can be adjusted
 * using the + and - keys.
 */

#include <GL/glut.h>
#include <math.h>

#include <stdlib.h>

void bunder(){
	glColor3f(0.0f, 0.0f, 0.0f);// Warna hitam
    glBegin(GL_POLYGON);
    for (int i = 0; i < 360; i++) {
        float theta = i * 3.14159 / 180;
        float x = 1.0 * cos(theta)  -0.0;
        float y = 1.0 * sin(theta)  -0.0;
        glVertex2f(x, y);
    }
    glEnd();
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();
    bunder();
    glFlush();
}


int main(int argc, char* argv[])
{
	glutInit(&argc, argv);
	glutInitWindowSize(640,640);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
	glutCreateWindow("Bunder");
	glutDisplayFunc(display);
	gluOrtho2D(-200,200,-200,200);
	glClearColor(1.0f,1.0f,1.0f,1.0f);
	glutMainLoop();
	return 0;
}
