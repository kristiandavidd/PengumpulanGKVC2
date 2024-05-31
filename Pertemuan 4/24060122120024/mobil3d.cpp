// Nama : Widiawati Sihaloho
// NIM  : 24060122120037
// Lab : C2	

#include <math.h>
#include <GL/glut.h>
#include <stdio.h>
#include <string.h>

float rotangle=0.0;
float rotangle1=0.0;
float angle=0.0, deltaAngle = 0.0, ratio;
float x=-8.0f,y=1.75f,z=35.0f; // posisi awal kamera
float lx=0.0f,ly=0.0f,lz=-1.0f;
int deltaMove = 0,h,w;
int bitmapHeight=12;
const double PI = 3.141592653589793;
int i,j,radius,jumlah_titik,x_tengah,y_tengah;

void reshape(int w1, int h1) {
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

void orientMe(float ang)
{
	// Fungsi ini untuk memutar arah kamera 
	lx = sin(ang);
	lz = -cos(ang);
	glLoadIdentity();
	gluLookAt(x, y, z,
	x + lx,y + ly,z + lz,
	0.0f,1.0f,0.0f);
}

void moveMeFlat(int i)
{
	// Fungsi ini untuk maju mundur kamera
	x = x + i*(lx)*0.1;
	z = z + i*(lz)*0.1;
	glLoadIdentity();
	gluLookAt(x, y, z,
	x + lx,y + ly,z + lz,
	0.0f,1.0f,0.0f);
}

void Grid() {
	// Fungsi untuk membuat grid di "lantai"
	double i;
	const float Z_MIN = -50, Z_MAX = 50;
	const float X_MIN = -50, X_MAX = 50;
	const float gap = 1.5;
	glColor3f(0.5, 0.5, 0.5);
	glBegin(GL_LINES);
		for(i=Z_MIN;i<Z_MAX;i+=gap)
		{
			glVertex3f(i, 0, Z_MIN);
			glVertex3f(i, 0, Z_MAX);
		}
		for(i=X_MIN;i<X_MAX;i+=gap)
		{
			glVertex3f(X_MIN, 0, i);
			glVertex3f(X_MAX, 0, i);
		}
	glEnd();
}

void MobilTruk()
{
	glPushMatrix();
		// truk depan bawah
        glPushMatrix();
            glTranslatef(0.23, 1.5, 0);
            glColor3f(0.9, 0.45, 0.1);
            glScalef(3.5, 0.5, 4.5);
            glBegin(GL_POLYGON);
                glVertex3f(-0.5, -0.5, 0.5);
                glVertex3f(0.5, -0.5, 0.5);
                glVertex3f(0.5, 0.5, 0.5);
                glVertex3f(-0.5, 0.5, 0.5);
            glEnd();
        glPopMatrix();

        //kaca depan
        glPushMatrix();
            glTranslatef(1.9, 4.1, 0);
            glColor3f(0.2, 0.4, 0.5);
            glScalef(0.1, 2, 4.5);
            glBegin(GL_POLYGON);
                glVertex3f(-0.5, -0.5, 0.5);
                glVertex3f(0.5, -0.5, 0.5);
                glVertex3f(0.5, 0.5, 0.5);
                glVertex3f(-0.5, 0.5, 0.5);
            glEnd();
        glPopMatrix();

        //kaca kanan
        glPushMatrix();
            glTranslatef(0.5, 4.1, 2.25);
            glColor3f(0.2, 0.4, 0.5);
            glScalef(1.8, 2, 0.01);
            glBegin(GL_POLYGON);
                glVertex3f(-0.5, -0.5, 0.5);
                glVertex3f(0.5, -0.5, 0.5);
                glVertex3f(0.5, 0.5, 0.5);
                glVertex3f(-0.5, 0.5, 0.5);
            glEnd();
        glPopMatrix();

        //kaca kiri
        glPushMatrix();
            glTranslatef(0.5, 4.1, -2.25);
            glColor3f(0.2, 0.4, 0.5);
            glScalef(1.8, 2, 0.01);
            glBegin(GL_POLYGON);
                glVertex3f(-0.5, -0.5, 0.5);
                glVertex3f(0.5, -0.5, 0.5);
                glVertex3f(0.5, 0.5, 0.5);
                glVertex3f(-0.5, 0.5, 0.5);
            glEnd();
        glPopMatrix();

        //bumber
        glPushMatrix();
            glTranslatef(1.9, 2.3, 0);
            glColor3f(0.9, 0.9, 0.7);
            glScalef(0.1, 0.8, 4.5);
            glBegin(GL_POLYGON);
                glVertex3f(-0.5, -0.5, 0.5);
                glVertex3f(0.5, -0.5, 0.5);
                glVertex3f(0.5, 0.5, 0.5);
                glVertex3f(-0.5, 0.5, 0.5);
            glEnd();
        glPopMatrix();

        //body truk
        glPushMatrix();
            glTranslatef(0.27, 3.65, 0);
            glColor3f(1.0, 0.2, 0.1);
            glScalef(3.2, 3.8, 4.5);
            glBegin(GL_POLYGON);
                glVertex3f(-0.5, -0.5, 0.5);
                glVertex3f(0.5, -0.5, 0.5);
                glVertex3f(0.5, 0.5, 0.5);
                glVertex3f(-0.5, 0.5, 0.5);
            glEnd();
        glPopMatrix();

        // bawah container 
        glPushMatrix();
            glColor3f(0.4, 0.4, 0.39);
            glTranslatef(-6.5, 1.5, 0);
            glScalef(10, 1, 4.5);
            glBegin(GL_POLYGON);
                glVertex3f(-0.5, -0.5, 0.5);
                glVertex3f(0.5, -0.5, 0.5);
                glVertex3f(0.5, 0.5, 0.5);
                glVertex3f(-0.5, 0.5, 0.5);
            glEnd();
        glPopMatrix();

        // container 
        glPushMatrix();
            glColor3f(0.2, 0.2, 1.0);
            glTranslatef(-6.5, 4., 0);
            glScalef(10, 4, 4.5);
            glBegin(GL_POLYGON);
                glVertex3f(-0.5, -0.5, 0.5);
                glVertex3f(0.5, -0.5, 0.5);
                glVertex3f(0.5, 0.5, 0.5);
                glVertex3f(-0.5, 0.5, 0.5);
            glEnd();
        glPopMatrix();

        // ban truk depan kanan
        glPushMatrix();
            glColor3f(0.1, 0.1, 0.1);
            glTranslatef(0., 0.98, 2.25);
            glScalef(0.65, 0.32, 0.65); 
            glutSolidCube(1);
        glPopMatrix();

        // ban truk depan kiri
        glPushMatrix();
            glColor3f(0.1, 0.1, 0.1);
            glTranslatef(0., 0.98, -2.25);
            glScalef(0.65, 0.32, 0.65); 
            glutSolidCube(1);
        glPopMatrix();

        // ban container kiri 1
        glPushMatrix();
            glColor3f(0.1, 0.1, 0.1);
            glTranslatef(-10., 0.98, 2.25);
            glScalef(0.65, 0.32, 0.65); 
            glutSolidCube(1);
        glPopMatrix();

        // ban container kiri 2
        glPushMatrix();
            glColor3f(0.1, 0.1, 0.1);
            glTranslatef(-7.8, 0.98, 2.25);
            glScalef(0.65, 0.32, 0.65); 
            glutSolidCube(1);
        glPopMatrix();

        // ban container kanan 1
        glPushMatrix();
            glColor3f(0.1, 0.1, 0.1);
            glTranslatef(-10., 0.98, -2.25);
            glScalef(0.65, 0.32, 0.65); 
            glutSolidCube(1);
        glPopMatrix();

        // ban container kanan 2
        glPushMatrix();
            glColor3f(0.1, 0.1, 0.1);
            glTranslatef(-7.8, 0.98, -2.25);
            glScalef(0.65, 0.32, 0.65); 
            glutSolidCube(1);
        glPopMatrix();
		
		// ban truk depan kanan
		glPushMatrix();
			glColor3f(0.1,0.1,0.1);
			glTranslatef(0.,0.98,2.25);
			glutSolidTorus(0.32, 0.65, 100, 100);
		glPopMatrix();
		
		// ban truk depan kiri
		glPushMatrix();
			glColor3f(0.1,0.1,0.1);
			glTranslatef(0.,0.98,-2.25);
			glutSolidTorus(0.32, 0.65, 100, 100);
		glPopMatrix();
		
		// ban container kiri 1
		glPushMatrix();
			glColor3f(0.1,0.1,0.1);
			glTranslatef(-10.,0.98,2.25);
			glutSolidTorus(0.32, 0.65, 100, 100);
		glPopMatrix();
		
		// ban container kiri 2
		glPushMatrix();
			glColor3f(0.1,0.1,0.1);
			glTranslatef(-7.8,0.98,2.25);
			glutSolidTorus(0.32, 0.65, 100, 100);
		glPopMatrix();
		
		// ban container kanan 1
		glPushMatrix();
			glColor3f(0.1,0.1,0.1);
			glTranslatef(-10.,0.98,-2.25);
			glutSolidTorus(0.32, 0.65, 100, 100);
		glPopMatrix();
		
		// ban container kanan 2
		glPushMatrix();
			glColor3f(0.1,0.1,0.1);
			glTranslatef(-7.8,0.98,-2.25);
			glutSolidTorus(0.32, 0.65, 100, 100);
		glPopMatrix();
		
	glPopMatrix();
}

void display() {
    if (deltaMove)
		moveMeFlat(deltaMove);
	if (deltaAngle) {
		angle += deltaAngle;
		orientMe(angle);
	}
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    Grid();
    MobilTruk();
    glutSwapBuffers();
    glFlush();
}

void pressKey(int key, int x, int y) {
	switch (key) {
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
		case GLUT_KEY_RIGHT : if (deltaAngle > 0.0f)
			deltaAngle = 0.0f;
			break;
		case GLUT_KEY_UP : if (deltaMove > 0)
			deltaMove = 0;
			break;
		case GLUT_KEY_DOWN : if (deltaMove < 0)
			deltaMove = 0;
			break;
	}
}

// Variabel untuk pencahayaan
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

void init(void)
{
	glEnable (GL_DEPTH_TEST);
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowPosition(50,50);
	glutInitWindowSize(800, 600); 
    glutCreateWindow("Mobil Truk 3d");
    glEnable(GL_DEPTH_TEST);
    glutIgnoreKeyRepeat(1);
	glutSpecialFunc(pressKey);
	glutSpecialUpFunc(releaseKey);
	glutDisplayFunc(display);
	glutIdleFunc(display);
    glutReshapeFunc(reshape);
    lighting();
    init();
    glutMainLoop();
    return 0;
}

