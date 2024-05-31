#include <GL/glut.h>

static int shoulderX = 0, shoulderY = 0, shoulderZ = 0, elbow = 0, telapakX = 0, telapakY = 0, telapakZ = 0, kelingking = 0, tengahKelingking = 0, telunjuk = 0, tengahTelunjuk = 0, manis = 0, tengahManis = 0, tengah = 0, tengahTengah = 0;
static int jempol = 0, tengahJempol = 0;

void init(void) {
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glShadeModel(GL_FLAT);
}

void display(void) {
    glClear(GL_COLOR_BUFFER_BIT);
    glPushMatrix();
    
    //ShoulderXY
    glTranslatef(-1.0, 0.0, 0.0); 
    glRotatef((GLfloat)shoulderX, 0.0, 1.0, 0);
    glRotatef((GLfloat)shoulderY, 1.0, 0.0, 0);
	glRotatef((GLfloat)shoulderZ, 0.0, 0.0, 1);
    glTranslatef(-1.0, 0.0, 0.0);
    glPushMatrix();
    glScalef(2.0, 0.5, 1.0);
    glutWireCube(1.0);
    glPopMatrix();

	//Elbow
    glTranslatef(1.0, 0.0, 0.0); 
    glRotatef((GLfloat)elbow, 0.0, 0.0, 1.0);
    glTranslatef(1.0, 0.0, 0.0);
    glPushMatrix();
    glScalef(2.0, 0.4, 1.0);
    glutWireCube(1.0);
    glPopMatrix();
	
	//Telapak
    glTranslatef(1.0, 0.0, 0.0);
    glRotatef((GLfloat)telapakX, 1.0, 0.0, 0.0);
    glRotatef((GLfloat)telapakY, 0.0, 1.0, 0.0);
    glRotatef((GLfloat)telapakZ, 0.0, 0.0, 1.0);
    glTranslatef(0.5, 0.0, 0.0);
    glPushMatrix();
    glScalef(1.0, 0.3, 1.2);
    glutWireCube(1.0);
    glPopMatrix();

    //Kelingking
    glPushMatrix();
    glTranslatef(0.5, 0.0, -0.5);
    glRotatef((GLfloat)kelingking, 0.0, 0.0, 1.0);
    glTranslatef(0.5, 0.0, 0.0);
    glPushMatrix();
    glScalef(0.5, 0.2, 0.2);
    glTranslatef(-0.6, 0.0, 0.0);
    glutWireCube(1.0);
    glPopMatrix();

    glTranslatef(0.0, 0.0, -0.5);
    glRotatef((GLfloat)tengahKelingking, 0.0, 0.0, 1.0);
    glTranslatef(0.0, 0.0, 0.5);
    glPushMatrix();
    glScalef(0.4, 0.2, 0.2);
    glTranslatef(0.4, 0.0, 0.0);
    glutWireCube(1.0);
    glPopMatrix();
    glPopMatrix();

    //Manis
    glPushMatrix();
    glTranslatef(0.5, 0.0, -0.15);
    glRotatef((GLfloat)manis, 0.0, 0.0, 1.0);
    glTranslatef(0.5, 0.0, 0.0);
    glPushMatrix();
    glScalef(0.7, 0.2, 0.2);
    glTranslatef(-0.3, 0.0, 0.0);
    glutWireCube(1.0);
    glPopMatrix();

    glTranslatef(0.2, 0.0, -0.5);
    glRotatef((GLfloat)tengahManis, 0.0, 0.0, 1.0);
    glTranslatef(0.0, 0.0, 0.5);
    glPushMatrix();
    glScalef(0.6, 0.2, 0.2);
    glTranslatef(0.4, 0.0, 0.0);
    glutWireCube(1.0);
    glPopMatrix();
    glPopMatrix();

    //Tengah
    glPushMatrix();
    glTranslatef(0.5, 0.0, 0.15);
    glRotatef((GLfloat)tengah, 0.0, 0.0, 1.0);
    glTranslatef(0.5, 0.0, 0.0);
    glPushMatrix();
    glScalef(0.7, 0.2, 0.2);
    glTranslatef(-0.3, 0.0, 0.0);
    glutWireCube(1.0);
    glPopMatrix();

    glTranslatef(0.2, 0.0, -0.5);
    glRotatef((GLfloat)tengahTengah, 0.0, 0.0, 1.0);
    glTranslatef(0.0, 0.0, 0.5);
    glPushMatrix();
    glScalef(0.7, 0.2, 0.2);
    glTranslatef(0.4, 0.0, 0.0);
    glutWireCube(1.0);
    glPopMatrix();
    glPopMatrix();

    //Telunjuk 
    glPushMatrix();
    glTranslatef(0.5, 0.0, 0.5);
    glRotatef((GLfloat)telunjuk, 0.0, 0.0, 1.0);
    glTranslatef(0.5, 0.0, 0.0);
    glPushMatrix();
    glScalef(0.7, 0.2, 0.2);
    glTranslatef(-0.3, 0.0, 0.0);
    glutWireCube(1.0);
    glPopMatrix();

    glTranslatef(0.2, 0.0, -0.5);
    glRotatef((GLfloat)tengahTelunjuk, 0.0, 0.0, 1.0);
    glTranslatef(0.0, 0.0, 0.5);
    glPushMatrix();
    glScalef(0.4, 0.2, 0.2);
    glTranslatef(0.35, 0.0, 0.0);
    glutWireCube(1.0);
    glPopMatrix();
    glPopMatrix();

    //Jempol
    glPushMatrix();
    glTranslatef(-0.4, 0.0, 0.5);
    glRotatef((GLfloat)jempol, 1.0, 0.0, 0.0);
    glTranslatef(0.5, 0.0, 0.0);
    glPushMatrix();
    glScalef(0.7, 0.2, 0.5);
    glTranslatef(0.0, 0.0, 0.3);
    glutWireCube(1.0);
    glPopMatrix();

    glTranslatef(-0.1, 0.0, 0.25);
    glRotatef((GLfloat)tengahJempol, 1.0, 0.0, 0.0);
    glTranslatef(0.0, 0.0, 0.5);
    glPushMatrix();
    glScalef(0.3, 0.2, 0.6);
    glTranslatef(0.0, 0.0, -0.2);
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
    case 's': shoulderX = (shoulderX + 5) % 360;
        glutPostRedisplay();
        break;
    case 'S': shoulderX = (shoulderX - 5) % 360;
        glutPostRedisplay();
        break;
    case ',': shoulderY = (shoulderY + 5) % 360;
        glutPostRedisplay();
        break;
    case '<': shoulderY = (shoulderY - 5) % 360;
        glutPostRedisplay();
        break;
    case '-': shoulderZ = (shoulderZ + 5) % 360;
        glutPostRedisplay();
        break;
    case '_': shoulderZ = (shoulderZ - 5) % 360;
        glutPostRedisplay();
        break;
    case 'e': elbow = (elbow + 5) % 360;
        glutPostRedisplay();
        break;
    case 'E': elbow = (elbow - 5) % 360;
        glutPostRedisplay();
        break;
    case 'h': telapakY = (telapakY + 5) % 360;
        glutPostRedisplay();
        break;
    case 'H': telapakY = (telapakY - 5) % 360;
        glutPostRedisplay();
        break;
    case '.': telapakX = (telapakX + 5) % 90;
        glutPostRedisplay();
        break;
    case '>': telapakX = (telapakX - 5) % 90;
        glutPostRedisplay();
        break;
    case '/': telapakZ = (telapakZ + 5) % 90;
        glutPostRedisplay();
        break;
    case '?': telapakZ = (telapakZ - 5) % 90;
        glutPostRedisplay();
        break;
    case 'b': kelingking = (kelingking + 5) % 90;
        glutPostRedisplay();
        break;
    case 'B': kelingking = (kelingking - 5) % 90;
        glutPostRedisplay();
        break;
    case '5': tengahKelingking = (tengahKelingking + 5) % 90;
        glutPostRedisplay();
        break;
    case '%': tengahKelingking = (tengahKelingking - 5) % 90;
        glutPostRedisplay();
        break;
    case 'x': telunjuk = (telunjuk + 5) % 90;
        glutPostRedisplay();
        break;
    case 'X': telunjuk = (telunjuk - 5) % 90;
        glutPostRedisplay();
        break;
    case '2': tengahTelunjuk = (tengahTelunjuk + 5) % 90;
        glutPostRedisplay();
        break;
    case '@': tengahTelunjuk = (tengahTelunjuk - 5) % 90;
        glutPostRedisplay();
        break;
    case 'v': manis = (manis + 5) % 90;
        glutPostRedisplay();
        break;
    case 'V': manis = (manis - 5) % 90;
        glutPostRedisplay();
        break;
    case '4': tengahManis = (tengahManis + 5) % 90;
        glutPostRedisplay();
        break;
    case '$': tengahManis = (tengahManis - 5) % 90;
        glutPostRedisplay();
        break;
    case 'c': tengah = (tengah + 5) % 90;
        glutPostRedisplay();
        break;
    case 'C': tengah = (tengah - 5) % 90;
        glutPostRedisplay();
        break;
    case '3': tengahTengah = (tengahTengah + 5) % 90;
        glutPostRedisplay();
        break;
    case '#': tengahTengah = (tengahTengah - 5) % 90;
        glutPostRedisplay();
        break;
    case 'Z': jempol = (jempol + 5) % 90;
        glutPostRedisplay();
        break;
    case 'z': jempol = (jempol - 5) % 90;
        glutPostRedisplay();
        break;
    case '!': tengahJempol = (tengahJempol + 5) % 90;
        glutPostRedisplay();
        break;
    case '1': tengahJempol = (tengahJempol - 5) % 90;
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
    glutInitWindowSize(900, 600);
    glutInitWindowPosition(100, 100);
    glutCreateWindow(argv[0]);
    init();
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(keyboard);
    glutMainLoop();
    return 0;
}

