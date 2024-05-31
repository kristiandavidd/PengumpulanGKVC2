/*Nama : Rania
 *NIM : 24060122120013
 *Lab : C2
 *Nama File : Truk3D.cpp
 *Tanggal : 23 Maret 2024
 *Deskripsi : Menampikan Truk 3D dengan menggunakan Dept dan Lighting.*/

#include <math.h> 
#include <GL/glut.h> 
#include <stdio.h> 
#include <string.h> 
#include <stdlib.h> 
#include <unistd.h>

float angle = 0.0, deltaAngle = 0.0, ratio;
float x = 0.0f, y = 1.75f, z = 15.0f;  //posisi awal kamera
float lx = 0.0f, ly = 0.0f, lz = -1.0f;
int deltaMove = 0, h, w;
int bitmapHeight = 12;
int deltaVerticalMove = 0;
int i, j;

void Reshape(int w1, int h1) {
    //Fungsi reshape 
    if (h1 == 0) h1 = 1;
    w = w1;
    h = h1;
    ratio = 1.0f * w / h;
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glViewport(0, 0, w, h);
    gluPerspective(45, ratio, 0.1, 1000);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(
        x, y, z,
        x + lx, y + ly, z + lz,
        0.0f, 1.0f, 0.0f);
}

void orientMe(float ang) {
    //Fungsi ini untuk memutar arah kamera (tengok kiri/kanan) 
    lx = sin(ang);
    lz = -cos(ang);
    glLoadIdentity();
    gluLookAt(
        x, y, z,
        x + lx, y + ly, z + lz,
        0.0f, 1.0f, 0.0f
    );
}


void moveMeFlat(int i) {
    //Fungsi ini untuk maju mundur kamera 
    x = x + i * (lx) * 0.003;
    z = z + i * (lz) * 0.003;
    glLoadIdentity();
    gluLookAt(
        x, y, z,
        x + lx, y + ly, z + lz,
        0.0f, 1.0f, 0.0f
    );
}

void moveMeVertically(int i) {
    //Fungsi untuk menggerakkan kamera secara vertikal (naik/turun)
    y = y + i * 0.001;
    glLoadIdentity();
    gluLookAt(
        x, y, z,
        x + lx, y + ly, z + lz,
        0.0f, 1.0f, 0.0f
    );
}


void Grid() {
    //Fungsi untuk membuat grid di "lantai" 
    double i;
    const float Z_MIN = -100, Z_MAX = 100;
    const float X_MIN = -100, X_MAX = 100;
    const float gap = 1.5;
    glColor3f(0.5, 0.5, 0.5);
    glBegin(GL_LINES);
    for (i = Z_MIN;i < Z_MAX;i += gap) {
        glVertex3f(i, 0, Z_MIN);
        glVertex3f(i, 0, Z_MAX);
    }
    for (i = X_MIN;i < X_MAX;i += gap) {
        glVertex3f(X_MIN, 0, i);
        glVertex3f(X_MAX, 0, i);
    }
    glEnd();
}

void Truk3D() {
    //RODA DEPAN
    glPushMatrix();
    glColor3f(0.1, 0.1, 0.1);
    glTranslatef(-2.5, 1.65, 2);
    glRotatef(angle, 0, 1, 0);
    glutSolidTorus(0.45, 1.5, 10, 20);

    //VELG DEPAN
    glColor3f(0.620, 0.624, 0.647);
    glTranslatef(0, 0, 0.01);
    glutSolidTorus(1.05, 0.0, 10, 20);
    glEnd();
    glPopMatrix();

    //RODA BELAKANG 1
    glPushMatrix();
    glColor3f(0.1, 0.1, 0.1);
    glTranslatef(4.5, 1.65, 2);
    glRotatef(angle, 0, 1, 0);
    glutSolidTorus(0.45, 1.5, 10, 20);

    //VELG BELAKANG 1
    glColor3f(0.620, 0.624, 0.647);
    glTranslatef(0, 0, 0.01);
    glutSolidTorus(1.05, 0.0, 10, 20);
    glEnd();
    glPopMatrix();

    //RODA BELAKANG 2
    glPushMatrix();
    glColor3f(0.1, 0.1, 0.1);
    glTranslatef(8.5, 1.65, 2);
    glRotatef(angle, 0, 1, 0);
    glutSolidTorus(0.45, 1.5, 10, 20);

    //VELG BELAKANG 2
    glColor3f(0.620, 0.624, 0.647);
    glTranslatef(0, 0, 0.01);
    glutSolidTorus(1.05, 0.0, 10, 20);
    glEnd();
    glPopMatrix();

    //RODA DEPAN SISI LAIN
    glPushMatrix();
    glColor3f(0.1, 0.1, 0.1);
    glTranslatef(-2.5, 1.65, -10);
    glRotatef(angle, 0, 1, 0);
    glutSolidTorus(0.45, 1.5, 10, 20);

    //VELG DEPAN SISI LAIN
    glColor3f(0.620, 0.624, 0.647);
    glTranslatef(0, 0, 0.01);
    glutSolidTorus(1.05, 0.0, 10, 20);
    glEnd();
    glPopMatrix();

    //RODA BELAKANG 1 SISI LAIN
    glPushMatrix();
    glColor3f(0.1, 0.1, 0.1);
    glTranslatef(4.5, 1.65, -10);
    glRotatef(angle, 0, 1, 0);
    glutSolidTorus(0.45, 1.5, 10, 20);

    //VELG BELAKANG 1 SISI LAIN
    glColor3f(0.620, 0.624, 0.647);
    glTranslatef(0, 0, 0.01);
    glutSolidTorus(1.05, 0.0, 10, 20);
    glEnd();
    glPopMatrix();

    //RODA BELAKANG 2 SISI LAIN
    glPushMatrix();
    glColor3f(0.1, 0.1, 0.1);
    glTranslatef(8.5, 1.65, -10);
    glRotatef(angle, 0, 1, 0);
    glutSolidTorus(0.45, 1.5, 10, 20);

    //VELG BELAKANG 2 SISI LAIN
    glColor3f(0.620, 0.624, 0.647);
    glTranslatef(0, 0, 0.01);
    glutSolidTorus(1.05, 0.0, 10, 20);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0, 4, 0);

    //BODY TRUK
    //BELAKANG
    glPushMatrix();
    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.4f, 0.3f);
    glVertex3f(10.5, 10, 2);
    glVertex3f(10.5, 10, -10);
    glVertex3f(10.5, -0.5, -10);
    glVertex3f(10.5, -0.5, 2);
    glEnd();
    glPopMatrix();

    //DEPAN
    glPushMatrix();
    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.4f, 0.3f);
    glVertex3f(0.5, 10, 2);
    glVertex3f(0.5, 10, -10);
    glVertex3f(0.5, -0.5, -10);
    glVertex3f(0.5, -0.5, 2);
    glEnd();
    glPopMatrix();

    //ATAS
    glPushMatrix();
    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.4f, 0.3f);
    glVertex3f(10.5, 10, 2);
    glVertex3f(10.5, 10, -10);
    glVertex3f(0.5, 10, -10);
    glVertex3f(0.5, 10, 2);
    glEnd();
    glPopMatrix();

    //BAWAH
    glPushMatrix();
    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.4f, 0.3f);
    glVertex3f(10.5, -0.5, 2);
    glVertex3f(10.5, -0.5, -10);
    glVertex3f(0.5, -0.5, -10);
    glVertex3f(0.5, -0.5, 2);
    glEnd();
    glPopMatrix();

    //KANAN
    glPushMatrix();
    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.4f, 0.3f);
    glVertex3f(10.5, 10, -10);
    glVertex3f(0.5, 10, -10);
    glVertex3f(0.5, -0.5, -10);
    glVertex3f(10.5, -0.5, -10);
    glEnd();
    glPopMatrix();

    //KIRI
    glPushMatrix();
    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.4f, 0.3f);
    glVertex3f(10.5, 10, 2);
    glVertex3f(0.5, 10, 2);
    glVertex3f(0.5, -0.5, 2);
    glVertex3f(10.5, -0.5, 2);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0, 4, 0);
    glColor3f(0.6f, 0.3f, 0.3f);

    //PINTU1
    glPushMatrix();
    glBegin(GL_POLYGON);
    glVertex3f(0.5, 5, -10);
    glVertex3f(0.5, -4.5, -10);
    glVertex3f(-5.5, -4.5, -10);
    glVertex3f(-5.5, -0.5, -10);
    glVertex3f(-4.5, -2.5, -10);
    glVertex3i(-4.5, 5, -10);
    glEnd();
    glPopMatrix();
    //PINTU2
    glPushMatrix();
    glBegin(GL_POLYGON);
    glVertex3f(0.5, 9, 2);
    glVertex3f(0.5, -0.5, 2);
    glVertex3f(-5.5, -0.5, 2);
    glVertex3f(-5.5, 3.5, 2);
    glVertex3f(-4.5, 1.5, 2);
    glVertex3i(-4.5, 9, 2);
    glEnd();
    glPopMatrix();

    //BODY TRUK DEPAN
    //DEPAN
    glPushMatrix();
    glBegin(GL_QUADS);
    glVertex3f(-4, 9, -10);
    glVertex3f(-4, 9, 2);
    glVertex3f(-4, 4.5, 2);
    glVertex3f(-4, 4.5, -10);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glBegin(GL_QUADS);
    glVertex3f(-5.5, 3.5, -10);
    glVertex3f(-5.5, 3.5, 2);
    glVertex3f(-4.4, 4.5, 2);
    glVertex3f(-4.4, 4.5, -10);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glBegin(GL_QUADS);
    glVertex3f(-5.5, 3.5, 2);
    glVertex3f(-5.5, 3.5, -10);
    glVertex3f(-5.5, -0.5, -10);
    glVertex3f(-5.5, -0.5, 2);
    glEnd();
    glPopMatrix();

    //ATAS
    glPushMatrix();
    glBegin(GL_QUADS);
    glVertex3f(-4, 9, -10);
    glVertex3f(-4, 9, 2);
    glVertex3f(0.5, 9, 2);
    glVertex3f(0.5, 9, -10);
    glEnd();
    glPopMatrix();

    //BAWAH
    glPushMatrix();
    glBegin(GL_QUADS);
    glVertex3f(-5.5, -0.5, -10);
    glVertex3f(-5.5, -0.5, 2);
    glVertex3f(0.5, -0.5, 2);
    glVertex3f(0.5, -0.5, -10);
    glEnd();
    glPopMatrix();

    //BODY TRUK BAWAH
    //KANAN
    glPushMatrix();
    glBegin(GL_QUADS);
    glColor3ub(80, 80, 80);
    glVertex3f(11, -0.5, -10);
    glVertex3f(-6, -0.5, -10);
    glVertex3f(-6, -1.5, -10);
    glVertex3f(11, -1.5, -10);
    glEnd();
    glPopMatrix();

    //KIRI
    glPushMatrix();
    glBegin(GL_QUADS);
    glColor3ub(80, 80, 80);
    glVertex3f(11, -0.5, 2);
    glVertex3f(-6, -0.5, 2);
    glVertex3f(-6, -1.5, 2);
    glVertex3f(11, -1.5, 2);
    glEnd();
    glPopMatrix();

    //DEPAN 
    glPushMatrix();
    glColor3ub(80, 80, 80);
    glBegin(GL_QUADS);
    glVertex3f(11, -0.5, -10);
    glVertex3f(11, -0.5, 2);
    glVertex3f(11, -1.5, 2);
    glVertex3f(11, -1.5, -10);
    glEnd();
    glPopMatrix();

    //BELAKANG
    glPushMatrix();
    glColor3ub(80, 80, 80);
    glBegin(GL_QUADS);
    glVertex3f(-6, -0.5, -10);
    glVertex3f(-6, -0.5, 2);
    glVertex3f(-6, -1.5, 2);
    glVertex3f(-6, -1.5, -10);
    glEnd();
    glPopMatrix();

    //BAWAH
    glPushMatrix();
    glColor3ub(80, 80, 80);
    glBegin(GL_QUADS);
    glVertex3f(-6, -1.5, -10);
    glVertex3f(-6, -1.5, 2);
    glVertex3f(11, -1.5, 2);
    glVertex3f(11, -1.5, -10);
    glEnd();
    glPopMatrix();

    //KACA DEPAN
    glPushMatrix();
    glColor3ub(239, 255, 253);
    glTranslatef(-4, 6, -4);
    glScalef(0.15, 4.5, 10);
    glutSolidCube(1);
    glEnd();
    glPopMatrix();

    //KACA SAMPING
    glPushMatrix();
    glColor3ub(239, 255, 253);
    glTranslatef(-1.75, 6.55, 2);
    glScalef(3.4, 4, 0.1);
    glutSolidCube(1);
    glEnd();
    glPopMatrix();

    //KACA SAMPING SISI LAIN
    glPushMatrix();
    glColor3ub(239, 255, 253);
    glTranslatef(-1.75, 6.55, -10);
    glScalef(3.4, 4, 0.1);
    glutSolidCube(1);
    glEnd();
    glPopMatrix();

    //LAMPU
    glPushMatrix();
    glColor3ub(255, 255, 0);
    glTranslatef(-5.5, 1.5, 0);
    glScalef(0.2, 1.5, 2.3);
    glutSolidCube(1);
    glEnd();
    glPopMatrix();

    //LAMPU 2
    glPushMatrix();
    glColor3ub(255, 255, 0);
    glTranslatef(-5.5, 1.5, -8);
    glScalef(0.2, 1.5, 2.3);
    glutSolidCube(1);
    glEnd();
    glPopMatrix();

    //GAGANG PINTU
    glPushMatrix();
    glColor3ub(1, 1, 1);
    glTranslatef(-0.5, 4, 2);
    glScalef(1, 0.20, 0.7);
    glutSolidCube(1);
    glEnd();
    glPopMatrix();

    //GAGANG PINTU 2
    glPushMatrix();
    glColor3ub(1, 1, 1);
    glTranslatef(-0.5, 4, -10);
    glScalef(1, 0.20, 0.7);
    glutSolidCube(1);
    glEnd();
    glPopMatrix();

    //DEKORASI
    //CORAK MOBIL KANAN 1
    glPushMatrix();
    glColor3f(0.6f, 0.3f, 0.3f);
    glTranslatef(6, 4, 2);
    glScalef(9, 2, 0.1);
    glutSolidCube(1);
    glEnd();
    glPopMatrix();

    //CORAK MOBIL KANAN 2
    glPushMatrix();
    glColor3f(0.6f, 0.3f, 0.3f);
    glTranslatef(7.4, 6, 2);
    glScalef(6.2, 0.9, 0.1);
    glutSolidCube(1);
    glEnd();
    glPopMatrix();

    //CORAK MOBIL KIRI 1
    glPushMatrix();
    glColor3f(0.6f, 0.3f, 0.3f);
    glTranslatef(6, 4, -10);
    glScalef(9, 2, 0.1);
    glutSolidCube(1);
    glEnd();
    glPopMatrix();

    //CORAK MOBIL KIRI 2
    glPushMatrix();
    glColor3f(0.6f, 0.3f, 0.3f);
    glTranslatef(7.4, 6, -10);
    glScalef(6.2, 0.9, 0.1);
    glutSolidCube(1);
    glEnd();
    glPopMatrix();

    //CORAK MOBIL BELAKANG 1
    glPushMatrix();
    glColor3f(0.6f, 0.3f, 0.3f);
    glTranslatef(10.5, 4, -4);
    glScalef(0.1, 2, 12);
    glutSolidCube(1);
    glEnd();
    glPopMatrix();

    //CORAK MOBIL BELAKANG 2
    glPushMatrix();
    glColor3f(0.6f, 0.3f, 0.3f);
    glTranslatef(10.5, 6, -4);
    glScalef(0.1, 0.9, 12);
    glutSolidCube(1);
    glEnd();
    glPopMatrix();
    glPopMatrix();
}

void display() {
    usleep(1);
    //Kalau move dan angle tidak nol, gerakkan kamera... 
    if (deltaMove) {
        moveMeFlat(deltaMove);
    }

    if (deltaAngle) {
        angle += deltaAngle;
        orientMe(angle);
    }

    if (deltaVerticalMove) {
        moveMeVertically(deltaVerticalMove);
    }

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glClearColor(0.0, 0.0, 0.0, 1.0);
    Grid();	// Gambar grid
    Truk3D();
    glutSwapBuffers();
    glFlush();
}

void pressKey(int key, int x, int y) {
    //Fungsi ini akan dijalankan saat tombol keyboard ditekan dan  belum dilepas 
    // Selama tombol ditekan, variabel angle dan move diubah => kamera bergerak 
    switch (key) {
    case GLUT_KEY_LEFT: deltaAngle = -0.004f; break;
    case GLUT_KEY_RIGHT: deltaAngle = 0.004f; break;
    case GLUT_KEY_UP: deltaMove = 1; break;
    case GLUT_KEY_DOWN: deltaMove = -1; break;
    case GLUT_KEY_PAGE_UP: deltaVerticalMove = 1; break; // Geser halaman ke atas
    case GLUT_KEY_PAGE_DOWN: deltaVerticalMove = -1; break; // Geser halaman ke bawah
    }
}

void releaseKey(int key, int x, int y) {
    // Fungsi ini akan dijalankan saat tekanan tombol keyboard dilepas 
    // Saat tombol dilepas, variabel angle dan move diset nol => kamera berhenti 
    switch (key) {
    case GLUT_KEY_LEFT:
        if (deltaAngle < 0.0f)
            deltaAngle = 0.0f;
        break;
    case GLUT_KEY_RIGHT:
        if (deltaAngle > 0.0f)
            deltaAngle = 0.0f;
        break;
    case GLUT_KEY_UP:
        if (deltaMove > 0)
            deltaMove = 0;
        break;
    case GLUT_KEY_DOWN:
        if (deltaMove < 0)
            deltaMove = 0;
        break;
    case GLUT_KEY_PAGE_UP:
        if (deltaVerticalMove > 0)
            deltaVerticalMove = 0;
        break;
    case GLUT_KEY_PAGE_DOWN:
        if (deltaVerticalMove < 0)
            deltaVerticalMove = 0;
        break;
    }
}


//Variable untuk pencahayaan 
const GLfloat light_ambient[] = { 0.5f, 0.5f, 0.5f, 0.0f };
const GLfloat light_diffuse[] = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat light_specular[] = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat light_position[] = { 0.0f, 20.0f, 10.0f, 1.0f };

const GLfloat mat_ambient[] = { 0.7f, 0.7f, 0.7f, 1.0f };
const GLfloat mat_diffuse[] = { 0.8f, 0.8f, 0.8f, 1.0f };
const GLfloat mat_specular[] = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat high_shininess[] = { 100.0f };

void lighting() {
    //Fungsi mengaktifkan pencahayaan 
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

void init(void) {
    glEnable(GL_DEPTH_TEST);
    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    glClearColor(0.0, 0.0, 0.0, 1.0);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
    glutInitWindowPosition(100, 100);
    glutInitWindowSize(640, 700);
    glutCreateWindow("Truk 3D dengan Dept dan Lighting");
    glutIgnoreKeyRepeat(1); //Mengabaikan key repeat (saat tombol  keyboard dipencet terus) 
    glutSpecialFunc(pressKey);
    glutSpecialUpFunc(releaseKey);
    glutDisplayFunc(display);
    glutIdleFunc(display); //Fungsi display-nya dipanggil terus menerus 
    glutReshapeFunc(Reshape);
    lighting();
    init();
    glutMainLoop();
    return(0);
}

