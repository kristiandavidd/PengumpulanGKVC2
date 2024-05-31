#include <iostream>
#include <stdlib.h>
#ifdef _APPLE_
#include <OpenGL/OpenGL.h>
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include "imageloader.h"
//#include "imageloader.cpp"

using namespace std;
const float BOX_SIZE = 7.0f; //Panjang tiap sisi kubus
float _angle = 0; //Rotasi terhadap box
//ID OpenGL untuk tekstur
GLuint _textureId;
GLuint _textureId1;
GLuint _textureId2;
GLuint _textureId3;
GLuint _textureId4;
GLuint _textureId5;

void handleKeypress(unsigned char key, int x, int y) {
    switch (key) {
    case 27: //Tekan Escape untuk EXIT
        exit(0);
    }
}
//Membuat gambar menjadi tekstur kemudian berikan ID pada tekstur
GLuint loadTexture(Image* image) {
    GLuint textureId;
    glGenTextures(1, &textureId);
    glBindTexture(GL_TEXTURE_2D, textureId);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, image->width, image->height, 0, GL_RGB, GL_UNSIGNED_BYTE, image->pixels);
    return textureId;
}
void initRendering() {
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glEnable(GL_NORMALIZE);
    glEnable(GL_COLOR_MATERIAL);
    Image* image = loadBMP("bg.bmp");
    _textureId = loadTexture(image);

    Image* image1 = loadBMP("bg1.bmp");
    _textureId1 = loadTexture(image1);

    Image* image2 = loadBMP("bg2.bmp");
    _textureId2 = loadTexture(image2);

    Image* image3 = loadBMP("bg3.bmp");
    _textureId3 = loadTexture(image3);

    Image* image4 = loadBMP("bg4.bmp");
    _textureId4 = loadTexture(image4);

    Image* image5 = loadBMP("bg5.bmp");
    _textureId5 = loadTexture(image5);
    delete image, image1, image2, image3, image4, image5;
}
void handleResize(int w, int h) {
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0, (float)w / (float)h, 1.0, 200.0);
}

void drawScene() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glTranslatef(0.0f, 0.0f, -20.0f);
    GLfloat ambientLight[] = {
      0.3f,
      0.3f,
      0.3f,
      1.0f
    };
    glLightModelfv(GL_LIGHT_MODEL_AMBIENT, ambientLight);
    GLfloat lightColor[] = {
      0.7f,
      0.7f,
      0.7f,
      1.0f
    };
    GLfloat lightPos[] = {
      -2 * BOX_SIZE,
      BOX_SIZE,
      4 * BOX_SIZE,
      1.0f
    };
    glLightfv(GL_LIGHT0, GL_DIFFUSE, lightColor);
    glLightfv(GL_LIGHT0, GL_POSITION, lightPos);
    glRotatef(-_angle, 1.0f, 1.0f, 0.0f);

    //Sisi atas
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, _textureId);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER,
        GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER,
        GL_LINEAR);
    glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_QUADS);
    glNormal3f(-1.0, 0.0f, 0.0f);
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(-BOX_SIZE / 2, BOX_SIZE / 2, -BOX_SIZE / 2);
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(-BOX_SIZE / 2, BOX_SIZE / 2, BOX_SIZE / 2);
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(BOX_SIZE / 2, BOX_SIZE / 2, BOX_SIZE / 2);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(BOX_SIZE / 2, BOX_SIZE / 2, -BOX_SIZE / 2);
    glEnd();

    //Sisi bawah
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, _textureId1);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER,
        GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER,
        GL_LINEAR);
    glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_QUADS);
    glNormal3f(-1.0, 0.0f, 0.0f);
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(-BOX_SIZE / 2, -BOX_SIZE / 2, -BOX_SIZE / 2);
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(BOX_SIZE / 2, -BOX_SIZE / 2, -BOX_SIZE / 2);
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(BOX_SIZE / 2, -BOX_SIZE / 2, BOX_SIZE / 2);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(-BOX_SIZE / 2, -BOX_SIZE / 2, BOX_SIZE / 2);
    glEnd();

    //Sisi kiri
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, _textureId2);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER,
        GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER,
        GL_LINEAR);
    glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_QUADS);
    glNormal3f(-1.0, 0.0f, 0.0f);
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(-BOX_SIZE / 2, -BOX_SIZE / 2, -BOX_SIZE / 2);
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(-BOX_SIZE / 2, -BOX_SIZE / 2, BOX_SIZE / 2);
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(-BOX_SIZE / 2, BOX_SIZE / 2, BOX_SIZE / 2);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(-BOX_SIZE / 2, BOX_SIZE / 2, -BOX_SIZE / 2);
    glEnd();


    //Sisi kanan
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, _textureId3);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER,
        GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER,
        GL_LINEAR);
    glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_QUADS);
    glNormal3f(1.0, 0.0f, 0.0f);
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(BOX_SIZE / 2, -BOX_SIZE / 2, -BOX_SIZE / 2);
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(BOX_SIZE / 2, BOX_SIZE / 2, -BOX_SIZE / 2);
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(BOX_SIZE / 2, BOX_SIZE / 2, BOX_SIZE / 2);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(BOX_SIZE / 2, -BOX_SIZE / 2, BOX_SIZE / 2);
    glEnd();

    //Sisi depan
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, _textureId4);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER,
        GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER,
        GL_LINEAR);
    glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_QUADS);
    glNormal3f(0.0, 0.0f, 1.0f);
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(-BOX_SIZE / 2, -BOX_SIZE / 2, BOX_SIZE / 2);
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(BOX_SIZE / 2, -BOX_SIZE / 2, BOX_SIZE / 2);
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(BOX_SIZE / 2, BOX_SIZE / 2, BOX_SIZE / 2);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(-BOX_SIZE / 2, BOX_SIZE / 2, BOX_SIZE / 2);
    glEnd();

    //Sisi belakang
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, _textureId5);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER,
        GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER,
        GL_LINEAR);
    glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_QUADS);
    glNormal3f(0.0, 0.0f, -1.0f);
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(-BOX_SIZE / 2, -BOX_SIZE / 2, -BOX_SIZE / 2);
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(-BOX_SIZE / 2, BOX_SIZE / 2, -BOX_SIZE / 2);
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(BOX_SIZE / 2, BOX_SIZE / 2, -BOX_SIZE / 2);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(BOX_SIZE / 2, -BOX_SIZE / 2, -BOX_SIZE / 2);
    glEnd();
    glDisable(GL_TEXTURE_2D);
    glutSwapBuffers();
}

//Panggil setiap 25ms
void update(int value) {
    _angle += 1.0f;
    if (_angle > 360) {
        _angle -= 360;
    }
    glutPostRedisplay();
    glutTimerFunc(20, update, 0);
}
int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(400, 400);
    glutCreateWindow("Texture With Image");
    initRendering();
    glutDisplayFunc(drawScene);
    glutKeyboardFunc(handleKeypress);
    glutReshapeFunc(handleResize);
    glutTimerFunc(25, update, 0);
    glutMainLoop();
    return 0;
}


/*
Inisialisasi dan Pengaturan Awal:

Pada fungsi main(), program melakukan inisialisasi GLUT dan mengatur mode tampilan untuk window (double buffering, RGB color mode, dan depth buffer).
Kemudian window dibuat dengan ukuran 400x400 dan judul "Texture With Image".
Fungsi Inisialisasi Rendering:

Fungsi initRendering() digunakan untuk mengatur beberapa pengaturan awal OpenGL seperti aktivasi depth test, pencahayaan, dan penggunaan tekstur.
Pada fungsi ini, setiap gambar (image) dimuat dari file BMP dan dikonversi menjadi tekstur menggunakan fungsi loadTexture().
Setiap tekstur kemudian diberikan ID unik yang akan digunakan untuk mengaitkan tekstur dengan objek 3D saat menggambar.
Fungsi Untuk Memuat dan Mengonversi Gambar Menjadi Tekstur:

Fungsi loadTexture() digunakan untuk memuat gambar BMP menjadi tekstur OpenGL.
Pada fungsi ini, glGenTextures() digunakan untuk menghasilkan ID tekstur baru, lalu glBindTexture() digunakan untuk mengaitkan tekstur dengan target GL_TEXTURE_2D.
Setelah itu, glTexImage2D() digunakan untuk mengirim data gambar ke GPU, yang akan digunakan sebagai tekstur.
Setelah proses pengiriman selesai, ID tekstur dikembalikan untuk digunakan dalam rendering.
Fungsi drawScene():

Fungsi ini digunakan untuk menggambar objek 3D dan menerapkan tekstur pada masing-masing sisinya.
Pertama-tama, objek ditempatkan pada koordinat yang sesuai untuk menampilkan dengan benar di dalam window.
Selanjutnya, diterapkan pencahayaan dengan mengatur warna dan posisi cahaya.
Setiap sisi dari objek kubus diberi tekstur yang berbeda dengan menggunakan fungsi glBindTexture() dan glBegin(GL_QUADS) untuk menggambar sisi-sisinya.
Tekstur diterapkan dengan menggunakan koordinat tekstur yang sesuai (glTexCoord2f()) dan gambaran dari objek yang digambar disesuaikan dengan koordinat tekstur yang ada.
Fungsi update():

Fungsi ini digunakan untuk memperbarui sudut rotasi objek (_angle) setiap 25ms.
Hal ini dilakukan dengan menggunakan fungsi glutTimerFunc() untuk mengatur waktu pemanggilan fungsi update() secara berkala.
Dengan alur kerja tersebut, program mampu menampilkan objek kubus dengan masing-masing sisinya diberi tekstur yang berbeda. Setiap tekstur diambil dari gambar BMP yang telah dimuat sebelumnya. Saat objek berputar, tekstur tetap berada pada sisi yang sama sesuai dengan pemetaan tekstur yang telah didefinisikan.
*/