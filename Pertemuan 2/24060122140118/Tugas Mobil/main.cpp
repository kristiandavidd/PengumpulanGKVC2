// Nama	: Arya Ajisadda Haryanto
// NIM	: 24060122140118

#include <GL/glut.h>
#include <math.h>
#define DEG2RAD 3.14159/180.0

void initOpenGL() {
    glClearColor(1.0, 1.0, 1.0, 0.0);
	}

void drawText(const char *text, float x, float y) {
    glRasterPos2f(x, y); 
    for (const char* c = text; *c != '\0'; c++) {
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_10, *c); 
	}
}
void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    // Car Body
    glColor3f(0.0, 0.0, 1.0); 
    glBegin(GL_POLYGON);
        glVertex2f(0.1, 0.2);
        glVertex2f(0.8, 0.2);
        glVertex2f(0.8, 0.4);
        glVertex2f(0.2, 0.4);
    glEnd();

    // Car Roof
    glBegin(GL_POLYGON);
        glVertex2f(0.3, 0.4);
        glVertex2f(0.7, 0.3);
        glVertex2f(0.63, 0.6);
        glVertex2f(0.44, 0.6);
    glEnd();

    // Roda
    glColor3f(0.0, 0.0, 0.0); 
    float radius = 0.1;
    int i;
	
    // Roda Depan
    glBegin(GL_POLYGON);
    for (i = 0; i < 360; i++) {
        float degInRad = i * DEG2RAD;
        glVertex2f(cos(degInRad) * radius + 0.3, sin(degInRad) * radius + 0.2);
    }
    glEnd();
    
    // Roda Belakang
    glBegin(GL_POLYGON);
    for (i = 0; i < 360; i++) {
        float degInRad = i * DEG2RAD;
        glVertex2f(cos(degInRad) * radius + 0.7, sin(degInRad) * radius + 0.2);
    }
    glEnd();
    
    // Jalan
    glBegin(GL_POLYGON);
    	glVertex2f(20, -0.05);
        glVertex2f(-20, -0.05);
        glVertex2f(-20, 0.1);
        glVertex2f(20, 0.1);
    glEnd();
    
    // Tiang Listrik
	glColor3f(0.5, 0.5, 0.5); // Warna abu-abu
	glBegin(GL_POLYGON);
		glVertex2f(-0.1, 20);  
    	glVertex2f(-0.15, 20);  
    	glVertex2f(-0.15, 0.1);  
    	glVertex2f(-0.1, 0.1);  
	glEnd();
	
	// Tiang Listrik
	glColor3f(0.5, 0.5, 0.5); 
	glBegin(GL_POLYGON);
		glVertex2f(-0.9, 20);  
    	glVertex2f(-0.95, 20);  
    	glVertex2f(-0.95, 0.1);  
    	glVertex2f(-0.9, 0.1);  
	glEnd();
	
	// Tiang Listrik
	glColor3f(0.5, 0.5, 0.5); 
	glBegin(GL_POLYGON);
		glVertex2f(0.9, 20);  
    	glVertex2f(0.95, 20);  
    	glVertex2f(0.95, 0.1);  
    	glVertex2f(0.9, 0.1);  
	glEnd();
	
	// Matahari
	glColor3f(1.0, 1.0, 0.0); 
    glBegin(GL_POLYGON);
    for (i = 0; i < 360; i++) {
        float degInRad = i * DEG2RAD;
        glVertex2f(cos(degInRad) * 0.2 + -0.65, sin(degInRad) * 0.2 + 0.9);
    }
    glEnd();
    
    
    // Stoplamp
    glColor3f(1.0, 0.0, 0.0); 
    glBegin(GL_POLYGON);
    for (i = 0; i < 360; i++) {
        float degInRad = i * DEG2RAD;
        glVertex2f(cos(degInRad) * 0.05 + 0.8, sin(degInRad) * 0.05 + 0.35);
    }
    glEnd();

    // Window
    glColor3f(0.5, 0.8, 0.9); 
    glBegin(GL_POLYGON);
        glVertex2f(0.37, 0.45);
        glVertex2f(0.62, 0.45);
        glVertex2f(0.60, 0.55);
        glVertex2f(0.44, 0.55);
    glEnd();
	// Spoiler 
	glColor3f(0.0, 0.0, 1.0);
	glBegin(GL_POLYGON);
        glVertex2f(0.75, 0.4);
        glVertex2f(0.8, 0.4);
        glVertex2f(0.85, 0.5);
        glVertex2f(0.85, 0.5);
    glEnd();
    // Headlight
    glColor3f(1.0, 1.0, 0.0); 
    glBegin(GL_POLYGON);
    for (i = 0; i < 360; i++) {
        float degInRad = i * DEG2RAD;
        glVertex2f(cos(degInRad) * 0.05 + 0.2, sin(degInRad) * 0.05 + 0.35);
    }
    glEnd();
    
    // Velg Belakang
	glColor3f(0.5, 0.8, 0.9); 
	glBegin(GL_POLYGON);
    for (i = 0; i < 360; i++) {
        float degInRad = i * DEG2RAD;
        glVertex2f(cos(degInRad) * 0.06 + 0.7, sin(degInRad) * 0.06 + 0.2);
    }
    glEnd();
    
    // Velg Depan
	glColor3f(0.5, 0.8, 0.9);
	glBegin(GL_POLYGON);
    for (i = 0; i < 360; i++) {
        float degInRad = i * DEG2RAD;
        glVertex2f(cos(degInRad) * 0.06 + 0.3, sin(degInRad) * 0.06 + 0.2);
    }
    glEnd();
    
    // Baut Depan
	glColor3f(0.5, 0.5, 0.5); 
	glBegin(GL_POLYGON);
    for (i = 0; i < 360; i++) {
        float degInRad = i * DEG2RAD;
        glVertex2f(cos(degInRad) * 0.01 + 0.3, sin(degInRad) * 0.01 + 0.2);
    }
    glEnd();
    // Baut Belakang
	glColor3f(0.5, 0.5, 0.5); 
	glBegin(GL_POLYGON);
    for (i = 0; i < 360; i++) {
        float degInRad = i * DEG2RAD;
        glVertex2f(cos(degInRad) * 0.01 + 0.7, sin(degInRad) * 0.01 + 0.2);
    }
    glEnd();
    
    // Knalpot
    glColor3f(0.5,0.5,0.5);
    glBegin(GL_POLYGON);
        glVertex2f(0.54, 0.17);
        glVertex2f(0.59, 0.17);
        glVertex2f(0.59, 0.2);
        glVertex2f(0.54, 0.2);
    glEnd();
    

    glColor3f(1.0, 1.0, 1.0);
    drawText("DINOCO", 0.58, 0.35);
    
    
    glFlush();
}


int main(int argc, char** argv) {
    glutInit(&argc, argv); 
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); 
    glutInitWindowSize(500, 500); 
    glutInitWindowPosition(100, 100); 
    glutCreateWindow("Chick Dinoco Car"); 
    initOpenGL(); 
    glutDisplayFunc(display); 
    glutMainLoop(); 
    return 0;
}

