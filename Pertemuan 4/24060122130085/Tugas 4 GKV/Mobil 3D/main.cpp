#include <math.h> 
#include <GL/glut.h> 
#include <stdio.h> 
#include <string.h> 
#include <stdlib.h> 

float angle=0.0, deltaAngle = 0.0, ratio; 
float x=0.0f, y=1.75f, z=15.0f; 
float lx=0.0f, ly=0.0f, lz=-1.0f; 
int deltaMove = 0, h, w; 
int bitmapHeight=12; 

void Reshape(int w1, int h1) 
{ 

    if(h1 == 0) h1 = 1; 
    w = w1; 
    h = h1; 
    ratio = 1.0f * w / h; 

    glMatrixMode(GL_PROJECTION); 
    glLoadIdentity(); 
    glViewport(0, 0, w, h); 
    gluPerspective(45, ratio, 0.1, 1000); 
    glMatrixMode(GL_MODELVIEW); 
    glLoadIdentity(); 
    gluLookAt(x, y, z, x + lx, y + ly, z + lz, 0.0f, 1.0f, 0.0f); 
} 

void orientMe(float ang) 
{ 
    // Fungsi ini untuk memutar arah kamera (tengok kiri/kanan) 
    lx = sin(ang); 
    lz = -cos(ang); 

    glLoadIdentity(); 
    gluLookAt(x, y, z, x + lx, y + ly, z + lz, 0.0f, 0.5f, 0.0f); 
} 

void moveMeFlat(int i) 
{ 
    x = x + i * lx * 0.1; 
    z = z + i * lz * 0.1; 

    glLoadIdentity(); 
    gluLookAt(x, y, z, x + lx, y + ly, z + lz, 0.0f, 1.0f, 0.0f); 
} 

void Mobil() 
{ 
    glBegin(GL_QUADS); 

    /* Gambar badan mobil */
    glColor3f(0.5, 0.1, 0); 
    glVertex3f(0.2, 0.4, 0.6);
    glVertex3f(0.6, 0.5, 0.6);
    glVertex3f(0.6, 0.5, 0.2);
    glVertex3f(0.2, 0.4, 0.2);

    /* bawah kubus*/
  glVertex3f( 0.2,0.4,0.6);
  glVertex3f(0.6,0.2,0.6);
  glVertex3f(0.6,0.2,0.2);
  glVertex3f( 0.2,0.2,0.2);

  /* depan kubus*/
  glVertex3f( 0.2,0.2,0.6);
  glVertex3f(0.2, 0.4,0.6);
  glVertex3f(0.2,0.4,0.2);
  glVertex3f( 0.2,0.2,0.2);

  /* belakang kubus*/
  glVertex3f(0.6,0.2,0.6);
  glVertex3f(0.6,0.5,0.6);
  glVertex3f(0.6,0.5,0.2);
  glVertex3f( 0.6,0.2,0.2);

  /* kiri kubus*/
  glVertex3f(0.2,0.2,0.6);
  glVertex3f(0.6,0.2,0.6);
  glVertex3f(0.6,0.5,0.6);
  glVertex3f(0.2,0.4,0.6);

  /* kanan kubus */
  glVertex3f(0.2,0.2,0.2);
  glVertex3f( 0.6,0.2,0.2);
  glVertex3f( 0.6,0.5,0.2);
  glVertex3f( 0.2,0.4,0.2);
//****************************************************************************
  glVertex3f(0.7,0.65,0.6);
  glVertex3f(0.7,0.65,0.2);
  glVertex3f(1.7,0.65,0.2);        //bagian cover atas
  glVertex3f(1.7,0.65,0.6);
//***************************bagian belakang******************************
  glColor3f(0.2,0.3,0.1);           
  glVertex3f( 1.8, 0.5,0.6);
  glVertex3f(1.8, 0.5,0.2);
  glVertex3f(2.1, 0.4, 0.2);
  glVertex3f(2.1,0.4,0.6);

  /* bawah kubus*/
  glVertex3f( 2.1,0.2,0.6);
  glVertex3f(2.1,0.2,0.2);
  glVertex3f(1.8,0.2,0.6);
  glVertex3f( 1.8,0.2,0.6);

  /* belakang kubus*/
  glVertex3f(2.1,0.4,0.6);
  glVertex3f(2.1,0.4,0.2);
  glVertex3f(2.1,0.2,0.2);
  glVertex3f(2.1,0.2,0.6);

  /* kiri kubus*/
  glVertex3f(1.8,0.2,0.2);
  glVertex3f(1.8,0.5,0.2);
  glVertex3f(2.1,0.4,0.2);
  glVertex3f(2.1,0.2,0.2);

  /* kanan kubus */
  glVertex3f(1.8,0.2,0.6);
  glVertex3f(1.8,0.5,0.6);
  glVertex3f(2.1,0.4,0.6);
  glVertex3f(2.1,0.2,0.6);
//******************badan bagian tengah************************************
  glVertex3f( 0.6, 0.5,0.6);
  glVertex3f(0.6, 0.2,0.6);
  glVertex3f(1.8, 0.2, 0.6);
  glVertex3f(1.8,0.5,0.6);

  /* bawah kubus*/
  glVertex3f( 0.6,0.2,0.6);
  glVertex3f(0.6,0.2,0.2);
  glVertex3f(1.8,0.2,0.2);
  glVertex3f( 1.8,0.2,0.6);

  /* belakang kubus*/
  glVertex3f(0.6,0.5,0.2);
  glVertex3f(0.6,0.2,0.2);
  glVertex3f(1.8,0.2,0.2);
  glVertex3f(1.8,0.5,0.2);
//*********************JENDELA**********************************
  glColor3f(0.3,0.3,0.3);
  glVertex3f( 0.77, 0.63,0.2);
  glVertex3f(0.75, 0.5,0.2);        //jendela depan
  glVertex3f(1.2, 0.5, 0.2);
  glVertex3f( 1.22,0.63,0.2);

  glVertex3f(1.27,0.63,.2);
  glVertex3f(1.25,0.5,0.2);        //jendela belakang
  glVertex3f(1.65,0.5,0.2);
  glVertex3f(1.67,0.63,0.2);

  glColor3f(0,0.5,0);
  glVertex3f(0.7,0.65,0.2);
  glVertex3f(0.7,0.5,.2);       //pemisah
  glVertex3f(0.75,0.5,0.2);
  glVertex3f(0.77,0.65,0.2);

  glVertex3f(1.2,0.65,0.2);
  glVertex3f(1.2,0.5,.2);       //pemisah
  glVertex3f(1.25,0.5,0.2);
  glVertex3f(1.27,0.65,0.2);

  glVertex3f(1.65,0.65,0.2);
  glVertex3f(1.65,0.5,.2);     //pemisa 3D
  glVertex3f(1.7,0.5,0.2);
  glVertex3f(1.7,0.65,0.2);

  glVertex3f( 0.75, 0.65,0.2);
  glVertex3f(0.75, 0.63,0.2);        //garis
  glVertex3f(1.7, 0.63, 0.2);
  glVertex3f( 1.7,0.65,0.2);

  glVertex3f( 0.75, 0.65,0.6);
  glVertex3f(0.75, 0.63,0.6);        //garis
  glVertex3f(1.7, 0.63, 0.6);
  glVertex3f( 1.7,0.65,0.6);

  glColor3f(0.3,0.3,0.3);
  glVertex3f( 0.77, 0.63,0.6);
  glVertex3f(0.75, 0.5,0.6);        //jendela depan
  glVertex3f(1.2, 0.5, 0.6);
  glVertex3f( 1.22,0.63,0.6);

  glVertex3f(1.27,0.63,.6);
  glVertex3f(1.25,0.5,0.6);        //jendela belakang
  glVertex3f(1.65,0.5,0.6);
  glVertex3f(1.67,0.63,0.6);

  glColor3f(0.2,0.3,0.5);
  glVertex3f(0.7,0.65,0.6);
  glVertex3f(0.7,0.5,.6);       //pemisah pertama
  glVertex3f(0.75,0.5,0.6);
  glVertex3f(0.77,0.65,0.6);

  glVertex3f(1.2,0.65,0.6);
  glVertex3f(1.2,0.5,.6);       //pemisah kedua
  glVertex3f(1.25,0.5,0.6);
  glVertex3f(1.27,0.65,0.6);

  glVertex3f(1.65,0.65,0.6);
  glVertex3f(1.65,0.5,.6);
  glVertex3f(1.7,0.5,0.6);
  glVertex3f(1.7,0.65,0.6);
  glEnd();


 //**************************************************************
  glBegin(GL_QUADS);

  /* kubus bagian atas */
  glColor3f(0.3,0.3,0.3);
  glVertex3f( 0.6, 0.5,0.6);
  glVertex3f(0.6, 0.5,0.2);        //jendela depan
  glVertex3f(0.7, 0.65, 0.2);
  glVertex3f( 0.7,0.65,0.6);

  glVertex3f(1.7,0.65,.6);
  glVertex3f(1.7,0.65,0.2);        //jendela belakang
  glVertex3f(1.8,0.5,0.2);
  glVertex3f(1.8,0.5,0.6);


    glEnd(); 
    
	glColor3f(0.1, 0.1, 0.1); // Warna roda


    // Roda depan kiri
 glPushMatrix();
    glTranslatef(0.6f, 0.2f, 0.6f); 
    glutSolidSphere(0.1f, 20, 20); 
    glPopMatrix(); 

    // Roda depan kanan
    glPushMatrix();
    glTranslatef(1.8f, 0.2f, 0.6f);
    glutSolidSphere(0.1f, 20, 20);
    glPopMatrix();

    // Roda belakang kiri
    glPushMatrix();
    glTranslatef(0.6f, 0.2f, 0.2f);
    glutSolidSphere(0.1f, 20, 20);
    glPopMatrix();

    // Roda belakang kanan
    glPushMatrix();
    glTranslatef(1.8f, 0.2f, 0.2f);
    glutSolidSphere(0.1f, 20, 20);
    glPopMatrix();

    glEnd(); 
}

void display() { 
    if (deltaMove) 
        moveMeFlat(deltaMove); 
    if (deltaAngle) { 
        angle += deltaAngle; 
        orientMe(angle); 
    } 
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); 
    Mobil(); 
    glutSwapBuffers(); 
    glFlush(); 
} 

void pressKey(int key, int x, int y) { 
    switch (key) { 
        case GLUT_KEY_LEFT : deltaAngle = -0.0001f;break; 
        case GLUT_KEY_RIGHT : deltaAngle = 0.0001f;break; 
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

void lighting() {  
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

void init(void) { 
    glEnable (GL_DEPTH_TEST); 
    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL); 
} 

int main(int argc, char **argv) { 
    glutInit(&argc, argv); 
    glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA); 
    glutInitWindowPosition(100,100); 
    glutInitWindowSize(640,480); 
    glutCreateWindow("Car in 3D"); 
    glutIgnoreKeyRepeat(1); 
    glutSpecialFunc(pressKey); 
    glutSpecialUpFunc(releaseKey); 
    glutDisplayFunc(display); 
    glutIdleFunc(display); 
    glutReshapeFunc(Reshape); 
    lighting(); 
    init(); 
    glutMainLoop(); 
    return 0; 
}

