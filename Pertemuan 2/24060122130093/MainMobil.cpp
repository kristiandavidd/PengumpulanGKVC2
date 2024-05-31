#include <glut.h>
#include <math.h>

const double PI = 3.142857143;
int i, radius, jumlah_titik;
float x_tengah, y_tengah;


void Mobil()
{  
    glClear(GL_COLOR_BUFFER_BIT);
    glPushMatrix();

    //RED
    glColor3f(1.0,0.0,0.0);
    glBegin(GL_POLYGON);
    glVertex2f(2.0, 2.0);
    glVertex2f(3.0, 0.0);
    glVertex2f(3.0, -2.0);
    glVertex2f(-3.0, -2.0);
    glVertex2f(-3.0, 0.0);
    glVertex2f(-2.0, 2.0);
    glEnd();
    
    glColor3f(1.0,0.0,0.0);
    glBegin(GL_POLYGON);
    glVertex2f(3.0, 0.0);
    glVertex2f(5.0, 0.0);
    glVertex2f(5.0, -2.0);
    glVertex2f(3.0, -2.0);
    glEnd();

    glColor3f(1.0,0.0,0.0);
    glBegin(GL_POLYGON);
    glVertex2f(-3.0, -2.0);
    glVertex2f(-5.0, -2.0);
    glVertex2f(-5.0, 0.0);
    glVertex2f(-3.0, 0.0);
    glEnd();

    glColor3f(5.0,1.0,5.0);
    glBegin(GL_POLYGON);
    glVertex2f(0.5, 1.7);   
	glVertex2f(1.5, 1.7);
    glVertex2f(2.5, 0.0);
    glVertex2f(0.5, 0.0);
    glEnd();

    glColor3f(5.0,1.0,5.0);
    glBegin(GL_POLYGON);
    glVertex2f(0.0, 1.7);
    glVertex2f(-1.1, 1.7);
    glVertex2f(-1.8, 0.0);
    glVertex2f(0.0, 0.0);
    glEnd();
    
    //WHEELS
 	glColor3f(0.0,0.0,0.0);
    glBegin(GL_POLYGON);
      
  	radius = 90;
    jumlah_titik = 60;
    x_tengah = 290;
    y_tengah = -190;
      
    for (i=0;i<=360;i++)
    {
    	float sudut=i*(2*PI/jumlah_titik);
        float x=x_tengah+radius*cos(sudut);
        float y=y_tengah+radius*sin(sudut);
        glVertex2f(x/100,y/100);
	}
    glEnd();
    
    glColor3f(0.0,0.0,0.0);
    glBegin(GL_POLYGON);
      
    radius = 90;
    jumlah_titik = 60;
    x_tengah = -250;
    y_tengah = -190;
      
    for (i=0;i<=360;i++)
    {
    	float sudut=i*(2*PI/jumlah_titik);
        float x=x_tengah+radius*cos(sudut);
        float y=y_tengah+radius*sin(sudut);
        glVertex2f(x/100,y/100);
    }      
    glEnd();
    glFlush();

    glPopMatrix();
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(400, 400);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Mobil");
    glClearColor(1.0, 9.0, 1.0, 0.0);
    gluOrtho2D(-20., 20., -20.0, 20.0);
    glutDisplayFunc(Mobil);
    glutMainLoop();
}

