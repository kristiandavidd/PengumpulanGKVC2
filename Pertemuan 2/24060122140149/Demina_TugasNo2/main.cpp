/*
Nama		: Demina Ayunda Chesara
Nim 		: 24060122140149
Tanggal		: 03-03-2024
Deskripsi 	: Kode membuat mobil box berwarna orange
*/

#include <GL/glut.h>
#include <cmath>


void drawBody() {
    
    glBegin(GL_POLYGON);
    glColor3f(1.0f, 0.53f, 0.06f); // box nya
        glVertex2f(0.1f, -0.1f);
        glVertex2f(0.9f, -0.1f);
        glVertex2f(0.9f, 0.6f);
        glVertex2f(0.1f, 0.6f);        
    glEnd();
    
    glBegin(GL_POLYGON);
    glColor3f(0.99f, 0.74f, 0.37f); // badan box
    	glVertex2f(-0.2f, 0.4f);
    	glVertex2f(-0.2f, -0.1f);
        glVertex2f(0.0f, -0.1f);
        glVertex2f(0.0f, 0.4f);   
    glEnd();
    
    glBegin(GL_POLYGON);
     glColor3f(0.99f, 0.74f, 0.37f); // badan box
    	glVertex2f(-0.2f, 0.4f);
    	glVertex2f(-0.4f, 0.2f);
        glVertex2f(-0.4f, -0.1f);
        glVertex2f(-0.2f, -0.1f);   
    glEnd();
    
    glBegin(GL_POLYGON);
     glColor3f(0.99f, 0.74f, 0.37f); // badan box
    	glVertex2f(-0.4f, 0.2f);
    	glVertex2f(-0.6f, 0.2f);
        glVertex2f(-0.6f, -0.1f);
        glVertex2f(-0.4f, -0.1f);   
    glEnd();
    
    glBegin(GL_POLYGON); // bagian sambung
    glColor3f(0.0f, 0.0f, 0.0f);
    	glVertex2f(0.0f, -0.1f);
    	glVertex2f(0.04f, -0.1f);
        glVertex2f(0.04f, 0.3f);
        glVertex2f(0.0f, 0.3f);   
    glEnd();
    
    glBegin(GL_POLYGON); // bagian sambung
    glColor3f(0.0f, 0.0f, 0.0f);
    	glVertex2f(0.0f, 0.0f);
    	glVertex2f(0.0f, -0.1f);
        glVertex2f(0.1f, -0.1f);
        glVertex2f(0.1f, 0.0f);   
    glEnd();
    
    glBegin(GL_POLYGON); // jendela
    glColor3f(0.0f, 0.0f, 0.0f);
    	glVertex2f(-0.05f, 0.35f);
		glVertex2f(-0.18f, 0.35f);
		glVertex2f(-0.28f, 0.22f);
        glVertex2f(-0.05f, 0.22f);       
    glEnd();
    
    glBegin(GL_POLYGON); // pintu
    glColor3f(0.0f, 0.0f, 0.0f);
    	glVertex2f(-0.018f, 0.19f);
		glVertex2f(-0.1f, 0.19f);
		glVertex2f(-0.1f, 0.16f);
        glVertex2f(-0.018f, 0.16f);       
    glEnd();
    
    glBegin(GL_POLYGON); // lampu
    glColor3f(0.7f, 0.07f, 0.07f);
    	glVertex2f(-0.52f, 0.1f);
		glVertex2f(-0.6f, 0.1f);
		glVertex2f(-0.6f, 0.0f);
        glVertex2f(-0.52f, 0.0f);       
    glEnd();
}

// Fungsi untuk menggambar roda mobil
void drawWheel() {
    glColor3f(0.1f, 0.1f, 0.1f); // Warna abu-abu
    glBegin(GL_POLYGON);
        for (int i = 0; i < 360; i++) {
            float rad = i * 3.14159 / 180;
            glVertex2f(0.1f * cos(rad) - 0.3f, 0.1f * sin(rad) - 0.2f);
        }
    glEnd();
}

// Fungsi untuk menggambar mobil
void drawCar() {
    // Badan mobil
    glPushMatrix();
    drawBody();
    glPopMatrix();

    // Roda 1
	glPushMatrix();
	glTranslatef(0.7f, 0.1f, 0.0f); // Posisi roda 1
	drawWheel();
	glPopMatrix();

	// Roda 2
	glPushMatrix();
	glTranslatef(1.0, 0.1f, 0.0f); // Posisi roda 2
	drawWheel();
	glPopMatrix();

	// Roda 3
	glPushMatrix();
	glTranslatef(-0.1f, 0.1f, 0.0f); // Posisi roda 3
	drawWheel();
	glPopMatrix();
    
}

// Fungsi untuk menggambar
void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    // Menggambar mobil
    drawCar();

    glFlush();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Mobil Box Toko Oren");
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f); // Warna background putih
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}

