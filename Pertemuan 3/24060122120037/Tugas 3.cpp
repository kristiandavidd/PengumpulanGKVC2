
//Nama : Widiawati Sihaloho
//NIM  : 24060122120037
//Deskripsi : Membuat lengan berserta jarinya

#include <GL/glut.h>
#include <string.h>
#include <stdio.h>

static int bahu = 0;
static int siku = 0;
static int telapakTangan = 0;
static int Jarikelingking = 0;
static int Jarimanis = 0;
static int Jaritengah = 0;
static int Jaritelunjuk = 0;
static int Jarijempol = 0;

void init() {
    glClearColor(1, 0.5, 0, 1);
    glShadeModel(GL_FLAT);
}

void display() {
	glColor3f(0.5f, 1.0f, 1.0f);
    glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glPushMatrix();
        glTranslatef (-1.0, 0.0, 0.0);
        glRotatef ((GLfloat) bahu, 0.0, 1.0, 0.0);
        glTranslatef (1.0, 0.0, 0.0);
        glPushMatrix();
            glScalef(2.0, 0.6, 1.0);
            glutWireCube(1.0);
        glPopMatrix();

        glTranslatef (1.0, 0.0, 0.0);
        glRotatef ((GLfloat) siku, 0.0, 0.0, 1.0);
        glTranslatef (1.0, 0.0, 0.0);
        glPushMatrix();
            glScalef (2.0, 0.6, 1.0);
            glutWireCube (1.0);
        glPopMatrix();

        glTranslatef (1.0, 0.0, 0.0);
        glRotatef ((GLfloat) telapakTangan, 0.0, 0.0, 1.0);
        glTranslatef (0.3, 0.0, 0.0);
        glPushMatrix();
            glScalef (0.6, 0.6, 1.0);
            glutWireCube (1.0);
        glPopMatrix();

        glPushMatrix();
                glTranslatef(0.0, 0.0, -0.5);
                glTranslatef(.25, 0., 0.);
                glRotatef((GLfloat) Jarikelingking, 0., 0., 1.);
                glTranslatef(.25, 0., 0.);
                glPushMatrix();
                    glScalef(.5, .25, .25);
                    glutWireCube(1.);
                glPopMatrix();

                glTranslatef(.25, 0., 0.);
                glRotatef((GLfloat) Jarikelingking, 0., 0., 1.);
                glTranslatef(.25, 0., 0.);
                glPushMatrix();
                    glScalef(.5, .25, .25);
                    glutWireCube(1.);
                glPopMatrix();
                
                
        glPopMatrix();

        glPushMatrix();
                glTranslatef(0.0, 0.0, -0.25);
                glTranslatef(.25, 0., 0.);
                glRotatef((GLfloat) Jarimanis, 0., 0., 1.);
                glTranslatef(.25, 0., 0.);
                glPushMatrix();
                    glScalef(.5, .25, .25);
                    glutWireCube(1.);
                glPopMatrix();

                glTranslatef(.25, 0., 0.);
                glRotatef((GLfloat) Jarimanis, 0., 0., 1.);
                glTranslatef(.25, 0., 0.);
                glPushMatrix();
                    glScalef(.5, .25, .25);
                    glutWireCube(1.);
                glPopMatrix();
        glPopMatrix();

        glPushMatrix();
                glTranslatef(0.0, 0.0, 0.0);
                glTranslatef(.25, 0., 0.);
                glRotatef((GLfloat) Jaritengah, 0., 0., 1.);
                glTranslatef(.25, 0., 0.);
                glPushMatrix();
                    glScalef(.5, .25, .25);
                    glutWireCube(1.);
                glPopMatrix();

                glTranslatef(.25, 0., 0.);
                glRotatef((GLfloat) Jaritengah, 0., 0., 1.);
                glTranslatef(.25, 0., 0.);
                glPushMatrix();
                    glScalef(.5, .25, .25);
                    glutWireCube(1.);
                glPopMatrix();
        glPopMatrix();

        glPushMatrix();
                glTranslatef(0.0, 0.0, 0.25);
                glTranslatef(.25, 0., 0.);
                glRotatef((GLfloat) Jaritelunjuk, 0., 0., 1.);
                glTranslatef(.25, 0., 0.);
                glPushMatrix();
                    glScalef(.5, .25, .25);
                    glutWireCube(1.);
                glPopMatrix();

                glTranslatef(.25, 0., 0.);
                glRotatef((GLfloat) Jaritelunjuk, 0., 0., 1.);
                glTranslatef(.25, 0., 0.);
                glPushMatrix();
                    glScalef(.5, .25, .25);
                    glutWireCube(1.);
                glPopMatrix();
        glPopMatrix();

        glPushMatrix();
                glTranslatef(0.0, 0.0, 0.5);
                glTranslatef(.25, 0., 0.);
                glRotatef((GLfloat) Jarijempol, 0., 0., 1.);
                glTranslatef(.25, 0., 0.);
                glPushMatrix();
                    glScalef(.5, .25, .25);
                    glutWireCube(1.);
                glPopMatrix();

                glTranslatef(.25, 0., 0.);
                glRotatef((GLfloat) Jarijempol, 0., 0., 1.);
                glTranslatef(.25, 0., 0.);
                glPushMatrix();
                    glScalef(.5, .25, .25);
                    glutWireCube(1.);
                glPopMatrix();
        glPopMatrix();
    glPopMatrix();
    glutSwapBuffers();
}

void reshape(int w, int h) {
    glViewport(0, 0, (GLsizei) w, (GLsizei) h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(65, (GLfloat) w/ (GLfloat)h, 1.0, 50.0); 
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glTranslatef(0.0, 0.0, -10.0);
}


static void keyboard(unsigned char key, int x, int y) {
    switch (key) {
        case 'd':
            bahu = (bahu + 5) % 360;
            glutPostRedisplay();
            break;
        case 'D':
            bahu = (bahu - 5) % 360;
            glutPostRedisplay();
            break;
        case 's':
            siku = (siku + 5) % 360;
            glutPostRedisplay();
            break;
        case 'S':
            siku = (siku - 5) % 360;
            glutPostRedisplay();
            break;
        case 'q':
            telapakTangan = (telapakTangan + 5) % 360;
            glutPostRedisplay();
            break;
        case 'Q':
            telapakTangan = (telapakTangan - 5) % 360;
            glutPostRedisplay();
            break;
        case 'w':
            Jarikelingking = (Jarikelingking + 5) % 360;
            glutPostRedisplay();
            break;
        case 'W':
            Jarikelingking = (Jarikelingking - 5) % 360;
            glutPostRedisplay();
            break;
        case 'e':
            Jarimanis = (Jarimanis + 5) % 360;
            glutPostRedisplay();
            break;
        case 'E':
            Jarimanis = (Jarimanis - 5) % 360;
            glutPostRedisplay();
        case 'r':
            Jaritengah = (Jaritengah + 5) % 360;
            glutPostRedisplay();
            break;
        case 'R':
            Jaritengah = (Jaritengah - 5) % 360;
            glutPostRedisplay();
        case 't':
            Jaritelunjuk = (Jaritelunjuk + 5) % 360;
            glutPostRedisplay();
            break;
        case 'T':
            Jaritelunjuk = (Jaritelunjuk - 5) % 360;
            glutPostRedisplay();
        case 'y':
            Jarijempol = (Jarijempol + 5) % 360;
            glutPostRedisplay();
            break;
        case 'Y':
            Jarijempol = (Jarijempol - 5) % 360;
            glutPostRedisplay();
        case 27 :
            exit(0);
            break;
        default:
            break;
    }
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(700, 600);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Lengan beserta jari");
    init();
    glutDisplayFunc(display);
    glClearColor(0.0f,0.0f,0.0f,0.0f);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(keyboard);
    glutMainLoop();
    return 0;
}
