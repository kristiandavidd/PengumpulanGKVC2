/*Nama : Rania
 *NIM : 24060122120013
 *Lab : C2
 *Nama File : lenganGerak.cpp
 *Tanggal : 11 Maret 2024
 *Deskripsi : Menampilkan lengan, telapak tangan, dan jari yang bisa bergerak sebagaimana semestinya.*/

#include <GL/glut.h>   
static int shoulderX = 0, shoulderY = 0, shoulderZ = 0,
elbowX = 0, elbowZ = 0,
palmX = 0, palmY = 0, palmZ = 0,
indexfinger1 = 0, indexfinger2 = 0,
middlefinger1 = 0, middlefinger2 = 0,
ringfinger1 = 0, ringfinger2 = 0,
littlefinger1 = 0, littlefinger2 = 0,
thumb1 = 0, thumb2 = 0;


void init(void) {
      glClearColor(0.0, 0.0, 0.0, 0.0);
      glShadeModel(GL_FLAT);
}

void display(void) {
      glClear(GL_COLOR_BUFFER_BIT);
      //shoulder
      glPushMatrix();
      glTranslatef(-1.0, 0.0, 0.0);
      glRotatef((GLfloat)shoulderX, 1.0, 0.0, 0.0);
      glRotatef((GLfloat)shoulderY, 0.0, 1.0, 0.0);
      glRotatef((GLfloat)shoulderZ, 0.0, 0.0, 1.0);
      glTranslatef(-1.0, 0.0, 0.0);

      glPushMatrix();
      glScalef(2.0, 0.5, 1.0);
      glutWireCube(1.0);
      glPopMatrix();

      //elbow
      glTranslatef(1.0, 0.0, 0.0);
      glRotatef((GLfloat)elbowX, 1.0, 0.0, 0.0);
      glRotatef((GLfloat)elbowZ, 0.0, 0.0, 1.0);
      glTranslatef(1.0, 0.0, 0.0);
      glPushMatrix();
      glScalef(2.0, 0.5, 1.0);
      glutWireCube(1.0);
      glPopMatrix();

      //palm
      glTranslatef(1.0, 0.0, 0.0);
      glRotatef((GLfloat)palmX, 1.0, 0.0, 0.0);
      glRotatef((GLfloat)palmY, 0.0, 1.0, 0.0);
      glRotatef((GLfloat)palmZ, 0.0, 0.0, 1.0);
      glTranslatef(0.5, 0.0, 0.0);
      glPushMatrix();
      glScalef(0.9, 0.4, 1.2);
      glutWireCube(1.0);
      glPopMatrix();

      //indexfinger1
      glPushMatrix();
      glTranslatef(0.5, 0.0, 0.7);
      glRotatef(-(GLfloat)indexfinger1, 0.0, 0.0, 1.0);
      glTranslatef(0.15, 0.0, -0.25);
      glPushMatrix();
      glScalef(0.5, 0.15, 0.2);
      glTranslatef(0.2, 0.0, 0.0);
      glutWireCube(1);
      glPopMatrix();

      //indexfinger2
      glTranslatef(0.2, 0.0, -0.7);
      glRotatef(-(GLfloat)indexfinger2, 0.0, 0.0, 1.0);
      glTranslatef(0.25, 0.0, 0.7);
      glPushMatrix();
      glScalef(0.5, 0.15, 0.2);
      glTranslatef(0.3, 0.0, 0.0);
      glutWireCube(1);
      glPopMatrix();

      glPopMatrix();

      //middlefinger1
      glPushMatrix();
      glTranslatef(0.5, 0.0, 0.4);
      glRotatef(-(GLfloat)middlefinger1, 0.0, 0.0, 1.0);
      glTranslatef(0.15, 0.0, -0.25);
      glPushMatrix();
      glScalef(0.6, 0.15, 0.2);
      glTranslatef(0.25, 0.0, 0.0);
      glutWireCube(1);
      glPopMatrix();

      //middlefinger2
      glTranslatef(0.2, 0.0, -0.7);
      glRotatef(-(GLfloat)middlefinger2, 0.0, 0.0, 1.0);
      glTranslatef(0.25, 0.0, 0.7);
      glPushMatrix();
      glScalef(0.6, 0.15, 0.2);
      glTranslatef(0.35, 0.0, 0.0);
      glutWireCube(1);
      glPopMatrix();

      glPopMatrix();

      //ringfinger2
      glPushMatrix();
      glTranslatef(0.5, 0.0, 0.1);
      glRotatef(-(GLfloat)ringfinger1, 0.0, 0.0, 1.0);
      glTranslatef(0.15, 0.0, -0.25);
      glPushMatrix();
      glScalef(0.5, 0.15, 0.2);
      glTranslatef(0.2, 0.0, 0.0);
      glutWireCube(1);
      glPopMatrix();

      //ringfinger2
      glTranslatef(0.2, 0.0, -0.7);
      glRotatef(-(GLfloat)ringfinger2, 0.0, 0.0, 1.0);
      glTranslatef(0.25, 0.0, 0.7);
      glPushMatrix();
      glScalef(0.5, 0.15, 0.2);
      glTranslatef(0.3, 0.0, 0.0);
      glutWireCube(1);
      glPopMatrix();

      glPopMatrix();

      //littlefiger1
      glPushMatrix();
      glTranslatef(0.5, 0.0, -0.2);
      glRotatef(-(GLfloat)littlefinger1, 0.0, 0.0, 1.0);
      glTranslatef(0.15, 0.0, -0.25);
      glPushMatrix();
      glScalef(0.4, 0.15, 0.2);
      glTranslatef(0.15, 0.0, 0.0);
      glutWireCube(1);
      glPopMatrix();

      //littlefiger2
      glTranslatef(0.2, 0.0, -0.7);
      glRotatef(-(GLfloat)littlefinger2, 0.0, 0.0, 1.0);
      glTranslatef(0.25, 0.0, 0.7);
      glPushMatrix();
      glScalef(0.4, 0.15, 0.2);
      glTranslatef(0.05, 0.0, 0.0);
      glutWireCube(1);
      glPopMatrix();

      glPopMatrix();

      //thumb1
      glPushMatrix();
      glTranslatef(-0.35, 0.0, 0.74);
      glRotatef((GLfloat)thumb1, 1.0, 0.0, 0.0);
      glTranslatef(0.4, 0.0, 0.0);
      glPushMatrix();
      glScalef(0.3, 0.1, 0.25);
      glutWireCube(1);
      glPopMatrix();

      //thumb2
      glTranslatef(-0.5, 0.0, 0.27);
      glRotatef((GLfloat)thumb2, 1.0, 0.0, 0.0);
      glTranslatef(0.5, 0.0, 0.0);
      glPushMatrix();
      glScalef(0.2, 0.15, 0.25);
      glutWireCube(1);
      glPopMatrix();

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
      case 'q': shoulderX = (shoulderX + 5) % 360;
            glutPostRedisplay();
            break;
      case 'Q': shoulderX = (shoulderX - 5) % 360;
            glutPostRedisplay();
            break;
      case 'w': shoulderY = (shoulderY + 5) % 180;
            glutPostRedisplay();
            break;
      case 'W': shoulderY = (shoulderY - 5) % 180;
            glutPostRedisplay();
            break;
      case 's': shoulderZ = (shoulderZ + 5) % 360;
            glutPostRedisplay();
            break;
      case 'S': shoulderZ = (shoulderZ - 5) % 360;
            glutPostRedisplay();
            break;
      case 'e': elbowX = (elbowX + 5) % 90;
            glutPostRedisplay();
            break;
      case 'E': elbowX = (elbowX - 5) % 90;
            glutPostRedisplay();
            break;
      case 'y': elbowZ = (elbowZ + 5) % 90;
            glutPostRedisplay();
            break;
      case 'Y': elbowZ = (elbowZ - 5) % 90;
            glutPostRedisplay();
            break;
      case 'p': palmX = (palmX + 5) % 180;
            glutPostRedisplay();
            break;
      case 'P': palmX = (palmX - 5) % 180;
            glutPostRedisplay();
            break;
      case 't': palmY = (palmY + 5) % 20;
            glutPostRedisplay();
            break;
      case 'T': palmY = (palmY - 5) % 20;
            glutPostRedisplay();
            break;
      case 'u': palmZ = (palmZ + 5) % 90;
            glutPostRedisplay();
            break;
      case 'U': palmZ = (palmZ - 5) % 90;
            glutPostRedisplay();
            break;
      case 'f':
            if (indexfinger1 < 90)
                  indexfinger1 = (indexfinger1 + 5) % 360;
            if (middlefinger1 < 90)
                  middlefinger1 = (middlefinger1 + 5) % 360;
            if (ringfinger1 < 90)
                  ringfinger1 = (ringfinger1 + 5) % 360;
            if (littlefinger1 < 90)
                  littlefinger1 = (littlefinger1 + 5) % 360;
            if (thumb1 < 90)
                  thumb1 = (thumb1 + 5) % 360;
            glutPostRedisplay();
            break;
      case 'F':
            if (indexfinger1 > 0)
                  indexfinger1 = (indexfinger1 - 5) % 360;
            if (middlefinger1 > 0)
                  middlefinger1 = (middlefinger1 - 5) % 360;
            if (ringfinger1 > 0)
                  ringfinger1 = (ringfinger1 - 5) % 360;
            if (littlefinger1 > 0)
                  littlefinger1 = (littlefinger1 - 5) % 360;
            if (thumb1 > 0)
                  thumb1 = (thumb1 - 5) % 360;
            glutPostRedisplay();
            break;
      case 'j':
            if (indexfinger2 < 130 && middlefinger2 < 130 && ringfinger2 < 130 && littlefinger2 < 130 && thumb2 < 130) {
                  indexfinger2 = (indexfinger2 + 5) % 360;
                  middlefinger2 = (middlefinger2 + 5) % 360;
                  ringfinger2 = (ringfinger2 + 5) % 360;
                  littlefinger2 = (littlefinger2 + 5) % 360;
                  thumb2 = (thumb2 + 5) % 360;
            }
            glutPostRedisplay();
            break;
      case 'J':
            if (indexfinger2 > 0 && middlefinger2 > 0 && ringfinger2 > 0 && littlefinger2 > 0 && thumb2 > 0) {
                  indexfinger2 = (indexfinger2 - 5) % 360;
                  middlefinger2 = (middlefinger2 - 5) % 360;
                  ringfinger2 = (ringfinger2 - 5) % 360;
                  littlefinger2 = (littlefinger2 - 5) % 360;
                  thumb2 = (thumb2 - 5) % 360;
            }
            glutPostRedisplay();
            break;
      case '1':
            if (indexfinger1 < 90)
                  indexfinger1 = (indexfinger1 + 5) % 360;
            glutPostRedisplay();
            break;
      case '!':
            if (indexfinger1 > 0)
                  indexfinger1 = (indexfinger1 - 5) % 360;
            glutPostRedisplay();
            break;
      case '2':
            if (middlefinger1 < 90)
                  middlefinger1 = (middlefinger1 + 5) % 360;
            glutPostRedisplay();
            break;
      case '@':
            if (middlefinger1 > 0)
                  middlefinger1 = (middlefinger1 - 5) % 360;
            glutPostRedisplay();
            break;
      case '3':
            if (ringfinger1 < 90)
                  ringfinger1 = (ringfinger1 + 5) % 360;
            glutPostRedisplay();
            break;
      case '#':
            if (ringfinger1 > 0)
                  ringfinger1 = (ringfinger1 - 5) % 360;
            glutPostRedisplay();
            break;
      case '4':
            if (littlefinger1 < 90)
                  littlefinger1 = (littlefinger1 + 5) % 360;
            glutPostRedisplay();
            break;
      case '$':
            if (littlefinger1 > 0)
                  littlefinger1 = (littlefinger1 - 5) % 360;
            glutPostRedisplay();
            break;
      case '5':
            if (thumb1 < 90)
                  thumb1 = (thumb1 + 5) % 360;
            glutPostRedisplay();
            break;
      case '%':
            if (thumb1 > 0)
                  thumb1 = (thumb1 - 5) % 360;
            glutPostRedisplay();
            break;
      case 'r':
            if (indexfinger1 < 90)
                  indexfinger1 = (indexfinger1 + 5) % 360;
            if (littlefinger1 < 90)
                  littlefinger1 = (littlefinger1 + 5) % 360;
            if (thumb1 < 90)
                  thumb1 = (thumb1 + 5) % 360;
            glutPostRedisplay();
            break;
      case 'R':
            if (indexfinger1 > 0)
                  indexfinger1 = (indexfinger1 - 5) % 360;
            if (littlefinger1 > 0)
                  littlefinger1 = (littlefinger1 - 5) % 360;
            if (thumb1 > 0)
                  thumb1 = (thumb1 - 5) % 360;
            glutPostRedisplay();
            break;
      case 'd':
            if (indexfinger1 < 90)
                  indexfinger1 = (indexfinger1 + 5) % 360;
            if (middlefinger1 < 90)
                  middlefinger1 = (middlefinger1 + 5) % 360;
            glutPostRedisplay();
            break;
      case 'D':
            if (indexfinger1 > 0)
                  indexfinger1 = (indexfinger1 - 5) % 360;
            if (middlefinger1 > 0)
                  middlefinger1 = (middlefinger1 - 5) % 360;
            glutPostRedisplay();
            break;
      case 'g':
            if (indexfinger1 < 90)
                  indexfinger1 = (indexfinger1 + 5) % 360;
            if (middlefinger1 < 90)
                  middlefinger1 = (middlefinger1 + 5) % 360;
            if (ringfinger1 < 90)
                  ringfinger1 = (ringfinger1 + 5) % 360;
            glutPostRedisplay();
            break;
      case 'G':
            if (indexfinger1 > 0)
                  indexfinger1 = (indexfinger1 - 5) % 360;
            if (middlefinger1 > 0)
                  middlefinger1 = (middlefinger1 - 5) % 360;
            if (ringfinger1 > 0)
                  ringfinger1 = (ringfinger1 - 5) % 360;
            glutPostRedisplay();
            break;
      case 'k':
            if (indexfinger1 < 90)
                  indexfinger1 = (indexfinger1 + 5) % 360;
            if (middlefinger1 < 90)
                  middlefinger1 = (middlefinger1 + 5) % 360;
            if (ringfinger1 < 90)
                  ringfinger1 = (ringfinger1 + 5) % 360;
            if (littlefinger1 < 90)
                  littlefinger1 = (littlefinger1 + 5) % 360;
            glutPostRedisplay();
            break;
      case 'K':
            if (indexfinger1 > 0)
                  indexfinger1 = (indexfinger1 - 5) % 360;
            if (middlefinger1 > 0)
                  middlefinger1 = (middlefinger1 - 5) % 360;
            if (ringfinger1 > 0)
                  ringfinger1 = (ringfinger1 - 5) % 360;
            if (littlefinger1 > 0)
                  littlefinger1 = (littlefinger1 - 5) % 360;
            glutPostRedisplay();
            break;
      case 27:
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
      glutCreateWindow(argv[0]);
      init();
      glutDisplayFunc(display);
      glutReshapeFunc(reshape);
      glutKeyboardFunc(keyboard);
      glutMainLoop();
      return 0;
}
