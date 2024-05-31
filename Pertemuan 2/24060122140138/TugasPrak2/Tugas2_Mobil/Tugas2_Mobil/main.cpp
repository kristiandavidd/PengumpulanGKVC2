//Nama : Adzkiya Qarina Salsabila
//NIM  : 24060122140138
//Deskripsi : Membuat sebuah lingkaran

#include <GLUT/glut.h>
#include <stdlib.h>
#include <math.h>


GLint b = 300;
float counter = 600.0;

void init() {
    glClearColor(0.5, 0.5, 0.5, 1);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, 700, 0, 500);
    glMatrixMode(GL_MODELVIEW);
}

void wheel(int x, int y) {
    float th;
    glBegin(GL_POLYGON);
    glColor3f(0, 0, 0);
    for(int i = 0; i < 360; i++) {
        th = i * (3.1416/180);
        glVertex2f(x + 20 * cos(th), y + 20 * sin(th));
    }
    glEnd();
}

void car() {
    //bagian bawah
    glLoadIdentity();
    counter = counter - 0.9;
    glTranslated(counter, 100, 0.0);
    
    glBegin(GL_POLYGON);
    glVertex2f(100, 100);
    glVertex2f(100, 160);
    glVertex2f(450, 160);
    glVertex2f(450, 100);
    
    //bagian atas
    glBegin(GL_POLYGON);
    glVertex2f(150, 160);
    glVertex2f(200, 200);
    glVertex2f(400, 200);
    glVertex2f(450, 160);
    
    glEnd();
    
    wheel(200, 100);
    wheel(380, 100);
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    //push dan pop matrix untuk memisahkan objek lingkaran dari background
    glColor3f(0.0, 1.0, 0.0);
    car();
    glutSwapBuffers();
    glFlush();
}

int main(int argc, char **argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
    glutInitWindowSize(700, 500);
    glutInitWindowPosition(0 , 0);
    glutCreateWindow("CAR");
    init();
    glutDisplayFunc(display);
    glutIdleFunc(display);
    glutMainLoop();
    
    return 0;
}
