#include <GL/glut.h>

// Variabel global untuk rotasi kubus
float angleXCube = 0.0f;
float angleYCube = 0.0f;

// Variabel global untuk rotasi bayangan
float angleXShadow = 0.0f;
float angleYShadow = 0.0f;

// Variabel global untuk menyimpan status tampilan kubus
bool showCube = false;

// Variabel global untuk menyimpan status tampilan bayangan
bool showShadow = false; // Mulai dengan bayangan mati

// Variabel global untuk menyimpan status tombol mouse dan posisi terakhir mouse
bool mouseDown = false;
int lastMouseX, lastMouseY;

// Variabel global untuk menyimpan jarak pandang kamera (zoom)
float zoom = 5.0f;

// Variabel global untuk mode kamera
bool perspectiveMode = true; // Default: perspektif

// Fungsi untuk menggambar kubus
void drawCube() {
    glBegin(GL_QUADS);

    // Sisi depan
    glColor3f(1.0f, 0.0f, 0.0f); // Warna merah
    glVertex3f(-0.5f, -0.5f,  0.5f);
    glVertex3f( 0.5f, -0.5f,  0.5f);
    glVertex3f( 0.5f,  0.5f,  0.5f);
    glVertex3f(-0.5f,  0.5f,  0.5f);

    // Sisi belakang
    glColor3f(0.0f, 1.0f, 0.0f); // Warna hijau
    glVertex3f(-0.5f, -0.5f, -0.5f);
    glVertex3f( 0.5f, -0.5f, -0.5f);
    glVertex3f( 0.5f,  0.5f, -0.5f);
    glVertex3f(-0.5f,  0.5f, -0.5f);

    // Sisi kiri
    glColor3f(0.0f, 0.0f, 1.0f); // Warna biru
    glVertex3f(-0.5f, -0.5f, -0.5f);
    glVertex3f(-0.5f, -0.5f,  0.5f);
    glVertex3f(-0.5f,  0.5f,  0.5f);
    glVertex3f(-0.5f,  0.5f, -0.5f);

    // Sisi kanan
    glColor3f(1.0f, 1.0f, 0.0f); // Warna kuning
    glVertex3f( 0.5f, -0.5f, -0.5f);
    glVertex3f( 0.5f, -0.5f,  0.5f);
    glVertex3f( 0.5f,  0.5f,  0.5f);
    glVertex3f( 0.5f,  0.5f, -0.5f);

    // Sisi atas
    glColor3f(1.0f, 0.0f, 1.0f); // Warna magenta
    glVertex3f(-0.5f,  0.5f, -0.5f);
    glVertex3f( 0.5f,  0.5f, -0.5f);
    glVertex3f( 0.5f,  0.5f,  0.5f);
    glVertex3f(-0.5f,  0.5f,  0.5f);

    // Sisi bawah
    glColor3f(0.0f, 1.0f, 1.0f); // Warna cyan
    glVertex3f(-0.5f, -0.5f, -0.5f);
    glVertex3f( 0.5f, -0.5f, -0.5f);
    glVertex3f( 0.5f, -0.5f,  0.5f);
    glVertex3f(-0.5f, -0.5f,  0.5f);

    glEnd();
}

// Fungsi untuk menggambar bayangan kubus di lantai
void drawCubeShadow() {
    // Simpan matriks transformasi saat ini
    glPushMatrix();

    // Lakukan transformasi bayangan
    GLfloat shadowMat[16] = {
        1, 0, 0, 0,
        0, 0, 0, 0,
        0, 0, 1, 0,
        0, 1, 0, 1
    };
    glMultMatrixf(shadowMat);

    // Gambar bayangan dengan gradasi
    glBegin(GL_QUADS);

    // Sisi depan
    glColor4f(0.2f, 0.2f, 0.2f, 0.1f); // Warna abu-abu transparan
    glVertex3f(-0.5f, -0.5f,  0.5f);
    glColor4f(0.2f, 0.2f, 0.2f, 0.5f); // Warna abu-abu lebih pekat
    glVertex3f( 0.5f, -0.5f,  0.5f);
    glVertex3f( 0.5f,  0.5f,  0.5f);
    glVertex3f(-0.5f,  0.5f,  0.5f);

    // Sisi belakang
    glColor4f(0.2f, 0.2f, 0.2f, 0.1f); // Warna abu-abu transparan
    glVertex3f(-0.5f, -0.5f, -0.5f);
    glColor4f(0.2f, 0.2f, 0.2f, 0.5f); // Warna abu-abu lebih pekat
   
    glVertex3f( 0.5f, -0.5f, -0.5f);
    glVertex3f( 0.5f,  0.5f, -0.5f);
    glVertex3f(-0.5f,  0.5f, -0.5f);

    // Sisi kiri
    glColor4f(0.2f, 0.2f, 0.2f, 0.1f); // Warna abu-abu transparan
    glVertex3f(-0.5f, -0.5f, -0.5f);
    glColor4f(0.2f, 0.2f, 0.2f, 0.5f); // Warna abu-abu lebih pekat
    glVertex3f(-0.5f, -0.5f,  0.5f);
    glVertex3f(-0.5f,  0.5f,  0.5f);
    glVertex3f(-0.5f,  0.5f, -0.5f);

    // Sisi kanan
    glColor4f(0.2f, 0.2f, 0.2f, 0.1f); // Warna abu-abu transparan
    glVertex3f( 0.5f, -0.5f, -0.5f);
    glColor4f(0.2f, 0.2f, 0.2f, 0.5f); // Warna abu-abu lebih pekat
    glVertex3f( 0.5f, -0.5f,  0.5f);
    glVertex3f( 0.5f,  0.5f,  0.5f);
    glVertex3f( 0.5f,  0.5f, -0.5f);

    // Sisi atas
    glColor4f(0.2f, 0.2f, 0.2f, 0.1f); // Warna abu-abu transparan
    glVertex3f(-0.5f,  0.5f, -0.5f);
    glColor4f(0.2f, 0.2f, 0.2f, 0.5f); // Warna abu-abu lebih pekat
    glVertex3f( 0.5f,  0.5f, -0.5f);
    glVertex3f( 0.5f,  0.5f,  0.5f);
    glVertex3f(-0.5f,  0.5f,  0.5f);

    // Sisi bawah
    glColor4f(0.2f, 0.2f, 0.2f, 0.1f); // Warna abu-abu transparan
    glVertex3f(-0.5f, -0.5f, -0.5f);
    glColor4f(0.2f, 0.2f, 0.2f, 0.5f); // Warna abu-abu lebih pekat
    glVertex3f( 0.5f, -0.5f, -0.5f);
    glVertex3f( 0.5f, -0.5f,  0.5f);
    glVertex3f(-0.5f, -0.5f,  0.5f);

    glEnd();

    // Kembalikan matriks transformasi
    glPopMatrix();
}

// Fungsi display
void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();

    if (perspectiveMode) {
        gluLookAt(0.0, 0.0, zoom,  // Posisi kamera (ditentukan oleh variabel zoom)
                  0.0, 0.0, 0.0,   // Titik yang dilihat
                  0.0, 1.0, 0.0);  // Arah atas
    } else {
        glOrtho(-zoom, zoom, -zoom, zoom, 1.0, 100.0);
        gluLookAt(0.0, 0.0, zoom,  // Posisi kamera (ditentukan oleh variabel zoom)
                  0.0, 0.0, 0.0,   // Titik yang dilihat
                  0.0, 1.0, 0.0);  // Arah atas
    }

    if (showCube) {
        if (showShadow) {
            // Transformasi rotasi untuk bayangan
            glPushMatrix();
            glRotatef(angleXShadow, 1.0, 0.0, 0.0);
            glRotatef(angleYShadow, 0.0, 1.0, 0.0);
            drawCubeShadow();
            glPopMatrix();
        }

        // Transformasi rotasi untuk kubus
        glRotatef(angleXCube, 1.0, 0.0, 0.0);
        glRotatef(angleYCube, 0.0, 1.0, 0.0);
        drawCube();
    }

    glutSwapBuffers();
}

// Fungsi inisialisasi
void init() {
    glClearColor(0.8, 0.8, 0.8, 1.0); // Latar belakang putih
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0, 1.0, 1.0, 100.0);
    glMatrixMode(GL_MODELVIEW);
}

// Fungsi untuk menangani rotasi dengan input keyboard
void keyboard(unsigned char key, int x, int y) {
    switch (key) {
        case 'a':
            angleYCube -= 5.0f;
            angleYShadow -= 5.0f;
            break;
        case 'd':
            angleYCube += 5.0f;
            angleYShadow += 5.0f;
            break;
        case 'w':
            angleXCube -= 5.0f;
            break;
        case 's':
            angleXCube += 5.0f;
            break;
        case '1': // Menampilkan atau menyembunyikan kubus dan bayangan dengan tombol 1
            showCube = !showCube;
            break;
        case 'l': // Menampilkan atau menyembunyikan bayangan dengan tombol l
            showShadow = !showShadow;
            break;
        case '9': // Zoom in
            zoom -= 0.5f;
            if (zoom < 1.0f) zoom = 1.0f; // Batas minimal zoom
            break;
        case '0': // Zoom out
            zoom += 0.5f;
            if (zoom > 20.0f) zoom = 20.0f; // Batas maksimal zoom
            break;
        case 'o': // Ubah ke mode ortografis
            perspectiveMode = false;
            glMatrixMode(GL_PROJECTION);
            glLoadIdentity();
            glOrtho(-zoom, zoom, -zoom, zoom, 1.0, 100.0);
            glMatrixMode(GL_MODELVIEW);
            break;
        case 'p': // Ubah ke mode perspektif
            perspectiveMode = true;
            glMatrixMode(GL_PROJECTION);
            glLoadIdentity();
            gluPerspective(45.0, 1.0, 1.0, 100.0);
            glMatrixMode(GL_MODELVIEW);
            break;
    }
    glutPostRedisplay(); // Meminta redisplay setelah perubahan
}

// Fungsi untuk menangani klik mouse dan scroll wheel
void mouse(int button, int state, int x, int y) {
    if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN) {
        showCube = !showCube; // Toggle tampilan kubus
        glutPostRedisplay();
    }
    if (button == GLUT_LEFT_BUTTON) {
        if (state == GLUT_DOWN) {
            mouseDown = true;
            lastMouseX = x;
            lastMouseY = y;
        } else if (state == GLUT_UP) {
            mouseDown = false;
        }
    }
    if (button == 3) { // Scroll up
        zoom -= 0.5f;
        if (zoom < 1.0f) zoom = 1.0f; // Batas minimal zoom
        glutPostRedisplay();
    } else if (button == 4) { // Scroll down
        zoom += 0.5f;
        if (zoom > 20.0f) zoom = 20.0f; // Batas maksimal zoom
        glutPostRedisplay();
    }
}

// Fungsi untuk menangani pergerakan mouse
void motion(int x, int y) {
    if (mouseDown) {
        int deltaX = x - lastMouseX;
        int deltaY = y - lastMouseY;
        angleXCube += (float)deltaY * 0.5f;
        angleYCube += (float)deltaX * 0.5f;
        angleXShadow += (float)deltaY * 0.5f;
        angleYShadow += (float)deltaX * 0.5f;
        lastMouseX = x;
        lastMouseY = y;
        glutPostRedisplay();
    }
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(500, 500);
    glutCreateWindow("OpenGL - Kubus dengan Bayangan");

    init();

    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    glutMouseFunc(mouse);
    glutMotionFunc(motion);

    glutMainLoop();
    return 0;
}
