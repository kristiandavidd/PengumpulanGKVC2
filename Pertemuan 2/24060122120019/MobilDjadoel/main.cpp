/*

	Diketik oleh Ghirsan Ahdani, 3 Maret 2024
	
	Program ini membuat grafis komputasi visual mobil Ford Falcon 1964.

*/


#include <GL/glut.h>
#include <math.h>

void Roda(float x, float y, float radius, float r, float g, float b){	// Membuat lingkaran untuk roda
	
    glBegin(GL_POLYGON);
    glColor3f(r, g, b);
    
	for (int i = 0; i < 360; i += 10){
        float angle = i * (3.14159 / 180.0);
        glVertex2f(x + radius * cos(angle), y + radius * sin(angle));
    }
    
	glEnd();
}

void Siluet(void){	// Siluet mobil
	
	glBegin(GL_POLYGON);
	glColor3f(0.0, 0.0, 0.0);
	
		glVertex2f(0.9116, -0.226);
		glVertex2f(0.66, -0.231);
		glVertex2f(0.43, -0.231);
		glVertex2f(0.355, -0.28);
		glVertex2f(-0.413, -0.28);
		glVertex2f(-0.77, -0.2616);
		glVertex2f(-0.8083, -0.24);
		glVertex2f(-0.8383, -0.24);
		glVertex2f(-0.846, -0.126);
		glVertex2f(-0.9016, -0.055);
		glVertex2f(-0.846, 0.0083);
		glVertex2f(0.9116, 0.0083);
		glVertex2f(0.935, -0.025);
		glVertex2f(0.935, -0.046);
		glVertex2f(0.946, -0.083);
		glVertex2f(0.925, -0.125);
	
	glEnd();
	
}

void Body(void){	// Badan mobil
	
	glBegin(GL_POLYGON);
	glColor3f(0.898, 0.231, 0.231);
	
		glVertex2f(0.9116, -0.226);
		
		glVertex2f(0.71, -0.235);	// Cutout roda (tidak ter-display)
		glVertex2f(0.643, -0.1983);
		glVertex2f(0.5416, -0.165);
		glVertex2f(0.485, -0.16);
		glVertex2f(0.43, -0.165);
		glVertex2f(0.4, -0.186);
		glVertex2f(0.3883, -0.2116);
		glVertex2f(0.3883, -0.246);
		
		glVertex2f(0.355, -0.28);
		
		glVertex2f(-0.455, -0.225);	// Cutout roda (tidak ter-display)
		glVertex2f(-0.505, -0.1683);
		glVertex2f(-0.5416, -0.135);
		glVertex2f(-0.596, -0.116);
		glVertex2f(-0.66, -0.116);
		glVertex2f(-0.706, -0.135);
		glVertex2f(-0.735, -0.1683);
		glVertex2f(-0.765, -0.24);
		
		
		glVertex2f(-0.8083, -0.24);
		glVertex2f(-0.8383, -0.24);
		glVertex2f(-0.846, -0.126);
		glVertex2f(-0.9016, -0.055);
		glVertex2f(-0.846, 0.0083);
		glVertex2f(0.9116, 0.0083);
		glVertex2f(0.935, -0.025);
		glVertex2f(0.935, -0.046);
		glVertex2f(0.946, -0.083);
		glVertex2f(0.925, -0.125);
	
	glEnd();
	
	glLineWidth(2.0f);
	glBegin(GL_LINE_STRIP);
	glColor3f(0.812, 0.812, 0.812);
	
		glVertex2f(0.9083, -0.045);	// Corak
		glVertex2f(-0.8216, -0.045);
		glVertex2f(-0.8483, -0.06);
		glVertex2f(-0.8216, -0.073);
		glVertex2f(0.9083, -0.1216);
		
	glEnd();
	
}

void Jendela(void){	// Jendela mobil
	
	glBegin(GL_POLYGON);
	glColor3f(0.812, 0.812, 0.812);
	
		glVertex2f(-0.106, 0.0083);	// Frame
		glVertex2f(-0.106, 0.1416);
		glVertex2f(-0.16, 0.17);
		glVertex2f(-0.365, 0.0083);
		
	glEnd();
	
	glBegin(GL_POLYGON);
	glColor3f(0.706, 0.706, 1.0);
	
		glVertex2f(-0.156, 0.1416);	// Winshield
		glVertex2f(-0.1783, 0.156);
		glVertex2f(-0.335, 0.03);
		glVertex2f(-0.27, 0.03);
	
	glEnd();
	
	glBegin(GL_POLYGON);
	glColor3f(0.706, 0.706, 1.0);
	
		glVertex2f(-0.126, 0.03);	// Samping
		glVertex2f(-0.126, 0.1316);
		glVertex2f(-0.225, 0.03);
	
	glEnd();
	
}

void Atap(void){
	
	glBegin(GL_POLYGON);	// Atap convertible
	glColor3f(0.18, 0.18, 0.18);
	
		glVertex2f(0.595, 0.0083);
		glVertex2f(0.496, 0.046);
		glVertex2f(0.3183, 0.03);
		glVertex2f(0.2783, 0.0083);
		
	glEnd();
		
}

void Bumper(void){	// Bumper mobil
	
	glBegin(GL_POLYGON);
	glColor3f(0.812, 0.812, 0.812);
	
		glVertex2f(0.3883, -0.246);	// Body
		glVertex2f(0.3883, -0.24);
		glVertex2f(-0.435, -0.2516);
		glVertex2f(0.355, -0.28);
		
	glEnd();
	
	glBegin(GL_POLYGON);
	glColor3f(0.812, 0.812, 0.812);
	
		glVertex2f(-0.8283, -0.2316);	// Depan
		glVertex2f(-0.8283, -0.15);
		glVertex2f(-0.893, -0.15);
		glVertex2f(-0.913, -0.1683);
		glVertex2f(-0.9016, -0.21);
		glVertex2f(-0.883, -0.2316);
		
	glEnd();
	
	glBegin(GL_POLYGON);
	glColor3f(0.812, 0.812, 0.812);
	
		glVertex2f(0.965, -0.145);	// Belakang
		glVertex2f(0.9016, -0.145);
		glVertex2f(0.9016, -0.22);
		glVertex2f(0.935, -0.22);
		glVertex2f(0.95, -0.1983);
		glVertex2f(0.95, -0.1783);
		
	glEnd();
		
	glBegin(GL_POLYGON);
	glColor3f(0.812, 0.812, 0.812);
	
		glVertex2f(-0.84, -0.086);	// Lampu
		glVertex2f(-0.8816, -0.086);
		glVertex2f(-0.876, -0.1216);
		glVertex2f(-0.865, -0.1416);
		glVertex2f(-0.84, -0.1416);
		
	glEnd();
	
}


void display(void){	// Konstruksi seluruh bagian mobil
	
	glClear(GL_COLOR_BUFFER_BIT);
	
	Siluet();
	
	glPushMatrix();
	glTranslatef(1.1483, 0.0, 0.0);
	
		Roda(-0.6216, -0.2583, 0.12916, 0.118, 0.118, 0.118);
		Roda(-0.6216, -0.2583, 0.0825, 0.851, 0.851, 0.851);
		Roda(-0.6216, -0.2583, 0.0175, 0.675, 0.675, 0.675);
	
	glPopMatrix();
	
	Body();
	Jendela();
	Atap();
	Bumper();
	Roda(-0.6216, -0.2583, 0.12916, 0.118, 0.118, 0.118);
	Roda(-0.6216, -0.2583, 0.0825, 0.851, 0.851, 0.851);
	Roda(-0.6216, -0.2583, 0.0175, 0.675, 0.675, 0.675);
	
	glFlush();
	
}

int main(int argc, char* argv[]){	// Main program
	
	glutInit(&argc, argv);
	glutInitWindowSize(600, 600);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
	
	glutCreateWindow("Ford Falcon 1964");
	glutDisplayFunc(display);
	glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
	
	glutMainLoop();
	
	return 0;
}
