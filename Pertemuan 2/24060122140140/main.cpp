#include <GL/glut.h>
#include <math.h>

void Lingkaran(float radius, float x_center, float y_center) {
    glPushMatrix();
    glTranslatef(x_center, y_center, 0.0);
    glBegin(GL_POLYGON);
    for (int i = 0; i < 360; i++) {
        float theta = 2.0f * 3.1415926f * float(i) / float(360);
        float x = radius * cosf(theta);
        float y = radius * sinf(theta);
        glVertex2f(x, y);
    }
    glEnd();
    glPopMatrix();
}

void PersegiPanjang(float x1, float y1, float x2, float y2, float x3, float y3, float x4, float y4) {
    glPushMatrix();
    glBegin(GL_POLYGON);
    glVertex2f(x1, y1);
    glVertex2f(x2, y2);
    glVertex2f(x3, y3);
    glVertex2f(x4, y4);
    glEnd();
    glPopMatrix(); 
}

void Mobil() {
  
    glColor3f(0.5, 0.5, 0.5);
    PersegiPanjang(-0.8, -0.2, 0.9, -0.2, 0.75, 0.2, -0.8, 0.2);

   
    glColor3f(0.7, 0.7, 0.7);
    glBegin(GL_POLYGON);
    glVertex2f(-0.6, 0.2);
    glVertex2f(0.6, 0.2);
    glVertex2f(0.4, 0.5);
    glVertex2f(-0.4, 0.5);
    glEnd();

    glColor3f(1, 1, 1);
    glBegin(GL_POLYGON);
    glVertex2f(-0.3, 0.3);
    glVertex2f(0.3, 0.3);
    glVertex2f(0.2, 0.45);
    glVertex2f(-0.2, 0.45);
    glEnd();

   
    glColor3f(0.2, 0.2, 0.2);
    glPushMatrix();
    glTranslatef(-0.4, -0.2, 0.0); 
    Lingkaran(0.1, 0.0, 0.0);
    glPopMatrix();

  
    glColor3f(0.2, 0.2, 0.2);
    glPushMatrix();
    glTranslatef(0.4, -0.2, 0.0);
    Lingkaran(0.1, 0.0, 0.0);
    glPopMatrix();
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();

    Mobil();

    glFlush();
}

void reshape(int w, int h) {
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-1, 1, -1, 1);
    glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(800, 600);
    glutCreateWindow("Mobil");
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glClearColor(1.0, 1.0, 1.0, 0.0);
    glutMainLoop();
    return 0;
}

