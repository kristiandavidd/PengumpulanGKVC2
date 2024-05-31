/*
Nama : Muhammad Luthfan Lazuardi
NIM : 24060122120010
Tanggal : 28-02-2024
*/

#include <GL/gl.h>
#include <stdio.h>
#include <math.h>
#include <GL/glut.h>

GLfloat wheelAngle = 0.0f;

void lingkaran(GLfloat rx, GLfloat ry, GLfloat cx, GLfloat cy)
{
    glBegin(GL_POLYGON);
    for (int i = 0; i <= 360; i++)
    {
        float angle = i * 3.1416 / 180;
        float x = rx * cos(angle);
        float y = ry * sin(angle);
        glVertex2f((x + cx), (y + cy));
    }
    glEnd();
}

void init(void)
{
    glClearColor(1.0, 1.0, 1.0, 1.0);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0, 150, 0, 150);
}


void background()
{
    //Jalan Tanah
    glColor3f(0.55, 0.27, 0.075);
    glBegin(GL_POLYGON);
    glVertex2d(0, 0);
    glVertex2d(150, 0);
    glVertex2d(150, 40);
    glVertex2d(0, 40);
    glEnd();
    
    //Langit malam
    glColor3f(0.0, 0.0, 0.0);
    glBegin(GL_POLYGON);
    glVertex2d(0, 40);
    glVertex2d(150, 40);
    glVertex2d(150, 150);
    glVertex2d(0, 150);
    glEnd();
}

float bx = 10;
void trukk()
{
	//Badan
    glPushMatrix();
    glTranslatef(bx, 0, 0);
    glColor3f(0.5, 0.5, 0.5); //bagian container
    glBegin(GL_POLYGON);
    glVertex2d(135, 40);
    glVertex2d(185, 40);
    glVertex2d(182, 55);
    glVertex2d(138, 55);
    glEnd();
    
    glColor3f(0.5, 0.5, 0.5); //bagian tengah
    glBegin(GL_POLYGON);
    glVertex2d(136, 41);
    glVertex2d(205, 41);
    glVertex2d(205, 52);
    glVertex2d(138, 52);
    glEnd();
    
    glColor3f(1.0, 0.0, 0.0); //bagian truk depan
    glBegin(GL_POLYGON);
    glVertex2d(205, 40);
    glVertex2d(240, 40);
    glVertex2d(235, 70);
    glVertex2d(205, 70);
    glEnd();
    
	glColor3f(0.5, 0.5, 0.5); //bumper depan
    glBegin(GL_POLYGON);
    glVertex2d(238, 40);
    glVertex2d(240, 40);
    glVertex2d(235, 70);
    glVertex2d(233, 70);
    glEnd();
    
    glColor3f(0.5, 0.5, 0.5); //knalpot
    glBegin(GL_POLYGON);
    glVertex2d(202, 40);
    glVertex2d(206, 40);
    glVertex2d(206, 92);
    glVertex2d(202, 92);
    glEnd();
    
    glColor3f(0.5, 0.5, 0.5); //knalpot atas
    glBegin(GL_POLYGON);
    glVertex2d(203, 92);
    glVertex2d(205, 92);
    glVertex2d(205, 105);
    glVertex2d(203, 103);
    glEnd();
    
    glColor3f(1.0, 0.0, 0.0); //bagian atas truk
    glBegin(GL_POLYGON);
    glVertex2d(206, 70);
    glVertex2d(225, 70);
    glVertex2d(215, 90);
    glVertex2d(206, 90);
    glEnd();
    
    glColor3f(1.0, 0.0, 0.0); //box kecil
    glBegin(GL_POLYGON);
    glVertex2d(193, 52);
    glVertex2d(202, 52);
    glVertex2d(202, 88);
    glVertex2d(193, 88);
    glEnd();
    
    glColor3f(1.0, 0.0, 0.0); //box kecil belakang
    glBegin(GL_POLYGON);
    glVertex2d(193, 88);
    glVertex2d(202, 88);
    glVertex2d(201, 90);
    glVertex2d(194, 90);
    glEnd();
    
    //Jendela
    glColor3f(0.5, 1.0, 0.83); 
    glBegin(GL_POLYGON);
    glVertex2d(210, 70);
    glVertex2d(225, 70);
    glVertex2d(215, 85);
    glVertex2d(210, 85);
    glEnd();
    
    //Ban
    glPushMatrix();
    glTranslatef(210, 40, 0);  
    glRotatef(wheelAngle, 0, 0, 1);  
    glColor3f(0.0, 0.0, 0.0); //ban depan hitam
    lingkaran(11, 11, 0, 0);  
    glColor3f(0.5, 0.5, 0.5); //velg abu-abu
    lingkaran(6, 7, 0, 0);
    glColor3f(0.0, 0.0, 0.0); //bagian dalem hitam
    lingkaran(3, 3, 0, 0);
    glPopMatrix();
    
    glPushMatrix();
    glTranslatef(170, 40, 0);  
    glRotatef(wheelAngle, 0, 0, 1);  
    glColor3f(0.0, 0.0, 0.0); //ban belakang 1 hitam
    lingkaran(10, 11, 0, 0);  
    glColor3f(0.5, 0.5, 0.5); //velg abu-abu
    lingkaran(6, 7, 0, 0);
    glColor3f(0.0, 0.0, 0.0); //bagian dalem hitam
    lingkaran(3, 3, 0, 0);
    glPopMatrix();
    
    glPushMatrix();
    glTranslatef(150, 40, 0);  
    glRotatef(wheelAngle, 0, 0, 1);  
    glColor3f(0.0, 0.0, 0.0); //ban belakang 2 hitam
    lingkaran(10, 11, 0, 0);  
    glColor3f(0.5, 0.5, 0.5); //velg abu-abu
    lingkaran(6, 7, 0, 0);
    glColor3f(0.0, 0.0, 0.0); //bagian dalam hitam
    lingkaran(3, 3, 0, 0);
    glPopMatrix();
    
    glPopMatrix();
    bx += 0.045;
    if (bx > 0)
        bx = -300;
    wheelAngle += 10.0;
    if (wheelAngle > 360.0)
        wheelAngle = 0.0;
    glutPostRedisplay();
}

void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    background();
    trukk();
    glFlush();
    glutSwapBuffers();
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(700, 500);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Truk Tabrak gas gas");
    init();
    glutDisplayFunc(display);
    glutIdleFunc(trukk);
    glutMainLoop();
    return 0;
}

