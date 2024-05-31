#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <GL/glut.h>

double rotAngleX = 10;
double rotAngleY = 10; 
double rotAngleZ = 0; 

void init()  
{  
    glClearColor(0, 0, 1, 0.5);
    glClearDepth(1.0);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(60, 1, 1, 1000);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(
        0.0, 0.0, 5.0,
        0.0, 0.0, 0.0,
        0.0, 1.0, 0.0);
}

void display()  
{  
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glPushMatrix();
    glRotated(rotAngleX, 1, 0, 0);
    glRotated(rotAngleY, 0, 1, 0);
    glRotated(rotAngleZ, 0, 0, 1);

    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);

    GLfloat light_position[] = { 10.0, 10.0, 10.0, 1.0 };
    GLfloat light_intensity[] = { 1.0, 1.0, 1.0, 1.0 };
    glLightfv(GL_LIGHT0, GL_POSITION, light_position);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, light_intensity);

    GLfloat mat_ambient_front[] = { 0.7, 0.7, 0.7, 1.0 };
    GLfloat mat_diffuse_front[] = { 0.8, 0.8, 0.8, 1.0 };
    GLfloat mat_specular_front[] = { 1.0, 1.0, 1.0, 1.0 };
    GLfloat mat_shininess_front[] = { 100.0 };
    glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient_front);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse_front);
    glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular_front);
    glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess_front);

    GLfloat mat_ambient_back[] = { 0.0, 0.0, 0.0, 1.0 };
    GLfloat mat_diffuse_back[] = { 0.0, 0.0, 0.0, 1.0 };
    GLfloat mat_specular_back[] = { 0.0, 0.0, 0.0, 1.0 };
    GLfloat mat_shininess_back[] = { 0.0 };
    glMaterialfv(GL_BACK, GL_AMBIENT, mat_ambient_back);
    glMaterialfv(GL_BACK, GL_DIFFUSE, mat_diffuse_back);
    glMaterialfv(GL_BACK, GL_SPECULAR, mat_specular_back);
    glMaterialfv(GL_BACK, GL_SHININESS, mat_shininess_back);
    
    glDisable(GL_BLEND);
    glEnable(GL_COLOR_MATERIAL);
    
    glPushMatrix();
    	glPushMatrix();
	    glColor4f(0.8, 0.1, 0.3, 0.9);
	    glScalef(1.0, 0.8, 1.0);
	    glTranslatef(0.0, -0.35, 0.0);
	    glutSolidCube(2.0);
	    glPopMatrix();
	    
	    glPushMatrix();
	    glTranslatef(0.1, 1.0, 0.0);
	    glScalef(1.8, 1.0, 1.0);
	    glutSolidCube(1.0);
	    glPopMatrix();
    glPopMatrix();

    glPushMatrix();
	    glColor4f(0.0, 0.0, 0.0, 0.8);
	    glTranslatef(-1.0, -1.0, -1.0);
	    glutSolidTorus(0.2, 0.5, 100, 100);
	    glTranslatef(2.0, 0.0, 0.0);
	    glutSolidTorus(0.2, 0.5, 100, 100);
	    glTranslatef(0.0, 0.0, 2.0);
	    glutSolidTorus(0.2, 0.5, 100, 100);
	    glTranslatef(-2.0, 0.0, 0.0);
	    glutSolidTorus(0.2, 0.5, 100, 100);
    glPopMatrix();

    glPopMatrix();
    glFlush();
    glutSwapBuffers();
}  

 
void keyboard(unsigned char k, int x, int y)  
{  
    switch (k)  
    {  
        case '8':  
            rotAngleX += 5;
            break;
        case '2':  
            rotAngleX -= 5; 
            break;
        case '6':  
            rotAngleY += 5; 
            break;  
        case '4':  
            rotAngleY -= 5; 
            break;
        case '5':  
            rotAngleZ -= 5; 
            break;
        case '.':  
            rotAngleZ -= 5; 
            break;
    }  
    glutPostRedisplay();
}  

int main()  
{  
    glutInitDisplayMode( GLUT_DOUBLE | GLUT_DEPTH | GLUT_RGBA );
    glutCreateWindow("Mobil 3D");  
    glutDisplayFunc(display); 
    glutKeyboardFunc(keyboard); 
    init();
    glutMainLoop();
    
    return 0;  
}

