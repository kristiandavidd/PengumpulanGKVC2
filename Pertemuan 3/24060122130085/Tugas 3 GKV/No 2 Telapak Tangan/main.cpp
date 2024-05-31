#include <GL/glut.h> 
static int shoulder = 0, elbow = 0, palm = 0, fingers1 = 0, fingers2 = 0, fingers3 = 0, fingers4 = 0, fingers5 = 0; 
 
void init(void) { 
    glClearColor (0.0, 0.0, 0.0, 0.0); 
    glShadeModel (GL_FLAT); 
} 
 
void display(void) { 
    glClear (GL_COLOR_BUFFER_BIT); 
    glPushMatrix(); 
    
    //Shoulder
    glTranslatef (-2.5, 0.0, 0.0); 
    glRotatef ((GLfloat) shoulder, 0.0, 0.0, 1.0); 
    glTranslatef (1.0, 0.0, 0.0); 
    glPushMatrix(); 
    glScalef (2.0, 0.4, 1.0); 
    glutWireCube (1.0); 
    glPopMatrix(); 
    
    //Elbow
    glTranslatef (1.0, 0.0, 0.0); 
    glRotatef ((GLfloat) elbow, 0.0, 0.0, 1.0); 
    glTranslatef (1.0, 0.0, 0.0); 
    glPushMatrix(); 
    glScalef (2.0, 0.4, 1.0); 
    glColor3f(0.96, 0.80, 0.69); 
    glutWireCube (1.0); 
    glPopMatrix(); 
    
    //Palm
    glTranslatef(1.0, 0.0, 0.0);
    glRotatef((GLfloat) palm, 0.0, 0.0, 1.0);
    glTranslatef(0.5, 0.0, 0.0);
    glPushMatrix();
    glScalef(1.0, 1.5, 1.0);
    glutWireCube(1.0);
    glPopMatrix();

    //Fingers
    glPushMatrix();
    glTranslatef(0.6, 0.6, 0.0);
    glRotatef ((GLfloat) fingers1, 0.0, 1.0, 0.0);
    glScalef(0.6, 0.2, 0.2);
    glColor3f(0.96, 0.80, 0.69); 
    glutWireCube(1.0);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.6, 0.3, 0.0);
    glRotatef ((GLfloat) fingers2, 0.0, 1.0, 0.0);
    glScalef(0.6, 0.2, 0.2);
    glColor3f(0.96, 0.80, 0.69); 
    glutWireCube(1.0);
    glPopMatrix();
    
    glPushMatrix();
    glTranslatef(0.6, 0.0, 0.0);
    glRotatef ((GLfloat) fingers3, 0.0, 1.0, 0.0);
    glScalef(0.6, 0.2, 0.2);
    glColor3f(0.96, 0.80, 0.69); 
    glutWireCube(1.0);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.6, -0.3, 0.0);
    glRotatef ((GLfloat) fingers4, 0.0, 1.0, 0.0);
    glScalef(0.6, 0.2, 0.2);
    glColor3f(0.96, 0.80, 0.69); 
    glutWireCube(1.0);
    glPopMatrix();
    
    glPushMatrix();
    glTranslatef(0.6, -0.6, 0.0);
    glRotatef ((GLfloat) fingers5, 0.0, 1.0, 0.0);
    glScalef(0.6, 0.2, 0.2);
    glColor3f(0.96, 0.80, 0.69); 
    glutWireCube(1.0);
    glPopMatrix();

    glPopMatrix();
    glutSwapBuffers(); 
} 
 
void reshape(int w, int h) { 
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
        case 's': shoulder = (shoulder + 5) % 360; 
            glutPostRedisplay(); 
            break; 
        case 'S': shoulder = (shoulder - 5) % 360; 
            glutPostRedisplay(); 
            break; 
        case 'e': elbow = (elbow + 5) % 360; 
            glutPostRedisplay(); 
            break; 
        case 'E': elbow = (elbow - 5) % 360; 
            glutPostRedisplay(); 
            break; 
        case 'p': palm = (palm + 5) % 360; 
            glutPostRedisplay(); 
            break; 
        case 'P': palm = (palm - 5) % 360; 
            glutPostRedisplay(); 
            break; 
        case '1': fingers1 = (fingers1 + 5) % 360; 
            glutPostRedisplay(); 
            break;
    	case '2': fingers2 = (fingers2 + 5) % 360; 
            glutPostRedisplay(); 
            break;
        case '3': fingers3 = (fingers3 + 5) % 360; 
            glutPostRedisplay(); 
            break;
        case '4': fingers4 = (fingers4 + 5) % 360; 
            glutPostRedisplay(); 
            break;
        case '5': fingers5 = (fingers5 + 5) % 360; 
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
    glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB); 
    glutInitWindowSize (1000, 1000); 
    glutInitWindowPosition (100, 100); 
    glutCreateWindow (argv[0]); 
    init(); 
    glutDisplayFunc(display); 
    glutReshapeFunc(reshape); 
    glutKeyboardFunc(keyboard); 
    glutMainLoop(); 
    return 0; 
}

