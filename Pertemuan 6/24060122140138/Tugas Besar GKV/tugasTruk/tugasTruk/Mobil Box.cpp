/* TUGAS BESAR GKV
NAMA  : 1. Widiawati Sihaloho - 24060122120037
        2. Meyta Rizki Khairunisa - 24060122130085
        3. Adzkiya Qarina Salsabila - 24060122140138
        4. Nabila Betari Anjani - 24060122140169
LAB C2
*/

#include <math.h>
#include <GLUT/glut.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <fstream>
#include "imageloader.h"

#define EN_SIZE 20
GLuint _textureId, _textureIdDepan, _textureIdKanan, _textureIdBelakang, _textureIdKiri, _textureIdAtas; //ID OpenGL untuk tekstur
float angle=0.0, deltaAngle = 0.0, ratio;
const float Z_MIN = -500, Z_MAX = 500;
const float X_MIN = -500, X_MAX = 500;
const float gap = 10;
float x=0.0f,y=50.0f,z=60.0f; // posisi awal kamera
float lx=0.0f,ly=-0.5f,lz=-1.f;
int deltaMove = 0,h,w;
static int rotAngleX =-20, rotAngleY =160, rotAngleZ =0;
float panjang, lebar, tinggi;
const double PI = 3.141592653589793;
int i;

void Reshape(int w1, int h1)
{
    // Fungsi reshape
    if(h1 == 0) h1 = 1;
    w = w1;
    h = h1;
    ratio = 1.0f * w / h;
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glViewport(0, 0, w, h);
    gluPerspective(45,ratio,0.1,1000);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(
    x, y, z,
    x + lx,y + ly,z + lz,
    0.0f,1.0f,0.0f);
}

//Kamera
void orientMe(float ang)
{
    // Fungsi ini untuk memutar arah kamera
    lx = sin(ang);
    lz = -cos(ang);
    glLoadIdentity();
    gluLookAt(x, y, z,
    x + lx,y + ly,z + lz,
    0.0f,1.0f,0.0f);
}

void moveMeFlat(int i)
{
    // Fungsi ini untuk maju mundur kamera
    x = x + i*(lx)*0.1;
    z = z + i*(lz)*0.1;
    glLoadIdentity();
    gluLookAt(x, y, z,
    x + lx,y + ly,z + lz,
    0.0f,1.0f,0.0f);
}
//

void Grid() {
    // Fungsi untuk membuat grid di "lantai"
    double i;
    const float Z_MIN = -50, Z_MAX = 50;
    const float X_MIN = -50, X_MAX = 50;
    const float gap = 1.5;
    glColor3f(0.5, 0.5, 0.5);
    glBegin(GL_LINES);
    for(i=Z_MIN;i<Z_MAX;i+=gap)
    {
        glVertex3f(i, 0, Z_MIN);
        glVertex3f(i, 0, Z_MAX);
    }
    for(i=X_MIN;i<X_MAX;i+=gap)
    {
        glVertex3f(X_MIN, 0, i);
        glVertex3f(X_MAX, 0, i);
    }
    glEnd();
}

void Mobil()
{
    glPushMatrix();
        glRotatef(-90, 0, 1, 0);
        //Mobil depan bawah
        glPushMatrix();
            glTranslatef(0.23,1.5,0);
            glColor3f(0.9, 0.45, 0.1);
            glScalef(3.5, 0.5, 4.5);
            glutSolidCube(1);
        glPopMatrix();
        
        //kaca depan
        glPushMatrix();
            glTranslatef(1.9,4.1,0);
            glColor3f(0.2, 0.4, 0.5);
            glRotated(0, 0, 0, 1);
            glScalef(0.1, 2, 4.5);
            glutSolidCube(1);
        glPopMatrix();
        
        //kaca kanan
        glPushMatrix();
            glTranslatef(0.5,4.1,2.25);
            glColor3f(0.2, 0.4, 0.5);
            glRotated(0, 0, 0, 1);
            glScalef(1.8, 2, 0.01);
            glutSolidCube(1);
        glPopMatrix();
        
        //kaca kiri
        glPushMatrix();
            glTranslatef(0.5,4.1,-2.25);
            glColor3f(0.2, 0.4, 0.5);
            glRotated(0, 0, 0, 1);
            glScalef(1.8, 2, 0.01);
            glutSolidCube(1);
        glPopMatrix();
        
        //bumber
        glPushMatrix();
            glTranslatef(1.9,2.3,0);
            glColor3f(0.9, 0.9, 0.7);
            glRotated(0, 0, 0, 1);
            glScalef(0.1, 0.8, 4.5);
            glutSolidCube(1);
        glPopMatrix();

        //body Mobil
        glPushMatrix();
            glTranslatef(0.27,3.65,0);
            glColor3f(1.0, 0.2, 0.1);
            glScalef(3.2, 3.8, 4.5);
            glutSolidCube(1);
        glPopMatrix();

        // bawah container 1
        glPushMatrix();
            glColor3f(0.4,0.4,0.39);
            glTranslatef(-6.5,1.5,0);
            glScalef(10, 1, 4.5);
            glutSolidCube(1);
        glPopMatrix();

        // container 1
        glPushMatrix();
            glColor3f(0.2,0.2,1.0);
            glTranslatef(-6.5,4.,0);
            glScalef(10, 4, 4.5);
            glutSolidCube(1);
        glPopMatrix();

        
        // ban Mobil depan kanan
        glPushMatrix();
            glColor3f(0.1,0.1,0.1);
            glTranslatef(0.,0.98,2.25);
            glutSolidTorus(0.32, 0.65, 100, 100);
        glPopMatrix();
        
        // ban Mobil depan kiri
        glPushMatrix();
            glColor3f(0.1,0.1,0.1);
            glTranslatef(0.,0.98,-2.25);
            glutSolidTorus(0.32, 0.65, 100, 100);
        glPopMatrix();
        
        // ban container 1 kiri 1
        glPushMatrix();
            glColor3f(0.1,0.1,0.1);
            glTranslatef(-10.,0.98,2.25);
            glutSolidTorus(0.32, 0.65, 100, 100);
        glPopMatrix();
        
        // ban container 1 kiri 2
        glPushMatrix();
            glColor3f(0.1,0.1,0.1);
            glTranslatef(-7.8,0.98,2.25);
            glutSolidTorus(0.32, 0.65, 100, 100);
        glPopMatrix();
        
        // ban container 1 kanan 1
        glPushMatrix();
            glColor3f(0.1,0.1,0.1);
            glTranslatef(-10.,0.98,-2.25);
            glutSolidTorus(0.32, 0.65, 100, 100);
        glPopMatrix();
        
        // ban container 1 kanan 2
        glPushMatrix();
            glColor3f(0.1,0.1,0.1);
            glTranslatef(-7.8,0.98,-2.25);
            glutSolidTorus(0.32, 0.65, 100, 100);
        glPopMatrix();
        
    glPopMatrix();
}

void Roda(float x_roda, float y_roda, float z_roda) {
    glPushMatrix();
    glRotated(90, 0, 0, 1);
    glTranslatef(x_roda,y_roda,z_roda);
    glScalef(3.,3.,3.);
    glColor3ub(40, 40,40);
        // Kanan Kiri Roda
        glPushMatrix();
            glBegin(GL_TRIANGLE_FAN);
            for (int a = 0; a <= 360; a+=1){
                glVertex3f(cos(a), 1, sin(a));
            }
            glEnd();
        glPopMatrix();
            
        glPushMatrix();
            glTranslatef(0.0, 1.0, 0.0);
            glBegin(GL_TRIANGLE_FAN);
            for (int a = 0; a <= 360; a+=1){
                glVertex3f(cos(a), 1, sin(a));
            }
            glEnd();
        glPopMatrix();
            
        // Tengah Roda
        glPushMatrix();
            int b;
            glColor3ub(10, 10, 10);
            glTranslatef(0.0, 1.0, 0.0);
            glBegin(GL_QUAD_STRIP);
            for (b=0; b<=360; b+=1){
                glVertex3f(cos(b), +1, sin(b));
                glVertex3f(cos(b), 0, sin(b));
            }
            glEnd();
        glPopMatrix();
    glPopMatrix();
}


void Environment()
{
    //Grid bawah
    glPushMatrix();
     glEnable(GL_LINE_SMOOTH);
     glColor3ub(100,100,255);
     glLineWidth(1);
         glBegin(GL_LINES);
         for(i=Z_MIN;i<Z_MAX;i+=gap)
         {
             glVertex3f(i, 0, Z_MIN);
             glVertex3f(i, 0, Z_MAX);
         }
         for(i=X_MIN;i<X_MAX;i+=gap)
         {
             glVertex3f(X_MIN, 0, i);
             glVertex3f(X_MAX, 0, i);
         }
         glEnd();
    glPopMatrix();
    
    glPushMatrix();
    glTranslatef(0,0,500);
    glScalef(0.5,0.69,0.7);
        //box depan
        glPushMatrix();
        glEnable(GL_TEXTURE_2D);
        glBindTexture(GL_TEXTURE_2D, _textureIdDepan);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glColor3f(1,1,1);
        glBegin(GL_QUADS);
        glTexCoord2f(0.0f, 0.0f);
        glVertex3f(100.0f, 0.05f, 100.0f);
        glTexCoord2f(1.0f, 0.0f);
        glVertex3f(100.0f,  135, 100.0f);
        glTexCoord2f(1.0f, 1.0f);
        glVertex3f( -100.0f,  135, 100.0f);
        glTexCoord2f(0.0f, 1.0f);
        glVertex3f(-100.0f, 0.05f, 100.0f);
        glEnd();
        glPopMatrix();
        
        //box kiri
        glPushMatrix();
        glEnable(GL_TEXTURE_2D);
        glBindTexture(GL_TEXTURE_2D, _textureIdKiri);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glBegin(GL_QUADS);
        glTexCoord2f(0.0f, 0.0f);
        glVertex3f(200.0f, 0.05f, 100.0f);
        glTexCoord2f(1.0f, 0.0f);
        glVertex3f(200.0f,  135, 100.0f);
        glTexCoord2f(1.0f, 1.0f);
        glVertex3f( 100.0f,  135, 100.0f);
        glTexCoord2f(0.0f, 1.0f);
        glVertex3f(100.0f, 0.05f, 100.0f);
        glEnd();
        glPopMatrix();
        
        //box kanan
        glPushMatrix();
        glEnable(GL_TEXTURE_2D);
        glBindTexture(GL_TEXTURE_2D, _textureIdKanan);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glBegin(GL_QUADS);
        glTexCoord2f(0.0f, 0.0f);
        glVertex3f(-100.0f, 0.05f, 100.0f);
        glTexCoord2f(1.0f, 0.0f);
        glVertex3f(-100.0f,  135, 100.0f);
        glTexCoord2f(1.0f, 1.0f);
        glVertex3f( -200.0f,  135, 100.0f);
        glTexCoord2f(0.0f, 1.0f);
        glVertex3f(-200.0f, 0.05f, 100.0f);
        glEnd();
        glPopMatrix();
    glPopMatrix();
    
    //box belakang
    glPushMatrix();
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, _textureIdBelakang);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glBegin(GL_QUADS);
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(100.0f, 0.05f, -100.0f);
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(100.0f,  135, -100.0f);
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(-100.0f,  135, -100.0f);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(-100.0f, 0.05f, -100.0f);
    glEnd();
    glPopMatrix();
    
        ////////////////////////// LANTAI DI BAWAH GRID ///////////////////////////
    glPushMatrix();
        glColor3ub(210, 180, 140);
        glBegin(GL_QUADS);
        glVertex3f(-500., -0.1, -700.);
        glVertex3f(500., -0.1, -700.);
        glVertex3f(500., -0.1, 700.);
        glVertex3f(-500., -0.1, 700.);
        glEnd();
    glPopMatrix();
}

void Jalan() {
    glPushMatrix(); //Bagian kepala
        panjang = 40;
        lebar = 40;
        tinggi = 0.5;
        glTranslatef(0,0,5);
        glColor3f(0.1f,0.1f,0.1f);
        //depan
        glPushMatrix();
        glTranslatef(0,0,panjang/2);
        glBegin(GL_QUADS);
        glVertex3f(-lebar/2,0.0f,0.0f);
        glVertex3f(lebar/2,0.0f,0.0f);
        glVertex3f(lebar/2,tinggi,0.0f);
        glVertex3f(-lebar/2,tinggi,0.0f);
        glEnd();
        glPopMatrix();
        // atas
        glPushMatrix();
        glRotated(-90, 1, 0, 0);
        glTranslatef(0,0,tinggi);
        glBegin(GL_QUADS);
        glVertex3f(-lebar/2,-panjang/2,0.0f);
        glVertex3f(lebar/2,-panjang/2,0.0f);
        glVertex3f(lebar/2,panjang/2,0.0f);
        glVertex3f(-lebar/2,panjang/2,0.0f);
        glEnd();
        glPopMatrix();
        // belakang
        glPushMatrix();
        glRotated(-180, 1, 0, 0);
        glTranslatef(0,0,panjang/2);
        glBegin(GL_QUADS);
        glTexCoord2f(0.0f,0.0f); // kiri bawah
        glVertex3f(-lebar/2,-tinggi,0.0f);
        glTexCoord2f(1.0f,0.0f); // kanan bawah
        glVertex3f(lebar/2,-tinggi,0.0f);
        glTexCoord2f(1.0f,1.0f); // kanan atas
        glVertex3f(lebar/2,0.0f,0.0f);
        glTexCoord2f(0.0f,1.0f); // kanan bawah
        glVertex3f(-lebar/2,0.0f,0.0f);
        glEnd();
        glPopMatrix();
        // bawah
        glPushMatrix();
        glRotated(90, 1, 0, 0);
        glTranslatef(0,0,0);
        glBegin(GL_QUADS);
        glTexCoord2f(0.0f,0.0f); // kiri bawah
        glVertex3f(-lebar/2,-panjang/2,0.0f);
        glTexCoord2f(1.0f,0.0f); // kanan bawah
        glVertex3f(lebar/2,-panjang/2,0.0f);
        glTexCoord2f(1.0f,1.0f); // kanan atas
        glVertex3f(lebar/2,panjang/2,0.0f);
        glTexCoord2f(0.0f,1.0f); // kanan bawah
        glVertex3f(-lebar/2,panjang/2,0.0f);
        glEnd();
        glPopMatrix();
        // kiri
        glPushMatrix();
        glRotated(-90, 0, 1, 0);
        glTranslatef(0,0,lebar/2);
        glBegin(GL_QUADS);
        glVertex3f(-panjang/2,0.0f,0.0f);
        glVertex3f(panjang/2,0.0f,0.0f);
        glVertex3f(panjang/2,tinggi,0.0f);
        glVertex3f(-panjang/2,tinggi,0.0f);
        glEnd();
        glPopMatrix();
        // kanan
        glPushMatrix();
        glRotated(90, 0, 1, 0);
        glTranslatef(0,0,lebar/2);
        glBegin(GL_QUADS);
        glVertex3f(-panjang/2,0.0f,0.0f);
        glVertex3f(panjang/2,0.0f,0.0f);
        glVertex3f(panjang/2,tinggi,0.0f);
        glVertex3f(-panjang/2,tinggi,0.0f);
        glEnd();
        glPopMatrix();
     glPopMatrix();
     
     glPushMatrix();
        panjang = 6;
        lebar = 1;
        tinggi = 4;
        glRotated(-90,1,0,0);
        glTranslatef(0,-7.5,-2.29);
        glColor3f(1,1,1);
        //depan
        glPushMatrix();
        glTranslatef(0,0,panjang/2);
        glBegin(GL_QUADS);
        glVertex3f(-lebar/2,0.0f,0.0f);
        glVertex3f(lebar/2,0.0f,0.0f);
        glVertex3f(lebar/2,tinggi,0.0f);
        glVertex3f(-lebar/2,tinggi,0.0f);
        glEnd();
        glPopMatrix();
     glPopMatrix();
}

void Tanah() {
    glPushMatrix(); //Bagian kepala
        panjang = 1000;
        lebar = 1000;
        tinggi = 0.2;
        glTranslatef(5,0,1);
        glColor3f(0.92f, 0.50f, 0.18f);
        //depan
        glPushMatrix();
        glTranslatef(0,0,panjang/2);
        glBegin(GL_QUADS);
        glVertex3f(-lebar/2,0.0f,0.0f);
        glVertex3f(lebar/2,0.0f,0.0f);
        glVertex3f(lebar/2,tinggi,0.0f);
        glVertex3f(-lebar/2,tinggi,0.0f);
        glEnd();
        glPopMatrix();
        // atas
        glPushMatrix();
        glRotated(-90, 1, 0, 0);
        glTranslatef(0,0,tinggi);
        glBegin(GL_QUADS);
        glVertex3f(-lebar/2,-panjang/2,0.0f);
        glVertex3f(lebar/2,-panjang/2,0.0f);
        glVertex3f(lebar/2,panjang/2,0.0f);
        glVertex3f(-lebar/2,panjang/2,0.0f);
        glEnd();
        glPopMatrix();
        // belakang
        glPushMatrix();
        glRotated(-180, 1, 0, 0);
        glTranslatef(0,0,panjang/2);
        glBegin(GL_QUADS);
        glTexCoord2f(0.0f,0.0f); // kiri bawah
        glVertex3f(-lebar/2,-tinggi,0.0f);
        glTexCoord2f(1.0f,0.0f); // kanan bawah
        glVertex3f(lebar/2,-tinggi,0.0f);
        glTexCoord2f(1.0f,1.0f); // kanan atas
        glVertex3f(lebar/2,0.0f,0.0f);
        glTexCoord2f(0.0f,1.0f); // kanan bawah
        glVertex3f(-lebar/2,0.0f,0.0f);
        glEnd();
        glPopMatrix();
        // bawah
        glPushMatrix();
        glRotated(90, 1, 0, 0);
        glTranslatef(0,0,0);
        glBegin(GL_QUADS);
        glTexCoord2f(0.0f,0.0f); // kiri bawah
        glVertex3f(-lebar/2,-panjang/2,0.0f);
        glTexCoord2f(1.0f,0.0f); // kanan bawah
        glVertex3f(lebar/2,-panjang/2,0.0f);
        glTexCoord2f(1.0f,1.0f); // kanan atas
        glVertex3f(lebar/2,panjang/2,0.0f);
        glTexCoord2f(0.0f,1.0f); // kanan bawah
        glVertex3f(-lebar/2,panjang/2,0.0f);
        glEnd();
        glPopMatrix();
        // kiri
        glPushMatrix();
        glRotated(-90, 0, 1, 0);
        glTranslatef(0,0,lebar/2);
        glBegin(GL_QUADS);
        glVertex3f(-panjang/2,0.0f,0.0f);
        glVertex3f(panjang/2,0.0f,0.0f);
        glVertex3f(panjang/2,tinggi,0.0f);
        glVertex3f(-panjang/2,tinggi,0.0f);
        glEnd();
        glPopMatrix();
        // kanan
        glPushMatrix();
        glRotated(90, 0, 1, 0);
        glTranslatef(0,0,lebar/2);
        glBegin(GL_QUADS);
        glVertex3f(-panjang/2,0.0f,0.0f);
        glVertex3f(panjang/2,0.0f,0.0f);
        glVertex3f(panjang/2,tinggi,0.0f);
        glVertex3f(-panjang/2,tinggi,0.0f);
        glEnd();
        glPopMatrix();
     glPopMatrix();
     
     glPushMatrix();
        panjang = 6;
        lebar = 1;
        tinggi = 4;
        glRotated(-90,1,0,0);
        glTranslatef(0,-7.5,-2.29);
        glColor3f(1,1,1);
        //depan
        glPushMatrix();
        glTranslatef(0,0,panjang/2);
        glBegin(GL_QUADS);
        glVertex3f(-lebar/2,0.0f,0.0f);
        glVertex3f(lebar/2,0.0f,0.0f);
        glVertex3f(lebar/2,tinggi,0.0f);
        glVertex3f(-lebar/2,tinggi,0.0f);
        glEnd();
        glPopMatrix();
     glPopMatrix();
}
void pohon1()
{
    glPushMatrix();
        glRotatef(0,0,1,0);
        glTranslatef(-40,2,0);
        // daun cone
        glPushMatrix();
        glColor3f(0.0f, 0.3f, 0.0f);
        glTranslatef(0.0f, 3, 0.0f);
        glScaled(4,4,4);
        glRotated(-90,1,0,0);
        glutSolidCone(1,2,60,1);
        glPopMatrix();
    
        // batang
        glPushMatrix();
        glColor3f(0.8f, 0.4f, 0.1f);     // coklat
        glTranslatef(0.0f, 1.5f, 0.0f);
        glScaled(1.1,6,1);
        glutSolidCube(2);
        glPopMatrix();
        glEnd();
    glPopMatrix();
}

void pohon2()
{
    glPushMatrix();
        glRotatef(0,0,1,0);
        glTranslatef(-60,2,0);
        // daun cone
        glPushMatrix();
        glColor3f(0.0f, 0.3f, 0.0f);
        glTranslatef(0.0f, 3, 0.0f);
        glScaled(4,4,4);
        glRotated(-90,1,0,0);
        glutSolidCone(1,2,60,1);
        glPopMatrix();
    
        // batang
        glPushMatrix();
        glColor3f(0.8f, 0.4f, 0.1f);     // coklat
        glTranslatef(0.0f, 1.5f, 0.0f);
        glScaled(1.1,6,1);
        glutSolidCube(2);
        glPopMatrix();
        glEnd();
    glPopMatrix();
}
void pohon3()
{
    glPushMatrix();
        glRotatef(0,0,1,0);
        glTranslatef(-80,2,0);
        // daun cone
        glPushMatrix();
        glColor3f(0.0f, 0.3f, 0.0f);
        glTranslatef(0.0f, 3, 0.0f);
        glScaled(4,4,4);
        glRotated(-90,1,0,0);
        glutSolidCone(1,2,60,1);
        glPopMatrix();
    
        // batang
        glPushMatrix();
        glColor3f(0.8f, 0.4f, 0.1f);     // coklat
        glTranslatef(0.0f, 1.5f, 0.0f);
        glScaled(1.1,6,1);
        glutSolidCube(2);
        glPopMatrix();
        glEnd();
    glPopMatrix();
}

void pohon4()
{
    glPushMatrix();
        glRotatef(0,0,1,0);
        glTranslatef(100,2,0);
        glScaled(3,3,3);
        // daun cone
        glPushMatrix();
        glColor3f(0.0f, 0.3f, 0.0f);
        glTranslatef(0.0f, 3, 0.0f);
        glScaled(4,4,4);
        glRotated(-90,1,0,0);
        glutSolidCone(1,2,60,1);
        glPopMatrix();
    
        // batang
        glPushMatrix();
        glColor3f(0.8f, 0.4f, 0.1f);     // coklat
        glTranslatef(0.0f, 1.5f, 0.0f);
        glScaled(1.1,6,1);
        glutSolidCube(2);
        glPopMatrix();
        glEnd();
    glPopMatrix();
}

void pohon5()
{
    glPushMatrix();
        glRotatef(0,0,1,0);
        glTranslatef(150,2,0);
        glScaled(2.5,2.5,2.5);
        // daun cone
        glPushMatrix();
        glColor3f(0.0f, 0.3f, 0.0f);
        glTranslatef(0.0f, 3, 0.0f);
        glScaled(4,4,4);
        glRotated(-90,1,0,0);
        glutSolidCone(1,2,60,1);
        glPopMatrix();
    
        // batang
        glPushMatrix();
        glColor3f(0.8f, 0.4f, 0.1f);     // coklat
        glTranslatef(0.0f, 1.5f, 0.0f);
        glScaled(1.1,6,1);
        glutSolidCube(2);
        glPopMatrix();
        glEnd();
    glPopMatrix();
}

void gunung1() {
    glPushMatrix();
    glColor3f(0.0f, 0.5f, 0.0f);
    glTranslatef(-120, -2, -20); // Atur posisi gunung di belakang pohon3
    glRotatef(-90, 1, 0, 0); // Putar gunung untuk tampilan 3D
    GLUquadricObj *obj = gluNewQuadric();
    gluQuadricDrawStyle(obj, GLU_FILL);
    gluCylinder(obj, 30, 0, 50, 50, 1); // Gambar gunung sebagai silinder dengan nilai jari-jari awal yang lebih besar dan tinggi yang lebih kecil
    gluDeleteQuadric(obj);
    glPopMatrix();
}
void gunung2() {
    glPushMatrix();
    glColor3f(0.0f, 0.5f, 0.0f);
    glTranslatef(180, -2, -20); // Atur posisi gunung di belakang pohon3
    glRotatef(-90, 1, 0, 0); // Putar gunung untuk tampilan 3D
    GLUquadricObj *obj = gluNewQuadric();
    gluQuadricDrawStyle(obj, GLU_FILL);
    gluCylinder(obj, 30, 0, 50, 50, 1); // Gambar gunung sebagai silinder dengan nilai jari-jari awal yang lebih besar dan tinggi yang lebih kecil
    gluDeleteQuadric(obj);
    glPopMatrix();
}

void LampuJalan() {
    glPushMatrix();
    glTranslatef(30,2,50);
    glRotatef(0,0,1,0);
    // Tiang lampu jalan
    glColor3f(0.5f, 0.5f, 0.5f); // Warna abu-abu
    glPushMatrix();
    glTranslatef(0.0f, 0.0f, 0.0f); // Atur posisi tiang lampu
    glScalef(1.2f, 60.0f, 0.2f); // Ukuran tiang lampu
    glutSolidCube(1.0f); // Gambar tiang lampu sebagai kubus
    glPopMatrix();
    
    // Lampu atas
    glColor3f(1.0f, 1.0f, 0.0f); // Warna kuning untuk lampu atas
    glPushMatrix();
    glTranslatef(0.0f, 20.0f, 0.0f); // Atur posisi lampu atas
    glutSolidSphere(0.5f, 10, 10); // Gambar lampu atas sebagai bola
    glPopMatrix();

    // Lampu tengah
    glColor3f(1.0f, 1.0f, 0.0f); // Warna kuning untuk lampu tengah
    glPushMatrix();
    glTranslatef(0.0f, 15.0f, 0.0f); // Atur posisi lampu tengah
    glutSolidSphere(0.5f, 10, 10); // Gambar lampu tengah sebagai bola
    glPopMatrix();

    // Lampu bawah
    glColor3f(1.0f, 1.0f, 0.0f); // Warna kuning untuk lampu bawah
    glPushMatrix();
    glTranslatef(0.0f, 10.0f, 0.0f); // Atur posisi lampu bawah
    glutSolidSphere(0.5f, 10, 10); // Gambar lampu bawah sebagai bola
    glPopMatrix();
    
}
void ayam() {
    glPushMatrix();
    glColor3f(1.0f, 1.0f, 0.0f); // Warna kuning untuk badan
    glTranslatef(-20.0f, 2.0f, 0.0f);
    glScalef(1.5f, 1.0f, 1.0f);
    glutSolidCube(1.0f);
    glPopMatrix();

    // Kepala ayam
    glPushMatrix();
    glColor3f(1.0f, 1.0f, 0.0f); // Warna kuning untuk kepala
    glTranslatef(-19.0f, 2.75f, 0.0f);
    glutSolidSphere(0.5f, 20, 20);
    glPopMatrix();

    // Paruh ayam
    glPushMatrix();
    glColor3f(1.0f, 0.5f, 0.0f); // Warna oranye untuk paruh
    glTranslatef(-18.6f, 2.75f, 0.0f);
    glRotatef(-90, 0.0f, -1.0f, 0.0f);
    glutSolidCone(0.2f, 0.5f, 20, 20);
    glPopMatrix();

    // Sayap kiri
    glPushMatrix();
    glColor3f(1.0f, 1.0f, 0.0f); // Warna kuning untuk sayap
    glTranslatef(-20.0f, 2.5f, 0.75f);
    glRotatef(45, 1.0f, 0.0f, 0.0f);
    glScalef(0.5f, 1.0f, 0.1f);
    glutSolidCube(1.0f);
    glPopMatrix();

    // Sayap kanan
    glPushMatrix();
    glColor3f(1.0f, 1.0f, 0.0f); // Warna kuning untuk sayap
    glTranslatef(-20.0f, 2.5f, -0.75f);
    glRotatef(-45, 1.0f, 0.0f, 0.0f);
    glScalef(0.5f, 1.0f, 0.1f);
    glutSolidCube(1.0f);
    glPopMatrix();

    // Kaki kiri
    glPushMatrix();
    glColor3f(1.0f, 0.5f, 0.0f); // Warna oranye untuk kaki
    glTranslatef(-20.15f, 1.25f, 0.3f);
    glScalef(0.1f, 1.0f, 0.1f);
    glutSolidCube(1.0f);
    glPopMatrix();

    // Kaki kanan
    glPushMatrix();
    glColor3f(1.0f, 0.5f, 0.0f); // Warna oranye untuk kaki
    glTranslatef(-20.15f, 1.25f, -0.3f);
    glScalef(0.1f, 1.0f, 0.1f);
    glutSolidCube(1.0f);
    glPopMatrix();
}

void rumah(void) {
    glRotatef(-90, 0, -1, 0);
    glTranslatef(-60,2,-10);
    glScaled(4,4,3);
        //atap
        glPushMatrix();
        glScaled(0.8, 1, 0.8);
        glTranslatef(0.0, 4.85, -1.9);
        glRotated(45, 0, 1, 0);
        glRotated(-90, 1, 0, 0);
        glColorMaterial(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE);
        glColor3d(40, 20, 20);
        glutSolidCone(4.2, 1.5, 4, 1);
        glPopMatrix();
         
        //atap
        glPushMatrix();
        glScaled(0.8, 1.0, 0.8);
        glTranslatef(0.0, 4.85, 2.1);
        glRotated(45, 0, 1, 0);
        glRotated(-90, 1, 0, 0);
        glColorMaterial(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE);
        glColor3d(40, 20, 20);
        glutSolidCone(4.2, 1.5, 4, 1);
        glPopMatrix();
         
        //lantai 1
        glPushMatrix();
        glScaled(1.115, 0.03, 2.2);
        glTranslatef(0.0, 0, 0.0);
        glColorMaterial(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE);
        glColor3f(0.3402, 0.3412, 0.3117);
        glutSolidCube(5.0);
        glPopMatrix();
         
        //lantai 2 depan
        glPushMatrix();
        glScaled(1.015, 0.03, 1.2);
        glTranslatef(0.0,80, 1.7);
        glColorMaterial(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE);
        glColor3f(0.4613, 0.4627, 0.4174);
        glutSolidCube(5.0);
        glPopMatrix();
         
        //lantai 2 belakang
        glPushMatrix();
        glScaled(0.5, 0.03, 0.8);
        glTranslatef(2.5,80, -2.8);
        glColorMaterial(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE);
        glColor3f(0.4613, 0.4627, 0.4174);
        glutSolidCube(5.0);
        glPopMatrix();
         
        //lantai 3
        glPushMatrix();
        glScaled(1.015, 0.03, 1.8);
        glTranslatef(0.0,160, 0.3);
        glColorMaterial(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE);
        glColor3f(0.3402, 0.3412, 0.3117);
        glutSolidCube(5.0);
        glPopMatrix();
         
        //Dinding Kiri Bawah
        glPushMatrix();
        glScaled(0.035, 0.5, 1.6);
        glTranslatef(-70.0, 2.45, 0.0);
        glColorMaterial(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE);
        glColor3f(0.4613, 0.4627, 0.4174);
        glutSolidCube(5.0);
        glPopMatrix();
         
        //Dinding Kanan Bawah
        glPushMatrix();
        glScaled(0.035, 0.5, 1.6);
        glTranslatef(70.0, 2.45, 0.0);
        glColorMaterial(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE);
        glColor3f(0.4613, 0.4627, 0.4174);
        glutSolidCube(5.0);
        glPopMatrix();
         
        //Dinding Kiri Atas
        glPushMatrix();
        glScaled(0.035, 0.5, 1.8);
        glTranslatef(-70.0, 7.45, 0.3);
        glColorMaterial(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE);
        glColor3f(0.4613, 0.4627, 0.4174);
        glutSolidCube(5.0);
        glPopMatrix();
         
        //Dinding Kanan Atas
        glPushMatrix();
        glScaled(0.035, 0.5, 1.8);
        glTranslatef(70.0, 7.45, 0.3);
        glColorMaterial(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE);
        glColor3f(0.4613, 0.4627, 0.4174);
        glutSolidCube(5.0);
        glPopMatrix();
         
        //Dinding Belakang bawah
        glPushMatrix();
        //glScaled(0.035, 0.5, 0.8);
        glScaled(1.015, 0.5, 0.07);
        glTranslatef(0, 2.45,-58);
        glColorMaterial(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE);
        glColor3f(0.4613, 0.4627, 0.4174);
        glutSolidCube(5.0);
        glPopMatrix();
         
        //Dinding Belakang atas
        glPushMatrix();
        //glScaled(0.035, 0.5, 0.8);
        glScaled(1.015, 0.5, 0.07);
        glTranslatef(0, 7.45,-58);
        glColorMaterial(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE);
        glColor3f(0.4613, 0.4627, 0.4174);
        glutSolidCube(5.0);
        glPopMatrix();
         
        //Dinding Depan bawah
        glPushMatrix();
        glScaled(1.015, 0.5, 0.035);
        glTranslatef(0, 2.45,116);
        glColorMaterial(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE);
        glColor3f(0.4613, 0.4627, 0.4174);
        glutSolidCube(5.0);
        glPopMatrix();
         
        //Dinding Depan atas
        glPushMatrix();
        glScaled(1.015, 0.5, 0.035);
        glTranslatef(0, 7.45,116);
        glColorMaterial(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE);
        glColor3f(0.4613, 0.4627, 0.4174);
        glutSolidCube(5.0);
        glPopMatrix();
         
        //list hitam atas
        glPushMatrix();
        glScaled(0.35, 0.5, 0.035);
        glTranslatef(1, 7.2,124);
        glColorMaterial(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE);
        glColor3f(0.1412, 0.1389, 0.1356);
        glutSolidCube(5.0);
        glPopMatrix();
         
        //list hitam atas
        glPushMatrix();
        glScaled(0.35, 0.43, 0.035);
        glTranslatef(1, 3.5,124);
        glColorMaterial(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE);
        glColor3f(0.1412, 0.1389, 0.1356);
        glutSolidCube(5.0);
        glPopMatrix();
         
        //pintu atas
        glPushMatrix();
        glScaled(0.18, 0.35, 0.035);
        glTranslatef(-8, 9.5,118);
        glColorMaterial(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE);
        glColor3f(0.0980, 0.0608, 0.0077);
        glutSolidCube(5.0);
        glPopMatrix();
         
        //pintu bawah
        glPushMatrix();
        glScaled(0.18, 0.35, 0.035);
        glTranslatef(-8, 2.5,118);
        glColorMaterial(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE);
        glColor3f(0.0980, 0.0608, 0.0077);
        glutSolidCube(5.0);
        glPopMatrix();
         
        //alis
        glPushMatrix();
        glScaled(0.18, 0.017, 0.035);
        glTranslatef(-8, 110.5,118);
        glColorMaterial(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE);
        glColor3f(0, 0, 0);
        glutSolidCube(5.0);
        glPopMatrix();
         
        //alis atas kiri
        glPushMatrix();
        glScaled(0.18, 0.017, 0.035);
        glTranslatef(-8, 254,118);
        glColorMaterial(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE);
        //glColor3f(0.3402, 0.3412, 0.3117);
        glColor3f(0, 0, 0);
        glutSolidCube(5.0);
        glPopMatrix();
         
        //alis atas kanan
        glPushMatrix();
        glScaled(0.10, 0.017, 0.035);
        glTranslatef(18, 254,118);
        glColorMaterial(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE);
        glColor3f(0, 0, 0);
        glutSolidCube(5.0);
        glPopMatrix();
         
        //alis jedela atas
        glPushMatrix();
        glScaled(0.08, 0.017, 0.035);
        glTranslatef(22.5, 245,118);
        glColorMaterial(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE);
        glColor3f(0.3402, 0.3412, 0.3117);
        glutSolidCube(5.0);
        glPopMatrix();
         
        //alis jedela bawah
        glPushMatrix();
        glScaled(0.08, 0.017, 0.035);
        glTranslatef(22.5, 165,118);
        glColorMaterial(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE);
        glColor3f(0.3402, 0.3412, 0.3117);
        glutSolidCube(5.0);
        glPopMatrix();
         
        //alis jedela kiri
        glPushMatrix();
        glScaled(0.017,0.28, 0.035);
        glTranslatef(96.6, 12.5,118);
        glColorMaterial(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE);
        glColor3f(0.3402, 0.3412, 0.3117);
        glutSolidCube(5.0);
        glPopMatrix();
         
        //alis jedela kanan
        glPushMatrix();
        glScaled(0.017,0.28, 0.035);
        glTranslatef(115.1, 12.5,118);
        glColorMaterial(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE);
        glColor3f(0.3402, 0.3412, 0.3117);
        glutSolidCube(5.0);
        glPopMatrix();
         
        //jendela bawah (kanan Bawah)
        //alis atas kanan (kanan Bawah)
        glPushMatrix();
        glScaled(0.10, 0.017, 0.035);
        glTranslatef(18, 110.5,118);
        glColorMaterial(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE);
        glColor3f(0, 0, 0);
        glutSolidCube(5.0);
        glPopMatrix();
         
        //alis jedela atas (kanan Bawah)
        glPushMatrix();
        glScaled(0.08, 0.017, 0.035);
        glTranslatef(22.5, 101.5,118);
        glColorMaterial(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE);
        glColor3f(0.3402, 0.3412, 0.3117);
        glutSolidCube(5.0);
        glPopMatrix();
         
        //alis jedela bawah (kanan Bawah)
        glPushMatrix();
        glScaled(0.08, 0.017, 0.035);
        glTranslatef(22.5, 22.0,118);
        glColorMaterial(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE);
        glColor3f(0.3402, 0.3412, 0.3117);
        glutSolidCube(5.0);
        glPopMatrix();
         
        //alis jedela kiri (kanan Bawah)
        glPushMatrix();
        glScaled(0.017,0.28, 0.035);
        glTranslatef(96.6, 3.8,118);
        glColorMaterial(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE);
        glColor3f(0.3402, 0.3412, 0.3117);
        glutSolidCube(5.0);
        glPopMatrix();
         
        //alis jedela kanan (kanan Bawah)
        glPushMatrix();
        glScaled(0.017,0.28, 0.035);
        glTranslatef(115.1, 3.8,118);
        glColorMaterial(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE);
        glColor3f(0.3402, 0.3412, 0.3117);
        glutSolidCube(5.0);
        glPopMatrix();
         
        //alis jedela atas (tengah1)
        glPushMatrix();
        glScaled(0.08, 0.017, 0.035);
        glTranslatef(0, 119.5,128);
        glColorMaterial(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE);
        glColor3f(1.0000, 0.5252, 0.0157);
        glutSolidCube(5.0);
        glPopMatrix();
         
        //alis jedela bawah (tengah1)
        glPushMatrix();
        glScaled(0.08, 0.017, 0.035);
        glTranslatef(0, 40.0,128);
        glColorMaterial(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE);
        glColor3f(1.0000, 0.5252, 0.0157);
        glutSolidCube(5.0);
        glPopMatrix();
         
        //alis jedela kiri (tengah1)
        glPushMatrix();
        glScaled(0.017,0.28, 0.035);
        glTranslatef(-9.6, 4.8,128);
        glColorMaterial(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE);
        glColor3f(1.0000, 0.5252, 0.0157);
        glutSolidCube(5.0);
        glPopMatrix();
         
        //alis jedela kanan (tengah1)
        glPushMatrix();
        glScaled(0.017,0.28, 0.035);
        glTranslatef(9.5, 4.8,128);
        glColorMaterial(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE);
        glColor3f(1.0000, 0.5252, 0.0157);
        glutSolidCube(5.0);
        glPopMatrix();
         
        //alis jedela atas (tengah2)
        glPushMatrix();
        glScaled(0.08, 0.017, 0.035);
        glTranslatef(9, 119.5,128);
        glColorMaterial(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE);
        glColor3f(1.0000, 0.5252, 0.0157);
        glutSolidCube(5.0);
        glPopMatrix();
         
        //alis jedela bawah (tengah2)
        glPushMatrix();
        glScaled(0.08, 0.017, 0.035);
        glTranslatef(9, 40.0,128);
        glColorMaterial(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE);
        glColor3f(1.0000, 0.5252, 0.0157);
        glutSolidCube(5.0);
        glPopMatrix();
         
        //alis jedela kiri (tengah2)
        glPushMatrix();
        glScaled(0.017,0.28, 0.035);
        glTranslatef(33, 4.8,128);
        glColorMaterial(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE);
        glColor3f(1.0000, 0.5252, 0.0157);
        glutSolidCube(5.0);
        glPopMatrix();
         
        //alis jedela kanan (tengah2)
        glPushMatrix();
        glScaled(0.017,0.28, 0.035);
        glTranslatef(51.7, 4.8,128);
        glColorMaterial(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE);
        glColor3f(1.0000, 0.5252, 0.0157);
        glutSolidCube(5.0);
        glPopMatrix();
         
        //alis tiang kiri atas orange
        glPushMatrix();
        glScaled(0.06, 0.037, 0.095);
        glTranslatef(-41, 115,51.5);
        glColorMaterial(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE);
        glColor3f(1.0000, 0.5252, 0.0157);
        glutSolidCube(5.0);
        glPopMatrix();
         
        //alis tiang kiri bawah orange
        glPushMatrix();
        glScaled(0.06, 0.037, 0.095);
        glTranslatef(-41, 80,51.5);
        glColorMaterial(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE);
        glColor3f(1.0000, 0.5252, 0.0157);
        glutSolidCube(5.0);
        glPopMatrix();
         
        //alis tiang kanan atas orange
        glPushMatrix();
        glScaled(0.06, 0.037, 0.095);
        glTranslatef(41, 115,51.5);
        glColorMaterial(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE);
        glColor3f(1.0000, 0.5252, 0.0157);
        glutSolidCube(5.0);
        glPopMatrix();
         
        //alis tiang kanan bawah orange
        glPushMatrix();
        glScaled(0.06, 0.037, 0.095);
        glTranslatef(41, 80,51.5);
        glColorMaterial(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE);
        glColor3f(1.0000, 0.5252, 0.0157);
        glutSolidCube(5.0);
        glPopMatrix();
         
        //orange 3 di tengah
        glPushMatrix();
        glScaled(0.017,0.33, 0.035);
        glTranslatef(-16.6, 12,125);
        glColorMaterial(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE);
        glColor3f(1.0000, 0.5252, 0.0157);
        glutSolidCube(5.0);
        glPopMatrix();
         
        //orange 3 di tengah
        glPushMatrix();
        glScaled(0.017,0.33, 0.035);
        glTranslatef(-6.6, 12,125);
        glColorMaterial(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE);
        glColor3f(1.0000, 0.5252, 0.0157);
        glutSolidCube(5.0);
        glPopMatrix();
         
        //orange 3 di tengah
        glPushMatrix();
        glScaled(0.017,0.33, 0.035);
        glTranslatef(3.6, 12,125);
        glColorMaterial(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE);
        glColor3f(1.0000, 0.5252, 0.0157);
        glutSolidCube(5.0);
        glPopMatrix();
         
        //pagar atas 1
        glPushMatrix();
        glScaled(.88, 0.017, 0.017);
        glTranslatef(-.01, 149,290);
        glColorMaterial(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE);
        glColor3f(1,1,1);
        glutSolidCube(5.0);
        glPopMatrix();
         
        //pagar atas 1
        glPushMatrix();
        glScaled(.88, 0.017, 0.017);
        glTranslatef(-.01, 159,290);
        glColorMaterial(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE);
        glColor3f(1.0000, 0.5252, 0.0157);
        glutSolidCube(5.0);
        glPopMatrix();
         
        //pagar atas 1
        glPushMatrix();
        glScaled(.88, 0.017, 0.017);
        glTranslatef(-.01, 169,290);
        glColorMaterial(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE);
        glColor3f(1,1,1);
        glutSolidCube(5.0);
        glPopMatrix();
         
        //pagar atas 1
        glPushMatrix();
        glScaled(.88, 0.017, 0.017);
        glTranslatef(-.01, 179,290);
        glColorMaterial(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE);
        glColor3f(0.3402, 0.3412, 0.3117);
        glutSolidCube(5.0);
        glPopMatrix();
         
        //lampu kanan atas
        glPushMatrix();
        glScaled(0.05, 0.05, 0.05);
        glTranslatef(34.5, 95.4, 96);
        glColorMaterial(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE); //untuk memunculkan warna
        glColor3ub(252, 243, 169);
        glutSolidSphere(2.0,20,50);
        glPopMatrix();
         
        //lampu kiri atas
        glPushMatrix();
        glScaled(0.05, 0.05, 0.05);
        glTranslatef(-32.5, 95.4, 96);
        glColorMaterial(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE);
        glColor3ub(252, 243, 169);
        glutSolidSphere(2.0,20,50);
        glPopMatrix();
         
        //lampu kanan atas
        glPushMatrix();
        glScaled(0.05, 0.05, 0.05);
        glTranslatef(34.5, 47, 96);
        glColorMaterial(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE); //untuk memunculkan warna
        glColor3ub(252, 243, 169);
        glutSolidSphere(2.0,20,50);
        glPopMatrix();
         
        //lampu kiri atas
        glPushMatrix();
        glScaled(0.05, 0.05, 0.05);
        glTranslatef(-32.5, 47, 96);
        glColorMaterial(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE);
        glColor3ub(252, 243, 169);
        glutSolidSphere(2.0,20,50);
        glPopMatrix();
         
        //pagar bawah
        glPushMatrix();
        glScaled(.7, 0.017, 0.017);
        glTranslatef(1, 50,400);
        glColorMaterial(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE);
        glColor3f(1,1,1);
        glutSolidCube(5.0);
        glPopMatrix();
         
        //pagar bawah
        glPushMatrix();
        glScaled(.7, 0.017, 0.017);
        glTranslatef(1, 40,400);
        glColorMaterial(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE);
        glColor3f(1,1,1);
        glutSolidCube(5.0);
        glPopMatrix();
         
        //pagar bawah
        glPushMatrix();
        glScaled(.7, 0.017, 0.017);
        glTranslatef(1, 30,400);
        glColorMaterial(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE);
        glColor3f(1,1,1);
        glutSolidCube(5.0);
        glPopMatrix();
         
        //pagar bawah
        glPushMatrix();
        glScaled(.7, 0.017, 0.017);
        glTranslatef(1, 20,400);
        glColorMaterial(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE);
        glColor3f(1,1,1);
        glutSolidCube(5.0);
        glPopMatrix();
         
        //pagar bawah
        glPushMatrix();
        glScaled(.7, 0.017, 0.017);
        glTranslatef(1, 10,400);
        glColorMaterial(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE);
        glColor3f(1,1,1);
        glutSolidCube(5.0);
        glPopMatrix();
         
        // Batang Tiang Kanan
        glPushMatrix();
        glScaled(0.06, 0.2,0.06);
        glTranslatef(43, 3,115.5);
        glColorMaterial(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE);
        glColor3f(1.0000, 0.5252, 0.0157);
        glutSolidCube(5.0);
        glPopMatrix();
         
        // Batang Tiang Kiri 1
        glPushMatrix();
        glScaled(0.06, 0.2,0.06);
        glTranslatef(-42, 3,115.5);
        glColorMaterial(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE);
        glColor3f(1.0000, 0.5252, 0.0157);
        glutSolidCube(5.0);
        glPopMatrix();
         
        // Batang Tiang Kiri 2
        glPushMatrix();
        glScaled(0.06, 0.2,0.06);
        glTranslatef(-20, 3,115.5);
        glColorMaterial(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE);
        glColor3f(1.0000, 0.5252, 0.0157);
        glutSolidCube(5.0);
        glPopMatrix();
        
    glEnd();
    glPopMatrix();
}

void bukit() {
    glPushMatrix();
        glRotatef(-90, 0, 0, 0);
        glTranslatef(100,2,0);
        // Segitiga 1
        glColor3f(0.0, 1.0, 0.0); // Warna hijau
        glBegin(GL_TRIANGLES);
        glVertex3f(-5.0, 0.0, 0.0);
        glVertex3f(5.0, 0.0, 0.0);
        glVertex3f(0.0, 3.0, 0.0);
        glEnd();
    
        // Segitiga 2
        glColor3f(0.0, 0.8, 0.0); // Warna hijau yang lebih gelap
        glBegin(GL_TRIANGLES);
        glVertex3f(-4.0, 0.0, 0.0);
        glVertex3f(4.0, 0.0, 0.0);
        glVertex3f(0.0, 2.5, 0.0);
        glEnd();
    
        // Segitiga 3
        glColor3f(0.0, 0.6, 0.0); // Warna hijau yang lebih gelap lagi
        glBegin(GL_TRIANGLES);
        glVertex3f(-3.0, 0.0, 0.0);
        glVertex3f(3.0, 0.0, 0.0);
        glVertex3f(0.0, 2.0, 0.0);
        glEnd();
    glPopMatrix();
}

// Fungsi untuk membuat Cone
void Cone() {
    glPushMatrix();
    glColor3ub(255, 60, 0);
    
    glPushMatrix();
    glTranslatef(5, 0, 70);
    glRotatef(-90, 1, 0, 0);
    glutSolidCone(3, 8, 20, 20);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(5, 0.8, 70);
    glRotatef(-90, 1, 0, 0);
    glBegin(GL_TRIANGLE_FAN);
    glVertex3f(0, 0, 0);
    int numSegments = 50;
    float radius = 5.0f;
    for (int i = 0; i <= numSegments; ++i) {
        float angle = i * 2.0f * M_PI / numSegments;
        float x = radius * cosf(angle);
        float y = radius * sinf(angle);
        glVertex3f(x, y, 0);
    }
    glEnd();
    glPopMatrix();

    glPopMatrix();
}


//////////////////////////Start////////////////////////////
int belok = 0;
float angMobil = 0.0;
float posZCone = 100;
int ujungCone = 0;
float speed = 0;
float posZJalan = -1000;
int ujung = 0;
float posZPohon = -100;
int ujungPohon = 0;

///////Pergerakan pada Mobil//////////////////////////////////////////////////////
float posXMobil = 0.0, posZMobil = 0.0;
void MobilMove()
{
    //Belok kanan
    if (belok == -1){
        if (angMobil>= -10){
            angMobil -= 2;
        }
        if (angMobil < -9.9){
            belok = -2;
        }
    }
    if (belok <= -2){
        if (angMobil <= -0.5){
            angMobil += 2;
            posXMobil -= 1;
        }
        if (angMobil > -0.1){
            belok = 0;
        }
    }
    
    //Belok kiri
    if (belok == 1){
        if (angMobil <= 10){
            angMobil += 2;
        }
        if (angMobil > 9.9){
            belok = 2;
        }
    }
    if (belok >= 2){
        if (angMobil >= 0.5){
            angMobil -= 2;
            posXMobil += 1;
        }
        if (angMobil < 0.1){
            belok = 0;
        }
    }
}

///////Pergerakan pada Pohon /////////////
void PohonMove()
{
    if(ujungPohon == 0)
    {
        posZPohon -= speed; //Kecepatan jalan
    } else
    {
        posZPohon = -100;
        ujungPohon = 0;
    }
    
    if(posZPohon <= -400) ujungPohon = 1;
}

///////Pergerakan pada jalan /////////////
void PergerakanJalan()
{
    //jika jalan belom mencapai ujung
    if(ujung == 0)
    {
        posZJalan -= speed; //Kecepatan jalan
    } else
    {
        posZJalan = -100;
        ujung = 0;
    }
    
    if(posZJalan <= -400) {
        ujung = 1;
    }
    if(speed >= 10){
        speed = 9;
    }
}

///////Pergerakan pada Cone /////////////
void ConeMove(){
    if(ujungCone == 0)
    {
        posZCone -= speed; //Kecepatan jalan
    } else
    {
        posZCone = 100;
        ujungCone = 0;
    }
    
    if(posZCone <= -400) {
        ujungCone = 1;
    }
}

///////Jika tabrak Cone /////////////
bool touch = false;

void isTouch(){
    if ((posZMobil< posZCone+80 and posZMobil > posZCone +64) and (posXMobil >= -8 and posXMobil <= 5)){
        touch = true;
    }
}

//Mengatur transformasi dan pergerakan objek-objek
void Object()
{
    glPushMatrix();
        glPushMatrix();
            MobilMove();
            glRotatef(angMobil,0,1,0);
            glTranslatef(posXMobil,0, posZMobil);
            Mobil();
        glPopMatrix();
    glPopMatrix();
    
    
    glPushMatrix();
    int a;
    PergerakanJalan();
    for(a = 180; a > 0; a -= 1){
        glPushMatrix();
            glTranslatef(-4,0,posZJalan+(a*5));
            Jalan();
        glPopMatrix();
    }
    glPopMatrix();
    
    glPushMatrix();
    int b;
    PohonMove();
    for(b = 20; b > 0; b -= 1){
        glPushMatrix();
            glTranslatef(-4,0,posZPohon+(b*50));
            pohon1();
            pohon2();
            pohon3();
            pohon4();
            pohon5();
            gunung1();
            gunung2();
            Tanah();
            ayam();
            LampuJalan();
            glPushMatrix();
            glTranslatef(0,0,-100);
            glRotated(180,0,1,0);
            rumah();
            glPopMatrix();
        glPopMatrix();
    }
    glPopMatrix();

    glPushMatrix();
        ConeMove();
        glTranslatef(-4,0,posZCone);
        Cone();
        glPushMatrix();
        glTranslatef(-15,0,0);
        Cone();
        glPopMatrix();
    glPopMatrix();
}

//Teks 3D
void drawStrokeText2(char* str,int x,int y,int z)
{
      char *c;
      glPushMatrix();
      glTranslatef(x, y+8,z);
      glScalef(0.05f,0.05f,0.02f);

      for (c=str; *c != '\0'; c++)
      {
            glutStrokeCharacter(GLUT_STROKE_ROMAN , *c);
      }
      glPopMatrix();
}

//Tampilan
void display() {
    if (deltaMove)
    moveMeFlat(deltaMove);
    if (deltaAngle) {
        angle += deltaAngle;
        orientMe(angle);
    }
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glPushMatrix();
    glRotated(rotAngleX+10, 1, 0, 0);
     glRotated(rotAngleY, 0, 1, 0);
     glRotated(rotAngleZ, 0, 0, 1);
    isTouch();
    if (touch){
        Mobil();
        drawStrokeText2("Hati-hati dijalan",-23,3,0);
        glRotated(180,0,1,0);
        drawStrokeText2("Game Over",-23,10,0);
        rotAngleY-=1;
         glClearColor(1,1,1,1);
    } else {
         Environment();
         Object();
          glClearColor(0,0,0,1);
    }
     glPopMatrix();
     glFlush();
     glutSwapBuffers();
}

//Keyboard
void pressKey(int key, int x, int y) {
    switch (key) {
        case GLUT_KEY_LEFT : deltaAngle = -0.01f;break;
        case GLUT_KEY_RIGHT : deltaAngle = 0.01f;break;
        case GLUT_KEY_UP : deltaMove = 1;break;
        case GLUT_KEY_DOWN : deltaMove = -1;break;
    }
}

void releaseKey(int key, int x, int y) {
    switch (key) {
        case GLUT_KEY_LEFT :
        if (deltaAngle < 0.0f)
        deltaAngle = 0.0f;
        break;
        case GLUT_KEY_RIGHT : if (deltaAngle > 0.0f)
        deltaAngle = 0.0f;
        break;
        case GLUT_KEY_UP : if (deltaMove > 0)
        deltaMove = 0;
        break;
        case GLUT_KEY_DOWN : if (deltaMove < 0)
        deltaMove = 0;
        break;
    }
}
void keyboard(unsigned char key, int x, int y)
{
    switch (key)
    {
        case 'a':
            belok++; break;
        case 'd':
            belok--; break;
        case 'w':
            posZMobil++; speed++; break;
        case 's':
            posZMobil--; speed--; break;
        case 'i':
            rotAngleX -= 10; break;
        case 'k':
            rotAngleX += 10; break;
        case 'j':
            rotAngleY -= 10; break;
        case 'l':
            rotAngleY += 10; break;
        case 27:
            exit(0);
        default:
            break;
    } glutPostRedisplay();
}

GLUquadricObj *IDquadric;
// Variable untuk pencahayaan
const GLfloat light_ambient[] = { 0.5f, 0.5f, 0.5f, 0.0f };
const GLfloat light_diffuse[] = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat light_specular[] = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat light_position[] = { 0.0f, 20.0f, 10.0f, 1.0f };
const GLfloat mat_ambient[] = { 0.7f, 0.7f, 0.7f, 1.0f };
const GLfloat mat_diffuse[] = { 0.8f, 0.8f, 0.8f, 1.0f };
const GLfloat mat_specular[] = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat high_shininess[] = { 100.0f };


void lighting(){
     // Fungsi mengaktifkan pencahayaan
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LESS);
    glEnable(GL_LIGHT0);
    glEnable(GL_NORMALIZE);
    glEnable(GL_COLOR_MATERIAL);
    glEnable(GL_LIGHTING);
    glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);
    glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
    glLightfv(GL_LIGHT0, GL_POSITION, light_position);
    glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, high_shininess);
}

GLuint loadTexture(Image* image) {
    // Fungsi menginisialisasi ID OpenGL tekstur
    GLuint textureId;
    glGenTextures(1, &textureId);
    glBindTexture(GL_TEXTURE_2D, textureId);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, image->width, image->height, 0, GL_RGB, GL_UNSIGNED_BYTE, image->pixels);
    return textureId;
}

void init(void)
{
     glEnable (GL_DEPTH_TEST);
     glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
     IDquadric=gluNewQuadric();      // Create A Pointer To The Quadric Object ( NEW )
      gluQuadricNormals(IDquadric, GLU_SMOOTH);  // Create Smooth Normals ( NEW )
      gluQuadricTexture(IDquadric, GL_TRUE);    // Create Texture Coords ( NEW )
      Image* imagedepan = loadBMP("tengah.bmp");
      Image* imagekiri = loadBMP("kiri.bmp");
      Image* imagekanan = loadBMP("kanan.bmp");
    _textureIdDepan = loadTexture(imagedepan);
    _textureIdKanan = loadTexture(imagekiri);
    _textureIdKiri = loadTexture(imagekanan);
    delete imagedepan;
    delete imagekiri;
    delete imagekanan;
}

int main(int argc, char **argv)
{

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
    glutInitWindowPosition(50,50);
    glutInitWindowSize(900,700);
    glutCreateWindow("Mobil Boxx");
    glutIgnoreKeyRepeat(1);
    glutSpecialFunc(pressKey);
    glutSpecialUpFunc(releaseKey);
    glutDisplayFunc(display);
    glutIdleFunc(display);
    glutKeyboardFunc(keyboard);
    glutReshapeFunc(Reshape);
    lighting();
    init();
    glutMainLoop();
    return(0);
}

