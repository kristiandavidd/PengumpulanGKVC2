/*
Nama		: Muhammad Farhan Hafiz ALkirami
NIM			: 24060122140045
Tanggal		: 11 Maret 2024
File		: mainLengan.cpp
Deskripsi	: file main untuk menggerakkan lengan

*/

#include <GL/glut.h>
static int shoulder = 0, elbow = 0, palm = 0, palmrot = 0;
static int thumb_base = 0, thumb_mid = 0, thumb_tip = 0;
static int index_base = 0, index_mid = 0, index_tip = 0;
static int middle_base = 0, middle_mid = 0, middle_tip = 0;
static int ring_base = 0, ring_mid = 0, ring_tip = 0;
static int little_base = 0, little_mid = 0, little_tip = 0;

void init(void) {
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glShadeModel(GL_FLAT);
}

void drawCube() {
    glutWireCube(1.0);
}

void display(void) {
    glClear(GL_COLOR_BUFFER_BIT);
    glPushMatrix();

    // Lengan atas
    glTranslatef(-2.0, 0.0, 0.0);
    glRotatef((GLfloat)shoulder, 0.0, 0.0, 1.0);
    glTranslatef(1.0, 0.0, 0.0);
    glPushMatrix();
    glScalef(2.0, 0.4, 1.0);
    drawCube();
    glPopMatrix();

    // Lengan bawah
    glTranslatef(1.0, 0.0, 0.0);
    glRotatef((GLfloat)elbow, 0.0, 0.0, 1.0);
    glTranslatef(1.0, 0.0, 0.0);
    glPushMatrix();
    glScalef(2.0, 0.4, 1.0);
    drawCube();
    glPopMatrix();

    // Telapak tangan
    glTranslatef(1.0, 0.0, 0.0);
    glRotatef((GLfloat)palm, 0.0, 0.0, 1.0);
    glRotatef((GLfloat)palmrot, 1.0, 0.0, 0.0);
    glPushMatrix();
    glScalef(1.0, 0.5, 1.0);
    drawCube();
    glPopMatrix();

    // Ibu jari
    glPushMatrix();
    glTranslatef(0.0, -0.2, 0.5);
    glRotatef((GLfloat)thumb_base, 0.0, 1.0, 0.0);
    glPushMatrix();
    glScalef(0.2, 0.2, 0.3);
    drawCube();
    glPopMatrix();

    glTranslatef(0.0, 0.0, 0.3);
    glRotatef((GLfloat)thumb_mid, 1.0, 0.0, 0.0);
    glPushMatrix();
    glScalef(0.2, 0.2, 0.3);
    drawCube();
    glPopMatrix();

    glTranslatef(0.0, 0.0, 0.3);
    glRotatef((GLfloat)thumb_tip, 1.0, 0.0, 0.0);
    glPushMatrix();
    glScalef(0.2, 0.2, 0.3);
    drawCube();
    glPopMatrix();
    glPopMatrix();
    
    
    // Jari telunjuk
    glPushMatrix();
    glTranslatef(0.5, 0.0, 0.4);
    glRotatef((GLfloat)index_base, 0.0, 0.0, 1.0);
    glPushMatrix();
    glScalef(0.4, 0.2, 0.2);
    drawCube();
    glPopMatrix();
    
    glRotatef((GLfloat)index_mid, 0.0, 0.0, 1.0);
    glPushMatrix();
    glTranslatef(0.3, 0.0, 0.0);
    glScalef(0.4, 0.2, 0.2);
    drawCube();
    glPopMatrix();
    
    glTranslatef(0.3, 0.0, 0.0);
    glRotatef((GLfloat)index_tip, 0.0, 0.0, 1.0);
    glPushMatrix();
    glTranslatef(0.3, 0.0, 0.0);
    glScalef(0.4, 0.2, 0.2);
    drawCube();
    glPopMatrix();
    glPopMatrix();
    
    // Jari tengah
    glPushMatrix();
    glTranslatef(0.6, 0.0, 0.1);
    glRotatef((GLfloat)middle_base, 0.0, 0.0, 1.0);
    glPushMatrix();
    glScalef(0.45, 0.2, 0.2);
    drawCube();
    glPopMatrix();
    
    glRotatef((GLfloat)middle_mid, 0.0, 0.0, 1.0);
    glPushMatrix();
    glTranslatef(0.35, 0.0, 0.0);
    glScalef(0.45, 0.2, 0.2);
    drawCube();
    glPopMatrix();
    
    glTranslatef(0.35, 0.0, 0.0);
    glRotatef((GLfloat)middle_tip, 0.0, 0.0, 1.0);
    glPushMatrix();
    glTranslatef(0.35, 0.0, 0.0);
    glScalef(0.45, 0.2, 0.2);
    drawCube();
    glPopMatrix();
    glPopMatrix();
    
    // Jari manis
    glPushMatrix();
    glTranslatef(0.55, 0.0, -0.1);
    glRotatef((GLfloat)ring_base, 0.0, 0.0, 1.0);
    glPushMatrix();
    glScalef(0.45, 0.2, 0.2);
    drawCube();
    glPopMatrix();
    
    glRotatef((GLfloat)ring_mid, 0.0, 0.0, 1.0);
    glPushMatrix();
    glTranslatef(0.35, 0.0, 0.0);
    glScalef(0.45, 0.2, 0.2);
    drawCube();
    glPopMatrix();
    
    glTranslatef(0.3, 0.0, 0.0);
    glRotatef((GLfloat)ring_tip, 0.0, 0.0, 1.0);
    glPushMatrix();
    glTranslatef(0.35, 0.0, 0.0);
    glScalef(0.45, 0.2, 0.2);
    drawCube();
    glPopMatrix();
    glPopMatrix();
    
    
    // Jari kelingking
    glPushMatrix();
    glTranslatef(0.55, 0.0, -0.4);
    glRotatef((GLfloat)little_base, 0.0, 0.0, 1.0);
    glPushMatrix();
    glScalef(0.3, 0.2, 0.2);
    drawCube();
    glPopMatrix();
    
    glRotatef((GLfloat)little_mid, 0.0, 0.0, 1.0);
    glPushMatrix();
    glTranslatef(0.2, 0.0, 0.0);
    glScalef(0.3, 0.2, 0.2);
    drawCube();
    glPopMatrix();
    
    glTranslatef(0.3, 0.0, 0.0);
    glRotatef((GLfloat)little_tip, 0.0, 0.0, 1.0);
    glPushMatrix();
    glTranslatef(0.2, 0.0, 0.0);
    glScalef(0.3, 0.2, 0.2);
    drawCube();
    glPopMatrix();
    glPopMatrix();
    
    
    glPopMatrix();
    glutSwapBuffers();
}

void keyboard(unsigned char key, int x, int y) {
    switch (key) {
    case 's':
        shoulder = (shoulder + 5) % 360;
        break;
    case 'S':
        shoulder = (shoulder - 5) % 360;
        break;
    case 'e':
        elbow = (elbow + 5) % 360;
        break;
    case 'E':
        elbow = (elbow - 5) % 360;
        break;
    case 'p':
        palm = (palm + 5) % 360;
        break;
    case 'P':
        palm = (palm - 5) % 360;
        break;
    case ';':
        palmrot = (palmrot + 5) % 360;
        break;
    case ':':
        palmrot = (palmrot - 5) % 360;
        break;
    case 't':
        thumb_base = (thumb_base + 5) % 360;
        break;
    case 'T':
        thumb_base = (thumb_base - 5) % 360;
        break;
    case 'g':
        thumb_mid = (thumb_mid + 5) % 360;
        break;
    case 'G':
        thumb_mid = (thumb_mid - 5) % 360;
        break;
    case 'b':
        thumb_tip = (thumb_tip + 5) % 360;
        break;
    case 'B':
        thumb_tip = (thumb_tip - 5) % 360;
        break;
    case 'y':
        index_base = (index_base + 5) % 360;
        break;
    case 'Y':
        index_base = (index_base - 5) % 360;
        break;
    case 'h':
        index_mid = (index_mid + 5) % 360;
        break;
    case 'H':
        index_mid = (index_mid - 5) % 360;
        break;
    case 'n':
        index_tip = (index_tip + 5) % 360;
        break;
    case 'N':
        index_tip = (index_tip - 5) % 360;
        break;
    case 'u':
        middle_base = (middle_base + 5) % 360;
        break;
    case 'U':
        middle_base = (middle_base - 5) % 360;
        break;
    case 'j':
        middle_mid = (middle_mid + 5) % 360;
        break;
    case 'J':
        middle_mid = (middle_mid - 5) % 360;
        break;
    case 'm':
        middle_tip = (middle_tip + 5) % 360;
        break;
    case 'M':
        middle_tip = (middle_tip - 5) % 360;
        break;
    case 'i':
        ring_base = (ring_base + 5) % 360;
        break;
    case 'I':
        ring_base = (ring_base - 5) % 360;
        break;
    case 'k':
        ring_mid = (ring_mid + 5) % 360;
        break;
    case 'K':
        ring_mid = (ring_mid - 5) % 360;
        break;
    case ',':
        ring_tip = (ring_tip + 5) % 360;
        break;
    case '<':
        ring_tip = (ring_tip - 5) % 360;
        break;
    case 'o':
        little_base = (little_base + 5) % 360;
        break;
    case 'O':
        little_base = (little_base - 5) % 360;
        break;
    case 'l':
        little_mid = (little_mid + 5) % 360;
        break;
    case 'L':
        little_mid = (little_mid - 5) % 360;
        break;
    case '.':
        little_tip = (little_tip + 5) % 360;
        break;
    case '>':
        little_tip = (little_tip - 5) % 360;
        break;
    case 27:
        exit(0);
        break;
    default:
        break;
    }
    glutPostRedisplay();
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

