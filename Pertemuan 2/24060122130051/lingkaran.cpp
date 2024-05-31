//Nama/NIM: Miriam Stefani Abigail Hutapea/ 24060122130051
//Hari, tanggal: Minggu,3 Maret 2024
//Nama file: lingkaran.cpp
//Deskripsi file: membuat sebuah lingkaran


#include <gl/glut.h>
#include <gl/gl.h>
#include <math.h>

void lingkaran(void){
	glClear(GL_COLOR_BUFFER_BIT);
	glPushMatrix();
		#define PI 3.1415926535898
		glBegin(GL_POLYGON);
			GLint circle_points = 100;
			int i;
			float angle;
			glColor3f(0.0f, 0.212f,0.369f);
			for(i=0;i<circle_points; i++) {
				angle = 2*PI*i/circle_points;
				glLineWidth(4.0f);
				glVertex2f(cos(angle), sin(angle));
			}
			
		glEnd();
	glPopMatrix();
	glFlush();
}

int main (int argc, char* argv[]){
	glutInit(&argc,argv);
	glutInitWindowSize(500,500);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
	glutCreateWindow("lingkaran");
	glutDisplayFunc(lingkaran);
	glClearColor(0.596f,0.851f,1.0f,1.0f);
	glOrtho(-5, 5, -5, 5, -4, 5);
	glutMainLoop();
	
	return 0; 
}
