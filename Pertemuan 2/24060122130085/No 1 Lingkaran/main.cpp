#include <GL/glut.h>
#include <math.h>

int i;
const double PI = 3.141592653589793;

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
	for (i=0;i<=360;i++)
	{
 		float sudut=i*(2*PI/jumlah_titik);
 		float x=x_tengah+radius*cos(sudut);
 		float y=y_tengah+radius*sin(sudut);
 		glVertex2f(x,y);
	}
	glEnd();
}
void display(void) {
    glClear(GL_COLOR_BUFFER_BIT); 
    back();
    glColor3f(0.0f, 0.75f, 0.75f); 

    lingkaran(75,100,0,0); 

    glFlush(); 
}

int main(int argc, char* argv[]) {
    glutInit(&argc, argv);
    glutInitWindowSize(300, 300);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
    glutCreateWindow("Lingkaran"); 
    gluOrtho2D(-150,150,-150,150);
    glutInitWindowPosition(200, 200);
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f); 

    glutDisplayFunc(display); 
    glutMainLoop(); 

    return 0;
}


