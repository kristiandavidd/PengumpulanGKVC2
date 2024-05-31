#include <GL/glut.h>
#include <math.h>

void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    
    glBegin(GL_POLYGON);
    glColor3f(0.5, 0.5, 0.5); 
    glVertex2f(-0.8, 0.0);
    glVertex2f(-0.6, 0.2);
    glVertex2f(0.6, 0.2);
    glVertex2f(0.8, 0.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.7, 0.91, 0.9);
    glVertex2f(-0.5, 0.2);
    glVertex2f(-0.3, 0.4);
    glVertex2f(0.3, 0.4);
    glVertex2f(0.5, 0.2);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.1, 0.1, 0.1); 
    for (int i = 0; i < 360; i++) {
        float theta = i * 3.14159 / 180;
        glVertex2f(-0.6 + 0.15 * cos(theta), -0.2 + 0.15 * sin(theta));
    }
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.1, 0.1, 0.1); 
    for (int i = 0; i < 360; i++) {
        float theta = i * 3.14159 / 180;
        glVertex2f(0.6 + 0.15 * cos(theta), -0.2 + 0.15 * sin(theta));
    }
    glEnd();

    glFlush();
}

void init() {
    glClearColor(1.0, 1.0, 1.0, 1.0); 
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-1.0, 1.0, -1.0, 1.0);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Mobil 2D");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}

