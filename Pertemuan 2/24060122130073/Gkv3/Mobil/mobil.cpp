#include <GL/glut.h>
#include <math.h>
#include <stdlib.h>>


void mobil(){
	
	// Badan Mobil
    glColor3f(0.3f, 0.3f, 0.3f); // Warna abu-abu
    glBegin(GL_QUADS);
    glVertex2f(-0.7f, -0.2f);
    glVertex2f(0.6f, -0.2f);
    glVertex2f(0.6f, 0.0f);
    glVertex2f(-0.7f, 0.0f);
    
    //Badan atas
    glColor3f(0.3f, 0.3f, 0.8f);
    glBegin(GL_QUADS);
    glVertex2f(-0.1f, 0.2f);
    glVertex2f(0.2f, 0.2f);
    glVertex2f(0.5f, 0.0f);
    glVertex2f(-0.4f, 0.0f);
    glEnd();
    
	// Roda 1
    glColor3f(0.0f, 0.0f, 0.0f); // Warna hitam
    glBegin(GL_POLYGON);
    for (int i = 0; i < 360; i++) {
        float theta = i * 3.14159 / 180;
        float x = 0.15 * cos(theta) - 0.4;
        float y = 0.15* sin(theta) - 0.2;
        glVertex2f(x, y);
    	}
    glEnd();
    glColor3f(0.3f, 0.3f, 0.4f); // Warna abu abu
    glBegin(GL_POLYGON);
    for (int i = 0; i < 360; i++) {
        float theta = i * 3.14159 / 180;
        float x = 0.1 * cos(theta) - 0.4;
        float y = 0.1* sin(theta) - 0.2;
        glVertex2f(x, y);
    }
    glEnd();

    // Roda 2
    glColor3f(0.0f, 0.0f, 0.0f);// Warna hitam
    glBegin(GL_POLYGON);
    for (int i = 0; i < 360; i++) {
        float theta = i * 3.14159 / 180;
        float x = 0.15 * cos(theta) + 0.3;
        float y = 0.15 * sin(theta) - 0.2;
        glVertex2f(x, y);
    }
    glEnd();
    glColor3f(0.3f, 0.3f, 0.4f); // Warna abu abu
    glBegin(GL_POLYGON);
    for (int i = 0; i < 360; i++) {
        float theta = i * 3.14159 / 180;
        float x = 0.1 * cos(theta) + 0.3;
        float y = 0.1* sin(theta) - 0.2;
        glVertex2f(x, y);
    }
    glEnd();
    
    
    

}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();
    mobil();
    glFlush();
}
    
int main(int argc, char* argv[])
{
	glutInit(&argc, argv);
	glutInitWindowSize(640,640);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
	glutCreateWindow("mobil");
	glutDisplayFunc(display);
	gluOrtho2D(-200,200,-200,200);
	glClearColor(1.0f,1.0f,1.0f,1.0f);
	glutMainLoop();
	return 0;
}
