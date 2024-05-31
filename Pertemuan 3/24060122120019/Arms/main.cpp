/*

	Diketik oleh Ghirsan Ahdani, 10 Maret 2024
	
	Program ini membuat grafik komputasi visual lengan beserta artikulasi geraknya.

*/

#include <GL/glut.h>
#include <stdlib.h>

static int shoulder = 0, elbow = 0, hand = 0, thumb_base = 0, thumb_base1 = 0, thumb_tip = 0,
           index_base = 0, index_base1 = 0, index_mid = 0, index_tip = 0,
		   mid_base = 0, mid_base1 = 0, mid_mid = 0, mid_tip = 0,
		   ring_base = 0, ring_base1 = 0, ring_mid = 0, ring_tip = 0,
		   pinky_base = 0, pinky_base1 = 0, pinky_mid = 0, pinky_tip = 0;

void init(void){
	
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glShadeModel(GL_FLAT);

}

void display(void){
	
    glClear(GL_COLOR_BUFFER_BIT);

    glPushMatrix();
    
	    // Bahu
		glTranslatef(-1.0, 0.0, 0.0);
	    glRotatef((GLfloat)shoulder, 0.0, 0.0, 1.0);
	    glTranslatef(1.0, 0.0, 0.0);
	    glPushMatrix();
		    
			glScalef(2.0, 0.4, 1.0);
		    glutWireCube(1.0);
	    
		glPopMatrix();
	    
	    // Lengan
		glTranslatef(1.0, 0.0, 0.0);
	    glRotatef((GLfloat)elbow, 0.0, 0.0, 1.0);
	    glTranslatef(1.0, 0.0, 0.0);
		glPushMatrix();
		    
			glScalef(2.0, 0.4, 1.0);
		    glutWireCube(1.0);
		    
		glPopMatrix();
	
	    // Tangan
	    glTranslatef(1.0, 0.0, 0.0);
	    glRotatef((GLfloat)hand, 0.0, 0.0, 1.0);
	    glTranslatef(0.5, 0.0, 0.0);
	    glPushMatrix();
		glScalef(1.0, 0.4, 1.0);
		
		    glutWireCube(1.0);
	    
		glPopMatrix();
	
	    // Jempol
	    glPushMatrix();
	    
		    glTranslatef(-0.4, 0.0, 0.6);	// thumb_base
		    glRotatef((GLfloat)thumb_base, 0.0, 0.0, 1.0);
		    glRotatef((GLfloat)thumb_base1, 0.0, 1.0, 0.0);
		    glTranslatef(0.4, 0.0, 0.0);
		    glPushMatrix();
		    glScalef(0.4, 0.2, 0.2);
		    
		    	glutWireCube(1.0);
		    
			glPopMatrix();
		
		    glTranslatef(0.1, 0.0, 0.0);	// thumb_tip
		    glRotatef((GLfloat)thumb_tip, 0.0, 1.0, 0.0);
		    glTranslatef(0.3, 0.0, 0.0);
		    glPushMatrix();
		    glScalef(0.4, 0.2, 0.2);
		    
				glutWireCube(1.0);
		    
			glPopMatrix();
	    
		glPopMatrix();
	
	    // Telunjuk
	    glPushMatrix();
	    
		    glTranslatef(0.5, 0.0, 0.4);	// index_base
		    glRotatef((GLfloat)index_base, 0.0, 0.0, 1.0);
		    glRotatef((GLfloat)index_base1, 0.0, 1.0, 0.0);
		    glTranslatef(0.2, 0.0, 0.0);
		    glPushMatrix();
		    glScalef(0.4, 0.2, 0.2);
		    
				glutWireCube(1.0);
		    
			glPopMatrix();
		
		    glTranslatef(0.2, 0.0, 0.0);	// index_mid
		    glRotatef((GLfloat)index_mid, 0.0, 0.0, 1.0);
		    glTranslatef(0.2, 0.0, 0.0);
		    glPushMatrix();
		    glScalef(0.4, 0.2, 0.2);
		    
				glutWireCube(1.0);
		    
			glPopMatrix();
		
		    glTranslatef(0.2, 0.0, 0.0);	// index_tip
		    glRotatef((GLfloat)index_tip, 0.0, 0.0, 1.0);
		    glTranslatef(0.1, 0.0, 0.0);
		    glPushMatrix();
		    glScalef(0.2, 0.2, 0.2);
		    	
				glutWireCube(1.0);
		    
			glPopMatrix();
		    
		glPopMatrix();
		
		// Tengah
		glPushMatrix();
		
		    glTranslatef(0.55, 0.0, 0.1325);	// mid_base
		    glRotatef((GLfloat)mid_base, 0.0, 0.0, 1.0);
		    glRotatef((GLfloat)mid_base1, 0.0, 1.0, 0.0);
		    glTranslatef(0.2, 0.0, 0.0);
		    glPushMatrix();
		    glScalef(0.5, 0.2, 0.2);
		    
				glutWireCube(1.0);
		    
			glPopMatrix();
		
		    glTranslatef(0.3, 0.0, 0.0);	// mid_mid
		    glRotatef((GLfloat)mid_mid, 0.0, 0.0, 1.0);
		    glTranslatef(0.2, 0.0, 0.0);
		    glPushMatrix();
		    glScalef(0.5, 0.2, 0.2);
		    
				glutWireCube(1.0);
		    
			glPopMatrix();
		
		    glTranslatef(0.25, 0.0, 0.0);	// mid_tip
		    glRotatef((GLfloat)mid_tip, 0.0, 0.0, 1.0);
		    glTranslatef(0.1, 0.0, 0.0);
		    glPushMatrix();
		    glScalef(0.2, 0.2, 0.2);
		    
				glutWireCube(1.0);
		    
			glPopMatrix();
	    
		glPopMatrix();
	
	    // Manis
	    glPushMatrix();
	    
		    glTranslatef(0.5, 0.0, -0.1325);	// ring_base
		    glRotatef((GLfloat)ring_base, 0.0, 0.0, 1.0);
		    glRotatef((GLfloat)ring_base1, 0.0, 1.0, 0.0);
		    glTranslatef(0.2, 0.0, 0.0);
		    glPushMatrix();
		    glScalef(0.4, 0.2, 0.2);
		    	
				glutWireCube(1.0);
		    
			glPopMatrix();
		
		    glTranslatef(0.2, 0.0, 0.0);	// ring_mid
		    glRotatef((GLfloat)ring_mid, 0.0, 0.0, 1.0);
		    glTranslatef(0.2, 0.0, 0.0);
		    glPushMatrix();
		    glScalef(0.4, 0.2, 0.2);
		    
				glutWireCube(1.0);
		    
			glPopMatrix();
		
		    glTranslatef(0.2, 0.0, 0.0);	// ring_tip
		    glRotatef((GLfloat)ring_tip, 0.0, 0.0, 1.0);
		    glTranslatef(0.1, 0.0, 0.0);
		    glPushMatrix();
		    glScalef(0.2, 0.2, 0.2);
		    
				glutWireCube(1.0);
		    
			glPopMatrix();
	    
		glPopMatrix();
	
		// Kelingking
	    glPushMatrix();
		 
		    glTranslatef(0.45, 0.0, -0.4);	//pinky_base
		    glRotatef((GLfloat)pinky_base, 0.0, 0.0, 1.0);
		    glRotatef((GLfloat)pinky_base1, 0.0, 1.0, 0.0);
		    glTranslatef(0.2, 0.0, 0.0);
		    glPushMatrix();
		    glScalef(0.3, 0.2, 0.2);
		    	
				glutWireCube(1.0);
		    
			glPopMatrix();
		
		    glTranslatef(0.1, 0.0, 0.0);	//pinky_mid
		    glRotatef((GLfloat)pinky_mid, 0.0, 0.0, 1.0);
		    glTranslatef(0.2, 0.0, 0.0);
		    glPushMatrix();
		    glScalef(0.3, 0.2, 0.2);
		    
				glutWireCube(1.0);
		    
			glPopMatrix();
		
		    glTranslatef(0.15, 0.0, 0.0);	//pinky_tip
		    glRotatef((GLfloat)pinky_tip, 0.0, 0.0, 1.0);
		    glTranslatef(0.1, 0.0, 0.0);
		    glPushMatrix();
		    glScalef(0.2, 0.2, 0.2);
		    
				glutWireCube(1.0);
		    
			glPopMatrix();
	    
		glPopMatrix();

    glPopMatrix();

    glutSwapBuffers();
}

void reshape(int w, int h){
	
    glViewport(0, 0, (GLsizei)w, (GLsizei)h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(80.0, (GLfloat)w / (GLfloat)h, 1.0, 20.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glTranslatef(0.0, 0.0, -7.0);
    glRotatef(0.0, 1.0, 0.0, 0.0);
    glRotatef(-90.0, 0.0, 1.0, 0.0);

}

void keyboard(unsigned char key, int x, int y){
	
    switch (key){
    	
	    case 's':
	    	
	        shoulder = (shoulder + 5) % 360;
	        glutPostRedisplay();
	        
			break;
	
	    case 'S':
	        
			shoulder = (shoulder - 5) % 360;
	        glutPostRedisplay();
	        
			break;
	
	    case 'e':
	    	
	    	if (elbow < 145){
	    		
		    	elbow = (elbow + 5) % 360;
		        glutPostRedisplay();
	    		
	    	}
	    	
	        break;
	
	    case 'E':
	    	
	    	if (elbow > 0){
	    		
	    		elbow = (elbow - 5) % 360;
	        	glutPostRedisplay();
	        	
	    	}
	    	
	        break;
	
	    case 'd':
	    	
	    	if (hand < 90){
	    		
	    		hand = (hand + 5) % 360;
	        	glutPostRedisplay();
	    		
	    	}
	    	
	        break;
	
	    case 'D':
	    	
	        if (hand > -90){
	    		
	    		hand = (hand - 5) % 360;
	        	glutPostRedisplay();
	    		
	    	}
			
			break;
	
		case 'b': // Thumb base1
	    	
	    	if (thumb_base1 < 45){
	    	
		        thumb_base1 = (thumb_base1 + 5) % 360;
		        glutPostRedisplay();
				
	    	}
	    	
	        break;
	
		case 'B': // Thumb base1
	    	
	    	if (thumb_base1 > -25){
	    	
		        thumb_base1 = (thumb_base1 - 5) % 360;
		        glutPostRedisplay();
				
	    	}
	    	
	        break;
	
	    case 'g': // Thumb base
	    	
	    	if (thumb_base < 45){
	    	
		        thumb_base = (thumb_base + 5) % 360;
		        glutPostRedisplay();
				
	    	}
	    	
	        break;
	
		case 'G': // Thumb base
	    	
	    	if (thumb_base > -25){
	    	
		        thumb_base = (thumb_base - 5) % 360;
		        glutPostRedisplay();
				
	    	}
	    	
	        break;
	
	    case 't': // Thumb tip
	        
	        if (thumb_tip < 60){
	        
				thumb_tip = (thumb_tip + 5) % 360;
		        glutPostRedisplay();	
	        	
	        }
	        
	        break;
	
		case 'T': // Thumb tip
	        
	        if (thumb_tip > 0){
	        
				thumb_tip = (thumb_tip - 5) % 360;
		        glutPostRedisplay();	
	        	
	        }
	        
	        break;
	        
	    case 'n': // Index base1
	    	
	    	if (index_base1 < 22.5){
	    	
		        index_base1 = (index_base1 + 5) % 360;
		        glutPostRedisplay();
				
	    	}
	    	
	        break;
	
		case 'N': // Index base1
	    	
	    	if (index_base1 > -22.5){
	    	
		        index_base1 = (index_base1 - 5) % 360;
		        glutPostRedisplay();
				
	    	}
	    	
	        break;
	
	    case 'h': // Index base
	    	
	    	if (index_base < 90){
	    	
		        index_base = (index_base + 5) % 360;
		        glutPostRedisplay();
				
	    	}
	    	
	        break;
	
		case 'H': // Index base
	    	
	    	if (index_base > -25){
	    	
		        index_base = (index_base - 5) % 360;
		        glutPostRedisplay();
				
	    	}
	    	
	        break;
	
		case 'y': // Index mid
	        
	        if (index_mid < 90){
	        
				index_mid = (index_mid + 5) % 360;
		        glutPostRedisplay();	
	        	
	        }
	        
	        break;
	
		case 'Y': // Index mid
	        
	        if (index_mid > 0){
	        
				index_mid = (index_mid - 5) % 360;
		        glutPostRedisplay();	
	        	
	        }
	        
	        break;
	
		case '6': // Index tip
	        
	        if (index_tip < 90){
	        
				index_tip = (index_tip + 5) % 360;
		        glutPostRedisplay();	
	        	
	        }
	        
	        break;
	
		case '^': // Index tip
	        
	        if (index_tip > 0){
	        
				index_tip = (index_tip - 5) % 360;
		        glutPostRedisplay();	
	        	
	        }
	        
	        break;
	
		case 'm': // mid base1
	    	
	    	if (mid_base1 < 22.5){
	    	
		        mid_base1 = (mid_base1 + 5) % 360;
		        glutPostRedisplay();
				
	    	}
	    	
	        break;
	
		case 'M': // mid base1
	    	
	    	if (mid_base1 > -22.5){
	    	
		        mid_base1 = (mid_base1 - 5) % 360;
		        glutPostRedisplay();
				
	    	}
	    	
	        break;
	
	    case 'j': // Mid base
	    	
	    	if (mid_base < 90){
	    	
		        mid_base = (mid_base + 5) % 360;
		        glutPostRedisplay();
				
	    	}
	    	
	        break;
	
		case 'J': // mid base
	    	
	    	if (mid_base > -25){
	    	
		        mid_base = (mid_base - 5) % 360;
		        glutPostRedisplay();
				
	    	}
	    	
	        break;
	
		case 'u': // mid mid
	        
	        if (mid_mid < 90){
	        
				mid_mid = (mid_mid + 5) % 360;
		        glutPostRedisplay();	
	        	
	        }
	        
	        break;
	
		case 'U': // mid mid
	        
	        if (mid_mid > 0){
	        
				mid_mid = (mid_mid - 5) % 360;
		        glutPostRedisplay();	
	        	
	        }
	        
	        break;
	
		case '7': // mid tip
	        
	        if (mid_tip < 90){
	        
				mid_tip = (mid_tip + 5) % 360;
		        glutPostRedisplay();	
	        	
	        }
	        
	        break;
	
		case '&': // mid tip
	        
	        if (mid_tip > 0){
	        
				mid_tip = (mid_tip - 5) % 360;
		        glutPostRedisplay();	
	        	
	        }
	        
	        break;
	
		case ',': // ring base1
	    	
	    	if (ring_base1 < 22.5){
	    	
		        ring_base1 = (ring_base1 + 5) % 360;
		        glutPostRedisplay();
				
	    	}
	    	
	        break;
	
		case '<': // ring base1
	    	
	    	if (ring_base1 > -22.5){
	    	
		        ring_base1 = (ring_base1 - 5) % 360;
		        glutPostRedisplay();
				
	    	}
	    	
	        break;
		
		case 'k': // ring base
	    	
	    	if (ring_base < 90){
	    	
		        ring_base = (ring_base + 5) % 360;
		        glutPostRedisplay();
				
	    	}
	    	
	        break;
	
		case 'K': // ring base
	    	
	    	if (ring_base > -25){
	    	
		        ring_base = (ring_base - 5) % 360;
		        glutPostRedisplay();
				
	    	}
	    	
	        break;
	
		case 'i': // ring mid
	        
	        if (ring_mid < 90){
	        
				ring_mid = (ring_mid + 5) % 360;
		        glutPostRedisplay();	
	        	
	        }
	        
	        break;
	
		case 'I': // ring mid
	        
	        if (ring_mid > 0){
	        
				ring_mid = (ring_mid - 5) % 360;
		        glutPostRedisplay();	
	        	
	        }
	        
	        break;
	
		case '8': // ring tip
	        
	        if (ring_tip < 90){
	        
				ring_tip = (ring_tip + 5) % 360;
		        glutPostRedisplay();	
	        	
	        }
	        
	        break;
	
		case '*': // ring tip
	        
	        if (ring_tip > 0){
	        
				ring_tip = (ring_tip - 5) % 360;
		        glutPostRedisplay();	
	        	
	        }
	        
	        break;
	    
	    case '.': // pinky base1
	    	
	    	if (pinky_base1 < 22.5){
	    	
		        pinky_base1 = (pinky_base1 + 5) % 360;
		        glutPostRedisplay();
				
	    	}
	    	
	        break;
	
		case '>': // pinky base1
	    	
	    	if (pinky_base1 > -22.5){
	    	
		        pinky_base1 = (pinky_base1 - 5) % 360;
		        glutPostRedisplay();
				
	    	}
	    	
	        break;
	
		case 'l': // pinky base
	    	
	    	if (pinky_base < 90){
	    	
		        pinky_base = (pinky_base + 5) % 360;
		        glutPostRedisplay();
				
	    	}
	    	
	        break;
	
		case 'L': // pinky base
	    	
	    	if (pinky_base > -25){
	    	
		        pinky_base = (pinky_base - 5) % 360;
		        glutPostRedisplay();
				
	    	}
	    	
	        break;
	
		case 'o': // pinky mid
	        
	        if (pinky_mid < 90){
	        
				pinky_mid = (pinky_mid + 5) % 360;
		        glutPostRedisplay();	
	        	
	        }
	        
	        break;
	
		case 'O': // pinky mid
	        
	        if (pinky_mid > 0){
	        
				pinky_mid = (pinky_mid - 5) % 360;
		        glutPostRedisplay();	
	        	
	        }
	        
	        break;
	
		case '9': // pinky tip
	        
	        if (pinky_tip < 90){
	        
				pinky_tip = (pinky_tip + 5) % 360;
		        glutPostRedisplay();	
	        	
	        }
	        
	        break;
	
		case '(': // pinky tip
	        
	        if (pinky_tip > 0){
	        
				pinky_tip = (pinky_tip - 5) % 360;
		        glutPostRedisplay();	
	        	
	        }
	        
	        break;
	
	
	    case 27:
	    	
	        exit(0);
	        
			break;
	
	    default:
	    	
	        break;
    
	}
    
}

int main(int argc, char** argv) {
	
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(700, 600);
    glutInitWindowPosition(100, 100);
    glutCreateWindow(argv[0]);
    
	init();
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(keyboard);
    glutMainLoop();

    return 0;

}

