// Azzam Saefudin Rosyidi
// 24060122130076

#include <gl/glut.h>
#include <gl/gl.h>
#include <math.h>

void Mobil(void) {
	glClear(GL_COLOR_BUFFER_BIT);

//	Langit
	glPushMatrix();
		glTranslatef(0.00,0.00,0.00);
	    glColor3f(0.529f, 0.808f, 0.922f);
	    glBegin(GL_QUADS);
	    glVertex3f(-1.0, 0.5, 0.0); 
 	   	glVertex3f(1.0, 0.5, 0.0); 
    	glVertex3f(1.0, 1.0, 0.0); 
    	glVertex3f(-1.0, 1.0, 0.0);
		glEnd(); 
	glPopMatrix();

//	Matahari
	glPushMatrix();
    	glTranslatef(0.65,0.75,0.0);
    	glColor3f(1.0f, 1.0f, 0.0f); 
		#define PI 3.1415926535898
		glBegin(GL_POLYGON);
			GLint cp = 360;
			int k;
			float g;
			for (k = 0; k < cp; k++){
				g = 2*PI*k/cp;
				glVertex2f(cos(g)/8, sin(g)/8);
			}
		glEnd();
	glPopMatrix();
	
	glPushMatrix();
//	jalan
		glTranslatef(0.00,0.00,0.00);
	    glColor3f(0.2f, 0.2f, 0.2f); 
	    glBegin(GL_QUADS);
	    glVertex3f(-1.0, -0.5, 0.0); 
 	   	glVertex3f(-1.0, -0.2, 0.0); 
    	glVertex3f(1.0, -0.2, 0.0); 
    	glVertex3f(1.0, -0.5, 0.0);
		glEnd(); 
//   garis tengah jalan
    	glColor3f(1.0f, 1.0f, 1.0f); 
	    glBegin(GL_LINES);
	    glVertex3f(-1.0, -0.35, 0.0); 
	    glVertex3f(1.0, -0.35, 0.0); 
    	glEnd();	
	glPopMatrix();
//	tembok
	glPushMatrix();
		glTranslatef(0.00,0.00,0.00);
	    glColor3f(0.8f, 0.8f, 0.8f); 
	    glBegin(GL_QUADS);
	    glVertex3f(-1.0, -0.2, 0.0); 
 	   	glVertex3f(-1.0, 0.5, 0.0); 
    	glVertex3f(1.0, 0.5, 0.0); 
    	glVertex3f(1.0, -0.2, 0.0);
		glEnd(); 
		glColor3f(0.4f, 0.4f, 0.4f); 
		glBegin(GL_QUADS);
	    glVertex3f(-1.0, 0.35, 0.0); 
 	   	glVertex3f(-1.0, 0.5, 0.0); 
    	glVertex3f(1.0, 0.5, 0.0); 
    	glVertex3f(1.0, 0.35, 0.0);
		glEnd(); 
	glPopMatrix();
	
//	mobil
	glPushMatrix();
		glTranslatef(0.00,0.00,0.00);
		glBegin(GL_TRIANGLE_FAN);
			glColor3f(0.5f, 0.0f, 0.0f);
			glVertex3f(-0.7, -0.3, 0.00);
			glColor3f(0.5f, 0.0f, 0.0f); 
			glVertex3f(0.6, -0.3, 0.00);
			glColor3f(0.8f, 0.0f, 0.0f); 
			glVertex3f(0.5, -0.1, 0.00);
			glColor3f(0.6f, 0.0f, 0.0f);
			glVertex3f(-0.6, -0.1, 0.00);
			glColor3f(0.5f, 0.0f, 0.0f);
			glVertex3f(-0.7, -0.3, 0.00);
		glEnd();
	glPopMatrix();
	glPushMatrix();
		glTranslatef(0.00,0.00,0.00);
		glBegin(GL_TRIANGLE_FAN);
			glColor3f(0.5f, 0.0f, 0.0f);
			glVertex3f(0.3, -0.1, 0.00);
			glColor3f(0.5f, 0.0f, 0.0f);
			glVertex3f(0.2, 0.1, 0.00);
			glColor3f(0.5f, 0.0f, 0.0f);
			glVertex3f(-0.1, 0.1, 0.00);
			glColor3f(1.0f, 0.0f, 0.0f);
			glVertex3f(-0.3, -0.1, 0.00);
		glEnd();
	glPopMatrix();
	
//	Ban
	glPushMatrix();
		glTranslatef(-0.35,-0.3,0.0);
		#define PI 3.1415926535898
		glBegin(GL_POLYGON);
			glColor3f(0.0f,0.0f,0.0f);
			GLint circle_points = 360;
			int i;
			float angle;
			for (i = 0; i < circle_points; i++){
				angle = 2*PI*i/circle_points;
				glVertex2f(cos(angle)/12, sin(angle)/12);
			}
		glEnd();
		
		glTranslatef(0.6,0.0,0.0);
		#define PI 3.1415926535898
		glBegin(GL_POLYGON);
			glColor3f(0.0f,0.0f,0.0f);
			GLint circlepoints = 360;
			int a;
			float ang;
			for(a=0;a<circlepoints; a++) {
				ang = 2*PI*a/circlepoints;
				glVertex2f(cos(ang)/12, sin(ang)/12);
			}
		glEnd();
	glPopMatrix();

//	Kaca
	glPushMatrix();
		glTranslatef(0.00,0.00,0.00);
		glColor3f(1.0f, 1.0f, 1.0f);
		glBegin(GL_QUADS);
		glVertex3f(-0.25,-0.1,0.00);
		glVertex3f(0.02,-0.1,0.00);
		glVertex3f(0.02,0.05,0.00);
		glVertex3f(-0.1,0.05,0.00);
		glEnd();
	glPopMatrix();
	
	glPushMatrix();
		glTranslatef(0.00,0.00,0.00);
		glColor3f(1.0f, 1.0f, 1.0f);
		glBegin(GL_QUADS);
		glVertex3f(0.05,-0.1,0.00);
		glVertex3f(0.265,-0.1,0.00);
		glVertex3f(0.188,0.05,0.00);
		glVertex3f(0.05,0.05,0.00);
		glEnd();
	glPopMatrix();

//	lampu	
	glPushMatrix();
		glTranslatef(-0.005,0.00,0.00);
		glColor3f(1.0f, 1.0f, 0.0f); 
		glBegin(GL_TRIANGLES);
		glVertex3f(-0.62, -0.15, 0.0);
		glVertex3f(-0.62, -0.25, 0.0);
		glVertex3f(-0.67, -0.25, 0.0);
	    glEnd();
	    
	    glTranslatef(0.0099,0.00,0.00);
		glBegin(GL_TRIANGLES);
		glVertex3f(0.52, -0.15, 0.0);
		glVertex3f(0.52, -0.25, 0.0);
		glVertex3f(0.57, -0.25, 0.0);
	    glEnd();
	glPopMatrix();
	
//	rear spoiler
	glPushMatrix();
		glTranslatef(0.0,0.0,0.0);
		glColor3f(0.0,0.0,0.0);
		glBegin(GL_TRIANGLE_FAN);
		glVertex3f(0.4, -0.1, 0.0);
		glVertex3f(0.45, 0.0, 0.0);
		glVertex3f(0.5, 0.0, 0.0);
		glVertex3f(0.45, -0.1, 0.0);
		glEnd();
		
		glTranslatef(0.0,0.0,0.0);
		glColor3f(0.0,0.0,0.0);
		glBegin(GL_TRIANGLE_FAN);
		glVertex3f(0.4, 0.0, 0.0);
		glVertex3f(0.4, 0.05, 0.0);
		glVertex3f(0.55, 0.05, 0.0);
		glVertex3f(0.55, 0.0, 0.0);
		glEnd();
	glPopMatrix();

//	angka
	glPushMatrix();
		glTranslatef(0.0,-0.01,0.0);
		glColor3f(1.0f, 0.7f, 0.0f);
		glBegin(GL_QUADS);
    	glVertex2f(-0.14, -0.12);
    	glVertex2f(-0.05, -0.12);
    	glVertex2f(-0.05, -0.2);
    	glVertex2f(-0.14, -0.2);
    	glEnd();
    	
		glBegin(GL_QUADS);
    	glVertex2f(-0.05, -0.2);
    	glVertex2f(-0.08, -0.2);
    	glVertex2f(-0.08, -0.24);
    	glVertex2f(-0.05, -0.24);
    	glEnd();
    	
		glBegin(GL_QUADS);
		glVertex2f(-0.14, -0.24);
    	glVertex2f(-0.14, -0.27);
    	glVertex2f(-0.05, -0.27);
    	glVertex2f(-0.05, -0.24);
    	glEnd();
	glPopMatrix();
	glPushMatrix();
		glTranslatef(-0.07,-0.4,0.0);
//		rotasi
		glRotated(180, 0.0, 0.0, 1.0);
		
		glColor3f(1.0f, 0.7f, 0.0f);
		glBegin(GL_QUADS);
    	glVertex2f(-0.14, -0.12);
    	glVertex2f(-0.05, -0.12);
    	glVertex2f(-0.05, -0.2);
    	glVertex2f(-0.14, -0.2);
    	glEnd();
    	
		glBegin(GL_QUADS);
    	glVertex2f(-0.05, -0.2);
    	glVertex2f(-0.08, -0.2);
    	glVertex2f(-0.08, -0.24);
    	glVertex2f(-0.05, -0.24);
    	glEnd();
    	
		glBegin(GL_QUADS);
		glVertex2f(-0.14, -0.24);
    	glVertex2f(-0.14, -0.27);
    	glVertex2f(-0.05, -0.27);
    	glVertex2f(-0.05, -0.24);
    	glEnd();
	glPopMatrix();
	glPushMatrix;
		glColor3f(0.6f, 0.0f, 0.0f);
		glBegin(GL_QUADS);
    	glVertex2f(-0.12, -0.15);
    	glVertex2f(-0.08, -0.15);
    	glVertex2f(-0.08, -0.18);
    	glVertex2f(-0.12, -0.18);
    	glEnd();
    	glTranslatef(0.131,-0.075, 0.0);
		glBegin(GL_QUADS);
    	glVertex2f(-0.12, -0.15);
    	glVertex2f(-0.08, -0.15);
    	glVertex2f(-0.08, -0.18);
    	glVertex2f(-0.12, -0.18);
    	glEnd();
	glPopMatrix;
	
	glFlush();
}

int main(int argc, char* argv[]) {
	glutInit(&argc,argv);
	glutInitWindowSize(640,480);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
	glutCreateWindow("Gambar Mobil");
	glutDisplayFunc(Mobil);
	glClearColor(0.0f, 0.5f, 0.0f, 1.0f); 
	glutMainLoop();
	return 0;
}
