// Nama	: Arya Ajisadda Haryanto
// NIM	: 24060122140118

#include <GL/glut.h>
#include <math.h>
#define DEG2RAD 3.14159/180.0

void initOpenGL() {
    glClearColor(1.0, 1.0, 1.0, 0.0);
}
void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 1.0, 0.0); 
    
    int i;
    glBegin(GL_POLYGON);
    for (i = 0; i < 360; i++) {
        float degInRad = i * DEG2RAD;
        glVertex2f(cos(degInRad) * 1 + 0, sin(degInRad) * 1 + 0);
    }
    glEnd();
    glFlush();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv); 
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); 
    glutInitWindowSize(500, 500); 
    glutInitWindowPosition(100, 100); 
    glutCreateWindow("Tugas Lingkaran"); 
    initOpenGL(); 
    glutDisplayFunc(display); 
    glutMainLoop(); 
    return 0;
}
