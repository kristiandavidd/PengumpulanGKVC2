//NAMA: REVA YASMIN NAUFALIA
//NIM: 24060122130075
// TUGAS PRAKTIKUM 1 SOAL 3 GKV
//TANGGAL: 26 FEB 2024
#include <GL/glut.h>

#include <stdlib.h>


void KubusStack2(void){
	glClear(GL_COLOR_BUFFER_BIT);
	glLineWidth(1.0f);
	
	//X
	glBegin(GL_QUADS);
	glColor3f(0.0f,0.5f,0.2f);
	glVertex2f(-0.95,0.85);
	glVertex2f(-0.85,0.85);
	glVertex2f(-0.45, 0.25);
	glVertex2f(-0.55, 0.25);	
	glEnd();
	glBegin(GL_QUADS);
	glColor3f(0.0f,0.5f,0.2f);
	glVertex2f(-0.95,0.25);
	glVertex2f(-0.85,0.25);
	glVertex2f(-0.45, 0.85);
	glVertex2f(-0.55, 0.85);	
	glEnd();
	
	//+
	glBegin(GL_QUADS);
	glColor3f(0.4f,0.0f,0.6f);
	glVertex2f(-0.30,0.55);
	glVertex2f(-0.30,0.60);
	glVertex2f(-0.05, 0.60);	
	glVertex2f(-0.05, 0.55);
	glEnd();
	glBegin(GL_QUADS);
	glColor3f(0.4f,0.0f,0.6f);
	glVertex2f(-0.20,0.70);
	glVertex2f(-0.15,0.70);
	glVertex2f(-0.15, 0.45);	
	glVertex2f(-0.20, 0.45);
	glEnd();
	
	//Y
	glBegin(GL_QUADS);
	glColor3f(0.9f,0.2f,0.0f);
	glVertex2f(0.05,0.85);
	glVertex2f(0.15,0.85);
	glVertex2f(0.35, 0.55);
	glVertex2f(0.25, 0.55);	
	glEnd();
	glBegin(GL_QUADS);
	glColor3f(0.9f,0.2f,0.0f);
	glVertex2f(0.45,0.85);
	glVertex2f(0.55,0.85);
	glVertex2f(0.35, 0.55);
	glVertex2f(0.25, 0.55);	
	glEnd();
	glBegin(GL_QUADS);
	glColor3f(0.9f,0.2f,0.0f);
	glVertex2f(0.35, 0.55);
	glVertex2f(0.25, 0.55);	
	glVertex2f(0.25,0.25);
	glVertex2f(0.35,0.25);
	glEnd();
	
	//=
	glBegin(GL_QUADS);
	glColor3f(0.2f,0.3f,0.6f);
	glVertex2f(0.65,0.65);
	glVertex2f(0.65,0.70);
	glVertex2f(0.95, 0.70);	
	glVertex2f(0.95, 0.65);
	glEnd();
	glBegin(GL_QUADS);
	glColor3f(0.2f,0.3f,0.6f);
	glVertex2f(0.65,0.45);
	glVertex2f(0.65,0.50);
	glVertex2f(0.95, 0.50);	
	glVertex2f(0.95, 0.45);
	glEnd();
	
	glBegin(GL_QUADS);
	glColor3f(0.2f,0.3f,0.6f);
	glVertex2f(0.65,0.45);
	glVertex2f(0.65,0.50);
	glVertex2f(0.95, 0.50);	
	glVertex2f(0.95, 0.45);
	glEnd();
	
	//3
	glBegin(GL_QUADS);
	glColor3f(0.5f,0.5f,0.0f);
	glVertex2f(-0.92,-0.15);
	glVertex2f(-0.92,-0.25);
	glVertex2f(-0.55, -0.25);
	glVertex2f(-0.55, -0.15);	
	glEnd();
	glBegin(GL_QUADS);
	glColor3f(0.5f,0.5f,0.0f);
	glVertex2f(-0.55, -0.25);
	glVertex2f(-0.55, -0.15);	
	glVertex2f(-0.8, -0.35);
	glVertex2f(-0.8, -0.45);
	glEnd();
	glBegin(GL_QUADS);
	glColor3f(0.5f,0.5f,0.0f);	
	glVertex2f(-0.8, -0.35);
	glVertex2f(-0.8, -0.45);
	glVertex2f(-0.55, -0.55);
	glVertex2f(-0.55, -0.45);
	glEnd();
	glBegin(GL_QUADS);
	glColor3f(0.5f,0.5f,0.0f);	
	glVertex2f(-0.55, -0.55);
	glVertex2f(-0.58, -0.45);
	glVertex2f(-0.7, -0.65);
	glVertex2f(-0.7, -0.75);
	glEnd();
	glBegin(GL_QUADS);
	glColor3f(0.5f,0.5f,0.0f);	
	glVertex2f(-0.7, -0.65);
	glVertex2f(-0.7, -0.75);
	glVertex2f(-0.92, -0.75);
	glVertex2f(-0.92, -0.65);
	glEnd();
	
	//7
	glBegin(GL_QUADS);
	glColor3f(0.5f,0.5f,0.0f);	
	glVertex2f(-0.25, -0.25);
	glVertex2f(-0.25, -0.15);
	glVertex2f(0.15, -0.15);
	glVertex2f(0.15, -0.25);
	glEnd();
	glBegin(GL_QUADS);
	glColor3f(0.5f,0.5f,0.0f);	
	glVertex2f(0.05, -0.25);
	glVertex2f(0.15, -0.25);
	glVertex2f(-0.15, -0.75);
	glVertex2f(-0.25, -0.75);
	glEnd();
	
	//5
	glBegin(GL_QUADS);
	glColor3f(0.5f,0.5f,0.0f);	
	glVertex2f(0.55, -0.25);
	glVertex2f(0.55, -0.15);
	glVertex2f(0.92, -0.15);
	glVertex2f(0.92, -0.25);
	glEnd();
	glBegin(GL_QUADS);
	glColor3f(0.5f,0.5f,0.0f);	
	glVertex2f(0.55, -0.25);
	glVertex2f(0.65, -0.25);
	glVertex2f(0.65, -0.45);
	glVertex2f(0.55, -0.45);
	glEnd();
	glBegin(GL_QUADS);
	glColor3f(0.5f,0.5f,0.0f);	
	glVertex2f(0.55, -0.35);
	glVertex2f(0.55, -0.45);
	glVertex2f(0.8, -0.45);
	glVertex2f(0.8, -0.35);
	glEnd();
	glBegin(GL_QUADS);
	glColor3f(0.5f,0.5f,0.0f);	
	glVertex2f(0.8, -0.45);
	glVertex2f(0.8, -0.35);
	glVertex2f(0.92, -0.5);
	glVertex2f(0.92, -0.6);
	glEnd();
	glBegin(GL_QUADS);
	glColor3f(0.5f,0.5f,0.0f);	
	glVertex2f(0.92, -0.5);
	glVertex2f(0.92, -0.6);
	glVertex2f(0.75, -0.75);
	glVertex2f(0.75, -0.65);
	glEnd();
	glBegin(GL_QUADS);
	glColor3f(0.5f,0.5f,0.0f);	
	glVertex2f(0.75, -0.75);
	glVertex2f(0.75, -0.65);
	glVertex2f(0.55, -0.65);
	glVertex2f(0.55, -0.75);
	glEnd();
	
	glFlush();
} 

int main(int argc, char*argv[]) {
	glutInit(&argc, argv);
	glutInitWindowSize(720,600);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
	glutCreateWindow("Stack Kotak");
	glutDisplayFunc(KubusStack2);
	glClearColor(1.0f,1.0f,1.0f,1.0f);
	glutMainLoop();
	//return 0;
}
