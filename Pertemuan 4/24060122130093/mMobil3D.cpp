#include <math.h>
#include <GL/glut.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h> 

    void cylinder(float alas,float atas,float tinggi);
    void kerucut(float alas, float atas, float tinggi);
    void blok(float tebal,int ratiol,int ratiop);

    GLfloat  source_light[]={0.30,0.30,0.30,0.50};
    double Loop,LoopAll=0;

	float angle=0.0, deltaAngle = 0.0, ratio;
	float x=0.0f,y=1.75f,z=15.0f;
	float lx=0.0f,ly=0.0f,lz=-1.0f;
	int deltaMove = 0,h,w;
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
	 lx = sin(ang);
	 lz = -cos(ang);
	 glLoadIdentity();
	 gluLookAt(x, y, z,
	 x + lx,y + ly,z + lz,
	 0.0f,1.0f,0.0f);
	}
	void moveMeFlat(int i)
	{
	 x = x + i*(lx)*0.1;
	 z = z + i*(lz)*0.1;
	 glLoadIdentity();
	 gluLookAt(x, y, z,
	 x + lx,y + ly,z + lz,
	 0.0f,1.0f,0.0f);
	}
	void Grid() {
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

    void kendaraan(void)
    {
     glClearColor(0.0,1.0,0.0,0.0);
     glShadeModel(GL_SMOOTH);
     glMatrixMode(GL_PROJECTION);
     glLoadIdentity();
     gluPerspective(50.0,1.5,10.0,1000.0);

     glEnable  (GL_DEPTH_TEST);
     glPolygonMode   (GL_FRONT_AND_BACK,GL_FILL);
     glEnable  (GL_LIGHTING);
     glLightfv  (GL_LIGHT7,GL_DIFFUSE,source_light);
     glEnable  (GL_LIGHT7);
     glEnable  (GL_COLOR_MATERIAL);
     glColorMaterial (GL_FRONT_AND_BACK,GL_AMBIENT);

    }

    void Mobil(void)
    {

     glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
     glMatrixMode(GL_MODELVIEW);
     glLoadIdentity();

      glTranslatef(0,0,-100);

     glPushMatrix();
     glColor3f(0.0,1.0,0.0);
     blok(10, 3, 2);
     glTranslatef(0, 9, 0);
     blok(10, 3, 2);
     glTranslatef(10, -10,0);
     blok(10, 5.5, 2);
     glRotatef(-35, 0, 0, 15);
     glTranslatef(0, 7,0);
     blok(10, 2, 2);
     glTranslatef(2, 4.9,-2.5);

     glColor3f(0.0,0.0,0.0);
     blok(0.5, 20, 31);

     glRotatef(180, 45, -45, 0);

     glPopMatrix();


     glPushMatrix();
     glColor3f(1.0,0.0,0.0);
     glTranslatef(20, -8,-7);
     cylinder(5, 5,3);

     glColor3f(1.0,0.0,0.0);
     glTranslatef(-20, 8,7);
     glTranslatef(-5, -8,-7);
     cylinder(5, 5,3);

     glColor3f(1.0,0.0,0.0);
     glTranslatef(5, 8,7);
     glRotatef(180,0,180,0);
     glTranslatef(3,-8,-17);
     cylinder(5, 5,3);

     glColor3f(1.0,0.0,0.0);
     glTranslatef(-3,8,17);
     glTranslatef(-22,-8,-17);
     cylinder(5, 5,3);

     glColor3f(0.0,0.0,0.0);
     glRotatef(90,1,0,0);
     glTranslatef(8, 2.5,-15);
     blok(2, 4, 5);


     glRotatef(90,0,1,0);
     glTranslatef(0,-0.2,7);
     blok(2, 4, 8);

    glColor3f(0.0,0.0,0.0);
     glRotatef(0,0,0,0);
     glTranslatef(0,19.2,0);
     blok(2, 4, 8);

    glColor3f(0.0,0.0,0.0);
     glRotatef(90,0,1,0);
     glTranslatef(7, 0,-8);
     blok(2, 4, 5);

     glColor3f(9.9,9.9,0.0);
     glRotatef(90,0,1,0);
     glTranslatef(0,-3,20);
     cylinder(2, 2,3);

     glColor3f(9.9,9.9,0.0);
     glRotatef(0,0,0,0);
     glTranslatef(0,-12,0);
     cylinder(2, 2,3);

     glColor3f(1.0,1.0,1.0);
     glRotatef(0,0,0,0);
     glTranslatef(0,-0.5,-52);
     cylinder(2, 1,3);

     glColor3f(1.0,1.0,1.0);
     glRotatef(0,0,0,0);
     glTranslatef(0,11.5,0);
     cylinder(2, 1,3);


     glColor3f(0.0,0.0,0.0);
     glRotatef(90,1,0,0);
     glTranslatef(-7,3.5,-0.5);
     blok(2, 6.0, 7.0);



     glPopMatrix();


     glFlush();
     glutSwapBuffers();

    }

    void kerucut(float bottom, float up, float width)
    {
     float i;
     glPushMatrix();
     glTranslatef(1.0,0.0,bottom/24);
     glutSolidCone(bottom,0,32,4);
     for(i=0;i<=width;i+=bottom/24)
     {
      glTranslatef(0.0,0.0,bottom/24);
      glutSolidTorus(bottom/4,bottom-((i*(bottom-up))/width),16,16);
     }
     glTranslatef(0.0,0.0,bottom/4);
     glutSolidCone(up,0,20,1);
     glColor3f(0.,1.,1.);
     glPopMatrix();
    }
    
    void cylinder(float alas,float up,float height)
    {
     float i;
     glPushMatrix();
     glTranslatef(1.0,0.0,-alas/8);
     glutSolidCone(alas,0,32,4);
     for(i=0;i<=height;i+=alas/24)
     {
      glTranslatef(0.0,0.0,alas/24);
      glutSolidTorus(alas/4,alas-((i*(alas-up))/height),16,16);
     }
     glTranslatef(0.0,0.0,alas/4);
     glutSolidCone(height,0,20,1);
     glColor3f(0.,0.,0.);
     glPopMatrix();
    }

    void blok(float tebal,int ratiol,int ratiop)
    {
     float i,j;
     glPushMatrix();
     for(i=0;i<ratiop;i++)
     {
      glTranslatef(-(ratiol+1)*tebal/2,0.0,0.0);
      for(j=0;j<ratiol;j++)
      {
       glTranslatef(tebal,0.0,0.0);
       glutSolidCube(tebal);
      }
      glTranslatef(-(ratiol-1)*tebal/2,0.0,tebal);
     }
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
	 Mobil();
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


int main(int argc, char **argv)
{ 
     glutInit(&argc,argv);
     glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA); 
     glutInitWindowPosition(100,100);
     glutInitWindowSize(500,600);
     glutCreateWindow("Mobil");
     glutIgnoreKeyRepeat(1); 
	 glutSpecialFunc(pressKey);
	 glutSpecialUpFunc(releaseKey);
	 glutDisplayFunc(display);
	 glutIdleFunc(display);
	 glutReshapeFunc(Reshape);
	 lighting();
	 init();
	 glutMainLoop();
	 return(0);
    }
