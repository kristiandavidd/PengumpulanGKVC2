#include <GL/glut.h>
#include <GL/glu.h>

static int shoulder = 0, elbow = 0, wrist = 0;
static int fingers_angle = 0;

void init(void) {
    glClearColor (0.0, 0.0, 0.0, 0.0);
    glShadeModel (GL_FLAT);
}

void display(void) {
    glClear (GL_COLOR_BUFFER_BIT);
    glPushMatrix();
    glTranslatef (-1.0, 0.0, 0.0);
    glRotatef ((GLfloat) shoulder, 0.0, 0.0, 1.0);
    glTranslatef (1.0, 0.0, 0.0);
    glPushMatrix();
    glScalef (2.0, 0.4, 1.0);
    glutWireCube (1.0);
    glPopMatrix();
    glTranslatef (1.0, 0.0, 0.0);
    glRotatef ((GLfloat) elbow, 0.0, 0.0, 1.0);
    glTranslatef (1.0, 0.0, 0.0);
    glPushMatrix();
    glScalef (2.0, 0.4, 1.0);
    glutWireCube (1.0);
    glPopMatrix();
    
  
    glTranslatef (1.0, 0.0, 0.0); 
    glRotatef ((GLfloat) elbow, 0.0, 0.0, 1.0); 
    
  
    glPushMatrix();
    glColor3f(0.0, 0.0, 1.0); 
    glTranslatef(0.0, 0.0, 0.2);
    glutWireCube(0.4); 
    glPopMatrix();
    
   
    glPushMatrix();
    glColor3f(1.0, 1.0, 1.0); 
    glTranslatef(0.2, 0.0, 0.2); 
    glRotatef ((GLfloat) fingers_angle, 1.0, 0.0, 0.0); 
    glTranslatef(0.0, 0.0, 0.1); 
    glutWireCube(0.1); 
    glPopMatrix();
    
    for (int i = 0; i < 4; ++i) {
        glPushMatrix();
        glColor3f(1.0, 1.0, 1.0); 
        glTranslatef(0.2 * (i + 1), 0.0, 0.0); 
        glRotatef ((GLfloat) fingers_angle, 1.0, 0.0, 0.0);
        glTranslatef(0.0, 0.0, 0.1); 
        glutWireCube(0.1); 
        glPopMatrix();
    }
    
    glPopMatrix();
    glutSwapBuffers();
}

void reshape (int w, int h) {
    glViewport (0, 0, (GLsizei) w, (GLsizei) h);
    glMatrixMode (GL_PROJECTION);
    glLoadIdentity ();
    gluPerspective(65.0, (GLfloat) w/(GLfloat) h, 1.0, 20.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glTranslatef (0.0, 0.0, -5.0);
}

void keyboard(unsigned char key, int x, int y) {
    switch (key) {
        case 'w':
            shoulder = (shoulder + 5) % 360;
            break;
        case 'W':
            shoulder = (shoulder - 5) % 360;
            break;
        case 'a':
            elbow = (elbow + 5) % 360;
            break;
        case 'A':
            elbow = (elbow - 5) % 360;
            break;
        case 's':
            wrist = (wrist + 5) % 360;
            break;
        case 'S':
            wrist = (wrist - 5) % 360;
            break;
        case 'd':
            fingers_angle = (fingers_angle + 5) % 360;
            break;
        case 'D':
            fingers_angle = (fingers_angle - 5) % 360;
            break;
        case 27:
            exit(0);
            break;
        default:
            break;
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

