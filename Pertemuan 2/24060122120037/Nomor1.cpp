// Nama : Widiawati Sihaloho 
// NIM : 24060122120037
// Deskripsi : Membuat Lingkaran 

#include <GL/glut.h>
#include<math.h>//agar terpasang rumus matematika


const double PI = 3.142857143;
int i,radius,jumlah_titik,x_tengah,y_tengah;

void display (void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0.4, 0.7, 1.0);
	glBegin(GL_POLYGON);
	       radius = 50;
	       jumlah_titik = 60;
	       x_tengah = 0;
	       y_tengah = 0;
	
	       for (i=0;i<=360;i++)
	       {
	              float sudut=i*(2*PI/jumlah_titik);
	              float x=x_tengah+radius*cos (sudut);
	              float y=y_tengah+radius*sin (sudut);
	              glVertex2f(x/100,y/100);
	       }
	glEnd();
	glFlush();

}

int main(int argc, char** argv)
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutInitWindowSize(600,600);
	glutCreateWindow("Lingkaran");
	glutDisplayFunc(display);
	glutMainLoop();
	return 0;
}
