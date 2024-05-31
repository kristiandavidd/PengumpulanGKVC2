/*
Nama		: Demina Ayunda Chesara
Nim 		: 24060122140149
Tanggal		: 03-03-2024
Deskripsi 	: Kode membuat lingkaran
*/

#include <GL/glut.h>
#include <cmath>

// Fungsi untuk menggambar lingkaran
void drawCircle(float cx, float cy, float r, int num_segments) {
    glBegin(GL_TRIANGLE_FAN);
    for (int i = 0; i < num_segments; i++) {
        float theta = 2.0f * 3.1415926f * float(i) / float(num_segments);  // Menghitung sudut theta
        float x = r * cosf(theta);  // Hitung koordinat x titik pada lingkaran
        float y = r * sinf(theta);  // Hitung koordinat y titik pada lingkaran
        glVertex2f(x + cx, y + cy);  // Gambar titik pada lingkaran
    }
    glEnd();
}

// Fungsi untuk menggambar
void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    // Menggambar lingkaran dengan pusat (0,0) dan radius 5, serta 50 segmen
    drawCircle(0, 0, 5, 50);

    glFlush();
}

// Fungsi inisialisasi
void init() {
    glClearColor(1.0, 1.0, 1.0, 0.0);  // Set background ke putih
    glColor3f(0.0, 0.0, 0.0);  // Set warna garis ke hitam
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-10.0, 10.0, -10.0, 10.0);  // Area tampilan
}

// Fungsi utama
int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Lingkaran");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}

