/*
Nama        : Ayyub Al Anshor
NIM         : 24060122130054
LAB         : C2
Pertemuan   : 3
*/
#include <GL/glut.h>
static int thumb1 = 0, thumb2 = 0, thumb3 = 0;
static int indexFinger1 = 0, indexFinger2 = 0, indexFinger3 = 0;
static int middleFinger1 = 0, middleFinger2 = 0, middleFinger3 = 0;
static int ringFinger1 = 0, ringFinger2 = 0, ringFinger3 = 0;
static int littleFinger1 = 0, littleFinger2 = 0, littleFinger3 = 0;
static int palm1 = 0, palm2 = 0;
static int armX1 = 0, armX2 = 0, armY = 0;

void init(void)
{
    glClearColor(0, 0, 0, 0);
    glShadeModel(GL_FLAT);
}

void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    glPushMatrix();
    // Upper Arm
    glTranslatef(-1.8, 0, 0);
    glRotatef((GLfloat)armX1, 0, 0, 1);
    glRotatef((GLfloat)armX2, 0, 1, 0);
    glTranslatef(1.8, 0, 0);
    glPushMatrix();
    glTranslatef(-1.4, 0, 0);
    glScalef(0.8, 0.2, 0.56);
    glutWireCube(1);
    glPopMatrix();

    // Lower Arm
    glTranslatef(-1, 0, 0);
    glRotatef((GLfloat)armY, 0, 0, 1);
    glTranslatef(1, 0, 0);
    glPushMatrix();
    glTranslatef(-0.6, 0, 0);
    glScalef(0.8, 0.2, 0.56);
    glutWireCube(1);
    glPopMatrix();

    // Palm
    glRotatef((GLfloat)palm1, 1, 0, 0);
    glRotatef((GLfloat)palm2, 0, 0, 1);
    glPushMatrix();
    glScalef(0.4, 0.2, 0.56);
    glutWireCube(1.0);
    glPopMatrix();

    // Thumb
    glPushMatrix();
    glTranslatef(0, 0, 0.38);
    glRotatef((GLfloat)-thumb3, 1, 0, 0);
    glRotatef((GLfloat)thumb1, 0, 1, 0);
    glPushMatrix();
    glScalef(0.1, 0.1, 0.2);
    glutWireCube(1.0);
    glPopMatrix();
    glTranslatef(0, 0, 0.2);
    glRotatef((GLfloat)-thumb2, 1, 0, 0);
    glPushMatrix();
    glScalef(0.1, 0.1, 0.25);
    glutWireCube(1.0);
    glPopMatrix();
    glPopMatrix();

    // Index Finger
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

    // Middle Finger
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

    // Ring Finger
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

    // Little Finger
    glPushMatrix();
    glTranslatef(0.3, 0, -0.21);
    glRotatef((GLfloat)littleFinger1, 0, 0, 1);
    glPushMatrix();
    glScalef(0.18, 0.1, 0.1);
    glutWireCube(1.0);
    glPopMatrix();
    glTranslatef(0.18, 0, 0);
    glRotatef((GLfloat)littleFinger2, 0, 0, 1);
    glPushMatrix();
    glScalef(0.17, 0.1, 0.1);
    glutWireCube(1.0);
    glPopMatrix();
    glTranslatef(0.17, 0, 0);
    glRotatef((GLfloat)littleFinger3, 0, 0, 1);
    glPushMatrix();
    glScalef(0.19, 0.1, 0.1);
    glutWireCube(1.0);
    glPopMatrix();
    glPopMatrix();

    glPopMatrix();
    glutSwapBuffers();
}

void reshape(int w, int h) {
    glViewport(0, 0, (GLsizei)w, (GLsizei)h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(65.0, (GLfloat)w / (GLfloat)h, 1.0, 20.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glTranslatef(0.0, 0.0, -5.0);
}

void keyboard(unsigned char key, int x, int y) {
    switch (key) {
        // Upper Arm
    case 'q': armX1 = (armX1 + 5) % 360;
        if (armX1 > 110) armX1 = 110;
        glutPostRedisplay();
        break;
    case 'w': armX1 = (armX1 - 5) % 360;
        if (armX1 < -110) armX1 = -110;
        glutPostRedisplay();
        break;
    case 'e': armX2 = (armX2 + 5) % 360;
        if (armX2 > 90) armX2 = 90;
        glutPostRedisplay();
        break;
    case 'r': armX2 = (armX2 - 5) % 360;
        if (armX2 < -90) armX2 = -90;
        glutPostRedisplay();
        break;

        // Lower Arm
    case 't': armY = (armY + 5) % 360;
        if (armY > 120) armY = 120;
        glutPostRedisplay();
        break;
    case 'a': armY = (armY - 5) % 360;
        if (armY < 0) armY = 0;
        glutPostRedisplay();
        break;

        // Palm
    case 's': palm1 = (palm1 + 5) % 360;
        if (palm1 > 90) palm1 = 90;
        glutPostRedisplay();
        break;
    case 'd': palm1 = (palm1 - 5) % 360;
        if (palm1 < -90) palm1 = -90;
        glutPostRedisplay();
        break;
    case 'f': palm2 = (palm2 + 5) % 360;
        if (palm2 > 90) palm2 = 90;
        glutPostRedisplay();
        break;
    case 'g': palm2 = (palm2 - 5) % 360;
        if (palm2 < 0) palm2 = 0;
        glutPostRedisplay();
        break;

    case 27: /*exit(10);*/

        // Use Tab key to reset
    case 9: thumb1 = thumb2 = thumb3 =
        armX1 = armX2 = armY = littleFinger1 = littleFinger2 = littleFinger3 = middleFinger1
        = middleFinger2 = middleFinger3 = indexFinger1 = indexFinger2 = indexFinger3 = palm1 =
        palm2 = 0;
        glutPostRedisplay();
        break;
    default:break;
    }
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(640, 480);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Arm");
    init();
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(keyboard);
    glutMainLoop();
    return 0;
}
