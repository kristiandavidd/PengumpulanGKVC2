// Nama : Adzkiya Qarina Salsabila
// NIM  : 24060122140138
// Lab  : C2

#include <iostream>
#include <math.h>
#include <GLUT/glut.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

using namespace std;

float rotangle=0.0;
float rotangle1=0.0;
float angle=0.0, deltaAngle = 0.0, ratio;
float x=0.0f,y=1.75f,z=15.0f; // Merupakan posisi awal kamera
float lx=0.0f,ly=0.0f,lz=-1.0f;
int deltaMove = 0,h,w;
int bitmapHeight=12;
const double PHI = 3.141592653589793;
int i,j,radius,jumlah_titik,x_tengah,y_tengah;

void Reshape(int w1, int h1) {
    // Fungsi reshape
    if(h1 == 0) h1 = 1;
    w = w1;
    h = h1;
    float aspectRatio = 1.0f * w / h;
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glViewport(0, 0, w, h);
    gluPerspective(45, aspectRatio, 0.1, 1000);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(
    x, y, z,
    x + lx,y + ly,z + lz,
    0.0f,1.0f,0.0f);
}

void orientMe(float ang) {
    // Fungsi untuk memutar arah kamera (tengok kiri/kanan)
    lx = sin(ang);
    lz = -cos(ang);
    glLoadIdentity();
    gluLookAt(x, y, z,
    x + lx,y + ly,z + lz,
    0.0f,1.0f,0.0f);
}

void moveMeFlat(int i) {
    // Fungsi untuk maju mundur kamera
    x = x + i*(lx)*0.1;
    z = z + i*(lz)*0.1;
    glLoadIdentity();
    gluLookAt(x, y, z,
    x + lx,y + ly,z + lz,
    0.0f,1.0f,0.0f);
}

void Grid() {
    // Fungsi untuk membuat grid di "lantai"
    double i;
    const float Z_MIN = -50, Z_MAX = 50;
    const float X_MIN = -50, X_MAX = 50;
    const float gap = 1.5;
    glColor3f(0.8, 0.8, 0.8);
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

void Roda() {
    glPushMatrix();
        for(int j=0; j<=360; j++) {
            glPushMatrix();
                glTranslatef(1,0,-0.5);
                glRotated(90,1,0,0);
                glRotated(j,0,1,0);
                glTranslatef(0,3,0.8);
                glColor3f(0.3,0.3,0.3);
                glBegin(GL_QUADS);
                glVertex3f(0,0,0);
                glVertex3f(0.1,0,0);
                glVertex3f(0.1,0.6,0);
                glVertex3f(0,0.6,0);
                glEnd();
            glPopMatrix();
        }
    glPopMatrix();

    // lingkaran depan
    glPushMatrix();
        glTranslatef(0,0,3.1);
        glColor3f(0.3,0.3,0.3);
        glBegin(GL_TRIANGLE_FAN);
        radius=80;
        jumlah_titik=20;
        x_tengah=100;
        y_tengah=0;
        for (i=0; i<=360; i++) {
            float sudut=i*(2*PHI/jumlah_titik);
            float x=x_tengah+radius*cos(sudut);
            float y=y_tengah+radius*sin(sudut);
            glVertex2f(x/100,y/100);
        }
        glEnd();
    glPopMatrix();

    // lingkaran belakang
    glPushMatrix();
        glTranslatef(0,0,2.5);
        glRotated(180,1,0,0);
        glColor3f(0.3,0.3,0.3);
        glBegin(GL_TRIANGLE_FAN);
        radius=80;
        jumlah_titik=20;
        x_tengah=100;
        y_tengah=0;
        for (i=0; i<=360; i++) {
            float sudut=i*(2*PHI/jumlah_titik);
            float x=x_tengah+radius*cos(sudut);
            float y=y_tengah+radius*sin(sudut);
            glVertex2f(x/100,y/100);
        }
        glEnd();
    glPopMatrix();
}

void TruckGandeng() {
    glPushMatrix();
        // Bagian depan
        glPushMatrix();
            glTranslatef(0.23,2,0);
            glColor3f(1.0f, 0.4f, 0.0f);
            glScalef(3.5, 2, 4.5);
            glutSolidCube(1);
        glPopMatrix();

        glPushMatrix();
            glTranslatef(1.39,3.8,0);
            glRotated(30, 0, 0, 1);
            glScalef(0.2, 2, 4.5);
            glutSolidCube(1);
        glPopMatrix();

        // Bagian atas
        glPushMatrix();
            glTranslatef(-0.27,3.83,0);
            glScalef(2.5, 1.8, 4.5);
            glutSolidCube(1);
        glPopMatrix();

        // Bagian gandeng 1
        glPushMatrix();
            glColor3f(0,0,0);
            glTranslatef(-6.5,1.5,0);
            glScalef(10, 1, 4.5);
            glutSolidCube(1);
        glPopMatrix();

        // Bagian container 1
        glPushMatrix();
            glColor3f(0.9f, 0.6f, 0.f);
            glTranslatef(-11,4,0);
            glScalef(1, 4, 4.5);
            glutSolidCube(1);
        glPopMatrix();
        glPushMatrix();
            glColor3f(0.9f, 0.6f, 0.f);
            glTranslatef(-2,4,0);
            glScalef(1, 4, 4.5);
            glutSolidCube(1);
        glPopMatrix();
        glPushMatrix();
            glColor3f(0.9f, 0.6f, 0.f);
            glTranslatef(-6.5,4,2.2);
            glScalef(8,4 , 0.1);
            glutSolidCube(1);
        glPopMatrix();
        glPushMatrix();
            glColor3f(0.9f, 0.6f, 0.f);
            glTranslatef(-6.5,4,-2.2);
            glScalef(8,4 , 0.1);
            glutSolidCube(1);
        glPopMatrix();

        // Bagian penyambung
        glPushMatrix();
            glColor3f(0.0f, 0.0f, 0.0f);
            glTranslatef(-12.3,1.5,0);
            glScalef(2, 0.2, 0.6);
            glutSolidCube(1);
        glPopMatrix();

        // Bagian gandeng 2
        glPushMatrix();
            glColor3f(0,0,0);
            glTranslatef(-17.8,1.5,0);
            glScalef(10, 1, 4.5);
            glutSolidCube(1);
        glPopMatrix();

        // Bagian container 2
        glPushMatrix();
            glColor3f(0.9f, 0.6f, 0.f);
            glTranslatef(-23.8,1,0);
            glRotatef(135,0,0,10);
            glScalef(0.1, 3, 4.5);
            glutSolidCube(1);
        glPopMatrix();
        glPushMatrix();
            glColor3f(0.9f, 0.6f, 0.f);
            glTranslatef(-13.3,4,0);
            glScalef(1, 4, 4.5);
            glutSolidCube(1);
        glPopMatrix();
        glPushMatrix();
            glColor3f(0.9f, 0.6f, 0.f);
            glTranslatef(-17.8,4,2.2);
            glScalef(10,4 , 0.1);
            glutSolidCube(1);
        glPopMatrix();
        glPushMatrix();
            glColor3f(0.9f, 0.6f, 0.f);
            glTranslatef(-17.8,4,-2.2);
            glScalef(10,4 , 0.1);
            glutSolidCube(1);
        glPopMatrix();


        // bagian roda depan
        glPushMatrix();
            glTranslatef(-1, 0.8, -0.8);
            Roda();
        glPopMatrix();

        glPushMatrix();
            glTranslatef(-1, 0.8, -4.8);
            Roda();
        glPopMatrix();

        // Bagian tengah
        glPushMatrix();
            glTranslatef(-10, 0.8, -0.8);
            Roda();
        glPopMatrix();

        glPushMatrix();
            glTranslatef(-10, 0.8, -4.8);
            Roda();
        glPopMatrix();

        // Bagian belakang 1
        glPushMatrix();
            glTranslatef(-16, 0.8, -0.8);
            Roda();
        glPopMatrix();

        glPushMatrix();
            glTranslatef(-16, 0.8, -4.8);
            Roda();
        glPopMatrix();

        // Bagian belakang 2
        glPushMatrix();
            glTranslatef(-22, 0.8, -0.8);
            Roda();
        glPopMatrix();

        glPushMatrix();
            glTranslatef(-22, 0.8, -4.8);
            Roda();
        glPopMatrix();
    glPopMatrix();
}

void display() {
    if (deltaMove)
    moveMeFlat(deltaMove);
    if (deltaAngle) {
        angle += deltaAngle;
        orientMe(angle);
    }
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    // Gambar grid
    Grid();
    // Gambar truck
    TruckGandeng();
    glutSwapBuffers();
    glFlush();
}

void pressKey(int key, int x, int y) {
    // Fungsi ini akan dijalankan saat tombol keyboard ditekan dan belum dilepas
    // Selama tombol ditekan, variabel angle dan move diubah => kamera bergerak
    switch (key) {
        case GLUT_KEY_LEFT : deltaAngle = -0.01f;break;
        case GLUT_KEY_RIGHT : deltaAngle = 0.01f;break;
        case GLUT_KEY_UP : deltaMove = 1;break;
        case GLUT_KEY_DOWN : deltaMove = -1;break;
    }
}

void releaseKey(int key, int x, int y) {
    // Fungsi ini akan dijalankan saat tekanan tombol keyboard dilepas
    // Saat tombol dilepas, variabel angle dan move diset nol => kamera berhenti
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
    // Fungsi untuk mengaktifkan pencahayaan
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

void init(void)
{
    glEnable (GL_DEPTH_TEST);
    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
    glutInitWindowPosition(50,50);
    glutInitWindowSize(1200,600);
    glutCreateWindow("TRUCKK");
    glutIgnoreKeyRepeat(1);
    glutSpecialFunc(pressKey);
    glutSpecialUpFunc(releaseKey);
    glutDisplayFunc(display);
    glutIdleFunc(display);
    glutReshapeFunc(Reshape);
    glClearColor(1, 1, 1, 1);
    lighting();
    init();
    glutMainLoop();

    return(0);
}
