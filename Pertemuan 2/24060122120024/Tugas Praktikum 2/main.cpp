//Nama : Elsa Hutagalung
//NIM  : 24060122120024
//Tanggal : 1 Maret 2024
//Tugas Praktikum 2 GKV translasi, rotasi dan stack pada objek

#include <stdio.h>
#include <stdlib.h>
#include<gl/gl.h>
#include <GL/glut.h>
#include <math.h>

void segiEmpat(void) {
	glClear(GL_COLOR_BUFFER_BIT);
	glTranslatef(0.50, -0.10, 0);
	glColor3f(1.0f, 0.0f, 0.0f);
	glRectf(-0.18, 0.18, 0.18, -0.18);
	glFlush();
}

void segiTiga(void) {
	glTranslatef(0.25, -0.25, 0);
	glRotated(60.0, 0.0, 0.0, 1.0);
	glBegin(GL_TRIANGLES);
		glColor3f(1.0f, 0.0f, 0.0f); glVertex3f(-0.05, -0.05, 0.00);
		glColor3f(0.0f, 1.0f, 0.0f); glVertex3f(0.15, -0.05, 0.00);
		glColor3f(0.0f, 0.0f, 1.0f); glVertex3f(-0.05, 0.05, 0.00);	
	glEnd();
}

void stackObject(void) {
	glClear(GL_COLOR_BUFFER_BIT);
	glPushMatrix();
		glLineWidth(2.0f);
		glBegin(GL_LINES);
			glColor3f(1.0f, 1.0f, 1.0f);
			glVertex3f(0.00, 0.20, 0.00);
			glVertex3f(0.00, -0.20, 0.00);
		glEnd();
	glPopMatrix();
	
	glPushMatrix();
		glPointSize(5.0f);
		glTranslatef(0.35, 0.35, 0.0);
		glBegin(GL_POINTS);
			glColor3f(1.0f, 1.0f, 1.0f);
			glVertex3f(0.25, 0.25, 0.00);
		glEnd();
	glPopMatrix();
	
	glPushMatrix();
		glTranslatef(0.50, 0.50, 0.0);
		glBegin(GL_TRIANGLE_STRIP);
			glColor3f(1.0f, 0.0f, 0.0f); glVertex3f(-0.05, -0.05, 0.00);
			glColor3f(0.0f, 1.0f, 0.0f); glVertex3f(0.15, -0.05, 0.00);
			glColor3f(0.0f, 0.0f, 1.0f); glVertex3f(-0.05, 0.05, 0.00);	
			glColor3f(1.0f, 1.0f, 0.0f); glVertex3f(0.15, 0.05, 0.00);	
		glEnd();
	glPopMatrix();
	
	glPushMatrix();
		#define PI 3.1415926535898
		glBegin(GL_LINE_LOOP);
			GLint circle_points = 100;
			int i;
			float angle;
			for (i = 0; i < circle_points; i++) {
				angle = 2 * PI * i / circle_points;
				glVertex2f(cos(angle), sin(angle));
			}
		glEnd();
	glPopMatrix();
	
	glFlush();
}

void carDesign(void) {
	glClear(GL_COLOR_BUFFER_BIT);
    // Set the color to draw the first rectangle (in this case, white)
    glColor3f(1.0f, 1.0f, 1.0f); 

    // Draw the first rectangle
    glPushMatrix(); // Save the current matrix
    glTranslatef(-0.4f, 0.0f, 0.0f); // Translate to the left
    glBegin(GL_QUADS);
        glVertex2f(-0.4f, -0.4f); // Bottom-left corner
        glVertex2f(0.4f, -0.4f);  // Bottom-right corner
        glVertex2f(0.4f, 0.4f);   // Top-right corner
        glVertex2f(-0.4f, 0.10f);  // Top-left corner
    glEnd();
    glPopMatrix(); // Restore the original matrix

    // Set the color to draw the second rectangle (in this case, red)
    glColor3f(1.0f, 0.0f, 0.0f); // R, G, B values

    // Draw the second rectangle
    glPushMatrix(); // Save the current matrix
    glTranslatef(0.2f, 0.0f, 0.0f); // Translate to the right
    glBegin(GL_QUADS);
        glVertex2f(-0.4f, -0.4f); // Bottom-left corner
        glVertex2f(0.4f, -0.4f);  // Bottom-right corner
        glVertex2f(0.4f, 0.4f);   // Top-right corner
        glVertex2f(-0.4f, 0.4f);  // Top-left corner
    glEnd();
    glPopMatrix(); // Restore the original matrix
    
        // Set the color to draw the circles (in this case, blue)
    glColor3f(0.0f, 0.0f, 1.0f); // R, G, B values

    // Draw the first circle below the first rectangle
    glPushMatrix(); // Save the current matrix
    glTranslatef(-0.5f, -0.7f, 0.0f); // Translate below the first rectangle
    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(0.0f, 0.0f); // Center of the circle
        int i;
        for (i = 0; i <= 360; i++) {
            glVertex2f(0.1f * cos(i * 3.14159 / 180.0), 0.1f * sin(i * 3.14159 / 180.0));
        }
    glEnd();
    glPopMatrix(); // Restore the original matrix

    // Draw the second circle below the second rectangle
    glPushMatrix(); // Save the current matrix
    glTranslatef(0.5f, -0.7f, 0.0f); // Translate below the second rectangle
    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(0.0f, 0.0f); // Center of the circle
        for (i = 0; i <= 360; i++) {
            glVertex2f(0.1f * cos(i * 3.14159 / 180.0), 0.1f * sin(i * 3.14159 / 180.0));
        }
    glEnd();
    glPopMatrix(); // Restore the original matrix
    
    // Set the color to draw the circles (in this case, blue)
    glColor3f(1.0f, 0.0f, 0.0f); // R, G, B values

    // Draw the first circle below the first rectangle
    glPushMatrix(); // Save the current matrix
    glTranslatef(-0.5f, -0.7f, 0.0f); // Translate below the first rectangle
    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(0.0f, 0.0f); // Center of the circle
        for (i = 0; i <= 360; i++) {
            glVertex2f(0.1f * cos(i * 3.14159 / 180.0), 0.1f * sin(i * 3.14159 / 180.0));
        }
    glEnd();
    glPopMatrix(); // Restore the original matrix
    
    // Draw the second circle below the second rectangle
    glPushMatrix(); // Save the current matrix
    glTranslatef(0.5f, -0.7f, 0.0f); // Translate below the second rectangle
    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(0.0f, 0.0f); // Center of the circle
        for (i = 0; i <= 360; i++) {
            glVertex2f(0.1f * cos(i * 3.14159 / 180.0), 0.1f * sin(i * 3.14159 / 180.0));
        }
    glEnd();
    glPopMatrix(); // Restore the original matrix
	
	glFlush();
}

void renderScene() {
    glClear(GL_COLOR_BUFFER_BIT); // Clear the color buffer

    // Set the color to draw the first rectangle (in this case, white)
//    glColor3f(1.0f, 1.0f, 1.0f); // R, G, B values
    glColor3f(0.5f, 1.0f, 1.0f);//cyan

    // Draw the first rectangle
    glPushMatrix(); // Save the current matrix
    glTranslatef(-0.6f, 0.0f, 0.0f); // Translate to the left
    glBegin(GL_QUADS);
        glVertex2f(-0.3f, -0.4f); // Bottom-left corner
        glVertex2f(0.25f, -0.4f);  // Bottom-right corner
        glVertex2f(0.25f, 0.3f);   // Top-right corner
        glVertex2f(-0.3f, -0.05f);  // Top-left corner
    glEnd();
    glPopMatrix(); // Restore the original matrix
    
    // Set the color to draw the second rectangle (in this case, red)
    glColor3f(1.0f, 0.5f, 0.0f);//Orange
     // Draw the second rectangle
    glPushMatrix(); // Save the current matrix
    glTranslatef(-0.1f, 0.0f, 0.0f); // Translate to the right
    glBegin(GL_QUADS);
        glVertex2f(-0.25f, -0.4f); // Bottom-left corner
        glVertex2f(-0.23f, -0.4f);  // Bottom-right corner
        glVertex2f(-0.23f, -0.20f);   // Top-right corner
        glVertex2f(-0.25f, -0.20f);  // Top-left corner
    glEnd();
    glPopMatrix(); // Restore the original matrix
    

    // Set the color to draw the second rectangle (in this case, red)
    glColor3f(0.3f, 0.3f, 0.3f); // R, G, B values

    // Draw the third rectangle
    glPushMatrix(); // Save the current matrix
    glTranslatef(0.17f, 0.0f, 0.0f); // Translate to the right
    glBegin(GL_QUADS);
        glVertex2f(-0.5f, -0.4f); // Bottom-left corner
        glVertex2f(0.5f, -0.4f);  // Bottom-right corner
        glVertex2f(0.5f, 0.4f);   // Top-right corner
        glVertex2f(-0.5f, 0.4f);  // Top-left corner
    glEnd();
    glPopMatrix(); // Restore the original matrix


	// BAN 1
    // Set the color to draw the circles (in this case, blue)
    glColor3f(0.0f, 0.0f, 0.0f); // R, G, B values

    // Draw the first circle below the first rectangle
    glPushMatrix(); // Save the current matrix
    glTranslatef(-0.5f, -0.5f, 0.0f); // Translate below the first rectangle
    int i;
    float circleRadius = 0.1f; // Original radius
    float scaleFactor = 2.0f; // Scaling factor
    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(0.0f, 0.0f); // Center of the circle
        for (i = 0; i <= 360; i++) {
            float angle = i * 3.14159 / 180.0;
            glVertex2f(circleRadius * cos(angle) * scaleFactor, circleRadius * sin(angle) * scaleFactor);
        }
    glEnd();
    glPopMatrix(); // Restore the original matrix

	// LINGKARAN BAN DALAM 1
	glColor4f(1.0f, 1.0f, 1.0f, 0.0f);//white
    // Draw the smaller circle on top of the first circle
    glPushMatrix(); // Save the current matrix
    glTranslatef(-0.5f, -0.5f, 0.0f); // Translate below the first rectangle
    circleRadius = 0.09f; // Original radius
    scaleFactor = 1.0f; // Scaling factor
    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(0.0f, 0.0f); // Center of the circle
        for (i = 0; i <= 360; i++) {
            float angle = i * 3.14159 / 180.0;
            glVertex2f(circleRadius * cos(angle) * scaleFactor, circleRadius * sin(angle) * scaleFactor);
        }
    glEnd();
    glPopMatrix(); // Restore the original matrix

	// BAN 2
	glColor3f(0.0f, 0.0f, 0.0f); // R, G, B values
    // Draw the second circle below the second rectangle
    glPushMatrix(); // Save the current matrix
    glTranslatef(0.3f, -0.5f, 0.0f); // Translate below the second rectangle
    circleRadius = 0.1f; // Original radius
    scaleFactor = 2.0f; // Scaling factor
    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(0.0f, 0.0f); // Center of the circle
        for (i = 0; i <= 360; i++) {
            float angle = i * 3.14159 / 180.0;
            glVertex2f(circleRadius * cos(angle) * scaleFactor, circleRadius * sin(angle) * scaleFactor);
        }
    glEnd();
    glPopMatrix(); // Restore the original matrix

	// LINGKARAN DALAM BAN 2
	glColor4f(1.0f, 1.0f, 1.0f, 0.0f);//white
    // Draw the smaller circle on top of the second circle
    glPushMatrix(); // Save the current matrix
    glTranslatef(0.3f, -0.5f, 0.0f); // Translate below the second rectangle
    circleRadius = 0.09f; // Original radius
    scaleFactor = 1.0f; // Scaling factor
    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(0.0f, 0.0f); // Center of the circle
        for (i = 0; i <= 360; i++) {
            float angle = i * 3.14159 / 180.0;
            glVertex2f(circleRadius * cos(angle) * scaleFactor, circleRadius * sin(angle) * scaleFactor);
        }
    glEnd();
    glPopMatrix(); // Restore the original matrix

    glFlush(); // Flush the OpenGL pipeline
}


int main(int argc, char *argv[]) {
	glutInit(&argc, argv);
	glutInitWindowSize(920, 640);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutCreateWindow("Segi Tiga");
	glutDisplayFunc(renderScene);
//	glutDisplayFunc(segiTiga);
	glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
	glutMainLoop();
	
	return 0;
}

