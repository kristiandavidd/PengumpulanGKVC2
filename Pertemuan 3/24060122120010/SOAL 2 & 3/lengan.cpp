//Nama		: Muhammad Luthfan Lazuardi
//NIM		: 24060122120010
//Tanggal	: 8 Maret 2024

#include <GL/glut.h>
static int bahux = 0, bahuy = 0, bahuz = 0; 
static int sikutz = 0, sikutx = 0; 
static int tlapakx = 0, tlapaky = 0, tlapakz = 0; 
static int jempol1 = 0, jempol2 = 0;
static int tlunjuk1 = 0, tlunjuk2 = 0;
static int tengah1 = 0, tengah2 = 0;
static int manis1 = 0, manis2 = 0;
static int klingking1 = 0, klingking2 = 0;

void init(void) {
	glClearColor (0.0, 0.0, 0.0, 0.0);
	glShadeModel (GL_FLAT);
}

void display(void) {
 	glClear (GL_COLOR_BUFFER_BIT);
	glPushMatrix();
	glScalef(0.6, 0.6, 0.6);
	
	//Lengan atas
	glTranslatef (-1.0, 0.0, 0.0);
	glRotatef((GLfloat)bahux, 1.0, 0.0, 0.0);  //bahu x-axis
    glRotatef((GLfloat)bahuy, 0.0, 1.0, 0.0);  //bahu y-axis
    glRotatef((GLfloat)bahuz, 0.0, 0.0, 1.0);  //bahu z-axis
	glTranslatef (-1.0, 0.0, 0.0); 
	glPushMatrix();
 	glScalef (2.0, 0.7, 1.0);
	glutWireCube (1.0); 
	glPopMatrix();
	
	//Forearm (lengan bawah)
    glTranslatef(1.0, 0.0, 0.0);
    glRotatef((GLfloat)sikutz, 0.0, 0.0, 1.0); //sikut z-axis
    glRotatef((GLfloat)sikutx, 1.0, 0.0, 0.0); //sikut x-axis
    glTranslatef(1.0, 0.0, 0.0);
    glPushMatrix();
    glScalef(2.0, 0.5, 0.9); 
    glutWireCube(1.0);
    glPopMatrix();
	
	//Telapak
	glTranslatef (1.0, 0.0, 0.0);
	glRotatef ((GLfloat) tlapakz, 0.0, 0.0, 1.0); //tlapak z-axis
	glRotatef((GLfloat) tlapaky, 0.0, 1.0, 0.0);  //tlapak y-axis
	glRotatef((GLfloat) tlapakx, 1.0, 0.0, 0.0);  //tlapak x-axis
	glTranslatef (0.5, 0.0, 0.0); 
	glPushMatrix();
 	glScalef (1.0, 0.4, 1.2);
	glutWireCube (1.0); 
	glPopMatrix();	
	
	//Jari Jempol
	glPushMatrix();
	glTranslatef (-0.4, 0.0, 0.5);
	glRotatef ((GLfloat) jempol1, 1.0, 0.0, 0.0);
	glTranslatef (0.4, 0.0, 0.0); 
	glPushMatrix();
 	glScalef (0.5, 0.2, 0.5);
 	glTranslatef(0.0, 0.0, 0.3);
	glutWireCube (1.0); 
	glPopMatrix();
		
	glTranslatef (-0.1, 0.0, 0.25);
	glRotatef ((GLfloat) jempol2, 1.0, 0.0, 0.0);
	glTranslatef (0.0, 0.0, 0.5); 
	glPushMatrix();
 	glScalef (0.3, 0.2, 0.6);
 	glTranslatef(0.0, 0.0, -0.2);
	glutWireCube (1.0); 
	glPopMatrix();
	glPopMatrix();	
	
	//Jari Telunjuk
	glPushMatrix();
	glTranslatef (0.5, 0.0, 0.5);
	glRotatef ((GLfloat) tlunjuk1, 0.0, 0.0, 1.0);
	glTranslatef (0.5, 0.0, 0.0); 
	glPushMatrix();
 	glScalef (0.7, 0.2, 0.2);
 	glTranslatef(-0.3, 0.0, 0.0);
	glutWireCube (1.0); 
	glPopMatrix();
		
	glTranslatef (0.2, 0.0, -0.5);
	glRotatef ((GLfloat) tlunjuk2, 0.0, 0.0, 1.0);
	glTranslatef (0.0, 0.0, 0.5); 
	glPushMatrix();
 	glScalef (0.4, 0.2, 0.2);
 	glTranslatef(0.35, 0.0, 0.0);
	glutWireCube (1.0); 
	glPopMatrix();
	glPopMatrix();
	
	//Jari Tengah	
	glPushMatrix();
	glTranslatef (0.5, 0.0, 0.15);
	glRotatef ((GLfloat) tengah1, 0.0, 0.0, 1.0);
	glTranslatef (0.5, 0.0, 0.0); 
	glPushMatrix();
 	glScalef (0.7, 0.2, 0.2);
 	glTranslatef(-0.3, 0.0, 0.0);
	glutWireCube (1.0); 
	glPopMatrix();
		
	glTranslatef (0.2, 0.0, -0.5);
	glRotatef ((GLfloat) tengah2, 0.0, 0.0, 1.0);
	glTranslatef (0.0, 0.0, 0.5); 
	glPushMatrix();
 	glScalef (0.7, 0.2, 0.2);
 	glTranslatef(0.4, 0.0, 0.0);
	glutWireCube (1.0); 
	glPopMatrix();
	glPopMatrix();
	
	//Jari Manis
	glPushMatrix();
	glTranslatef (0.5, 0.0, -0.15);
	glRotatef ((GLfloat) manis1, 0.0, 0.0, 1.0);
	glTranslatef (0.5, 0.0, 0.0); 
	glPushMatrix();
 	glScalef (0.7, 0.2, 0.2);
 	glTranslatef(-0.3, 0.0, 0.0);
	glutWireCube (1.0); 
	glPopMatrix();
		
	glTranslatef (0.2, 0.0, -0.5);
	glRotatef ((GLfloat) manis2, 0.0, 0.0, 1.0);
	glTranslatef (0.0, 0.0, 0.5); 
	glPushMatrix();
 	glScalef (0.6, 0.2, 0.2);
 	glTranslatef(0.4, 0.0, 0.0);
	glutWireCube (1.0); 
	glPopMatrix();
	glPopMatrix();
	
	//Jari Kelingking	
	glPushMatrix();
	glTranslatef (0.5, 0.0, -0.5);
	glRotatef ((GLfloat) klingking1, 0.0, 0.0, 1.0);
	glTranslatef (0.5, 0.0, 0.0); 
	glPushMatrix();
 	glScalef (0.5, 0.2, 0.2);
 	glTranslatef(-0.6, 0.0, 0.0);
	glutWireCube (1.0); 
	glPopMatrix();
		
	glTranslatef (0.0, 0.0, -0.5);
	glRotatef ((GLfloat) klingking2, 0.0, 0.0, 1.0);
	glTranslatef (0.0, 0.0, 0.5); 
	glPushMatrix();
 	glScalef (0.4, 0.2, 0.2);
 	glTranslatef(0.4, 0.0, 0.0);
	glutWireCube (1.0); 
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
	glMatrixMode(GL_MODELVIEW); 
	glLoadIdentity();
 	glTranslatef (0.0, 0.0, -5.0);
}

void keyboard(unsigned char key, int x, int y) {
	switch (key) {
		case 'a': bahux = (bahux + 5) % 360;
			glutPostRedisplay(); 
			break;
 		case 'A': bahux = (bahux - 5) % 360;
			glutPostRedisplay(); 
			break;
    	case 's': bahuy = (bahuy + 5) % 360;
            glutPostRedisplay();
            break;
    	case 'S': bahuy = (bahuy - 5) % 360;
            glutPostRedisplay();
            break;
    	case 'd': bahuz = (bahuz + 5) % 360;
            glutPostRedisplay();
            break;
    	case 'D': bahuz = (bahuz - 5) % 360;
            glutPostRedisplay();
        	break;
 		case 'e': sikutz = (sikutz + 5) % 120;
			glutPostRedisplay(); 
			break;
 		case 'E': sikutz = (sikutz - 5) % 120;
			glutPostRedisplay(); 
			break;
 		case 'w': sikutx = (sikutx + 5) % 90;
			glutPostRedisplay();
			break;
 		case 'W': sikutx = (sikutx - 5) % 90;
			glutPostRedisplay();
			break;
 		case 'z': tlapakz = (tlapakz + 5) % 120;
			glutPostRedisplay(); 
			break;
 		case 'Z': tlapakz = (tlapakz - 5) % 120;
			glutPostRedisplay();
			break;
 		case 'x': tlapaky = (tlapaky + 5) % 40;
			glutPostRedisplay();
			break;
 		case 'X': tlapaky = (tlapaky - 5) % 40;
			glutPostRedisplay();
			break;
 		case 'c': tlapakx = (tlapakx + 5) % 120;
			glutPostRedisplay();
			break;
 		case 'C': tlapakx = (tlapakx - 5) % 120;
			glutPostRedisplay();
			break;
	
	//Jempol
 		case 'B': jempol1 = (jempol1 + 5) % 90;
			glutPostRedisplay(); 
			break;
 		case 'b': jempol1 = (jempol1 - 5) % 90;
			glutPostRedisplay(); 
			break;
 		case 'N': jempol2 = (jempol2 + 5) % 90;
			glutPostRedisplay(); 
			break;
 		case 'n': jempol2 = (jempol2 - 5) % 90;
			glutPostRedisplay(); 
			break;
			
	//Telunjuk
 		case 'j': tlunjuk1 = (tlunjuk1 + 5) % 90;
			glutPostRedisplay(); 
			break;
 		case 'J': tlunjuk1 = (tlunjuk1 - 5) % 90;
			glutPostRedisplay(); 
			break;
 		case 'u': tlunjuk2 = (tlunjuk2 + 5) % 90;
			glutPostRedisplay(); 
			break;
 		case 'U': tlunjuk2 = (tlunjuk2 - 5) % 90;
			glutPostRedisplay(); 
			break;
			
	//Tengah
 		case 'k': tengah1 = (tengah1 + 5) % 90;
			glutPostRedisplay(); 
			break;
 		case 'K': tengah1 = (tengah1 - 5) % 90;
			glutPostRedisplay(); 
			break;
 		case 'i': tengah2 = (tengah2 + 5) % 90;
			glutPostRedisplay(); 
			break;
 		case 'I': tengah2 = (tengah2 - 5) % 90;
			glutPostRedisplay(); 
			break;

	//Manis
 		case 'l': manis1 = (manis1 + 5) % 90;
			glutPostRedisplay(); 
			break;
 		case 'L': manis1 = (manis1 - 5) % 90;
			glutPostRedisplay(); 
			break;
 		case 'o': manis2 = (manis2 + 5) % 90;
			glutPostRedisplay(); 
			break;
 		case 'O': manis2 = (manis2 - 5) % 90;
			glutPostRedisplay(); 
			break;
			
	//Kelingking
 		case ';': klingking1 = (klingking1 + 5) % 90;
			glutPostRedisplay(); 
			break;
 		case ':': klingking1 = (klingking1 - 5) % 90;
			glutPostRedisplay(); 
			break;
 		case 'p': klingking2 = (klingking2 + 5) % 90;
			glutPostRedisplay(); 
			break;
 		case 'P': klingking2 = (klingking2 - 5) % 90;
			glutPostRedisplay(); 
			break;
			
		case 27: exit(0); 
			break;
			default: break;
 	}
}

int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize (800, 800);
	glutInitWindowPosition (100, 100);
	glutCreateWindow (argv[0]); init();
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutKeyboardFunc(keyboard);
	glutMainLoop(); return 0;
}
