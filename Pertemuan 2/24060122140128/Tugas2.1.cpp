#include <GL/glut.h>
#include <GL/gl.h>
#include <math.h>
//Rahman Hanif Aji Saputra
//24060122140128
void RenderScene(void) {
    glClear(GL_COLOR_BUFFER_BIT);

    glPushMatrix();
        #define PI 3.1415926535898

        // Lingkaran pertama 
        glBegin(GL_LINE_LOOP);
            glColor3f(0.5f, 0.0f, 0.5f);
            GLint circle_points = 100;
            int i;
            float angle;
            for (i = 0; i < circle_points; i++) {
                angle = 2 * PI * i / circle_points;
                glVertex2f(cos(angle)/1.4, sin(angle)/1.4);
            }
        glEnd();

        // Lingkaran kedua 
        glBegin(GL_LINE_LOOP);
            glColor3f(1.0f, 0.0f, 0.0f);
            for (i = 0; i < circle_points; i++) {
                angle = 2 * PI * i / circle_points;
                glVertex2f( cos(angle)/2,sin(angle)/2);
            }
        glEnd();

        // Lingkaran ketiga 
        glBegin(GL_LINE_LOOP);
            glColor3f(0.0f, 0.0f, 1.0f);
            for (i = 0; i < circle_points; i++) {
                angle = 2 * PI * i / circle_points;
                glVertex2f(cos(angle)/3,sin(angle)/3);
            }
        glEnd();

    glPopMatrix();

    glFlush();
}

int main(int argc, char* argv[]) {
    glutInit(&argc, argv);
    glutInitWindowSize(640, 480);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
    glutCreateWindow("Nested Circles");
    glutDisplayFunc(RenderScene);
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    glutMainLoop();
    return 0;
}

