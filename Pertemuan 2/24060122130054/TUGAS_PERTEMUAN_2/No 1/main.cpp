// Nama File : No_1
// Nama : Ayyub Al Anshor
// Tanggal : Rabu, 26 Februari 2024
// Lab : C2 / GKV

#include <GL/glut.h>
#include <gl/gl.h>
#include <cmath>
#include <math.h>

void drawCircle(float cx, float cy, float r, int num_segments)
{
	glPushMatrix();
	    glBegin(GL_TRIANGLE_FAN);
	    for (int i = 0; i < num_segments; i++)
	    {
	        float theta = 2.0f * 3.1415926f * float(i) / float(num_segments);
	        float x = r * cosf(theta);
	        float y = r * sinf(theta);
	        glVertex2f(x + cx, y + cy);
	    }
	    glEnd();
	glPopMatrix();
}


void display()
{
    glClear(GL_COLOR_BUFFER_BIT);

    // Matahari
    glColor3f(1.0, 1.0, 0.0);
    drawCircle(700.0, 500.0, 50.0, 100);
    
        // Matahari 2
    glColor3f(1.0, 0.9, 0.0);
    drawCircle(700.0, 500.0, 43.0, 100);
    
            // Matahari 3
    glColor3f(1.0, 0.7, 0.0);
    drawCircle(700.0, 500.0, 35.0, 100);

    // Pemandangan alam
    glColor3f(0.2, 0.8, 0.2);
    glBegin(GL_POLYGON);
    glVertex2f(0.0, 300.0);
    glVertex2f(800.0, 300.0);
    glVertex2f(800.0, 0.0);
    glVertex2f(0.0, 0.0);
    glEnd();


    glFlush();
}

void init()
{
    glClearColor(0.7, 0.9, 1.0, 1.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, 800.0, 0.0, 600.0);
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(800, 600);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Mobil dan Lingkaran");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}

