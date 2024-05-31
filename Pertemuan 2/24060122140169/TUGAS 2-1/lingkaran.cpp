#include <GL/glut.h>
#include <stdlib.h>
#include <math.h>

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

void init(void) {
    glClearColor(1.0, 1.0, 1.0, 1.0);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0, 400, 0, 400);
}

void lingkaran(void){
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0.0f, 0.0f, 0.0f);
	circle(50, 60, 200, 200);
	glFlush();
}

int main(int argc, char *argv[]){
	glutInit(&argc, argv);
	glutInitWindowSize(640, 480);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutCreateWindow("Lingkaran");
	glutDisplayFunc(lingkaran);
	init();
	glutMainLoop();
	return 0;
}

