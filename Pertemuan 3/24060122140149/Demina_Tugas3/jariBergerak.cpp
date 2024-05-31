/*  Nama     :Demina Ayunda Chesara
    NIM      :24060122140149
    Tugas Praktikum 3 GKV
*/
#include <GL/glut.h> 
static int shoulder = 0, elbow = 0;
static int palm = 0;
static int thumb1 = 0, thumb2 = 0, thumb3 = 0;
static int index1 = 0, index2 = 0, index3 = 0;
static int middle1 = 0, middle2 = 0, middle3 = 0;
static int ring1 = 0, ring2 = 0, ring3 = 0;
static int pinky1 = 0, pinky2 = 0, pinky3 = 0;

void init(void) {
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glShadeModel(GL_FLAT);
}

void display(void) {
    glClear(GL_COLOR_BUFFER_BIT);

    // shoulder
    glPushMatrix();
    glTranslatef(-1.0, 0.0, 0.0);
    glRotatef((GLfloat)shoulder, 0.0, 0.0, 1.0);
    glTranslatef(1.0, 0.0, 0.0);
    glPushMatrix();
    glScalef(2.0, 0.4, 1.0);
    glutWireCube(1.0);
    glPopMatrix();

    // elbow
    glTranslatef(1.0, 0.0, 0.0);
    glRotatef((GLfloat)elbow, 0.0, 0.0, 1.0);
    glTranslatef(1.0, 0.0, 0.0);
    glPushMatrix();
    glScalef(2.0, 0.4, 1.0);
    glutWireCube(1.0);
    glPopMatrix();

    // telapak tangan (palm)
    glTranslatef(0.1, 0.0, 0.0); // posisi palm
    glRotatef((GLfloat)palm, 1.0, 0.0, 0.0);
    glTranslatef(1.0, 0.0, 0.0);
    glPushMatrix();
    glScalef(0.9, 0.4, 0.7);
    glutWireCube(1.0);
    glPopMatrix();

    // Menggambar jari-jari

    // thumbs (jempol)
    glPushMatrix();
    glTranslatef(0, 0, 0.4); // posisi jari
    glRotatef((GLfloat)-thumb1, 1, 0, 0);
    glRotatef((GLfloat)thumb2, 0, 1, 0);
    glPushMatrix();
    glScalef(0.1, 0.1, 0.2); // memperkecil
    glutWireCube(1.0); // menggambar kubus
    glPopMatrix();

    glTranslatef(0, 0, 0.2);
    glRotatef((GLfloat)-thumb3, 1, 0, 0);
    glPushMatrix();
    glScalef(0.1, 0.1, 0.25);
    glutWireCube(1.0);
    glPopMatrix();
    glPopMatrix();

    // index finger (telunjuk)
    glPushMatrix();
    glTranslatef(0.4, 0, 0.2); // posisi telunjuk
    glRotatef((GLfloat)index1, 0, 0, 1);
    glPushMatrix();
    glScalef(0.23, 0.1, 0.1); //ngecilin
    glutWireCube(1.0);
    glPopMatrix();

    glTranslatef(0.2, 0, 0);
    glRotatef((GLfloat)index2, 0, 0, 1);
    glPushMatrix();
    glScalef(0.2, 0.1, 0.1);
    glutWireCube(1.0);
    glPopMatrix();

    glTranslatef(0.2, 0, 0);
    glRotatef((GLfloat)index3, 0, 0, 1);
    glPushMatrix();
    glScalef(0.2, 0.1, 0.1);
    glutWireCube(1.0);
    glPopMatrix();
    glPopMatrix();

    // middle finger (jari tengah)
    glPushMatrix();
    glTranslatef(0.4, 0, 0.05); // posisi jari 
    glRotatef((GLfloat)middle1, 0, 0, 1);
    glPushMatrix();
    glScalef(0.3, 0.1, 0.1);
    glutWireCube(1.0);
    glPopMatrix();

    glTranslatef(0.2, 0, 0);
    glRotatef((GLfloat)middle2, 0, 0, 1);
    glPushMatrix();
    glScalef(0.4, 0.1, 0.1);
    glutWireCube(1.0);
    glPopMatrix();

    glTranslatef(0.2, 0, 0);
    glRotatef((GLfloat)middle3, 0, 0, 1);
    glPushMatrix();
    glScalef(0.4, 0.1, 0.1);
    glutWireCube(1.0);
    glPopMatrix();
    glPopMatrix();

    // ring finger (jari manis)
    glPushMatrix();
    glTranslatef(0.4, 0, -0.1); // posisi jari 
    glRotatef((GLfloat)ring1, 0, 0, 1);
    glPushMatrix();
    glScalef(0.23, 0.1, 0.1);
    glutWireCube(1.0);
    glPopMatrix();

    glTranslatef(0.2, 0, 0);
    glRotatef((GLfloat)ring2, 0, 0, 1);
    glPushMatrix();
    glScalef(0.2, 0.1, 0.1);
    glutWireCube(1.0);
    glPopMatrix();

    glTranslatef(0.2, 0, 0);
    glRotatef((GLfloat)ring3, 0, 0, 1);
    glPushMatrix();
    glScalef(0.2, 0.1, 0.1);
    glutWireCube(1.0);
    glPopMatrix();
    glPopMatrix();

    // pinky finger (jari kelingking)
    glPushMatrix();
    glTranslatef(0.4, 0, -0.25); // posisi jari 
    glRotatef((GLfloat)pinky1, 0, 0, 1);
    glPushMatrix();
    glScalef(0.22, 0.1, 0.1);
    glutWireCube(1.0);
    glPopMatrix();

    glTranslatef(0.15, 0, 0);
    glRotatef((GLfloat)pinky2, 0, 0, 1);
    glPushMatrix();
    glScalef(0.22, 0.1, 0.1);
    glutWireCube(1.0);
    glPopMatrix();

    glTranslatef(0.1, 0, 0);
    glRotatef((GLfloat)pinky3, 0, 0, 1);
    glPushMatrix();
    glScalef(0.22, 0.1, 0.1);
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
        // shoulder S s
    case 's': shoulder = (shoulder + 5) % 360;
        glutPostRedisplay();
        break;
    case 'S': shoulder = (shoulder - 5) % 360;
        glutPostRedisplay();
        break;

        // elbow e E
    case 'e': elbow = (elbow + 5) % 360;
        glutPostRedisplay();
        break;
    case 'E': elbow = (elbow - 5) % 360;
        glutPostRedisplay();
        break;

        // palm p P 
    case 'p': palm = (palm + 5) % 360;
        glutPostRedisplay();
        break;
    case 'P': palm = (palm - 5) % 360;
        glutPostRedisplay();
        break;

        // jempol
    case 'j': thumb1 = (thumb1 + 5) % 90;
        glutPostRedisplay();
        break;
    case 'J': thumb1 = (thumb1 - 5) % 90;
        glutPostRedisplay();
        break;
    case 'u': thumb2 = (thumb2 + 5) % 90;
        glutPostRedisplay();
        break;
    case 'U': thumb2 = (thumb2 - 5) % 90;
        glutPostRedisplay();
        break;
    case 'b': thumb3 = (thumb3 + 5) % 90;
        glutPostRedisplay();
        break;
    case 'B': thumb3 = (thumb3 - 5) % 90;
        glutPostRedisplay();
        break;

        // telunjuk
    case 't': index1 = (index1 + 5) % 90;
        glutPostRedisplay();
        break;
    case 'T': index1 = (index1 - 5) % 90;
        glutPostRedisplay();
        break;
    case 'i': index2 = (index2 + 5) % 90;
        glutPostRedisplay();
        break;
    case 'I': index2 = (index2 - 5) % 90;
        glutPostRedisplay();
        break;
    case 'l': index3 = (index3 + 5) % 90;
        glutPostRedisplay();
        break;
    case 'L': index3 = (index3 - 5) % 90;
        glutPostRedisplay();
        break;

        // jari tengah
    case 'm': middle1 = (middle1 + 5) % 90;
        glutPostRedisplay();
        break;
    case 'M': middle1 = (middle1 - 5) % 90;
        glutPostRedisplay();
        break;
    case 'f': middle2 = (middle2 + 5) % 90;
        glutPostRedisplay();
        break;
    case 'F': middle2 = (middle2 - 5) % 90;
        glutPostRedisplay();
        break;
    case 'h': middle3 = (middle3 + 5) % 90;
        glutPostRedisplay();
        break;
    case 'H': middle3 = (middle3 - 5) % 90;
        glutPostRedisplay();
        break;

        // jari manis
    case 'r': ring1 = (ring1 + 5) % 90;
        glutPostRedisplay();
        break;
    case 'R': ring1 = (ring1 - 5) % 90;
        glutPostRedisplay();
        break;
    case 'g': ring2 = (ring2 + 5) % 90;
        glutPostRedisplay();
        break;
    case 'G': ring2 = (ring2 - 5) % 90;
        glutPostRedisplay();
        break;
    case 'n': ring3 = (ring3 + 5) % 90;
        glutPostRedisplay();
        break;
    case 'N': ring3 = (ring3 - 5) % 90;
        glutPostRedisplay();
        break;

        // kelingking
    case 'k': pinky1 = (pinky1 + 5) % 90;
        glutPostRedisplay();
        break;
    case 'K': pinky1 = (pinky1 - 5) % 90;
        glutPostRedisplay();
        break;
    case 'a': pinky2 = (pinky2 + 5) % 90;
        glutPostRedisplay();
        break;
    case 'A': pinky2 = (pinky2 - 5) % 90;
        glutPostRedisplay();
        break;
    case 'z': pinky3 = (pinky3 + 5) % 90;
        glutPostRedisplay();
        break;
    case 'Z': pinky3 = (pinky3 - 5) % 90;
        glutPostRedisplay();
        break;
    case 27: exit(0);
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
