#include <GL/glut.h>
#include <stdlib.h>

static int slices = 16;
static int stacks = 16;

static void resize(int width, int height){
    const float ar = (float) width / (float) height;
    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-2.0 * ar, 2.0 * ar, -2.0, 2.0, -2.0, 2.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity() ;
}

static void mobil(void){
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glColor3d(0,0.5,0);

    // Body Mid
    glBegin(GL_POLYGON);
        glColor3d(0, 0.2, 0);
        glVertex2f(0.9f, 0.3f);
        glVertex2f(0.8f, 0.4f);
        glVertex2f(-0.5f, 0.4f); 
        glVertex2f(-0.6f, 0.5f);
        glVertex2f(-1.2f, 0.5f); 
        glVertex2f(-1.2f, 0.3f);
    glEnd();

    // Body
    glBegin(GL_POLYGON);
        glColor3d(0, 0.5, 0);
        glVertex2f(-1.3f, -0.1f);
        glVertex2f(1.3f, -0.1f);
        glVertex2f(0.9f, 0.3f); 
        glVertex2f(-1.2f, 0.3f); 
    glEnd();
    
    // Body Top
    glBegin(GL_POLYGON);
    	glColor3d(0, 0.5, 0);
    	glVertex2f(0.6f, 0.4f);
    	glVertex2f(0.7f, 0.6f);
    	glVertex2f(0.6f, 0.8f);
    	glVertex2f(-0.7f, 0.9f);
    	glVertex2f(-0.8f, 0.6f);
    	glVertex2f(-0.7f, 0.4f);
    glEnd();
    
    glBegin(GL_POLYGON);
    	glColor3d(0, 0.4, 0);
    	glVertex2f(-0.6f, 0.8f);
    	glVertex2f(-0.5f, 1.0f);
    	glVertex2f(-0.1f, 1.0f);
    	glVertex2f(0.0f, 0.8f);
    glEnd();
    
    glBegin(GL_QUADS);
    	glColor3f(0, 0.4, 0);
    	glVertex2f(2.3f, 0.9f);
    	glVertex2f(0.6f, 0.7f);
    	glVertex2f(0.6f, 0.5f);
    	glVertex2f(2.3f, 0.7f);
    glEnd();

    // Left Wheel
    glPushMatrix();
        glColor3d(0,0,0);
        glTranslated(-0.8,-0.2,-0.6);
        glutSolidTorus(0.1, 0.2, slices, stacks);
    glPopMatrix();
    

    // Right Wheel
    glPushMatrix();
        glColor3d(0,0,0);
        glTranslated(0.8,-0.2,-0.6);
        glutSolidTorus(0.1, 0.2, slices, stacks);
    glPopMatrix();
    
    // Mid Wheel
    glPushMatrix();
        glColor3d(0,0,0);
        glTranslated(0.0,-0.2,-0.6);
        glutSolidTorus(0.1, 0.2, slices, stacks);
    glPopMatrix();
    
    glLineWidth(8.0f);
    glBegin(GL_LINE_STRIP);
    	glColor3f(0, 0, 0);
    	glVertex2f(-1.2f, 0.0f);
    	glVertex2f(-1.3f, -0.3f);
    	glVertex2f(-1.2f, -0.4f);
    	glVertex2f(-1.1f, -0.5f);
    	glVertex2f(1.1f, -0.5f);
    	glVertex2f(1.2f, -0.4f);
    	glVertex2f(1.3f, -0.3f);
    	glVertex2f(1.1f, 0.0f);
    glEnd();
    
    glPushMatrix();
    glTranslatef(0.0, 0.0, -1.0);
    glBegin(GL_TRIANGLE_FAN);
    	glColor3d(0, 0.2, 0);
    	glVertex2f(-1.2f, 0.0f);
		glVertex2f(-1.3f, -0.3f);
		glVertex2f(-1.2f, -0.4f);
    	glVertex2f(-1.1f, -0.5f);
    	glVertex2f(1.1f, -0.5f);
		glVertex2f(1.2f, -0.4f);
    	glVertex2f(1.3f, -0.3f);
    	glVertex2f(1.1f, 0.0f);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.0, 0.0, -1.0);
    glBegin(GL_QUADS);
        glColor3f(0, 0.9, 0.1);
        glVertex2f(10.0f, -0.4f);
        glVertex2f(-10.0f, -0.4f);
        glVertex2f(0.6f, 0.5f);
        glVertex2f(2.3f, 0.7f);
    glEnd();
    glPopMatrix();
    
    glPushMatrix();
    glTranslatef(0.0, 0.0, -1.0);
    glBegin(GL_QUADS);
        glColor3f(1.0, 0.95, 0.65);
        glVertex2f(10.0f, -0.4f);
        glVertex2f(-10.0f, -0.4f);
        glVertex2f(-10.0f, -10.0f);
        glVertex2f(10.0f, -10.0f);
    glEnd();
    glPopMatrix();

    glutSwapBuffers();
}

static void key(unsigned char key, int x, int y){
    switch (key) 
    {
        case 27 : 
        case 'q':
            exit(0);
            break;
    }

    glutPostRedisplay();
}

static void idle(void){
    glutPostRedisplay();
}

/* Program entry point */

int 
main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitWindowSize(640,480);
    glutInitWindowPosition(10,10);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
    glutCreateWindow("Sajid- Tank");
    glutReshapeFunc(resize);
    glutDisplayFunc(mobil);
    glutKeyboardFunc(key);
    glutIdleFunc(idle);
    glClearColor(0,0.7,1,0);
    glEnable(GL_DEPTH_TEST);
    glutMainLoop();
    return EXIT_SUCCESS;
}
