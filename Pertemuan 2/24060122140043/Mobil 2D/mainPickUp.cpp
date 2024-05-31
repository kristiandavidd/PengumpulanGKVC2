#include <GL/glut.h>
#include <math.h>

void drawMobil() {
	#define PI 3.145926535898
	
	glClear(GL_COLOR_BUFFER_BIT);
	
    // Badan mobil
    glPushMatrix();
	    glColor4f(0.7, 0.0, 0.0, 0.9);
	    glBegin(GL_POLYGON);
	    glVertex2f(-0.2, 0.0);
	    glVertex2f(-0.2, 0.2);
	    glVertex2f(-0.5, 0.2);
	    glVertex2f(-0.7, 0.0);
	    glVertex2f(-0.7, -0.2);
	    glVertex2f(0.5, -0.2);
	    glVertex2f(0.5, 0.0);
	    glEnd();
    glPopMatrix();
    
    // Roda Luar Depan
    glPushMatrix();
	    glColor4f(0.0, 0.0, 0.0, 0.0);
	    glTranslatef(-0.45, -0.2, 0);
	    
		GLfloat radiusLuar = 0.15;
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
    glPopMatrix();
    
    // Roda Luar Belakang
    glPushMatrix();
	    glColor4f(0.0, 0.0, 0.0, 0.0);
	    glTranslatef(0.30, -0.2, 0);
		
	    glBegin(GL_POLYGON);
		    for (i = 0; i < circle_points; i++){
		    	angle = 2*PI*i/circle_points;
		    	GLfloat x = radiusLuar * cos(angle);
		    	GLfloat y = radiusLuar * sin(angle);
		    	glVertex2f(x,y);
		    }
	    glEnd();
    glPopMatrix();

    // Roda Dalam Depan
    glPushMatrix();
	    glColor4f(1.0, 1.0, 1.0, 1.0);
	    glTranslatef(-0.45, -0.2, 0);
	    
		GLfloat radiusDalam = 0.065;
		
	    glBegin(GL_POLYGON);
		    for (i = 0; i < circle_points; i++){
		    	angle = 2*PI*i/circle_points;
		    	GLfloat x = radiusDalam * cos(angle);
		    	GLfloat y = radiusDalam * sin(angle);
		    	glVertex2f(x,y);
		    }
	    glEnd();
    glPopMatrix();

    // Roda Dalam Belakang
    glPushMatrix();
	    glColor4f(1.0, 1.0, 1.0, 1.0);
	    glTranslatef(0.30, -0.2, 0);
	    
	    glBegin(GL_POLYGON);
		    for (i = 0; i < circle_points; i++){
		    	angle = 2*PI*i/circle_points;
		    	GLfloat x = radiusDalam * cos(angle);
		    	GLfloat y = radiusDalam * sin(angle);
		    	glVertex2f(x,y);
		    }
	    glEnd();
    glPopMatrix();
    
    // Frame besi belakang
    glPushMatrix();
    	glLineWidth(5.0);
    	glColor4f(0.5, 0.5, 0.5, 1.0);
    	glTranslatef(0.15, 0, 0);
    	glBegin(GL_LINES);
    		glVertex2f(-0.35, 0.0);
    		glVertex2f(0.35, 0.0);
    	glEnd();
    glPopMatrix();
    
    glPushMatrix();
    	glLineWidth(4.0);
    	glColor4f(0.5, 0.5, 0.5, 1.0);
    	glTranslatef(-0.2, 0.2, 0);
    	glRotatef(90, 0.0, 0.0, 1.0);
    	glBegin(GL_LINES);
    		glVertex2f(-0.1, 0.0);
    		glVertex2f(0.1, 0.0);
    	glEnd();
    glPopMatrix();
    
    
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
    glutCreateWindow("Mobil Pickup");
    glutDisplayFunc(drawMobil);
    glClearColor(0.0f, 1.0f, 0.0f, 1.0f);
    glutMainLoop();
    return 0;
}

