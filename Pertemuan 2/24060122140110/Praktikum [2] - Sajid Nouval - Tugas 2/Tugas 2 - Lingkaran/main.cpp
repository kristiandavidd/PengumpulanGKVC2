#include <GL/glut.h>
#include <GL/gl.h>
#include <math.h>

void RenderScene(void) {
    glClear(GL_COLOR_BUFFER_BIT);
    glLineWidth(2.0f);
    glPushMatrix();
    float aspect_ratio = 640.0 / 480.0;
    glScalef(0.2 * aspect_ratio, 0.5, 1.0);

    #define PI 3.1415926535898
    glBegin(GL_LINE_LOOP);
        GLint circle_points = 100;
        int i;
        float angle;
        for(i=0;i<circle_points; i++) {
            angle = 2*PI*i/circle_points;
            glVertex2f(cos(angle), sin(angle));
        }
    glEnd();
    glPopMatrix();
    glFlush();
}

int main(int argc, char* argv[]) {
    glutInit(&argc,argv);
    glutInitWindowSize(640,480);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
    glutCreateWindow("Sajid - Lingkaran");
    glutDisplayFunc(RenderScene);
    glClearColor(0.0f,0.0f,1.0f,1.0f);
    glutMainLoop();
    return 0;
}

