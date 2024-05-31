#include <GL/glut.h>
static int shoulder = 0, elbow = 0, palm = 0, thumb = 0, index = 0, middle = 0, ring = 0, pinky = 0;

void init(void) {
	glClearColor (0.0, 0.0, 0.0, 0.0);
	glShadeModel (GL_FLAT);
}

void display(void) {
	glColor3f(1.0f, 0.0f, 1.0f);
    glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glPushMatrix();
    	//SHOULDER
	 	glTranslatef (-1.0, 0.0, 0.0);
	 	glRotatef ((GLfloat) shoulder, 0.0, 1.0, 0.0);
		glTranslatef (1.0, 0.0, 0.0);
		glPushMatrix();
			glScalef (2.0, 0.4, 1.0);
			glutWireCube (1.0);
		glPopMatrix();
 
 		//ELBOW
	 	glTranslatef (1.0, 0.0, 0.0);
		glRotatef ((GLfloat) elbow, 0.0, 0.0, 1.0);
		glTranslatef (1.0, 0.0, 0.0);
		glPushMatrix();
			glScalef (2.0, 0.4, 1.0);
			glutWireCube (1.0);
		glPopMatrix();
		
		//PALM
		glTranslatef (1.0, 0.0, 0.0);
		glRotatef ((GLfloat) palm, 0.0, 0.0, 1.0);
		glTranslatef (0.5, 0.0, 0.0);
		glPushMatrix();
			glScalef (1.5, 0.3, 1.0);
			glutWireCube (1.0);
		glPopMatrix();
		
		//FINGERS
			//THUMB
			glPushMatrix();
                glTranslatef(0.0, 0.0, 0.65);
                glTranslatef(-0.25, -0.25, -0.15);
                glRotatef((GLfloat) thumb, -1., 0., 1.);
                glTranslatef(.25, 0., 0.);
                glPushMatrix();
                    glScalef(.5, .25, .25);
                    glutWireCube(1.);
                glPopMatrix();

                glTranslatef(.25, 0., 0.);
                glRotatef((GLfloat) thumb, 0., 0., 1.);
                glTranslatef(.25, 0., 0.);
                glPushMatrix();
                    glScalef(.5, .25, .25);
                    glutWireCube(1.);
                glPopMatrix();
                
                glTranslatef(.15, 0., 0.);
                glRotatef((GLfloat) thumb, 1., 0., 1.);
                glTranslatef(.25, 0., 0.);
                glPushMatrix();
                    glScalef(.25, .25, .25);
                    glutWireCube(1.);
                glPopMatrix();
       		glPopMatrix();
       		
       		//INDEX
       		glPushMatrix();
                glTranslatef(0.0, 0.0, 0.4);
                glTranslatef(.25, 0., 0.);
                glRotatef((GLfloat) index, 0., 0., 1.);
                glTranslatef(.25, 0., 0.);
                glPushMatrix();
                    glScalef(.5, .25, .25);
                    glutWireCube(1.);
                glPopMatrix();

                glTranslatef(.25, 0., 0.);
                glRotatef((GLfloat) index, 0., 0., 1.);
                glTranslatef(.25, 0., 0.);
                glPushMatrix();
                    glScalef(.5, .25, .25);
                    glutWireCube(1.);
                glPopMatrix();
                
                glTranslatef(.25, 0., 0.);
                glRotatef((GLfloat) index, 0., 0., 1.);
                glTranslatef(.25, 0., 0.);
                glPushMatrix();
                    glScalef(.5, .25, .25);
                    glutWireCube(1.);
                glPopMatrix();
        	glPopMatrix();
        	
        	//MIDDLE
        	glPushMatrix();
                glTranslatef(0.25, 0.0, 0.15);
                glTranslatef(.25, 0., 0.);
                glRotatef((GLfloat) middle, 0., 0., 1.);
                glTranslatef(.25, 0., 0.);
                glPushMatrix();
                    glScalef(.75, .25, .25);
                    glutWireCube(1.);
                glPopMatrix();

                glTranslatef(.25, 0., 0.);
                glRotatef((GLfloat) middle, 0., 0., 1.);
                glTranslatef(.25, 0., 0.);
                glPushMatrix();
                    glScalef(.5, .25, .25);
                    glutWireCube(1.);
                glPopMatrix();
                
                glTranslatef(.25, 0., 0.);
                glRotatef((GLfloat) middle, 0., 0., 1.);
                glTranslatef(.25, 0., 0.);
                glPushMatrix();
                    glScalef(.5, .25, .25);
                    glutWireCube(1.);
                glPopMatrix();
       		glPopMatrix();
       		
       		//RING
       		glPushMatrix();
                glTranslatef(0.15, 0.0, -0.1);
                glTranslatef(.25, 0., 0.);
                glRotatef((GLfloat) ring, 0., 0., 1.);
                glTranslatef(.25, 0., 0.);
                glPushMatrix();
                    glScalef(.5, .25, .25);
                    glutWireCube(1.);
                glPopMatrix();

                glTranslatef(.25, 0., 0.);
                glRotatef((GLfloat) ring, 0., 0., 1.);
                glTranslatef(.25, 0., 0.);
                glPushMatrix();
                    glScalef(.5, .25, .25);
                    glutWireCube(1.);
                glPopMatrix();
                
                glTranslatef(.25, 0., 0.);
                glRotatef((GLfloat) ring, 0., 0., 1.);
                glTranslatef(.25, 0., 0.);
                glPushMatrix();
                    glScalef(.5, .25, .25);
                    glutWireCube(1.);
                glPopMatrix();
      		glPopMatrix();
        
			//PINKY
			glPushMatrix();
	            glTranslatef(0.0, 0.0, -0.6);
	       	    glTranslatef(.25, 0., 0.25);
	            glRotatef((GLfloat) pinky, 0., 0., 1.);
	            glTranslatef(.25, 0., 0.);
	            glPushMatrix();
	                glScalef(.5, .25, .25);
	                glutWireCube(1.);
	            glPopMatrix();
	
	            glTranslatef(.25, 0., 0.);
	            glRotatef((GLfloat) pinky, 0., 0., 1.);
	            glTranslatef(.25, 0., 0.);
	            glPushMatrix();
	                glScalef(.5, .25, .25);
	                glutWireCube(1.);
	            glPopMatrix();
	                
	            glTranslatef(.15, 0., 0.);
	            glRotatef((GLfloat) pinky, 0., 0., 1.);
	            glTranslatef(.25, 0., 0.);
	            glPushMatrix();
	                glScalef(.35, .25, .25);
	                glutWireCube(1.);
	            glPopMatrix();
	        glPopMatrix();
		
		
	glPopMatrix();
	glutSwapBuffers();
}

void reshape (int w, int h) {
	glViewport (0, 0, (GLsizei) w, (GLsizei) h);
	glMatrixMode (GL_PROJECTION); glLoadIdentity();
	gluPerspective(65.0, (GLfloat) w/(GLfloat) h, 1.0, 20.0);
	glMatrixMode(GL_MODELVIEW); glLoadIdentity();
 	glTranslatef (0.0, 0.0, -5.0);
}

void keyboard(unsigned char key, int x, int y) {
	switch (key) {
		case 'q': shoulder = (shoulder + 5) % 360;
		glutPostRedisplay(); break;
	 	case 'e': shoulder = (shoulder - 5) % 360;
		glutPostRedisplay(); break;
	 	case 'w': elbow = (elbow + 5) % 360;
		glutPostRedisplay(); break;
	 	case 's': elbow = (elbow - 5) % 360;
		glutPostRedisplay(); break;
		case 'a': palm = (palm + 5) % 360;
        glutPostRedisplay(); break;
        case 'd': palm = (palm - 5) % 360;
        glutPostRedisplay(); break;
        case 't': thumb = (thumb + 5) % 360;
        glutPostRedisplay(); break;
        case 'T': thumb = (thumb - 5) % 360;
        glutPostRedisplay(); break;
        case 'i': index = (index + 5) % 360;
        glutPostRedisplay(); break;
        case 'I': index = (index - 5) % 360;
        glutPostRedisplay(); break;
        case 'm': middle = (middle + 5) % 360;
        glutPostRedisplay(); break;
        case 'M': middle = (middle - 5) % 360;
        glutPostRedisplay(); break;
        case 'r': ring = (ring + 5) % 360;
        glutPostRedisplay(); break;
        case 'R': ring = (ring - 5) % 360;
        glutPostRedisplay(); break;
        case 'p': pinky = (pinky + 5) % 360;
        glutPostRedisplay(); break;
        case 'P': pinky = (pinky - 5) % 360;
        glutPostRedisplay(); break;
		case 27: exit(0); break;
		default: break;
	 }
}

int main(int argc, char** argv) {
glutInit(&argc, argv);
 glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB);
glutInitWindowSize (700, 600);
glutInitWindowPosition (100, 100);
glutCreateWindow (argv[0]); init();
 glutDisplayFunc(display);
glutReshapeFunc(reshape);
glutKeyboardFunc(keyboard);
glutMainLoop(); return 0;
} 
