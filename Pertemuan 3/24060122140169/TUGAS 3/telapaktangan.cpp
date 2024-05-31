#include <GL/glut.h>
#include <gl/glut.h>
static int shoulder = 0, elbow = 0, hand=0, kelingking=0, kelingking1=0, telunjuk=0, telunjuk1=0, manis=0, manis1=0, tengah=0, tengah1=0;
static int jempol=0, jempol1=0;

void init(void) {
 glClearColor (0.0, 0.0, 0.0, 0.0);
glShadeModel (GL_FLAT);
}

void telapaktangan(void) {
    glClear(GL_COLOR_BUFFER_BIT);
    glPushMatrix();

    glTranslatef(-1.0, 0.0, 0.0); // pundak
    glRotatef((GLfloat)shoulder, 1.0, 0.0, 0);
    glTranslatef(-1.0, 0.0, 0.0);
    glPushMatrix();
    glScalef(2.0, 0.7, 1.0);
    glutWireCube(1.0);
    glPopMatrix();

    glTranslatef(1.0, 0.0, 0.0); // lengan siku
    glRotatef((GLfloat)elbow, 0.0, 0.0, 1.0);
    glTranslatef(1.0, 0.0, 0.0);
    glPushMatrix();
    glScalef(2.0, 0.6, 1.0);
    glutWireCube(1.0);
    glPopMatrix();

    glTranslatef(1.0, 0.0, 0.0); // telapak
    glRotatef((GLfloat)hand, 0.0, 0.0, 1.0);
    glTranslatef(0.5, 0.0, 0.0);
    glPushMatrix();
    glScalef(1.0, 0.4, 1.2);
    glutWireCube(1.0);
    glPopMatrix();

    // ibu jari
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
    glRotatef((GLfloat)jempol1, 1.0, 0.0, 0.0);
    glTranslatef(0.0, 0.0, 0.5);
    glPushMatrix();
    glScalef(0.3, 0.2, 0.6);
    glTranslatef(0.0, 0.0, -0.2);
    glutWireCube(1.0);
    glPopMatrix();
    glPopMatrix();

    // telunjuk
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
    glRotatef((GLfloat)telunjuk1, 0.0, 0.0, 1.0);
    glTranslatef(0.0, 0.0, 0.5);
    glPushMatrix();
    glScalef(0.4, 0.2, 0.2);
    glTranslatef(0.35, 0.0, 0.0);
    glutWireCube(1.0);
    glPopMatrix();
    glPopMatrix();

    // tengah
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
    glRotatef((GLfloat)tengah1, 0.0, 0.0, 1.0);
    glTranslatef(0.0, 0.0, 0.5);
    glPushMatrix();
    glScalef(0.7, 0.2, 0.2);
    glTranslatef(0.4, 0.0, 0.0);
    glutWireCube(1.0);
    glPopMatrix();
    glPopMatrix();

    // manis
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
    glRotatef((GLfloat)manis1, 0.0, 0.0, 1.0);
    glTranslatef(0.0, 0.0, 0.5);
	glPushMatrix();
	glScalef(0.6, 0.2, 0.2);
	glTranslatef(0.4, 0.0, 0.0);
	glutWireCube(1.0);
	glPopMatrix();
	glPopMatrix();
	
	// kelingking
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
	glRotatef((GLfloat)kelingking1, 0.0, 0.0, 1.0);
	glTranslatef(0.0, 0.0, 0.5);
	glPushMatrix();
	glScalef(0.4, 0.2, 0.2);
	glTranslatef(0.4, 0.0, 0.0);
	glutWireCube(1.0);
	glPopMatrix();
	glPopMatrix();

	glPopMatrix();
	glutSwapBuffers();
    
}
void reshape (int w, int h) {
	glViewport (0, 0, (GLsizei) w, (GLsizei) h);
	glMatrixMode (GL_PROJECTION); 
	glLoadIdentity();
	gluPerspective(65.0, (GLfloat) w/(GLfloat) h, 1.0, 20.0);
	glMatrixMode(GL_MODELVIEW); glLoadIdentity();
 	glTranslatef (0.0, 0.0, -5.0);
}

void keyboard(unsigned char key, int x, int y) {
	switch (key) {
	//memutar keseluruhan, tampak samping ke tampak depan
	case 's': shoulder = (shoulder + 5) % 360;
	glutPostRedisplay(); break;
 	case 'S': shoulder = (shoulder - 5) % 360;
	glutPostRedisplay(); break;
	
	//pundak + lengan siku
 	case 'e': elbow = (elbow + 5) % 360;
	glutPostRedisplay(); break;
 	case 'E': elbow = (elbow - 5) % 360;
	glutPostRedisplay(); break;
	
	//lengan siku + telapak
 	case 'h': hand = (hand + 5) % 360;
	glutPostRedisplay(); break;
 	case 'H': hand = (hand - 5) % 360;
	glutPostRedisplay(); break;
	
	//jempol
 	case 'g': jempol = (jempol - 5) % 90; //telapak + jari
	glutPostRedisplay(); break;
 	case 'G': jempol = (jempol + 5) % 90;
	glutPostRedisplay(); break;
	
 	case 'j': jempol1 = (jempol1 + 5) % 90; //jari
	glutPostRedisplay(); break;
 	case 'J': jempol1 = (jempol1 - 5) % 90;
	glutPostRedisplay(); break;
	
	case 27: exit(0); break;
	default: break;
	
	//kelingking
	case 'k': kelingking = (kelingking + 5) % 90; //telapak + jari
	glutPostRedisplay(); break;
 	case 'K': kelingking = (kelingking - 5) % 90;
	glutPostRedisplay(); break;
	
 	case 'l': kelingking1 = (kelingking1 - 5) % 90; //jari
	glutPostRedisplay(); break;
 	case 'L': kelingking1 = (kelingking1 + 5) % 90;
	glutPostRedisplay(); break;
	
	//telunjuk
 	case 't': telunjuk = (telunjuk + 5) % 90; //telapak + jari
	glutPostRedisplay(); break;
 	case 'T': telunjuk = (telunjuk - 5) % 90;
	glutPostRedisplay(); break;
	
 	case 'r': telunjuk1 = (telunjuk1 - 5) % 90; //jari
	glutPostRedisplay(); break;
 	case 'R': telunjuk1 = (telunjuk1 + 5) % 90;
	glutPostRedisplay(); break;
	
	//manis
 	case 'm': manis = (manis + 5) % 90; //telapak + jari
	glutPostRedisplay(); break;
 	case 'M': manis = (manis - 5) % 90;
	glutPostRedisplay(); break;
	
 	case 'n': manis1 = (manis1 - 5) % 90; //jari
	glutPostRedisplay(); break;
 	case 'N': manis1 = (manis1 + 5) % 90;
	glutPostRedisplay(); break;
	
	//tengah
 	case 'o': tengah = (tengah + 5) % 90; //telapak + jari
	glutPostRedisplay(); break;
 	case 'O': tengah = (tengah - 5) % 90;
	glutPostRedisplay(); break;
	
 	case 'p': tengah1 = (tengah1 - 5) % 90; //jari
	glutPostRedisplay(); break;
 	case 'P': tengah1 = (tengah1 + 5) % 90;
	glutPostRedisplay(); break;
	
	//s = shoulder; e = elbow; h = hand; 
	//[g,j = ibu jari]; [t,r = telunjuk]; [o,p = tengah]; [m,n = manis]; [k,l = kelingking]
	//huruf pertama untuk menggerakkan ruas bawah (capslock ke belakang)
	//huruf kedua untuk menggerakkan ruas atas (capslock ke depan)
	}
}

int main(int argc, char** argv){
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(700, 600);
	glutInitWindowPosition(100,100);
	glutCreateWindow(argv[0]);
	init();
	glutDisplayFunc(telapaktangan);
	glutReshapeFunc(reshape);
	glutKeyboardFunc(keyboard);
	glutMainLoop();
	return 0;
}
