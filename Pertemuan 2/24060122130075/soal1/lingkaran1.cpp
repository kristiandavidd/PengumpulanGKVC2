//NAMA: REVA YASMIN NAUFALIA
//NIM: 24060122130075
//TANGGAL: 4 MARET 20024
//TUGAS PRAKTIKUM 2 SOAL 1
#include <GL/glut.h>
#include<math.h>
int i=0; int j=0;
void Lingkaran(int xp, int yp, int r, int n){
	glClear(GL_COLOR_BUFFER_BIT);
	
	glPushMatrix();
    	float a,x,y;
    	glColor3f(0.0f,0.2f,1.0f);
    	glBegin(GL_POLYGON);
        	a=6.7/n;
        	for (int i=0; i<n; i++){
            	x = xp+r * cos(i*a);
            	y = yp+r * sin(i*a);
            	glVertex2d(x,y);
        	}
    	glEnd();
    glPopMatrix();
    
    glFlush();
}
 
static void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA); //untuk membuat opacity
    glColor3ub(255,0,0);
 
    Lingkaran(100,-100,100,50);
    i+=20;
    j+=1;
    glutSwapBuffers();
}
 
int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitWindowSize(1000,800);
    glutInitWindowPosition(10,10);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
 
    glutCreateWindow("Lingkaran");
 
    gluOrtho2D(-500,500,-400,400);
 
 
    glutDisplayFunc(display);
    glutIdleFunc(display);
 
    glClearColor(1,1,0,1);
    glutMainLoop();
}
