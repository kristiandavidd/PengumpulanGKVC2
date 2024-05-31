//NAMA: REVA YASMIN NAUFALIA
//NIM: 24060122130075


#include <GL/glut.h>

#include <stdlib.h>

void TesFungsi(void){
	glClear(GL_COLOR_BUFFER_BIT);
	glLineWidth(2.0f);
	//MERAH
	glBegin(GL_LINES);
	glColor3f(0.7f,0.0f,0.0f);
	glVertex3f(0.0,-0.1,0.1);
	glVertex3f(-0.2,0.3,-0.2);
	//glEnd();
	
	glBegin(GL_LINES);
	glColor3f(0.7f,0.0f,0.0f);
	glVertex3f(0.0,0.1,-0.1);
	glVertex3f(0.2,-0.3,0.2);
	//glEnd();
	//Membuat garis yg akan terhubung dgn garis pertama
	//BIRU
	glBegin(GL_LINE_STRIP);
	glColor3f(0.0f,0.0f,1.0f);
	glVertex3f(-0.2,0.3,-0.2);
	glVertex3f(-0.2,-0.6,0.1);
	//glEnd();
	glBegin(GL_LINES);
	glColor3f(0.7f,0.0f,0.0f);
	glVertex3f(0.0,0.1,-0.1);
	glVertex3f(0.2,-0.3,0.2);
	
	//hIJAU
	glBegin(GL_LINE_LOOP);
	glColor3f(0.0f,0.4f,0.0f);
	glVertex3f(-0.4,-0.20,0.1);
	glVertex3f(-0.6,-0.4,0.1);
	
	glBegin(GL_TRIANGLE_FAN);
	glEnd();
	
	glBegin(GL_TRIANGLE_STRIP);
	glColor3f(0.0f,0.4f,0.0f);
	glVertex3f(-0.4,-0.20,0.1);
	glVertex3f(-0.6,-0.4,0.1);
	glEnd();
	
	glBegin(GL_QUADS);
	glColor3f(0.6f,0.0f,0.5f);
	glVertex2f(0.5,0.5);
	glVertex2f(0.5,0.1);
	glVertex2f(0.3, 0.1);	
	glVertex2f(0.3, 0.5);
	glEnd();	
	
	glBegin(GL_QUAD_STRIP);
	glColor3f(0.6f,0.0f,0.5f);
	glVertex2f(0.7,0.5);
	glVertex2f(0.7,0.1);
	glVertex2f(0.9, 0.1);	
	glVertex2f(0.8, 0.0);
	glEnd();
	glBegin(GL_QUAD_STRIP);
	glColor3f(0.6f,0.0f,0.5f);
	glVertex2f(0.5,0.7);
	glVertex2f(0.1,0.7);
	glVertex2f(0.1, 0.9);	
	glVertex2f(0.0, 0.8);
	
	
	glEnd();
	glFlush();
}
int main(int argc, char*argv[]) {
	glutInit(&argc, argv);
	glutInitWindowSize(640,480);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
	glutCreateWindow("Membuat Garis");
	glutDisplayFunc(TesFungsi);
	//glutDisplayFunc(Segitiga1);
	glClearColor(1.0f,1.0f,1.0f,1.0f);
	glutMainLoop();
	//return 0;
	
}
