#include <math.h>
#include <stdio.h>
#include <GL/glut.h>
#define LEBAR 600
#define TINGGI 600
#define POS_X 350
#define POS_Y 60
#define PI 3.141592653
#define MAKS 24
#define AKSELERASI_MIN 0.021f
#define AKSELERASI_MAX 0.799f
#define KAMERA_MIN 24.0f
#define KAMERA_MAX 36.0f
#define GESERAN_TANAH 0.98f
#define GESERAN_DINDING 0.6f
#define MULAI_X 10.0f
#define MULAI_Y 10.0f
#define NUM_POINTS 100

GLfloat WarnaLatar[] = {0.95f, 0.95f, 0.95f, 1.0f};
GLfloat PosisiLampu[] = { 20.0f, 30.0f, 50.0f, 1.0f };
GLfloat LampuDif[] = { 0.8f, 0.8f, 0.0f, 1.0f };
GLfloat Sekitar[] = { 0.2f, 0.2f, 0.2f, 1.0f };
GLfloat Difus[] = { 0.7f, 0.7f, 0.7f, 1.0f };
GLfloat Spesuler[] = { 1.0f, 1.0f, 1.0f, 1.0f };

int score = 0;
float Akselerasi = 0.06f;
float Kamera = 28.0f;
float x, y, ax, ay, vx, vy;
int i, j, j2, k, a, b, tmp;
int ArahHor = -1, ArahVer = -1;
char IsPressHor = 0, IsPressVer = 0;
int SudutOffset[] = { 2, -2 }, SudutMaksOffset[] = { 30, -30 };
char teks[30];

typedef struct {
    float x;
    float y;
    int collected;
} Point;


Point points[NUM_POINTS];
int pointCount = 0;

int Peta[MAKS][MAKS] = {

    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 0, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 0, 1, 1, 0 },
    { 0, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 0, 1, 1, 0 },
    { 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0 },
    { 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 0, 1, 1, 0, 1, 1, 1, 1, 1, 0 },
    { 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 0, 0, 1, 1, 0, 1, 1, 1, 1, 1, 0 },
    { 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 0, 1, 1, 0 },
    { 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 0, 1, 1, 0 },
    { 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 0, 0,0 , 0, 0, 1, 1, 0, 0, 0, 0, 1, 1, 0 },
    { 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 0 },
    { 0, 1, 1, 0, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 0 },
    { 0, 1, 1, 0, 1, 1, 1, 1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0 },
    { 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1,1 , 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0 },
    { 0, 1, 1, 0, 1, 1, 0, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0 },
    { 0, 1, 1, 0, 1, 1, 0, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 0 },
    { 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 0, 1, 1, 0 },
    { 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 0, 1, 1, 0 },
    { 0, 1, 1, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0 },
    { 0, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 0, 1, 1, 0 },
    { 0, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 0, 1, 1, 0 },
    { 0, 1, 1, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 1, 1, 0, 1, 1, 0 },
    { 0, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 0 },
    { 0, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }


};

void TeksBitmap(float x, float y, char* s)
{
    glRasterPos2f(x, y);
    while (*s != '\0')
        glutBitmapCharacter(GLUT_BITMAP_9_BY_15, *(s++));
}

void AturTampilanMeja()
{
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(60.0, 1.0, 1.0, 50.0);
    glTranslatef(0.0f, 0.0f, -Kamera);
    glRotatef(-0.6f * a, 0.0f, 1.0f, 0.0f);
    glRotatef(0.6f * b - 30, 1.0f, 0.0f, 0.0f);
    glMatrixMode(GL_MODELVIEW);
    ax = -Akselerasi * sin(a * PI / 180);
    ay = -Akselerasi * sin(b * PI / 180);
}

void AturTampilanTeks()
{
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glMatrixMode(GL_MODELVIEW);
}
void Tampilkan() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    AturTampilanMeja();
    glLoadIdentity();
    glColor3fv(WarnaLatar);
    glBegin(GL_QUADS);
    glVertex2f(-12.0f, -12.0f);
    glVertex2f(12.0f, -12.0f);
    glVertex2f(12.0f, 12.0f);
    glVertex2f(-12.0f, 12.0f);
    glEnd();
    glEnable(GL_LIGHTING);
    glCallList(1);
    glLoadIdentity();
    glTranslatef(x, y, 0.5f);
    glColor3f(0.0f, 0.0f, 0.0f);
    glutSolidSphere(0.5, 40, 40);
    glDisable(GL_LIGHTING);

    for (int i = 0; i < NUM_POINTS; i++) {
        glLoadIdentity();
        glTranslatef(points[i].x, points[i].y, 0.5f);
        if (points[i].collected)
            glColor3f(0.5f, 0.5f, 0.5f); // Change color if collected
        else
            glColor3f(1.0f, 0.0f, 0.0f); // Default color for uncollected points
        glutSolidSphere(0.2, 20, 20);
}

    AturTampilanTeks();
    glLoadIdentity();

    glutSwapBuffers();
}

void InisialisasiPoin() {
    // Hapus semua titik-titik sebelumnya
    pointCount = 0;

    // Tambahkan titik-titik pada lokasi tertentu dalam matriks Peta
    points[pointCount++] = (Point){-4.0f, -5.0f, 0};
    points[pointCount++] = (Point){7.0f, -5.0f, 0};
    points[pointCount++] = (Point){-4.0f, 5.0f, 0};
    points[pointCount++] = (Point){7.0f, 5.0f, 0};
    points[pointCount++] = (Point){-10.0f, 9.5f, 0};
    points[pointCount++] = (Point){1.0f, 10.0f, 0};
    points[pointCount++] = (Point){1.5f, -8.0f, 0};
}

void Inisialisasi() {
    glClearColor(0.5f, 0.5f, 0.5f, 1.000f);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_LIGHT0);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, LampuDif);
    glLightfv(GL_LIGHT0, GL_POSITION, PosisiLampu);
    glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, Sekitar);
    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, Difus);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, Spesuler);
    glMaterialf(GL_FRONT, GL_SHININESS, 90.0f);
    glNewList(1, GL_COMPILE);
    for (i = 0; i < MAKS; i++) {
        for (j = 0; j < MAKS; j++) {
            if (Peta[i][j] == 0) {
                glLoadIdentity();
                glTranslatef(-11.5f + j, -11.5f + i, 0.5f);
                glutSolidCube(1.0);
            }
        }
    }
    glEndList();
    x = MULAI_X;
    y = MULAI_Y;
    vx = 0.0f;
    vy = 0.0f;
    a = 0;
    b = 0;
    ax = 0.0f;
    ay = 0.0f;

    InisialisasiPoin();  // Initialize the points
}


void Timer(int nilai) {
    vx += ax;
    vy += ay;
    vx *= GESERAN_TANAH;
    vy *= GESERAN_TANAH;
    if (vx > 0) {
        j = (int)(y + 11.6f);
        j2 = (int)(y + 12.4f);
        k = (int)vx;
        tmp = (int)(x + 43.5f) - 30;
        for (i = 0; i < k; i++) {
            if (!Peta[j][tmp] || !Peta[j2][tmp])
                break;
            tmp++;
        }
        if (i == k) {
            tmp = (int)(x + vx + 42.5f) - 30;
            if (Peta[j][tmp] && Peta[j2][tmp])
                i++;
        }
        if (i > k) {
            x += vx;
        } else {
            x = (int)(x + i + 25) - 24.5f;
            vx *= -GESERAN_DINDING;
        }
    } else {
        j = (int)(y + 11.6f);
        j2 = (int)(y + 12.4f);
        k = -(int)vx;
        tmp = (int)(x + 40.5f) - 30;
        for (i = 0; i < k; i++) {
            if (!Peta[j][tmp] || !Peta[j2][tmp])
                break;
            tmp--;
        }
        if (i == k) {
            tmp = (int)(x + vx + 41.5f) - 30;
            if (Peta[j][tmp] && Peta[j2][tmp])
                i++;
        }
        if (i > k) {
            x += vx;
        } else {
            x = (int)(x - i + 25) - 24.5f;
            vx *= -GESERAN_DINDING;
        }
    }
    if (vy > 0) {
        j = (int)(x + 11.6f);
        j2 = (int)(x + 12.4f);
        k = (int)vy;
        tmp = (int)(y + 43.5f) - 30;
        for (i = 0; i < k; i++) {
            if (!Peta[tmp][j] || !Peta[tmp][j2])
                break;
            tmp++;
        }
        if (i == k) {
            tmp = (int)(y + vy + 42.5f) - 30;
            if (Peta[tmp][j] && Peta[tmp][j2])
                i++;
        }
        if (i > k)
            y += vy;
        else {
            y = (int)(y + i + 25) - 24.5f;
            vy *= -GESERAN_DINDING;
        }
    } else {
        j = (int)(x + 11.6f);
        j2 = (int)(x + 12.4f);
        k = -(int)vy;
        tmp = (int)(y + 40.5f) - 30;
        for (i = 0; i < k; i++) {
            if (!Peta[tmp][j] || !Peta[tmp][j2])
                break;
            tmp--;
        }
        if (i == k) {
            tmp = (int)(y + vy + 41.5f) - 30;
            if (Peta[tmp][j] && Peta[tmp][j2])
                i++;
        }
        if (i > k)
            y += vy;
        else {
            y = (int)(y - i + 25) - 24.5f;
            vy *= -GESERAN_DINDING;
        }
    }
    if (ArahHor > -1) {
        if (a == 0) {
            if (!IsPressHor)
                ArahHor = -1;
            else
                a += SudutOffset[ArahHor];
        } else if (a != SudutMaksOffset[ArahHor])
            a += SudutOffset[ArahHor];
    }
    if (ArahVer > -1) {
        if (b == 0) {
            if (!IsPressVer)
                ArahVer = -1;
            else
                b += SudutOffset[ArahVer];
        } else if (b != SudutMaksOffset[ArahVer])
            b += SudutOffset[ArahVer];
    }

    if (score==7) {
        x = MULAI_X;
        y = MULAI_Y;
    }

    // Collect points
    for (int i = 0; i < pointCount; i++) {
        if (!points[i].collected) {
            if (fabs(x - points[i].x) < 0.5f && fabs(y - points[i].y) < 0.5f) {
                points[i].collected = 1;
                score++; // Increment score when collecting a point
            }
        }
    }

    glutPostRedisplay();
    glutTimerFunc(25, Timer, 0);
}

void Spesial(int key, int x, int y)
{
    switch (key) {
    case GLUT_KEY_LEFT:
        ArahHor = 0;
        IsPressHor = 1;
        break;
    case GLUT_KEY_RIGHT:
        ArahHor = 1;
        IsPressHor = 1;
        break;
    case GLUT_KEY_DOWN:
        ArahVer = 0;
        IsPressVer = 1;
        break;
    case GLUT_KEY_UP:
        ArahVer = 1;
        IsPressVer = 1;
        break;
    }
}

void Spesial_Up(int key, int x, int y)
{
    switch (key) {
    case GLUT_KEY_LEFT:
        if (ArahHor == 0) {
            ArahHor = 1;
            IsPressHor = 0;
        }
        break;
    case GLUT_KEY_RIGHT:
        if (ArahHor == 1) {
            ArahHor = 0;
            IsPressHor = 0;
        }
        break;
    case GLUT_KEY_DOWN:
        if (ArahVer == 0) {
            ArahVer = 1;
            IsPressVer = 0;
        }
        break;
    case GLUT_KEY_UP:
        if (ArahVer == 1) {
            ArahVer = 0;
            IsPressVer = 0;
        }
        break;
    }
}

void PapanKunci(GLubyte key, int x, int y)
{
    switch (key) {
    case 'q':
        if (Kamera > KAMERA_MIN)
            Kamera -= 1.0f;
        break;
    case 'w':
        if (Kamera < KAMERA_MAX)
            Kamera += 1.0f;
        break;
    case 'e':
        if (Akselerasi > AKSELERASI_MIN)
            Akselerasi -= 0.01f;
        break;
    case 'r':
        if (Akselerasi < AKSELERASI_MAX)
            Akselerasi += 0.01f;
        break;
    }
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DEPTH | GLUT_DOUBLE);
    glutInitWindowSize(LEBAR, TINGGI);
    glutInitWindowPosition(POS_X, POS_Y);
    glutCreateWindow("Maze");
    Inisialisasi();
    glutSpecialFunc(Spesial);
    glutSpecialUpFunc(Spesial_Up);
    glutKeyboardFunc(PapanKunci);
    glutTimerFunc(0, Timer, 0);
    glutDisplayFunc(Tampilkan);
    glutMainLoop();
}
