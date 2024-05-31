// 	Azzam Saefudin Rosyidi
//	24060122130076

#include <GL/glut.h> 
static int shoulder = 0, elbow = 0, hand= 0, ibujari=0, ibujari2=0, telunjuk=0 , telunjuk2=0, tengah=0, tengah2=0, manis=0, manis2=0, kelingking=0, kelingking2=0; 
 
void init(void) { 
	glClearColor (0.0, 0.0, 0.0, 0.0); 
	glShadeModel (GL_FLAT); 
} 
 
void display(void) { 
	glClear (GL_COLOR_BUFFER_BIT); 
	
	glPushMatrix(); 
		glTranslatef (-2.5, -2.0, 0.0); 
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
///	tangan
        glTranslatef(0.7, 0.0, 0.0);
        glRotatef((GLfloat)hand, 1.0, 0.0, 0.0);
        glTranslatef(0.7, 0.0, 0.0);
        
        glPushMatrix(); 
            glScalef(1.0, 1.0, 0.8); 
            glutWireCube(1.0);  
        glPopMatrix();

//Jari :

//	ibujari
 		glPushMatrix();      
	        glTranslatef(-0.03, 0.5, 0.0);
	        glRotatef((GLfloat)ibujari, 0.0, 0.0, 1.0);
	        glTranslatef(-0.03, 0.1, 0.0);
                glScalef(0.15, 0.3, 0.15);
                glutWireCube(1.0);
        glPopMatrix(); 
        
        glPushMatrix();      
	        glTranslatef(-0.03, 0.55, 0.0);
	        glRotatef((GLfloat)ibujari2, 0.0, 0.0, 1.0);
	        glTranslatef(-0.03, 0.35, 0.0);
                glScalef(0.15, 0.3, 0.15);
                glutWireCube(1.0);
        glPopMatrix(); 

//	telunjuk
 		glPushMatrix();       
	        glTranslatef(0.46, 0.2, 0.0);
	        glRotatef((GLfloat)telunjuk, 0.0, 1.0, 0.0);
	        glTranslatef(0.2, 0.2, 0.0);
                glScalef(0.35, 0.13, 0.1);
                glutWireCube(1.0);
        glPopMatrix();
        glPushMatrix();       
	        glTranslatef(0.6, 0.2, 0.0);
	        glRotatef((GLfloat)telunjuk2, 0.0, 1.0, 0.0);
	        glTranslatef(0.4, 0.2, 0.0);
                glScalef(0.35, 0.13, 0.1);
                glutWireCube(1.0);
        glPopMatrix();
// tengah
		glPushMatrix();
        	glTranslatef(0.51, 0.06, 0.0);
        	glRotatef((GLfloat)tengah, 0.0, 1.0, 0.0);
        	glTranslatef(0.2, 0.06, 0.0);
            	glScalef(0.45, 0.13, 0.13);
            	glutWireCube(1.0);
        glPopMatrix();
        glPushMatrix();
        	glTranslatef(0.67, 0.06, 0.0);
        	glRotatef((GLfloat)tengah2, 0.0, 1.0, 0.0);
        	glTranslatef(0.45, 0.06, 0.0);
            	glScalef(0.45, 0.13, 0.13);
            	glutWireCube(1.0);
        glPopMatrix();
        
// manis
        glPushMatrix();	       
	        glTranslatef(0.49, -0.07, 0.0);
	        glRotatef((GLfloat)manis, 0.0, 1.0, 0.0);
	        glTranslatef(0.2, -0.07, 0.0);
                glScalef(0.37, 0.13, 0.13);
                glutWireCube(1.0);
        glPopMatrix();
		glPushMatrix();	       
	        glTranslatef(0.63, -0.07, 0.0);
	        glRotatef((GLfloat)manis2, 0.0, 1.0, 0.0);
	        glTranslatef(0.42, -0.07, 0.0);
                glScalef(0.37, 0.13, 0.13);
                glutWireCube(1.0);
        glPopMatrix();
//// kelingking
		glPushMatrix(); 		       
	        glTranslatef(0.48, -0.2, 0.0);
	        glRotatef((GLfloat)kelingking, 0.0, 1.0, 0.0);
	        glTranslatef(0.15, -0.2, 0.0);
                glScalef(0.3, 0.13, 0.13);
                glutWireCube(1.0);
        glPopMatrix();  
		glPushMatrix(); 		       
	        glTranslatef(0.55, -0.2, 0.0);
	        glRotatef((GLfloat)kelingking2, 0.0, 1.0, 0.0);
	        glTranslatef(0.35, -0.2, 0.0);
                glScalef(0.3, 0.13, 0.13);
                glutWireCube(1.0);
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
		case 'a': shoulder = (shoulder + 5) % 360; 
			glutPostRedisplay(); 
			break; 
		case 'A': shoulder = (shoulder - 5) % 360; 
			glutPostRedisplay(); 
			break; 
		case 's': elbow = (elbow + 5) % 360; 
			glutPostRedisplay(); 
			break; 
		case 'S': elbow = (elbow - 5) % 360; 
			glutPostRedisplay(); 
			break;
		case 'd': hand = (hand + 5) % 360; 
			glutPostRedisplay(); 
			break; 
		case 'D': hand = (hand - 5) % 360; 
			glutPostRedisplay(); 
			break;
		case 'q': ibujari = (ibujari + 5) % 360; 
			glutPostRedisplay(); 
			break; 
		case 'Q': ibujari = (ibujari - 5) % 360; 
			glutPostRedisplay(); 
			break;
		case 'z': ibujari2 = (ibujari2 + 5) % 360; 
			glutPostRedisplay(); 
			break; 
		case 'Z': ibujari2 = (ibujari2 - 5) % 360; 
			glutPostRedisplay(); 
			break;
		case 'w': telunjuk = (telunjuk + 5) % 360; 
			glutPostRedisplay(); 
			break; 
		case 'W': telunjuk = (telunjuk - 5) % 360; 
			glutPostRedisplay(); 
			break;
		case 'x': telunjuk2 = (telunjuk2 + 5) % 360; 
			glutPostRedisplay(); 
			break; 
		case 'X': telunjuk2 = (telunjuk2 - 5) % 360; 
			glutPostRedisplay(); 
			break;
		case 'e': tengah = (tengah + 5) % 360; 
			glutPostRedisplay(); 
			break; 
		case 'E': tengah = (tengah - 5) % 360; 
			glutPostRedisplay(); 
			break;
		case 'c': tengah2 = (tengah2 + 5) % 360; 
			glutPostRedisplay(); 
			break; 
		case 'C': tengah2 = (tengah2 - 5) % 360; 
			glutPostRedisplay(); 
			break;
		case 'r': manis = ( manis + 5) % 360; 
			glutPostRedisplay(); 
			break; 
		case 'R': manis = (manis - 5) % 360; 
			glutPostRedisplay(); 
			break;
		case 'v': manis2 = ( manis2 + 5) % 360; 
			glutPostRedisplay(); 
			break; 
		case 'V': manis2 = (manis2 - 5) % 360; 
			glutPostRedisplay(); 
			break;
		case 't': kelingking = (kelingking + 5) % 360; 
			glutPostRedisplay(); 
			break; 
		case 'T': kelingking = (kelingking - 5) % 360; 
			glutPostRedisplay(); 
			break;
		case 'b': kelingking2 = (kelingking2 + 5) % 360; 
			glutPostRedisplay(); 
			break; 
		case 'B': kelingking2 = (kelingking2 - 5) % 360; 
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
	glutInitWindowSize (900, 720); 
	glutInitWindowPosition (100, 100); 
	glutCreateWindow (argv[0]); init(); 
	glutDisplayFunc(display); 
	glutReshapeFunc(reshape); 
	glutKeyboardFunc(keyboard); 
	glutMainLoop(); 
	return 0; 
}
