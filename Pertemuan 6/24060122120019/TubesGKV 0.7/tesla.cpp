#include <math.h> 
#include <GL/glut.h> 
#include <stdio.h> 
#include <string.h> 
#include <stdlib.h> 
#include "tesla.h"

//Berisi Render keseluruhan Mobil Tesla

float cpDepanX, cpDepanZ, cpBelakangX, cpBelakangZ;

void ban(float x, float y, float z)
{
	glPushMatrix();
	glTranslatef(x, y, z);
	glPushMatrix();
	for (int j = 0; j <= 360; j++)
	{
		glPushMatrix();
		glTranslatef(0, 0, -0.5);
		glRotated(90, 1, 0, 0);
		glRotated(j, 0, 1, 0);
		glTranslatef(0, 3, 1);
		glColor3f(0.2, 0.2, 0.2);
		glBegin(GL_QUADS);
		glVertex3f(0, 0, 0);
		glVertex3f(0.3, 0, 0);
		glVertex3f(0.3, 0.6, 0);
		glVertex3f(0, 0.6, 0);
		glEnd();
		glPopMatrix();
	}
	glPopMatrix();

	//velg ban
	float th;
	glPushMatrix();
	glTranslatef(0, 0, 3.1);
	glColor3f(0.2, 0.2, 0.2);
	glBegin(GL_POLYGON);
	for(int i=0; i<360; i++)
	{
		th = i * M_PI / 180;
		glVertex3f(cos(th), sin(th), 0);
	}
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0, 0, 2.5);
	glColor3f(0.2, 0.2, 0.2);
	glBegin(GL_POLYGON);
	for(int i=0; i<360; i++)
	{
		th = i * M_PI / 180;
		glVertex3f(cos(th), sin(th), 0);
	}
	glEnd();
	glPopMatrix();

	glPopMatrix();
}



void collisionBox(float putaran, float tx, float ty, float tz) {
    putaran = putaran - 90;
    cpDepanX = tx + -7.0*sin(putaran*M_PI/180);
    cpDepanZ = tz + -7.0*cos(putaran*M_PI/180);

    cpBelakangX = tx + 6.0*sin(putaran*M_PI/180);
    cpBelakangZ = tz + 6.0*cos(putaran*M_PI/180);

//    //hanya untuk visualisasi tempat collisionnya saja
//    //titik nya pas ditengah cube nya (jangan dihapus buat debug)
//    glPushMatrix();
//    glColor3f(0.5,0.5,0);
//    glTranslatef(cpDepanX, ty+3, cpDepanZ);
//    glRotatef(putaran, 0.0, 1.0, 0.0);
//    glutSolidCube(3.0f);
//    glPopMatrix();
//    glPushMatrix();
//    glColor3f(1,1,1);
//    glTranslatef(cpBelakangX, ty+3, cpBelakangZ);
//    glRotatef(putaran, 0.0, 1.0, 0.0);
//    glutSolidCube(3.0f);
//    glPopMatrix();
}


void Tesla(float putaran, float x, float y, float z) {
    collisionBox(putaran, x, y, z);
    glTranslatef(x, y, z);
    glRotated(putaran, 0.0f, 1.0f, 0.0f);
    
    glPushMatrix();
        glRotatef(90, 0, 1, 0);
        glScalef(0.8, 0.6, 0.65);
        
        //////////// BODY DAN BAN /////////////
        glPushMatrix();
            glScalef(0.85, 0.85, 0.85);
            //WHeel
            glPushMatrix();
            	glScalef(2.7, 2.7, 2.7);
            	glRotatef(-90, 0, 1, 0);
            	ban(0.5, 0.9, -1.3); // depan kanan
            	ban(0.5, 0.9, -4.3); // depan kiri 
            	ban(-5, 0.9, -1.2); // belakang kanan
            	ban(-5, 0.9, -4.4); // belakang kiri
        	glPopMatrix();
            glPushMatrix();
                glTranslatef(4, -1.4, -20);
                glRotated(-90, 0, 1, 0);
                glScalef(2, 2, 2);
                glColor3ub(110, 110, 110);
                glBegin(GL_QUADS);
                    // Depan
                    glVertex3f(13.8, 2.2, 0);
                    glVertex3f(13.8, 2.2, 4);
                    glVertex3f(14, 3, 4);
                    glVertex3f(14, 3, 0);
                    // Depan Atas
                    glVertex3f(14, 3, 4);
                    glVertex3f(14, 3, 0);
                    glVertex3f(13, 3.3, 0);
                    glVertex3f(13, 3.3, 4);
                    // Belakang Atas
                    glVertex3f(6, 5, 0);
                    glVertex3f(6, 5, 4);
                    glVertex3f(0, 4, 4);
                    glVertex3f(0, 4, 0);
                    // Bawah
                    glVertex3f(0.5, 1.4, 0);
                    glVertex3f(0.5, 1.4, 4);
                    glVertex3f(13.6, 1.4, 4);
                    glVertex3f(13.6, 1.4, 0);
                    // Kaca Depan
                    glColor3ub(20, 20, 20);
                    glVertex3f(13, 3.3, 0);
                    glVertex3f(13, 3.3, 4);
                    glVertex3f(8, 5, 4);
                    glVertex3f(8, 5, 0);
                    // Bumper Depan
                    glColor3ub(5, 5, 5);
                    glVertex3f(13.6, 1.4, 0);
                    glVertex3f(13.6, 1.4, 4);
                    glVertex3f(13.8, 2.2, 4);
                    glVertex3f(13.8, 2.2, 0);
                    // Lampu Belakang
                    glColor3ub(175, 69, 42);
                    glVertex3f(0.3, 2.4, 0);
                    glVertex3f(0.3, 2.4, 4);
                    glVertex3f(0.5, 1.4, 4);
                    glVertex3f(0.5, 1.4, 0);
                    // Belakang
                    glColor3ub(1, 133, 121);
                    glVertex3f(0, 4, 4);
                    glVertex3f(0, 4, 0);
                    glVertex3f(0.3, 2.4, 0);
                    glVertex3f(0.3, 2.4, 4);
                    // Atap
                    glVertex3f(8, 5, 4);
                    glVertex3f(8, 5, 0);
                    glVertex3f(6, 5, 0);
                    glVertex3f(6, 5, 4);
                glEnd();
            glPopMatrix();

            /////////////// Sisi Kiri ///////////////////////
            glPushMatrix();
                glScalef(2, 2, 2);
                glRotated(-90, 0, 1, 0);
                glTranslatef(-10, -0.7, 2);
                glColor3ub(20, 20, 20);
                glBegin(GL_TRIANGLE_STRIP);
                    // Kaca
                    glVertex2f(4, 4.3);
                    glVertex2f(4, 3.7);
                    glVertex2f(6, 4.6);
                    glVertex2f(8, 3.5);
                    glVertex2f(8, 4.7);
                    glVertex2f(12.1, 3.3);
                glEnd();
                // Body
                glColor3ub(100, 100, 100);
                glBegin(GL_QUADS);
                    // Bawah Belakang
                    glVertex2f(0, 4);
                    glVertex2f(0.3, 2.4);
                    glVertex2f(4, 2.3);
                    glVertex2f(4, 3.7);
                    // Bawah Tengah
                    glVertex2f(4, 2.3);
                    glVertex2f(4, 3.7);
                    glVertex2f(12.1, 3.3);
                    glVertex2f(12, 2.2);
                    // Bawah Depan
                    glVertex2f(12.1, 3.3);
                    glVertex2f(12, 2.2);
                    glVertex2f(13.8, 2.2);
                    glVertex2f(14, 3);
                    // Depan Atas
                    glVertex2f(12.1, 3.3);
                    glVertex2f(14, 3);
                    glVertex2f(8, 5);
                    glVertex2f(8, 4.7);
                    // Atas Tengah
                    glVertex2f(8, 5);
                    glVertex2f(8, 4.7);
                    glVertex2f(6, 4.6);
                    glVertex2f(6, 5);
                    // Belakang Tengah
                    glVertex2f(6, 4.6);
                    glVertex2f(6, 5);
                    glVertex2f(4, 4.7);
                    glVertex2f(4, 4.3);
                    // Belakang Atas
                    glVertex2f(4, 4.7);
                    glVertex2f(4, 4.3);
                    glVertex2f(4, 3.7);
                    glVertex2f(0, 4);
                    // Outline Bawah
                    glColor3ub(15, 15, 15);
                    glVertex2f(0.3, 2.4);
                    glVertex2f(0.5, 1.4);
                    glVertex2f(13.6, 1.4);
                    glVertex2f(13.8, 2.2);
                glEnd();
            glPopMatrix();
            
            /////////////////// Sisi Kanan ///////////////////////
            glPushMatrix();
                glScalef(2, 2, 2);
                glRotated(-90, 0, 1, 0);
                glTranslatef(-10, -0.7, -2);
                glColor3ub(20, 20, 20);
                glBegin(GL_TRIANGLE_STRIP);
                    // Kaca
                    glVertex2f(4, 4.3);
                    glVertex2f(4, 3.7);
                    glVertex2f(6, 4.6);
                    glVertex2f(8, 3.5);
                    glVertex2f(8, 4.7);
                    glVertex2f(12.1, 3.3);
                glEnd();
                // Body
                glColor3ub(100, 100, 100);
                glBegin(GL_QUADS);
                    // Bawah Belakang
                    glVertex2f(0, 4);
                    glVertex2f(0.3, 2.4);
                    glVertex2f(4, 2.3);
                    glVertex2f(4, 3.7);
                    // Bawah Tengah
                    glVertex2f(4, 2.3);
                    glVertex2f(4, 3.7);
		            glVertex2f(12.1, 3.3);
                    glVertex2f(12, 2.2);
                    // Bawah Depan
                    glVertex2f(12.1, 3.3);
                    glVertex2f(12, 2.2);
                    glVertex2f(13.8, 2.2);
                    glVertex2f(14, 3);
                    // Depan Atas
                    glVertex2f(12.1, 3.3);
                    glVertex2f(14, 3);
                    glVertex2f(8, 5);
                    glVertex2f(8, 4.7);
                    // Atas Tengah
                    glVertex2f(8, 5);
                    glVertex2f(8, 4.7);
                    glVertex2f(6, 4.6);
                    glVertex2f(6, 5);
                    // Belakang Tengah
                    glVertex2f(6, 4.6);
                    glVertex2f(6, 5);
                    glVertex2f(4, 4.7);
                    glVertex2f(4, 4.3);
                    // Belakang Atas
                    glVertex2f(4, 4.7);
                    glVertex2f(4, 4.3);
                    glVertex2f(4, 3.7);
                    glVertex2f(0, 4);
                    // Outline Bawah
                    glColor3ub(15, 15, 15);
                    glVertex2f(0.3, 2.4);
                    glVertex2f(0.5, 1.4);
                    glVertex2f(13.6, 1.4);
                    glVertex2f(13.8, 2.2);
                glEnd();
            glPopMatrix();
        glPopMatrix();
    glPopMatrix();
}


