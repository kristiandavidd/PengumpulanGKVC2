/*Nama : Rania 
 *NIM : 24060122120013 
 *Lab : C2 
 *Nama File : main.cpp
 *Tanggal : 3 Maret 2024
 *Deskripsi : Menampilkan lingkaran*/
 
#include "stdlib.h"
#include "gl/glut.h"
#include "math.h"

const double PI = 3.141592653589793;
int i;

void background() {
    glBegin(GL_QUADS);
    glColor3f(205, 255, 205); 
    glVertex2d(-150, 150);
    glVertex2d(150, 150);
    glVertex2d(150, -150);
    glVertex2d(-150, -150);
    glEnd();
}

void Lingkaran(int radius, int jumlah_titik, int x_tengah, int y_tengah) {
    glBegin(GL_POLYGON);
    {
        for (i = 0; i <= 360; i++) {
            float sudut = i * (2 * PI / jumlah_titik);
            float x = x_tengah + radius * cos(sudut);
            float y = y_tengah + radius * sin(sudut);
            glVertex2f(x, y);
        }
    }
    glEnd();
}

void gambarLingkaran() {
    glClear(GL_COLOR_BUFFER_BIT);
    background();

    //lINGKARAN 1
    glColor3f(0.8, 0.8, 0.6); 
    Lingkaran(25, 100, -105, 0);

    //lINGKARAN 2
    glColor3f(1.0, 0.8, 1.0); 
    Lingkaran(21, 70, -40, 0);

    //lINGKARAN 3
    glColor3f(0.8, 0.8, 1.0); 
    Lingkaran(17, 70, 15, 0);

   //lINGKARAN 4
    glColor3f(0.6, 0.9, 0.6); 
    Lingkaran(13, 70, 65, 0);

    //lINGKARAN 5
    glColor3f(0.9, 0.6, 0.6); 
    Lingkaran(9, 70, 110, 0);

    glFlush();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(300, 300);
    glutInitWindowPosition(200, 200);
    glutCreateWindow("LINGKARAN");
    gluOrtho2D(-150, 150, -150, 150);
    glutDisplayFunc(gambarLingkaran);
    glutMainLoop();
    return 0;
}

