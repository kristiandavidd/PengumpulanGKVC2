//Sajid Nouval - 24060122140110
#include <GL/glut.h>

// Variabel lengan
static int shoulderX1 = 0, shoulderX2 = 0, shoulderY = 0;

// Variabel telapak tangan
static int palm1 = 0, palm2 = 0;

// Variabel ibu jari
static int thumbBase = 0, thumbUpper = 0, thumbEnd = 0;

// Variabel jari telunjuk
static int indexFinger1 = 0, indexFinger2 = 0, indexFinger3 = 0;

// Variabel jari tengah
static int middleFinger1 = 0, middleFinger2 = 0, middleFinger3 = 0;

// Variabel jari manis
static int ringFinger1 = 0, ringFinger2 = 0, ringFinger3 = 0;

// Variabel jari kelingking
static int pinkyFinger1 = 0, pinkyFinger2 = 0, pinkyFinger3 = 0;

// Variabel untuk rotasi telapak tangan
static int palmRotation1 = 0, palmRotation2 = 0;

void init(void)
{
    glClearColor(0, 0, 0, 0);
    glShadeModel(GL_FLAT);
}

void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    glPushMatrix();

    // Lengan Bagian Atas
    glTranslatef(-1.8, 0, 0);
    glRotatef((GLfloat)shoulderX1, 0, 0, 1);
    glRotatef((GLfloat)shoulderX2, 0, 1, 0);
    glTranslatef(1.8, 0, 0);
    glPushMatrix();
    glTranslatef(-1.4, 0, 0);
    glScalef(0.8, 0.2, 0.56);
    glutWireCube(1);
    glPopMatrix();

    // Lengan Bagian Bawah
    glTranslatef(-1, 0, 0);
    glRotatef((GLfloat)shoulderY, 0, 0, 1);
    glTranslatef(1, 0, 0);
    glPushMatrix();
    glTranslatef(-0.6, 0, 0);
    glScalef(0.8, 0.2, 0.56);
    glutWireCube(1);
    glPopMatrix();

    // Telapak Tangan
    glRotatef((GLfloat)palmRotation1, 1, 0, 0);
    glRotatef((GLfloat)palmRotation2, 0, 0, 1);
    glPushMatrix();
    glScalef(0.4, 0.2, 0.56);
    glutWireCube(1.0);
    glPopMatrix();

    // Ibu Jari
    glPushMatrix();
    glTranslatef(0, 0, 0.38);
    glRotatef((GLfloat)-thumbEnd, 1, 0, 0);
    glRotatef((GLfloat)thumbBase, 0, 1, 0);
    glPushMatrix();
    glScalef(0.1, 0.1, 0.2);
    glutWireCube(1.0);
    glPopMatrix();
    glTranslatef(0, 0, 0.2);
    glRotatef((GLfloat)-thumbUpper, 1, 0, 0);
    glPushMatrix();
    glScalef(0.1, 0.1, 0.25);
    glutWireCube(1.0);
    glPopMatrix();
    glPopMatrix();

    // Jari Telunjuk
    glPushMatrix();
    glTranslatef(0.3, 0, 0.22);
    glRotatef((GLfloat)indexFinger1, 0, 0, 1);
    glPushMatrix();
    glScalef(0.2, 0.1, 0.13);
    glutWireCube(1.0);
    glPopMatrix();
    glTranslatef(0.2, 0, 0);
    glRotatef((GLfloat)indexFinger2, 0, 0, 1);
    glPushMatrix();
    glScalef(0.22, 0.1, 0.13);
    glutWireCube(1.0);
    glPopMatrix();
    glTranslatef(0.22, 0, 0);
    glRotatef((GLfloat)indexFinger3, 0, 0, 1);
    glPushMatrix();
    glScalef(0.21, 0.1, 0.13);
    glutWireCube(1.0);
    glPopMatrix();
    glPopMatrix();

    // Jari Tengah
    glPushMatrix();
    glTranslatef(0.3, 0, 0.05);
    glRotatef((GLfloat)middleFinger1, 0, 0, 1);
    glPushMatrix();
    glScalef(0.25, 0.1, 0.14);
    glutWireCube(1.0);
    glPopMatrix();
    glTranslatef(0.25, 0, 0);
    glRotatef((GLfloat)middleFinger2, 0, 0, 1);
    glPushMatrix();
    glScalef(0.27, 0.1, 0.14);
    glutWireCube(1.0);
    glPopMatrix();
    glTranslatef(0.27, 0, 0);
    glRotatef((GLfloat)middleFinger3, 0, 0, 1);
    glPushMatrix();
    glScalef(0.21, 0.1, 0.14);
    glutWireCube(1.0);
    glPopMatrix();
    glPopMatrix();

    // Jari Manis
    glPushMatrix();
    glTranslatef(0.3, 0, -0.1);
    glRotatef((GLfloat)ringFinger1, 0, 0, 1);
    glPushMatrix();
    glScalef(0.2, 0.1, 0.11);
    glutWireCube(1.0);
    glPopMatrix();
    glTranslatef(0.2, 0, 0);
    glRotatef((GLfloat)ringFinger2, 0, 0, 1);
    glPushMatrix();
    glScalef(0.21, 0.1, 0.11);
    glutWireCube(1.0);
    glPopMatrix();
    glTranslatef(0.21, 0, 0);
    glRotatef((GLfloat)ringFinger3, 0, 0, 1);
    glPushMatrix();
    glScalef(0.2, 0.1, 0.11);
    glutWireCube(1.0);
    glPopMatrix();
    glPopMatrix();

    // Jari Kelingking
    glPushMatrix();
    glTranslatef(0.3, 0, -0.21);
    glRotatef((GLfloat)pinkyFinger1, 0, 0, 1);
    glPushMatrix();
    glScalef(0.18, 0.1, 0.1);
    glutWireCube(1.0);
    glPopMatrix();
    glTranslatef(0.18, 0, 0);
    glRotatef((GLfloat)pinkyFinger2, 0, 0, 1);
    glPushMatrix();
    glScalef(0.17, 0.1, 0.1);
    glutWireCube(1.0);
    glPopMatrix();
    glTranslatef(0.17, 0, 0);
    glRotatef((GLfloat)pinkyFinger3, 0, 0, 1);
    glPushMatrix();
    glScalef(0.19, 0.1, 0.1);
    glutWireCube(1.0);
    glPopMatrix();
    glPopMatrix();

    glPopMatrix();
    glutSwapBuffers();
}

void reshape(int w, int h)
{
    glViewport(0, 0, (GLsizei)w, (GLsizei)h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(65.0, (GLfloat)w / (GLfloat)h, 1.0, 20.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glTranslatef(0.0, 0.0, -5.0);
}

void keyboard(unsigned char key, int x, int y)
{
    switch (key)
    {
    // Rotasi lengan bagian Atas
    case '1':
        shoulderX1 = (shoulderX1 + 5) % 360;
        if (shoulderX1 > 110)
            shoulderX1 = 110;
        glutPostRedisplay();
        break;
    case '2':
        shoulderX1 = (shoulderX1 - 5) % 360;
        if (shoulderX1 < -110)
            shoulderX1 = -110;
        glutPostRedisplay();
        break;
    case '3':
        shoulderX2 = (shoulderX2 + 5) % 360;
        if (shoulderX2 > 90)
            shoulderX2 = 90;
        glutPostRedisplay();
        break;
    case '4':
        shoulderX2 = (shoulderX2 - 5) % 360;
        if (shoulderX2 < -90)
            shoulderX2 = -90;
        glutPostRedisplay();
        break;

    // Rotasi lengan Bagaian bawah
    case 'q':
        shoulderY = (shoulderY + 5) % 360;
        if (shoulderY > 120)
            shoulderY = 120;
        glutPostRedisplay();
        break;
    case 'Q':
        shoulderY = (shoulderY - 5) % 360;
        if (shoulderY < 0)
            shoulderY = 0;
        glutPostRedisplay();
        break;

    // Rotasi Telapak Tangan
    case 'w':
        palmRotation1 = (palmRotation1 + 5) % 360;
        if (palmRotation1 > 90)
            palmRotation1 = 90;
        glutPostRedisplay();
        break;
    case 'W':
        palmRotation1 = (palmRotation1 - 5) % 360;
        if (palmRotation1 < -90)
            palmRotation1 = -90;
        glutPostRedisplay();
        break;
    case 'z':
        palmRotation2 = (palmRotation2 + 5) % 360;
        if (palmRotation2 > 90)
            palmRotation2 = 90;
        glutPostRedisplay();
        break;
    case 'Z':
        palmRotation2 = (palmRotation2 - 5) % 360;
        if (palmRotation2 < 0)
            palmRotation2 = 0;
        glutPostRedisplay();
        break;

    // Rotasi Ibu Jari
    case 'x':
        thumbEnd = (thumbEnd - 5) % 360;
        if (thumbEnd < 0)
            thumbEnd = 0;
        glutPostRedisplay();
        break;
    case 'X':
        thumbEnd = (thumbEnd + 5) % 360;
        if (thumbEnd > 90)
            thumbEnd = 90;
        glutPostRedisplay();
        break;
    case 'c':
        thumbBase = (thumbBase - 5) % 360;
        if (thumbBase < 0)
            thumbBase = 0;
        glutPostRedisplay();
        break;
    case 'C':
        thumbBase = (thumbBase + 5) % 360;
        if (thumbBase > 90)
            thumbBase = 90;
        glutPostRedisplay();
        break;
    case 'd':
        thumbUpper = (thumbUpper - 5) % 360;
        if (thumbUpper < 0)
            thumbUpper = 0;
        glutPostRedisplay();
        break;
    case 'D':
        thumbUpper = (thumbUpper + 5) % 360;
        if (thumbUpper > 90)
            thumbUpper = 90;
        glutPostRedisplay();
        break;

    // Rotasi Jari Telunjuk
    case 'e':
        indexFinger1 = (indexFinger1 - 5) % 360;
        if (indexFinger1 < 0)
            indexFinger1 = 0;
        glutPostRedisplay();
        break;
    case 'E':
        indexFinger1 = (indexFinger1 + 5) % 360;
        if (indexFinger1 > 90)
            indexFinger1 = 90;
        glutPostRedisplay();
        break;
    case 'f':
        indexFinger2 = (indexFinger2 - 5) % 360;
        if (indexFinger2 < 0)
            indexFinger2 = 0;
        glutPostRedisplay();
        break;
    case 'F':
        indexFinger2 = (indexFinger2 + 5) % 360;
        if (indexFinger2 > 90)
            indexFinger2 = 90;
        glutPostRedisplay();
        break;
    case 'v':
        indexFinger3 = (indexFinger3 - 5) % 360;
        if (indexFinger3 < 0)
            indexFinger3 = 0;
        glutPostRedisplay();
        break;
    case 'V':
        indexFinger3 = (indexFinger3 + 5) % 360;
        if (indexFinger3 > 90)
            indexFinger3 = 90;
        glutPostRedisplay();
        break;

    // Rotasi Jari Tengah
    case 'r':
        middleFinger1 = (middleFinger1 - 5) % 360;
        if (middleFinger1 < 0)
            middleFinger1 = 0;
        glutPostRedisplay();
        break;
    case 'R':
        middleFinger1 = (middleFinger1 + 5) % 360;
        if (middleFinger1 > 90)
            middleFinger1 = 90;
        glutPostRedisplay();
        break;
    case 't':
        middleFinger2 = (middleFinger2 - 5) % 360;
        if (middleFinger2 < 0)
            middleFinger2 = 0;
        glutPostRedisplay();
        break;
    case 'T':
        middleFinger2 = (middleFinger2 + 5) % 360;
        if (middleFinger2 > 90)
            middleFinger2 = 90;
        glutPostRedisplay();
        break;
    case 'n':
        middleFinger3 = (middleFinger3 - 5) % 360;
        if (middleFinger3 < 0)
            middleFinger3 = 0;
        glutPostRedisplay();
        break;
    case 'N':
        middleFinger3 = (middleFinger3 + 5) % 360;
        if (middleFinger3 > 90)
            middleFinger3 = 90;
        glutPostRedisplay();
        break;

    // Rotasi Jari Manis
    case 'y':
        ringFinger1 = (ringFinger1 - 5) % 360;
        if (ringFinger1 < 0)
            ringFinger1 = 0;
        glutPostRedisplay();
        break;
    case 'Y':
        ringFinger1 = (ringFinger1 + 5) % 360;
        if (ringFinger1 > 90)
            ringFinger1 = 90;
        glutPostRedisplay();
        break;
    case 'u':
        ringFinger2 = (ringFinger2 - 5) % 360;
        if (ringFinger2 < 0)
            ringFinger2 = 0;
        glutPostRedisplay();
        break;
    case 'U':
        ringFinger2 = (ringFinger2 + 5) % 360;
        if (ringFinger2 > 90)
            ringFinger2 = 90;
        glutPostRedisplay();
        break;
    case 'm':
        ringFinger3 = (ringFinger3 - 5) % 360;
        if (ringFinger3 < 0)
            ringFinger3 = 0;
        glutPostRedisplay();
        break;
    case 'M':
        ringFinger3 = (ringFinger3 + 5) % 360;
        if (ringFinger3 > 90)
            ringFinger3 = 90;
        glutPostRedisplay();
        break;

    // Rotasi Jari Kelingking
    case 'o':
        pinkyFinger1 = (pinkyFinger1 - 5) % 360;
        if (pinkyFinger1 < 0)
            pinkyFinger1 = 0;
        glutPostRedisplay();
        break;
    case 'O':
        pinkyFinger1 = (pinkyFinger1 + 5) % 360;
        if (pinkyFinger1 > 90)
            pinkyFinger1 = 90;
        glutPostRedisplay();
        break;
    case 'p':
        pinkyFinger2 = (pinkyFinger2 - 5) % 360;
        if (pinkyFinger2 < 0)
            pinkyFinger2 = 0;
        glutPostRedisplay();
        break;
    case 'P':
        pinkyFinger2 = (pinkyFinger2 + 5) % 360;
        if (pinkyFinger2 > 90)
            pinkyFinger2 = 90;
        glutPostRedisplay();
        break;
    case 's':
        pinkyFinger3 = (pinkyFinger3 - 5) % 360;
        if (pinkyFinger3 < 0)
            pinkyFinger3 = 0;
        glutPostRedisplay();
        break;
    case 'S':
        pinkyFinger3 = (pinkyFinger3 + 5) % 360;
        if (pinkyFinger3 > 90)
            pinkyFinger3 = 90;
        glutPostRedisplay();
        break;

    // Reset Posisi
    case '0':
        shoulderX1 = shoulderX2 = shoulderY = 0;
        palm1 = palm2 = 0;
        thumbBase = thumbUpper = thumbEnd = 0;
        indexFinger1 = indexFinger2 = indexFinger3 = 0;
        middleFinger1 = middleFinger2 = middleFinger3 = 0;
        ringFinger1 = ringFinger2 = ringFinger3 = 0;
        pinkyFinger1 = pinkyFinger2 = pinkyFinger3 = 0;
        glutPostRedisplay();
        break;

    // Keluar dari Program
    case 27:
        exit(0);
        break;

    default:
        break;
    }
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(800, 600);
    glutInitWindowPosition(100, 100);
    glutCreateWindow(argv[0]);
    init();
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(keyboard);
    glutMainLoop();
    return 0;
}

