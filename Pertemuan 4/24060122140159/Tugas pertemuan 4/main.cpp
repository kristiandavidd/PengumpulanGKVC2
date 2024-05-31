
#include <GL/glut.h>

void init() {
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);

    GLfloat light_pos[] = {1.0, 1.0, 1.0, 0.0};
    glLightfv(GL_LIGHT0, GL_POSITION, light_pos);

    GLfloat ambient[] = {0.2, 0.2, 0.2, 1.0};
    GLfloat diffuse[] = {0.8, 0.8, 0.8, 1.0};
    GLfloat specular[] = {1.0, 1.0, 1.0, 1.0};
    glLightfv(GL_LIGHT0, GL_AMBIENT, ambient);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuse);
    glLightfv(GL_LIGHT0, GL_SPECULAR, specular);

    glEnable(GL_COLOR_MATERIAL);
    glColorMaterial(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE);

    glClearColor(0.7, 0.7, 1.0, 1.0);
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();

    gluLookAt(5.0, 5.0, 5.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);

    // Badan
    glColor3f(0.5, 0.5, 0.5);
    glPushMatrix();
    glTranslatef(0.0, 0.5, 0.0);
    glScalef(2.5, 0.5, 1.0);
    glutSolidCube(1.0);
    glPopMatrix();

    // Atap
    glColor3f(0.1, 0.1, 0.1);
    glPushMatrix();
    glTranslatef(0.0, 0.75, 0.0);
    glScalef(1.5, 0.3, 1.0);
    glutSolidCube(1.0);
    glPopMatrix();

    // Jendela
    glColor3f(0.0, 0.0, 0.5);
    glPushMatrix();
    glTranslatef(-0.6, 0.65, 0.0);
    glScalef(0.8, 0.3, 1.0);
    glutSolidCube(1.0);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.6, 0.65, 0.0);
    glScalef(0.8, 0.3, 1.0);
    glutSolidCube(1.0);
    glPopMatrix();

    // Lampu Depan
    glColor3f(1.0, 1.0, 0.0);
    glPushMatrix();
    glTranslatef(-1.2, 0.5, 0.50);
    glutSolidSphere(0.1, 20, 20);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-1.2, 0.5, -0.50);
    glutSolidSphere(0.1, 20, 20);
    glPopMatrix();

    // Lampu Belakang
    glColor3f(1.0, 0.0, 0.0);
    glPushMatrix();
    glTranslatef(1.2, 0.3, 0.42);
    glutSolidSphere(0.1, 20, 20);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(1.2, 0.3, -0.42);
    glutSolidSphere(0.1, 20, 20);
    glPopMatrix();

    // Ban
    glColor3f(0.1, 0.1, 0.1);
    glPushMatrix();
    glTranslatef(-0.8, 0.100, -0.4);
    glutSolidSphere(0.3, 20, 20);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-0.8, 0.100, 0.4);
    glutSolidSphere(0.3, 20, 20);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.8, 0.100, -0.4);
    glutSolidSphere(0.3, 20, 20);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.8, 0.100, 0.4);
    glutSolidSphere(0.3, 20, 20);
    glPopMatrix();
    
    // Sayap
    glColor3f(0.5, 0.5, 0.5);
    glPushMatrix();
    glTranslatef(1.25, 0.75, 0.0);
    glRotatef(45.0, 0.0, 0.0, 1.0); 
    glScalef(0.3, 0.1, 1.0);
    glutSolidCube(1.0);
    glPopMatrix();

    glutSwapBuffers();
}

void reshape(int w, int h) {
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0, (float)w / (float)h, 1.0, 100.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(800, 600);
    glutCreateWindow("Mobil 3D");

    init();
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);

    glutMainLoop();

    return 0;
}
