#include <GL/glut.h>   
static int shoulder = 0, elbow = 0; 
static int palm=0,finger1=0,finger2=0;
static int finger3=0,finger4=0,finger5=0; 
   
 void init(void) {   
    glClearColor (0.0, 0.0, 0.0, 0.0);        
	glShadeModel (GL_FLAT);   
 }   
   
 void display(void) {   
    glClear (GL_COLOR_BUFFER_BIT);        
	glPushMatrix();   
    	glTranslatef (-1.0, 0.0, 0.0);  //bahu 
    	glRotatef ((GLfloat) shoulder, 0.0, 0.0, 1.0);            
		glTranslatef (-1.0, 0.0, 0.0);            
		glPushMatrix();   
            glScalef (2.0, 0.4, 1.0);                
			glutWireCube (1.0);            
		glPopMatrix();   
        glTranslatef (1.0, 0.0, 0.0);  //elbow  
        glRotatef ((GLfloat) elbow, 0.0, 0.0, 1.0);            
		glTranslatef (1.0, 0.0, 0.0);            
		glPushMatrix();   
        	glScalef (2.0, 0.4, 1.0);                
			glutWireCube (1.0);            
		glPopMatrix();  
		glTranslatef (0.65,0.0,0.0);
		glRotatef((GLfloat)palm, 0.0,0.0 ,1.0);
		glTranslatef(0.5,0.0,0.0);
		glPushMatrix();
			glScalef(0.6,0.4,1.0);
			glutWireCube(1.0);
		glPopMatrix();
		glTranslatef (0.0,0.0,1.0);
		glRotatef((GLfloat)finger1, 0.0,0.0 ,1.0);
		glTranslatef(0.0,0.0,0.0);
		glPushMatrix();
			glScalef(0.1,0.1,0.4);
			glutWireCube(1.0);
		glPopMatrix();
		glTranslatef (0.2,0.0,-0.4);
		glRotatef((GLfloat)finger2, 0.0,0.0 ,1.0);
		glTranslatef(0.2,0.0,0.0);
		glPushMatrix();
			glScalef(0.4,0.1,0.2);
			glutWireCube(1.0);
		glPopMatrix();
		glTranslatef (0.1,0.0,-0.45);
		glRotatef((GLfloat)finger3, 0.0,0.0 ,1.0);
		glTranslatef(0.1,0.0,0.0);
		glPushMatrix();
			glScalef(0.5,0.1,0.2);
			glutWireCube(1.0);
		glPopMatrix();
		glTranslatef (0.1,0.0,-0.45);
		glRotatef((GLfloat)finger4, 0.0,0.0 ,1.0);
		glTranslatef(0.1,0.0,0.0);
		glPushMatrix();
			glScalef(0.6,0.1,0.2);
			glutWireCube(1.0);
		glPopMatrix();
		glTranslatef (-0.05,0.0,-0.45);
		glRotatef((GLfloat)finger5, 0.0,0.0 ,1.0);
		glTranslatef(-0.05,0.0,0.0);
		glPushMatrix();
			glScalef(0.55,0.1,0.2);
			glutWireCube(1.0);
		glPopMatrix();
		
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
	case 's': shoulder = (shoulder + 5) % 360;                    
	glutPostRedisplay();                    
	break;   
	case 'S': shoulder = (shoulder - 5) % 360;                    	
	glutPostRedisplay();                    break;   
	case 'e': elbow = (elbow + 5) % 360;                    
	glutPostRedisplay();                    break;   
	case 'E': elbow = (elbow - 5) % 360;                    
	glutPostRedisplay();                    break;
	case 'w':palm=(palm+5)%90;
	glutPostRedisplay(); break;
	case 'W':palm= (palm-5)%90;
	glutPostRedisplay(); break;            
	case 'z':finger1=(finger1+5)%90;
	glutPostRedisplay(); break;
	case 'Z':finger1= (finger1-5)%90;
	glutPostRedisplay(); break;  
	case 'x':finger2=(finger2+5)%90;
	glutPostRedisplay(); break;
	case 'X':finger2= (finger2-5)%90;
	glutPostRedisplay(); break;  
	case 'c':finger3=(finger3+5)%90;
	glutPostRedisplay(); break;
	case 'C':finger3= (finger3-5)%90;
	glutPostRedisplay(); break;  
	case 'v':finger4=(finger4+5)%90;
	glutPostRedisplay(); break;
	case 'V':finger4= (finger4-5)%90;
	glutPostRedisplay(); break; 
	case 'b':finger5=(finger5+5)%90;
	glutPostRedisplay(); break;
	case 'B':finger5= (finger5-5)%90;
	glutPostRedisplay(); break;                  
	case 27: exit(0);                    break;              
	default: break;   
	}   
}

int main(int argc, char** argv) {        
	glutInit(&argc, argv);   
	glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB);        
	glutInitWindowSize (700, 600);        
	glutInitWindowPosition (300, 100);        
	glutCreateWindow (argv[0]);        init();   
	glutDisplayFunc(display);        
	glutReshapeFunc(reshape);        
	glutKeyboardFunc(keyboard);        
	glutMainLoop();        return 0;  
}  
