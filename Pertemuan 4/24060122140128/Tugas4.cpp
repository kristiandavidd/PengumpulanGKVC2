/*
Nama 	: Rahman Hanif Aji Saputra
Nim		: 24060122140128
tema	: Mobil (bus sekolah 3d)
*/
#include <math.h> 
#include <GL/glut.h> 
#include <stdio.h> 
#include <string.h> 
#include <stdlib.h> 
#include <unistd.h>

float rotangle=0.0;
float rotangle1=0.0;
float angle=0.0, deltaAngle = 0.0, ratio;
float x=0.0f,y=3.0f,z=25.0f; 
float lx=0.0f,ly=0.0f,lz=-1.0f;
int deltaMove = 0,h,w;
int bitmapHeight=12;
int i,j,radius,jumlah_titik,x_tengah,y_tengah;
const double PI = 3.141592653589793;

void Reshape(int w1, int h1){ 
 	// Fungsi reshape 
 	if(h1 == 0) h1 = 1; 
 	w = w1; 
 	h = h1; 
 	ratio = 1.0f * w / h; 
 	
 	glMatrixMode(GL_PROJECTION); 
 	glLoadIdentity(); 
 	glViewport(0, 0, w, h); 
 	gluPerspective(45,ratio,0.1,1000);
 	glMatrixMode(GL_MODELVIEW); 
 	glLoadIdentity(); 
 	gluLookAt(
 		x, y, z, 
 		x + lx,y + ly,z + lz, 
 		0.0f,1.0f,0.0f);
} 

void orientMe(float ang) { 
 	// Fungsi ini untuk kanan kiri kamera
 	lx = sin(ang); 
 	lz = -cos(ang); 
 	glLoadIdentity(); 
 	gluLookAt(
	 	x, y, z, 
 		x + lx,y + ly,z + lz, 
 		0.0f,1.0f,0.0f); 
} 

void moveMeFlat(int i) 
{ 
 	// Fungsi ini untuk maju mundur kamera 
 	x = x + i*(lx)*0.1; 
 	z = z + i*(lz)*0.1; 
 	glLoadIdentity(); 
 	gluLookAt(
	 	x, y, z, 
 		x + lx,y + ly,z + lz, 
 		0.0f,1.0f,0.0f
	); 
} 



void wheel(){
	//wheel function
	glPushMatrix();
		for(int j=0; j<=360; j++) {
			glPushMatrix();
				glTranslatef(1,0,-0.5);
				glRotated(90,1,0,0);
				glRotated(j,0,1,0);
				glTranslatef(0,3,0.8);
				
				glColor3f(0.1,0.1,0.1);
				glBegin(GL_QUADS);
				glVertex3f(0,0,0);
				glVertex3f(0.1,0,0);
				glVertex3f(0.1,0.6,0);
				glVertex3f(0,0.6,0);
				glEnd();
			glPopMatrix();
		}
	glPopMatrix();

	// front circle
	glPushMatrix();
		glTranslatef(0,0,3.1);
		glColor3f(0.1,0.1,0.1);
		glBegin(GL_TRIANGLE_FAN);
		radius=80;
		jumlah_titik=100;
		x_tengah=100;
		y_tengah=0;
		for (i=0; i<=360; i++) {
			float sudut=i*(2*PI/jumlah_titik);
			float x=x_tengah+radius*cos(sudut);
			float y=y_tengah+radius*sin(sudut);
			glVertex2f(x/100,y/100);
		}
		glEnd();
	glPopMatrix();

	// back circle
	glPushMatrix();
		glTranslatef(0,0,2.5);
		glRotated(180,1,0,0);
		
		glColor3f(0.1,0.1,0.1);
		glBegin(GL_TRIANGLE_FAN);
		radius=80;
		jumlah_titik=100;
		x_tengah=100;
		y_tengah=0;
		for (i=0; i<=360; i++) {
			float sudut=i*(2*PI/jumlah_titik);
			float x=x_tengah+radius*cos(sudut);
			float y=y_tengah+radius*sin(sudut);
			glVertex2f(x/100,y/100);
		}
		glEnd();
	glPopMatrix();
}

void main_body(){
	glPushMatrix();
		glTranslatef(0,4,0);
		glColor3ub(255, 199, 0);
		//pintu1
		glPushMatrix();
			glBegin(GL_POLYGON);
			glVertex3i(-8,4,4);
			glVertex3i(-8,-4,4);
			glVertex3i(-12,-4,4);
			glVertex3i(-12,-2,4);
			glVertex3i(-11,-1,4);
			glVertex3i(-11,4,4);
			glEnd(); 
		glPopMatrix();
		//pintu2
		glPushMatrix();
			glBegin(GL_POLYGON);
			glVertex3i(-8,4,-4);
			glVertex3i(-8,-4,-4);
			glVertex3i(-12,-4,-4);
			glVertex3i(-12,-2,-4);
			glVertex3i(-11,-1,-4);
			glVertex3i(-11,4,-4);
			glEnd(); 
		glPopMatrix();
	
		//depan
		glPushMatrix();
			glBegin(GL_QUADS);
			glVertex3i(-11,4,-4);
			glVertex3i(-11,4,4);
			glVertex3i(-11,-1,4);
			glVertex3i(-11,-1,-4);
			glEnd();
			
			glBegin(GL_QUADS);
			glVertex3i(-11,-1,4);
			glVertex3i(-12,-2,4);
			glVertex3i(-12,-2,-4);
			glVertex3i(-11,-1,-4);
			glEnd();
			
			glBegin(GL_QUADS);
			glVertex3i(-12,-2,4);
			glVertex3i(-12,-2,-4);
			glVertex3i(-12,-4,-4);
			glVertex3i(-12,-4,4);
			glEnd();
		glPopMatrix();
	
		//atas
		glPushMatrix();
			glBegin(GL_QUADS);
			glVertex3i(-8,4,-4);
			glVertex3i(-8,4,4);
			glVertex3i(-11,4,4);
			glVertex3i(-11,4,-4);
			glEnd();
		glPopMatrix();
		//bawah
		glPushMatrix();
			glBegin(GL_QUADS);
			glVertex3i(-8,-4,-4);
			glVertex3i(-8,-4,4);
			glVertex3i(-12,-4,4);
			glVertex3i(-12,-4,-4);
			glEnd();
		glPopMatrix();
		//main boy decoration
		glPushMatrix();
			//kaca depan
			glPushMatrix();
				glColor3ub(239, 255, 253);
				glTranslatef(-11,1.5,0);
				glScalef(0.15,4,7);
				glutSolidCube(1);
			glPopMatrix();
			//kaca samping
			glPushMatrix();
				glColor3ub(239, 255, 253);
				glTranslatef(-9.5,1.5,4);
				glScalef(2,4,0.15);
				glutSolidCube(1);
			glPopMatrix();
			//kaca samping2
			glPushMatrix();
				glColor3ub(239, 255, 253);
				glTranslatef(-9.5,1.5,-4);
				glScalef(2,4,0.15);
				glutSolidCube(1);
			glPopMatrix();
			
			
		glPopMatrix();
		//wheel
		glColor3ub(24, 10,10);
		glPushMatrix();
			glTranslatef(-11.4,-4,1.2);
			glScalef(1.5,1.5,1);
			wheel();
		glPopMatrix();
		glPushMatrix();
			glTranslatef(-11.4,-4,-7);
			glScalef(1.5,1.5,1);
			wheel();
		glPopMatrix();
	glPopMatrix();
	glPushMatrix();
	glTranslatef(0,4,0);
	
		
		//belakang
		glPushMatrix();
			glBegin(GL_QUADS); 
			glColor3ub(255, 152, 0);
			glVertex3i(-8,4,-4);
			glVertex3i(8,4,-4);
			glVertex3i(8,-4,-4);
			glVertex3i(-8,-4,-4);
			glEnd();
		glPopMatrix();
		
		
		
			
		//depan
		glPushMatrix();
			glBegin(GL_QUADS); 
			glColor3ub(255, 152, 0);
			glVertex3i(-8,4,4);
			glVertex3i(8,4,4);
			glVertex3i(8,-4,4);
			glVertex3i(-8,-4,4);
			glEnd();
		glPopMatrix();
		
		//atas
		glPushMatrix();
			glBegin(GL_QUADS); 
			glScalef(3,3,4);
			glColor3ub(255, 152, 0);
			glVertex3i(-8,4,-4);
			glVertex3i(8,4,-4);
			glVertex3i(8,4,4);
			glVertex3i(-8,4,4);
			glEnd();
		glPopMatrix();
		
		//kiri
		glPushMatrix();
			glBegin(GL_QUADS); 
			glColor3ub(255, 152, 0);
			glVertex3i(-8,4,-4);
			glVertex3i(-8,4,4);
			glVertex3i(-8,-4,4);
			glVertex3i(-8,-4,-4);
			glEnd();
		glPopMatrix();
		
		//kaca samping kiri
			glPushMatrix();
				glColor3ub(239, 255, 253);
				glTranslatef(-6,1.5,4);
				glScalef(3,3,0.15);
				glutSolidCube(1);
			glPopMatrix();
			
			glPushMatrix();
				glColor3ub(239, 255, 253);
				glTranslatef(-2.5,1.5,4);
				glScalef(3,3,0.15);
				glutSolidCube(1);
			glPopMatrix();
			
			glPushMatrix();
				glColor3ub(239, 255, 253);
				glTranslatef(1,1.5,4);
				glScalef(3,3,0.15);
				glutSolidCube(1);
			glPopMatrix();
			
			glPushMatrix();
				glColor3ub(239, 255, 253);
				glTranslatef(4.5,1.5,4);
				glScalef(3,3,0.15);
				glutSolidCube(1);
			glPopMatrix();
			
			glPushMatrix();
				glColor3ub(239, 255, 253);
				glTranslatef(8,1.5,4);
				glScalef(3,3,0.15);
				glutSolidCube(1);
			glPopMatrix();
			
		
		//kanan
		glPushMatrix();
			glTranslatef(16,0,0);
			glBegin(GL_QUADS);
			glColor3ub(255, 152, 0);
			glVertex3i(-8,4,-4);
			glVertex3i(-8,4,4);
			glVertex3i(-8,-4,4);
			glVertex3i(-8,-4,-4);
			glEnd();
		glPopMatrix();
		
		//kaca samping kanan
			glPushMatrix();
				glColor3ub(239, 255, 253);
				glTranslatef(-6,1.5,-4);
				glScalef(3,3,0.15);
				glutSolidCube(1);
			glPopMatrix();
			
			glPushMatrix();
				glColor3ub(239, 255, 253);
				glTranslatef(-2.5,1.5,-4);
				glScalef(3,3,0.15);
				glutSolidCube(1);
			glPopMatrix();
			
			glPushMatrix();
				glColor3ub(239, 255, 253);
				glTranslatef(1,1.5,-4);
				glScalef(3,3,0.15);
				glutSolidCube(1);
			glPopMatrix();
			
			glPushMatrix();
				glColor3ub(239, 255, 253);
				glTranslatef(4.5,1.5,-4);
				glScalef(3,3,0.15);
				glutSolidCube(1);
			glPopMatrix();
			
			glPushMatrix();
				glColor3ub(239, 255, 253);
				glTranslatef(8,1.5,-4);
				glScalef(3,3,0.15);
				glutSolidCube(1);
			glPopMatrix();
		
		//bawah
		glPushMatrix();
			glTranslatef(0,-8,0);
			glBegin(GL_QUADS); 
			glColor3ub(255, 152, 0);
			glVertex3i(-8,4,-4);
			glVertex3i(8,4,-4);
			glVertex3i(8,4,4);
			glVertex3i(-8,4,4);
			glEnd();
		glPopMatrix();
		
		
		glColor3ub(255, 152, 0);
		//pintu1
		glPushMatrix();
			glBegin(GL_POLYGON);
			glVertex3i(8,4,4);
			glVertex3i(8,-4,4);
			glVertex3i(12,-4,4);
			glVertex3i(12,-2,4);
			glVertex3i(11,-1,4);
			glVertex3i(11,4,4);
			glEnd(); 
		glPopMatrix();
		//pintu2
		glPushMatrix();
			glBegin(GL_POLYGON);
			glVertex3i(8,4,-4);
			glVertex3i(8,-4,-4);
			glVertex3i(12,-4,-4);
			glVertex3i(12,-2,-4);
			glVertex3i(11,-1,-4);
			glVertex3i(11,4,-4);
			glEnd(); 
		glPopMatrix();
	
		//depan
		glPushMatrix();
			glBegin(GL_QUADS);
			glVertex3i(11,4,-4);
			glVertex3i(11,4,4);
			glVertex3i(11,-1,4);
			glVertex3i(11,-1,-4);
			glEnd();
			
			glBegin(GL_QUADS);
			glVertex3i(11,-1,4);
			glVertex3i(12,-2,4);
			glVertex3i(12,-2,-4);
			glVertex3i(11,-1,-4);
			glEnd();
			
			glBegin(GL_QUADS);
			glVertex3i(12,-2,4);
			glVertex3i(12,-2,-4);
			glVertex3i(12,-4,-4);
			glVertex3i(12,-4,4);
			glEnd();
		glPopMatrix();
	
		//atas
		glPushMatrix();
			glBegin(GL_QUADS);
			glVertex3i(-8,4,-4);
			glVertex3i(-8,4,4);
			glVertex3i(-11,4,4);
			glVertex3i(-11,4,-4);
			glEnd();
		glPopMatrix();
		//bawah
		glPushMatrix();
			glBegin(GL_QUADS);
			glVertex3i(-8,-4,-4);
			glVertex3i(-8,-4,4);
			glVertex3i(-12,-4,4);
			glVertex3i(-12,-4,-4);
			glEnd();
		glPopMatrix();
		
		//wheel
		glColor3ub(24, 10,10);
		glPushMatrix();
			glTranslatef(9,-4,1.2);
			glScalef(1.5,1.5,1);
			wheel();
		glPopMatrix();
		glPushMatrix();
			glTranslatef(9,-4,-7);
			glScalef(1.5,1.5,1);
			wheel();
		glPopMatrix();
	glPopMatrix();
	
			

}
void road() {
    // Fungsi untuk membuat jalan raya

    // Warna jalan
    glColor3f(0.2, 0.2, 0.2);

    // Segmen jalan
    glBegin(GL_QUADS);
    glVertex3f(-20, -1.5, -100);  
    glVertex3f(20, -1.5, -100);   
    glVertex3f(20, -1.5, 100);    
    glVertex3f(-20, -1.5, 100);   
    glEnd();
}
void display(){ 
	usleep(1);
 	
	if (deltaMove){
		moveMeFlat(deltaMove); 
	}
 		
 	if (deltaAngle){ 
 		angle += deltaAngle; 
 		orientMe(angle); 
 	}
 	
 	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
 	glClearColor(1.0,1.0,1.0,1.0);
 	
	road();
	main_body();
 	glutSwapBuffers(); 
 	glFlush(); 
} 

void pressKey(int key, int x, int y) { 
 	switch (key){ 
 		case GLUT_KEY_LEFT : deltaAngle = -0.01f;break; 
 		case GLUT_KEY_RIGHT : deltaAngle = 0.01f;break; 
 		case GLUT_KEY_UP : deltaMove = 1;break; 
 		case GLUT_KEY_DOWN : deltaMove = -1;break; 
 	} 
} 
void releaseKey(int key, int x, int y) { 
 	switch (key) { 
 		case GLUT_KEY_LEFT : 
 			if (deltaAngle < 0.0f) 
 			deltaAngle = 0.0f; 
 		break; 
 		case GLUT_KEY_RIGHT : 
		 	if (deltaAngle > 0.0f) 
 			deltaAngle = 0.0f; 
 		break; 
 		case GLUT_KEY_UP : 
		 	if (deltaMove > 0) 
 			deltaMove = 0; 
 		break; 
 		case GLUT_KEY_DOWN : 
		 	if (deltaMove < 0) 
 			deltaMove = 0; 
 		break; 
 	} 
}	 


const GLfloat light_ambient[] = { 0.5f, 0.5f, 0.5f, 0.0f }; 
const GLfloat light_diffuse[] = { 1.0f, 1.0f, 1.0f, 1.0f }; 
const GLfloat light_specular[] = { 1.0f, 1.0f, 1.0f, 1.0f }; 
const GLfloat light_position[] = { 0.0f, 20.0f, 10.0f, 1.0f };

const GLfloat mat_ambient[] = { 0.7f, 0.7f, 0.7f, 1.0f }; 
const GLfloat mat_diffuse[] = { 0.8f, 0.8f, 0.8f, 1.0f }; 
const GLfloat mat_specular[] = { 1.0f, 1.0f, 1.0f, 1.0f }; 
const GLfloat high_shininess[] = { 100.0f }; 

void lighting(){ 

 	glEnable(GL_DEPTH_TEST); 
 	glDepthFunc(GL_LESS); 
 	glEnable(GL_LIGHT0); 
 	glEnable(GL_NORMALIZE); 
 	glEnable(GL_COLOR_MATERIAL); 
 	glEnable(GL_LIGHTING);
 	
 	glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient); 
 	glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse); 
 	glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular); 
 	glLightfv(GL_LIGHT0, GL_POSITION, light_position); 
 	
 	glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient); 
 	glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse); 
 	glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular); 
 	glMaterialfv(GL_FRONT, GL_SHININESS, high_shininess); 
} 
void init(void){
 	glEnable (GL_DEPTH_TEST); 
 	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL); 
}


int main(int argc, char **argv){ 
 	glutInit(&argc, argv); 
 	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA); 
 	glutInitWindowPosition(50,50); 
 	glutInitWindowSize(900,700); 
 	glutCreateWindow("3D Lighting");
 	
 	glutIgnoreKeyRepeat(1); 
 	glutSpecialFunc(pressKey);
 	glutSpecialUpFunc(releaseKey); 
 	glutDisplayFunc(display); 
 	glutIdleFunc(display); 
 	glutReshapeFunc(Reshape);
 	glClearColor(1, 1, 1, 1);
 	lighting(); 
 	init();
 	
 	glutMainLoop(); 
 	return(0); 
}


