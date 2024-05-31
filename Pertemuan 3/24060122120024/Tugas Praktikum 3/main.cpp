#include <GL/glut.h>
static int shoulder = 0, elbow = 0, palm = 0, thumb = 0, index_finger = 0, middle_finger = 0, ring_finger = 0, little_finger = 0;

void init(void) {
	glClearColor (0.0, 0.0, 0.0, 0.0);
	glShadeModel (GL_FLAT);
}

void display(void) {
    glClear(GL_COLOR_BUFFER_BIT);
    
    glPushMatrix();
    
    glTranslatef(-3.0, 0.0, 0.0);
    glRotatef((GLfloat)shoulder, 0.0, 0.0, 1.0);
    glTranslatef(1.5, 0.0, 0.0);
    glColor3f(1.0, 1.0, 1.0);
    glPushMatrix();
    glScalef(1.0, 0.4, 1.0);
    glutWireCube(1.0);
    glPopMatrix();

    glTranslatef(-0.5, 0.0, 0.0);
    glRotatef((GLfloat)elbow, 0.0, 0.0, 1.0);
    glTranslatef(1.5, 0.0, 0.0);
    glColor3f(1.0, 1.0, 1.0);
    glPushMatrix();
    glScalef(1.0, 0.3, 1.0);
    glutWireCube(1.0);
    glPopMatrix();

    glTranslatef(-0.5, 0.0, 0.0);
    glRotatef((GLfloat)palm, 0.0, 0.0, 0.8);
    glTranslatef(1.4, 0.0, 0.0);
    glColor3f(1.0, 1.0, 1.0);
    glPushMatrix();
    glScalef(0.8, 0.5, 1.4);
    glutWireCube(1.0);
    glPopMatrix();
    
	
	// space for fingers
//    thumb
    glTranslatef(-0.5, -0.1, 0.0);
    glRotatef((GLfloat) thumb, 0.0, 0.0, 1.0);
    glTranslatef(1.0, 0.4, 0.0);
    glColor3f(1.0, 0.0, 0.0);
    glPushMatrix();
    glScalef(0.2, 0.2, 2.0);
    glutWireCube(0.3);
    glPopMatrix();

//    index finger
    glTranslatef(-0.5, -0.1, 0.0);
    glRotatef((GLfloat) index_finger, 0.0, 0.0, 1.0);
    glTranslatef(0.5, 0.0, 0.0);
    glColor3f(0.0, 1.0, 0.0);
    glPushMatrix();
    glScalef(0.6, 0.2, 2.0);
    glutWireCube(0.3);
    glPopMatrix();

//    middle finger
    glTranslatef(-0.5, -0.1, 0.0);
    glRotatef((GLfloat) middle_finger, 0.0, 0.0, 1.0);
    glTranslatef(0.5, -0.1, 0.0);
    glColor3f(0.0, 0.0, 1.0);
    glPushMatrix();
    glScalef(0.5, 0.2, 2.0);
    glutWireCube(0.5);
    glPopMatrix();

//	  ring finger
    glTranslatef(-0.5, -0.1, 0.0);
    glRotatef((GLfloat) ring_finger, 0.0, 0.0, 1.0);
    glTranslatef(0.5, -0.1, 0.0);
    glColor3f(1.0, 1.0, 0.0);
    glPushMatrix();
    glScalef(0.2, 0.1, 2.0);
    glutWireCube(0.5);
    glPopMatrix();

//    little finger
    glTranslatef(-0.5, -0.1, 0.0);
    glRotatef((GLfloat) little_finger, 0.0, 0.0, 1.0);
    glTranslatef(0.5, -0.1, 0.0);
    glColor3f(0.0, 1.0, 1.0);
    glPushMatrix();
    glScalef(0.2, 0.1, 2.0);
    glutWireCube(0.5);
    glPopMatrix();

    glPopMatrix();
    glutSwapBuffers();
}

void reshape (int w, int h) {
	glViewport (0, 0, (GLsizei) w, (GLsizei) h);
	glMatrixMode (GL_PROJECTION); 
	glLoadIdentity();
 	gluPerspective(65.0, (GLfloat) w/(GLfloat) h, 1.0, 20.0);
	glMatrixMode(GL_MODELVIEW); 
	glLoadIdentity();
 	glTranslatef (0.0, 0.0, -5.0);
}

void rotateJoint(int* joint, int increment, int minAngle, int maxAngle) {
    if (*joint + increment >= minAngle && *joint + increment <= maxAngle)
        *joint = (*joint + increment) % 360;
}

void keyboard(unsigned char key, int x, int y) {
    switch (key) {
        case 's': rotateJoint(&shoulder, 5, -90, 90); break;
        case 'S': rotateJoint(&shoulder, -5, -90, 90); break;
        case 'e': rotateJoint(&elbow, 5, 0, 35); break;
        case 'E': rotateJoint(&elbow, -5, 0, 35); break;
        case 'p': rotateJoint(&palm, 5, -20, 20); break;
        case 'P': rotateJoint(&palm, -5, -20, 20); break;
        case '1': rotateJoint(&thumb, 5, -10, 20); break;
        case '!': rotateJoint(&thumb, -5, -10, 20); break;
        case '2': rotateJoint(&index_finger, 5, -10, 20); break;
        case '@': rotateJoint(&index_finger, -5, -10, 20); break;
        case '3': rotateJoint(&middle_finger, 5, -10, 20); break;
        case '#': rotateJoint(&middle_finger, -5, -10, 20); break;
        case '4': rotateJoint(&ring_finger, 5, -10, 20); break;
        case '$': rotateJoint(&ring_finger, -5, -10, 20); break;
        case '5': rotateJoint(&little_finger, 5, -10, 20); break;
        case '%': rotateJoint(&little_finger, -5, -10, 20); break;
        case 27: exit(0); break;
        default: break;
    }
    glutPostRedisplay();
}



int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize (700, 600);
	glutInitWindowPosition (100, 100);
	glutCreateWindow (argv[0]); 
	init();
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutKeyboardFunc(keyboard);
	glutMainLoop(); 
	return 0;
}
