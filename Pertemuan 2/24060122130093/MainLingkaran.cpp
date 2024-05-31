#include "stdlib.h"
#include "gl/glut.h"
#include "math.h"
const double PI = 3.141592653589793;
int i;
void back(){
glBegin(GL_QUADS);
glColor3f(0,0,0);
 glVertex2d (-150,150);
 glVertex2d(150,150);
 glVertex2d(150,-150);
 glVertex2d (-150,-150);
glEnd();
}
void lingkaran(int radius, int jumlah_titik, int x_tengah, int y_tengah) {
glBegin(GL_POLYGON);
{for (i=0;i<=360;i++){
 float sudut=i*(2*PI/jumlah_titik);
 float x=x_tengah+radius*cos(sudut);
 float y=y_tengah+radius*sin(sudut);
 glVertex2f(x,y);
}
}
glEnd();
}
void Draw() {
 glClear(GL_COLOR_BUFFER_BIT);
 back();
 glColor4f(1.0, 0.0, 0.0, 0.0);
 lingkaran(100,100,0,0);
 glColor4f(0.0, 1.0, 0.1, 0.0);
 lingkaran(90,100,0,0);
 glFlush();
}
int main(int argc, char **argv) {
 glutInit(&argc, argv);
 glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
 glutInitWindowSize(500, 500);
 glutInitWindowPosition(200, 200);
 glutCreateWindow("Lingkaran");
 gluOrtho2D(-150,150,-150,150);
 glutDisplayFunc(Draw);
 glutMainLoop();
 return 0;
}
