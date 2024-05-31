/*Nama : Rania 
 *NIM : 24060122120013 
 *Lab : C2 
 *Nama File : main.cpp
 *Tanggal : 3 Maret 2024
 *Deskripsi : Menampilkan mobil dan rodanya dengan mengunakan transformasi, objek primitif, dan stack*/
 
#include <GL/glut.h>
#include <cmath>

const double PI = 3.142857143;
int i, radius, jumlah_titik, x_tengah, y_tengah;
float gerak_x = 0.0f; //Translasi mobil pada sumbu x
float sudut_rotasi = 0.0f; //Rotasi mobil
float skala = 4.0f;

void mobil()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glPushMatrix();

    //Translasi dan Rotasi Mobil
    glTranslatef(gerak_x, 0.0f, 0.0f);
    glRotatef(sudut_rotasi, 0.0f, 0.0f, 1.0f);
    
    //Skala ukuran Mobil
    glScalef(skala, skala, 1.0f);

   	//Badan Depan Atas 
	glBegin(GL_POLYGON);
	glColor3f(0.7, 0.8, 1.0); glVertex2f(2.0, 3.0);  
	glColor3f(0.7, 0.8, 1.0); glVertex2f(2.5, 1.0);  
	glColor3f(0.7, 0.8, 1.0); glVertex2f(0.75, 1.0); 
	glColor3f(0.7, 0.8, 1.0); glVertex2f(0.75, 3.0); 
	glEnd();

	//Kaca Depan 
	glBegin(GL_POLYGON);
	glColor3f(0.0, 0.0, 0.4); glVertex2f(1.85, 2.75); 
	glColor3f(0.0, 0.0, 0.4); glVertex2f(2.15, 1.5);  
	glColor3f(0.0, 0.0, 0.4); glVertex2f(1.0, 1.5);   
	glColor3f(0.0, 0.0, 0.4); glVertex2f(1.0, 2.75); 
	glEnd();

	//Badan Tengah 
	glBegin(GL_POLYGON);
	glColor3f(0.0, 0.0, 0.4); glVertex2f(-1.5, 1.25); 
	glColor3f(0.0, 0.0, 0.4); glVertex2f(2.5, 1.25);  
	glColor3f(0.0, 0.0, 0.4); glVertex2f(2.5, -0.68); 
	glColor3f(0.0, 0.0, 0.4); glVertex2f(-1.5, -0.68); 
	glEnd();

	//Badan Bawah 
	glBegin(GL_POLYGON);
	glColor3f(0.7, 0.8, 1.0); glVertex2f(-1.70, -0.68); 
	glColor3f(0.7, 0.8, 1.0); glVertex2f(2.70, -0.68);  
	glColor3f(0.7, 0.8, 1.0); glVertex2f(2.75, -1.0);  
	glColor3f(0.7, 0.8, 1.0); glVertex2f(-1.75, -1.0); 
	glEnd();
    
    	//Ban Depan dan Belakang 
    	glColor3f(0.0, 0.0, 0.0); 
    	glBegin(GL_TRIANGLE_FAN);
    	glVertex2f(1.8, -0.9);
    	radius = 50;
    	jumlah_titik = 60;
    	x_tengah = 180;
    	y_tengah = -90;
    	for (i = 0; i <= 360; i++) {
        	float sudut = i * (2 * PI / jumlah_titik);
        	float x = x_tengah + radius * cos(sudut);
        	float y = y_tengah + radius * sin(sudut);
        	glVertex2f(x / 100, y / 100);
    	}
    	glEnd();
    
    	glBegin(GL_TRIANGLE_FAN);
    	glVertex2f(-0.8, -0.9);
    	radius = 50;
    	jumlah_titik = 60;
    	x_tengah = -80;
    	y_tengah = -90;
	for (i = 0; i <= 360; i++) {
        	float sudut = i * (2 * PI / jumlah_titik);
        	float x = x_tengah + radius * cos(sudut);
        	float y = y_tengah + radius * sin(sudut);
        	glVertex2f(x / 100, y / 100);
    	}
    	glEnd();

   	 //Lingkaran putih di roda
    	glColor3f(1.0, 1.0, 1.0); 
    	glBegin(GL_TRIANGLE_FAN);
    	glVertex2f(1.8, -0.9); 
    	radius = 15; 
    	jumlah_titik = 60;
    	x_tengah = 180;
    	y_tengah = -90;
    	for (i = 0; i <= 360; i++) {
       		float sudut = i * (2 * PI / jumlah_titik);
        	float x = x_tengah + radius * cos(sudut);
        	float y = y_tengah + radius * sin(sudut);
        	glVertex2f(x / 100, y / 100);
    	}
    	glEnd();

    	glBegin(GL_TRIANGLE_FAN);
    	glVertex2f(-0.9, -0.9); 
    	radius = 15; 
    	jumlah_titik = 60;
    	x_tengah = -80;
    	y_tengah = -90;
    	for (i = 0; i <= 360; i++) {
        	float sudut = i * (2 * PI / jumlah_titik);
        	float x = x_tengah + radius * cos(sudut);
        	float y = y_tengah + radius * sin(sudut);
        	glVertex2f(x / 100, y / 100);
    	}
   	 glEnd();
    
	//Jalan
	glColor3f(0.5, 0.5, 0.5);
	glBegin(GL_QUADS);
	glVertex2f(-5.0, -4.0);  
	glVertex2f(-5.0, -2.0); 
	glVertex2f(5.0, -2.0);  
	glVertex2f(5.0, -4.0);   
	glEnd();
	
	//Garis-garis hitam di jalan
	glColor3f(0.0, 0.0, 0.0);
	glLineWidth(2.0); 
	glBegin(GL_LINES);
	glVertex2f(-5.0, -3.0); 
	glVertex2f(5.0, -3.0);
	glEnd();

    glPopMatrix();
    glFlush();
}

void rotasiTranslasi(unsigned char key, int x, int y)
{
    switch (key)
    {
    case 'r': //Rotasi berlawanan arah jarum jam
        sudut_rotasi += 5.0f;
        break;
    case 'R': //Rotasi searah jarum jam
        sudut_rotasi -= 5.0f;
        break;
    case 'a': //Translasi ke kiri
        gerak_x -= 0.1f;
        break;
    case 'd': //Translasi ke kanan
        gerak_x += 0.1f;
        break;
    default:
        break;
    }
    glutPostRedisplay();
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Mobil Pick Up dengan Translasi dan Rotasi");
    glClearColor(1.0, 1.0, 1.0, 0.0);
    gluOrtho2D(-20.0, 20.0, -20.0, 20.0);
    glutDisplayFunc(mobil);
    glutKeyboardFunc(rotasiTranslasi);
    glutMainLoop();
    return 0;
}

