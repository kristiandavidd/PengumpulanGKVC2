// Nama File : Tugas_2
// Nama : Ayyub Al Anshor
// Tanggal : Rabu, 26 Februari 2024
// Lab : C2 / GKV

#include <GL/glut.h>
#include <gl/gl.h>
#include <cmath>
#include <math.h>

void drawCircle(float cx, float cy, float r, int num_segments)
{
	glPushMatrix();
	    glBegin(GL_TRIANGLE_FAN);
	    for (int i = 0; i < num_segments; i++)
	    {
	        float theta = 2.0f * 3.1415926f * float(i) / float(num_segments);
	        float x = r * cosf(theta);
	        float y = r * sinf(theta);
	        glVertex2f(x + cx, y + cy);
	    }
	    glEnd();
	glPopMatrix();
}

void drawCar(float x, float y, float angle)
{
    glPushMatrix();
	    glTranslatef(x, y, 0.0);
	    glRotatef(angle, 0.0, 0.0, 0.0);
	
	    // Bodi mobil
	    glColor3f(0.8, 0.2, 0.2);
	    glBegin(GL_POLYGON);
	    glVertex2f(-199.0, -20.0); //titik pojok kiri bawah
	    glVertex2f(-90.0, 380.0); //titik pojok kiri atas
	    glVertex2f(350.0, 380.0); //titik pojok kanan atas
	    glVertex2f(550.0, -20.0); //titik pojok kanan bawah
	    glEnd();
	    
	    
	    // Bodi 2 depan
	    glColor3f(0.8, 0.2, 0.2);
	    glBegin(GL_POLYGON);
	    glVertex2f(420.0, -20.0 ); // pojok kiri bawah
	    glVertex2f(300.0, 200.0); //pojok kiri atas
	    glVertex2f(650.0, 170.0); //pojok kanan atas
	    glVertex2f(650.0, -20.0); // pojok kanan bawah
		glEnd();
		
		 // Bodi mobil gradien
	    glColor3f(0.685, 0.2, 0.2);
	    glBegin(GL_POLYGON);
	    glVertex2f(-198.0, -20.0); //titik pojok kiri bawah
	    glVertex2f(-158.0, 130.0); //titik pojok kiri atas
	    glVertex2f(650.0, 130.0); //titik pojok kanan atas
	    glVertex2f(650.0, -20.0); //titik pojok kanan bawah
	    glEnd();
		
		// Bodi mobil : gagang depan
	    glColor3f(0.0, 0.0, 0.0);
	    glBegin(GL_POLYGON);
	    glVertex2f(200.0, 135.0); //titik pojok kiri bawah
	    glVertex2f(200.0, 153.0); //titik pojok kiri atas
	    glVertex2f(265.0, 153.0); //titik pojok kanan atas
	    glVertex2f(265.0, 135.0); //titik pojok kanan bawah
	    glEnd();
	    
	    		// Bodi mobil : gagang bealakng
	    glColor3f(0.0, 0.0, 0.0);
	    glBegin(GL_POLYGON);
	    glVertex2f(0.0, 135.0); //titik pojok kiri bawah
	    glVertex2f(0.0, 153.0); //titik pojok kiri atas
	    glVertex2f(65.0, 153.0); //titik pojok kanan atas
	    glVertex2f(65.0, 135.0); //titik pojok kanan bawah
	    glEnd();
	    
		// Bodi mobil : kaca
	    glColor3f(1.0, 1.0, 1.0);
	    glBegin(GL_POLYGON);
	    glVertex2f(200.0, 200.0); //titik pojok kiri bawah
	    glVertex2f(200.0, 350.0); //titik pojok kiri atas
	    glVertex2f(350.0, 350.0); //titik pojok kanan atas
	    glVertex2f(420.0, 200.0); //titik pojok kanan bawah
	    glEnd();
	    
	    // Bodi mobil : kaca gradien
	    glColor3f(0.9, 0.9, 0.9);
	    glBegin(GL_POLYGON);
	    glVertex2f(200.0, 200.0); //titik pojok kiri bawah
	    glVertex2f(200.0, 350.0); //titik pojok kiri atas
	    //glVertex2f(350.0, 350.0); //titik pojok kanan atas
	    glVertex2f(420.0, 200.0); //titik pojok kanan bawah
	    glEnd();
	    
	    // Bodi mobil : kaca 2
	    glColor3f(1.0, 1.0, 1.0);
	    glBegin(GL_POLYGON);
	    glVertex2f(20.0, 200.0); //titik pojok kiri bawah
	    glVertex2f(20.0, 350.0); //titik pojok kiri atas
	    glVertex2f(172.0, 350.0); //titik pojok kanan atas
	    glVertex2f(172.0, 200.0); //titik pojok kanan bawah
	    glEnd();
	    
	    // Bodi mobil : kaca 2 gradien
	    glColor3f(0.9, 0.9, 0.9);
	    glBegin(GL_POLYGON);
	    glVertex2f(20.0, 200.0); //titik pojok kiri bawah
	    glVertex2f(20.0, 350.0); //titik pojok kiri atas
	    //glVertex2f(172.0, 350.0); //titik pojok kanan atas
	    glVertex2f(140.0, 200.0); //titik pojok kanan bawah
	    glEnd();
	    
	    // Bodi mobil : kaca 3
	    glColor3f(1.0, 1.0, 1.0);
	    glBegin(GL_POLYGON);
	    glVertex2f(-140.0, 200.0); //titik pojok kiri bawah
	    glVertex2f(-100.0, 350.0); //titik pojok kiri atas
	    glVertex2f(-20.0, 350.0); //titik pojok kanan atas
	    glVertex2f(-20.0, 200.0); //titik pojok kanan bawah
	    glEnd();
	    
	      // Bodi mobil : kaca 3 gradien
	    glColor3f(0.9, 0.9, 0.9);
	    glBegin(GL_POLYGON);
	    glVertex2f(-140.0, 200.0); //titik pojok kiri bawah
	    glVertex2f(-100.0, 350.0); //titik pojok kiri atas
	    //glVertex2f(-20.0, 350.0); //titik pojok kanan atas
	    glVertex2f(-35.0, 200.0); //titik pojok kanan bawah
	    glEnd();
	    
	    // Bodi mobil : lampu depan
	    glColor3f(1.0, 0.6, 0.0);
	    glBegin(GL_POLYGON);
	    glVertex2f(580.0, 43.0); //titik pojok kiri bawah
	    glVertex2f(580.0, 100.0); //titik pojok kiri atas
	    glVertex2f(650.0, 100.0); //titik pojok kanan atas
	    glVertex2f(650.0, 43.0); //titik pojok kanan bawah
	    glEnd();
	    
	    	    // Bodi mobil : lampu depan grad
	    glColor3f(1.0, 0.8, 0.0);
	    glBegin(GL_POLYGON);
	    glVertex2f(580.0, 43.0); //titik pojok kiri bawah
	    glVertex2f(580.0, 100.0); //titik pojok kiri atas
	    //glVertex2f(650.0, 100.0); //titik pojok kanan atas
	    glVertex2f(650.0, 43.0); //titik pojok kanan bawah
	    glEnd();
	    
	    // Bodi mobil : lampu belakang
	    glColor3f(1.0, 0.6, 0.0);
	    glBegin(GL_POLYGON);
	    glVertex2f(-182.0, 43.0); //titik pojok kiri bawah
	    glVertex2f(-167.0, 100.0); //titik pojok kiri atas
	    glVertex2f(-90.0, 100.0); //titik pojok kanan atas
	    glVertex2f(-90.0, 43.0); //titik pojok kanan bawah
	    glEnd();

				// Bodi mobil : lampu belakang
	    glColor3f(1.0, 0.8, 0.0);
	    glBegin(GL_POLYGON);
	    glVertex2f(-182.0, 43.0); //titik pojok kiri bawah
	    glVertex2f(-167.0, 100.0); //titik pojok kiri atas
	    //glVertex2f(-90.0, 100.0); //titik pojok kanan atas
	    glVertex2f(-90.0, 43.0); //titik pojok kanan bawah
	    glEnd();
			    
	    // Bodi mobil : bemper depan
	    glColor3f(0.6, 0.7, 0.7);
	    glBegin(GL_POLYGON);
	    glVertex2f(580.0, -20.0); //titik pojok kiri bawah
	    glVertex2f(560.0, 40.0); //titik pojok kiri atas
	    glVertex2f(650.0, 40.0); //titik pojok kanan atas
	    glVertex2f(650.0, -20.0); //titik pojok kanan bawah
	    glEnd();
	    
	    // Bodi mobil : bemper belakang
	    glColor3f(0.6, 0.7, 0.7);
	    glBegin(GL_POLYGON);
	    glVertex2f(-199.0, -20.0); //titik pojok kiri bawah
	    glVertex2f(-183.0, 40.0); //titik pojok kiri atas
	    glVertex2f(-60.0, 40.0); //titik pojok kanan atas
	    glVertex2f(-60.0, -20.0); //titik pojok kanan bawah
	    glEnd();
		
	    // Roda kiri
	    glColor3f(0.0, 0.0, 0.0);
	    drawCircle(-30.0, -20.0, 77.0, 100);
	
		// Roda kiri 2
	    glColor3f(1.0, 1.0, 1.0);
	    drawCircle(-30.0, -20.0, 45.0, 100);
	    
	    // Roda kanan
	    glColor3f(0.0, 0.0, 0.0);
	    drawCircle(514.0, -20.0, 77.0, 100);
	    
	    // Roda kanan 2
	    glColor3f(1.0, 1.0, 1.0);
	    drawCircle(514.0, -20.0, 45.0, 100);
	    
    glPopMatrix();
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);

    // Matahari
    glColor3f(1.0, 1.0, 0.0);
    drawCircle(700.0, 500.0, 50.0, 100);
    
        // Matahari 2
    glColor3f(1.0, 0.9, 0.0);
    drawCircle(700.0, 500.0, 43.0, 100);
    
            // Matahari 3
    glColor3f(1.0, 0.7, 0.0);
    drawCircle(700.0, 500.0, 35.0, 100);
    
//    //Garis
//    glBegin(GL_LINES);
//    glColor3f(1.0, 1.0, 0.0);
//    glVertex2f(550.0, 450.0);
//    glVertex2f(650.0, 480.0);
//    glEnd();

    // Pemandangan alam
    glColor3f(0.2, 0.8, 0.2);
    glBegin(GL_POLYGON);
    glVertex2f(0.0, 300.0);
    glVertex2f(800.0, 300.0);
    glVertex2f(800.0, 0.0);
    glVertex2f(0.0, 0.0);
    glEnd();

    // Mobil 
    drawCar(200.0, 100.0, 45.0);

    glFlush();
}

void init()
{
    glClearColor(0.7, 0.9, 1.0, 1.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, 800.0, 0.0, 600.0);
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(800, 600);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Mobil dan Lingkaran");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
