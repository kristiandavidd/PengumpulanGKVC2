//Nabila Betari Anjani
//24060122140169 GKV C2
//Tugas Praktikum 2

#include <GL/glut.h>
#include <gl/glut.h>
#include <stdlib.h>
#include<math.h>

void circle(GLfloat rx, GLfloat ry, GLfloat cx, GLfloat cy){
	glBegin(GL_POLYGON);
	glVertex2f(cx, cy);
	for (int i=0; i<=360; i++){
		float angle = i * 3.1416 / 180;
		float x = rx * cos(angle);
		float y = ry * sin(angle);
		glVertex2f((x + cx), (y + cy));
	}
	glEnd();
}

void init(void){
	glClearColor(1.0, 1.0, 1.0, 1.0);
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(0, 400, 0, 400);
}


void Mobilku(void){
	glClear(GL_COLOR_BUFFER_BIT);
	
	//body mobil
	glColor3f(1.0f, 0.71f, 0.76f);
	glBegin(GL_POLYGON);
	glVertex2d(70,120);
	glVertex2d(350,120);
	glVertex2d(350,200);
	glVertex2d(320,200);
	glVertex2d(270,250);
	glVertex2d(150,250);
	glVertex2d(100,200);
	glVertex2d(70,200);
	glVertex2d(70,120);
	glEnd();
	
	//kaca mobil
	glColor3f(0.75f, 0.75f, 0.75f);
	glBegin(GL_POLYGON);
	glVertex2d(120,200);
	glVertex2d(310,200);
	glVertex2d(270,240);
	glVertex2d(150,240);
	glEnd();
	
	//roda mobil
	glColor3f(0.0f, 0.0f, 0.0f);
	circle(25, 30, 270, 120);
	circle(25, 30, 150, 120);
	
	
	glColor3ub(192, 192, 192);
	circle(20, 25, 270, 120);
	circle(20, 25, 150, 120);
	
	
	glFlush();
	glutSwapBuffers();
}


int main(int argc, char *argv[]){
	glutInit(&argc, argv);
	glutInitWindowSize(640, 480);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutCreateWindow("Mobilku");
	glutDisplayFunc(Mobilku);
	init();
	glutMainLoop();
	return 0;
}
