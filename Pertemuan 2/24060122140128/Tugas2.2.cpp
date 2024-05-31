#include <GL/glut.h>
#include <math.h>
// Rahman Hanif Aji Saputra
// 24060122140128
const double PI = 3.142857143;
int i, radius, jumlah_titik, x_tengah, y_tengah;
bool atas = true;

void mobil()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glPushMatrix();
    glScalef(4.0, 4.0, 1.0);

    // Gradien latar belakang jalan 
    glBegin(GL_QUADS);
    glColor3f(0.2, 0.2, 0.2);
    glVertex2f(-10.0, -2.0);
    glVertex2f(-10.0, -10.0);
    glColor3f(0.2, 0.2, 0.2);
    glVertex2f(10.0, -10.0);
    glVertex2f(10.0, -2.0);
    glEnd();

    // Tepi jalan
    glColor3f(1.0, 1.0, 1.0);
    glLineWidth(3.0);
    glBegin(GL_LINES);
    glVertex2f(-10.0, -2.0);
    glVertex2f(-10.0, -10.0);
    glVertex2f(10.0, -2.0);
    glVertex2f(10.0, -10.0);
    glEnd();

    // Garis pemisah jalan
    glColor3f(1.0, 1.0, 1.0); 
    glBegin(GL_LINES);
    for (float x = -9.5; x < 10.0; x += 1.0)
    {
        glVertex2f(x, -6.0);
        glVertex2f(x + 0.5, -6.0);
    }
    glEnd();

    // Cup tengah 
    glBegin(GL_POLYGON);
    glColor3f(0.678, 0.498, 1.0); 
    glVertex2f(2.0, 2.0);
    glColor3f(0.4, 0.12, 0.4); 
    glVertex2f(3.0, 0.0);
    glVertex2f(3.0, -2.0);
    glVertex2f(-2.0, -2.0);
    glVertex2f(-2.0, 0.0);
    glVertex2f(-1.4, 2.0);
    glEnd();
    glFlush();

    // Cup depan 
    glBegin(GL_POLYGON);
    glColor3f(0.678, 0.498, 1.0); 
    glVertex2f(3.0, 0.0);
    glColor3f(0.4, 0.12, 0.4); 
    glVertex2f(5.0, 0.0);
    glVertex2f(5.0, -2.0);
    glVertex2f(3.0, -2.0);
    glEnd();
    glFlush();

    // Cup belakang 
    glBegin(GL_POLYGON);
    glColor3f(0.678, 0.498, 1.0); 
    glVertex2f(-2.0, -2.0);
    glColor3f(0.4, 0.12, 0.4); 
    glVertex2f(-3.0, -2.0);
    glVertex2f(-3.0, 0.0);
    glVertex2f(-2.0, 0.0);
    glEnd();
    glFlush();

    // Kaca samping depan 
	glBegin(GL_POLYGON);
	glColor3f(0.529, 0.808, 0.922); 
	glVertex2f(0.5, 1.7);
	glVertex2f(1.7, 1.7);
	glVertex2f(2.5, 0.0);
	glVertex2f(0.5, 0.0);
	glEnd();
	glFlush();

	// Kaca samping 
	glBegin(GL_POLYGON);
	glVertex2f(0.0, 1.7);
	glVertex2f(-1.1, 1.7);
	glColor3f(0.529, 0.808, 0.922); 
	glVertex2f(-1.6, 0.0);
	glVertex2f(0.0, 0.0);
	glEnd();
	glFlush();

    // Ban depan
    glColor3f(0.0, 0.0, 0.0);
    glBegin(GL_POLYGON);

    radius = 80; 
    jumlah_titik = 60;
    x_tengah = 380; 
    y_tengah = -180;

    for (i = 0; i <= 360; i++)
    {
        float sudut = i * (2 * PI / jumlah_titik);
        float x = x_tengah + radius * cos(sudut);
        float y = y_tengah + radius * sin(sudut);
        glVertex2f(x / 100, y / 100);
    }
    glEnd();
    glFlush();

    // Ban belakang
    glColor3f(0.0, 0.0, 0.0);
    glBegin(GL_POLYGON);

    radius = 80; 
    jumlah_titik = 60;
    x_tengah = -180; 
    y_tengah = -180; 

    for (i = 0; i <= 360; i++)
    {
        float sudut = i * (2 * PI / jumlah_titik);
        float x = x_tengah + radius * cos(sudut);
        float y = y_tengah + radius * sin(sudut);
        glVertex2f(x / 100, y / 100);
    }

    glEnd();

    glFlush();

    glPopMatrix();
}


int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(720, 480); 
    glutCreateWindow("Mobil 2D");
    glClearColor(0.529, 0.808, 0.922, 0.0);
    glutDisplayFunc(mobil);
    gluOrtho2D(-40., 40., -40.0, 40.0);
    glutMainLoop();
    return 0;
}
