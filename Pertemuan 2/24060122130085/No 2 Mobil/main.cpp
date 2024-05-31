#include <GL/gl.h>
#include<math.h>
#include <GL/glut.h>

void circle(GLfloat rx, GLfloat ry, GLfloat cx, GLfloat cy)
{
    glBegin(GL_POLYGON);
    glVertex2f(cx, cy);
    for (int i = 0; i <= 360; i++)
    {
        float angle = i * 3.1416 / 180;
        float x = rx * cos(angle);
        float y = ry * sin(angle);
        glVertex2f((x + cx), (y + cy));
    }
    glEnd();
}

void sun(GLfloat rx, GLfloat ry, GLfloat cx, GLfloat cy)
{
    glBegin(GL_POLYGON);
    glVertex2f(cx, cy);
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
    glClearColor(0.0, 0.0, 0.2, 0.0);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0.0, 500, 0.0, 500); 
}
float bx = 100;

void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT);

    // road

    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_POLYGON);
    glVertex2d(0, 185);
    glVertex2d(500, 185);
    glVertex2d(500, 245);
    glVertex2d(0, 245);
    glEnd();

    glColor3f(0.0, 0.0, 0.0);
    glBegin(GL_POLYGON);
    glVertex2d(0, 190);
    glVertex2d(500, 190);
    glVertex2d(500, 240);
    glVertex2d(0, 240);
    glEnd();

	glPushMatrix();
	
    //bulan
    glColor3f(1.0, 0.95, 0.0);
    sun(28, 35, 400, 450);
    glRotated(90.0,0.0,0.0,1.0);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(bx, 0, 0);

	//mobil bawah
    glColor3f(0.0, 0.89, 0.68);
    glBegin(GL_POLYGON);
    glVertex2d(500, 230);
    glVertex2d(580, 230);
    glVertex2d(580, 270);
    glVertex2d(500, 270);
    glEnd();

	//mobil atas
    glColor3f(0.0, 0.89, 0.68);
    glBegin(GL_POLYGON);
    glVertex2d(510, 260);
    glVertex2d(565, 260);
    glVertex2d(555, 300);
    glVertex2d(520, 300);
    glEnd();

    //jendela mobil
    glColor3ub(220, 220, 220);
    glBegin(GL_POLYGON);
    glVertex2d(515, 270);
    glVertex2d(535, 270);
    glVertex2d(535, 290);
    glVertex2d(520, 290);
    glEnd();

    //jendela mobil
    glColor3ub(220, 220, 220);
    glBegin(GL_POLYGON);
    glVertex2d(540, 270);
    glVertex2d(560, 270);
    glVertex2d(555, 290);
    glVertex2d(540, 290);
    glEnd();

    // roda
    glColor3ub(0, 0, 0);
    circle(10, 16, 525, 230);
    circle(10, 16, 555, 230);

    glColor3ub(245, 255, 245);
    circle(6, 12, 525, 230);
    circle(6, 12, 555, 230);

    glPopMatrix();
    bx += 0.05;
    if (bx > 0)
        bx = -500;
    glutPostRedisplay();

    glFlush();
    glutSwapBuffers();
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(1000, 600);
    glutInitWindowPosition(200, 50);
    glutCreateWindow("Mobil gerak");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}

