//Nama : Adzkiya Qarina Salsabila
//NIM  : 24060122140138
//Deskripsi : Membuat sebuah lingkaran

#include <GLUT/glut.h>
#include <iostream>
#include <math.h>
#define _USE_MATH_DEFINES

void drawCircle(double r, int vertex) {
    double ng = (double) vertex;
    glBegin(GL_POLYGON);
    for (int i = 0; i < vertex; i++) {
        double x = r * cos(2 * M_PI * i / ng);
        double y = r * sin(2 * M_PI * i / ng);
        
        float red = sin(x) * 0.5 + 0.5;  // Sumbu x mempengaruhi komponen merah
        float green = sin(y) * 0.5 + 0.5;  // Sumbu y mempengaruhi komponen hijau
        glColor3f(red, green, 0.7);  // Warna biru tetap konstan

        glVertex2d(x, y);
    }
    glEnd();
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 1.0, 0.0);
    drawCircle(1.0, 100);
    glutSwapBuffers();
}

void init() {
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glColor3f(1.0, 0.0, 0.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-2.0f, 2.0f, -2.0f, 2.0f);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(0, 0);
    glutCreateWindow("Circle");
    glutDisplayFunc(display);
    
    init();
    glutMainLoop();
    
    return 0;
}
