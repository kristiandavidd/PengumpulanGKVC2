#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <GL/glut.h>

double rotAngle=10;
double rotAngle1=10;

void init(){
	glClearColor(0.408f,0.671f,0.973f,0.0f);
	glClearDepth(1.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(60,1,1,1000);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(
		0.0,0.0,5.0,
		0.0,0.0,0.0,
		0.0,1.0,0.0);
}

void drawCar(){
	//badan mobil
	glColor3f(0.122f,0.184f,0.251f);
	glPushMatrix();
	glTranslatef(0.0f,0.1f,0.0f);
	glScalef(3.5,1.1,1.5);
	glutSolidCube(1);
	glTranslatef(-0.12f,1.0f,0.0f);
	glScalef(1.5,2,2);
	glutSolidCube(0.5);
	glPopMatrix();
	
	//roda
	glColor3f(1.0f,0.961f,0.851f);
	glPushMatrix();
	glTranslatef(-0.95,-0.6,-0.75);
	glutSolidTorus(0.2,0.4,16,16);
	glPopMatrix();
	
	glPushMatrix();
    glTranslatef(-0.95, -0.6, 0.75);
    glutSolidTorus(0.2, 0.4, 16, 16); 
    glPopMatrix();
    
    glPushMatrix();
	glTranslatef(0.9,-0.6,-0.75);
	glutSolidTorus(0.2,0.4,16,16);
	glPopMatrix();
	
	glPushMatrix();
    glTranslatef(0.95, -0.6, 0.75);
    glutSolidTorus(0.2, 0.4, 16, 16); 
    glPopMatrix();
    
    //jendela atau ruang dalam mobil
    glColor3f(0.6, 0.6, 1.0); 
    glPushMatrix();
	glTranslatef(-0.4f,1.2f,0.0f);
	glScalef(5,1.8,2.5);
	glutSolidCube(0.5); 
    glPopMatrix();
    
    //lampu
    glColor3f(1.0, 1.0, 0.0); 
    glPushMatrix();
    glTranslatef(1.7, 0.4, 0.6);
    glutSolidSphere(0.15, 20, 20); 
    glPopMatrix();
    glPushMatrix();
    glTranslatef(1.7, 0.4, -0.6);
    glutSolidSphere(0.15, 20, 20); 
    glPopMatrix();
    
    
    
}

void setupLighting() {
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);

    GLfloat light_position[] = { 5.0, 5.0, 5.0, 1.0 };
    GLfloat light_ambient[] = { 0.2, 0.2, 0.2, 1.0 };
    GLfloat light_diffuse[] = { 1.0, 1.0, 1.0, 1.0 };

    glLightfv(GL_LIGHT0, GL_POSITION, light_position);
    glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);
}

void display(){
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	glPushMatrix();
	glRotated(rotAngle,0,1,0);
	glRotated(rotAngle1,1,0,0);
	glEnable(GL_COLOR_MATERIAL);
	setupLighting();
	drawCar();
	glPopMatrix();
	glFlush();
	glutSwapBuffers();
}

void reshape(int w, int h){
	glViewport(0,0,w,h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45,(double)w/(double)h,1,50);
	glMatrixMode(GL_MODELVIEW);
}

void keyboard(unsigned char k, int x, int y){
	switch(k)
	{
		case 'a':
			rotAngle +=5;
			break;
		case 'y':
			rotAngle1 +=5; break;
		case 'b':
			rotAngle1 -= 5; break;
		case 'l':
			rotAngle-=5; break;
		case 'q':
			exit(0);
	}
	glutPostRedisplay();
}

int main(){
	glutInitDisplayMode(GLUT_DOUBLE|GLUT_DEPTH|GLUT_RGB);
	glutCreateWindow("Mobil 3D");
	glutInitWindowSize(1000,1000);
	glutDisplayFunc(display);
	glutKeyboardFunc(keyboard);
	glutReshapeFunc(reshape);
	init();
	glutMainLoop();
	return 0;
}
