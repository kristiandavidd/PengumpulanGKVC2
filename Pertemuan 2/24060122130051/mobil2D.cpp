//Nama/NIM: Miriam Stefani Abigail Hutapea/ 24060122130051
//Hari, tanggal: Minggu,3 Maret 2024
//Nama file: mobil2D.cpp
//Deskripsi file: membuat sebuah mobil 2D yang memanfaatkan object primitif dan transformasi


#include <GL/glut.h>


void mobil2d() {
    glPushMatrix();


	//pohon
	
	glBegin(GL_POLYGON);
    glColor3f(0.53f,0.663f,0.134f);
    glVertex2f(-0.7f,-0.3f);
    glVertex2f(-0.6f,0.4f);
    glVertex2f(-0.5f,-0.3f);
    glEnd();
    
	glBegin(GL_POLYGON);
    glColor3f(0.067f,0.259f,0.196f);
    glVertex2f(-1.0f,-0.3f);
    glVertex2f(-0.8f,0.6f);
    glVertex2f(-0.6f,-0.3f);
    glEnd();
    
    glBegin(GL_POLYGON);
    glColor3f(0.53f,0.663f,0.134f);
    glVertex2f(0.8f,-0.3f);
    glVertex2f(0.55f,0.6f);
    glVertex2f(0.4f,-0.3f);
    glEnd();
    
    glBegin(GL_POLYGON);
    glColor3f(0.067f,0.259f,0.196f);
    glVertex2f(1.0f,-0.3f);
    glVertex2f(0.85f,0.4f);
    glVertex2f(0.7f,-0.3f);
    glEnd();
	
    // Menggambar badan mobil
    glBegin(GL_POLYGON);
    glColor3f(0.8f, 0.2f, 0.2f); 
    glVertex2f(-0.7f, -0.25f);
    glVertex2f(-0.5f, 0.1f);
    glVertex2f(-0.2f, 0.1f);
    glVertex2f(0.0f, 0.4f);
    glVertex2f(0.5f,0.4f);
    glVertex2f(0.6f,0.1f);
    glVertex2f(0.7f, -0.25f);
    glEnd();
    
    //Menggambar lampu mobil 
    glPushMatrix();
    glColor3f(1.0f,1.0f,0.0f);
    glTranslatef(-0.47f, 0.05f, 0.0f);
    glutSolidSphere(0.05, 30,30);
    glPopMatrix();
    
    //menggambar jendela
    glBegin(GL_POLYGON);
    glColor3f(0.349f,0.835f,0.878f);
    glVertex2f(-0.25f,0.1f);
    glVertex2f(0.0f,0.35f);
    glVertex2f(0.0f,0.1f);
    glEnd();
    
    glBegin(GL_POLYGON);
    glColor3f(0.349f,0.835f,0.878f);
    glVertex2f(0.55f,0.1f);
    glVertex2f(0.47f,0.35f);
    glVertex2f(0.06f,0.35f);
    glVertex2f(0.06f,0.1f);
    glEnd();
    
    //dasar
    glBegin(GL_POLYGON);
    glColor3f(0.714f,0.451f,0.322f);
    glVertex2f(-1.0f,-0.3f);
    glVertex2f(-1.0f,-1.0f);
    glVertex2f(1.0f,-1.0f);
    glVertex2f(1.0f,-0.3f);
    glEnd();
    
    //roda kiri
    glPushMatrix();
    glColor3f(0.0f, 0.0f, 0.0f); 
    glTranslatef(-0.37f, -0.25f, 0.0f);
    glutSolidSphere(0.2, 30, 30); 
    glPopMatrix();
    
    //velg roda kiri
    glPushMatrix();
    glColor3f(1.0f, 1.0f, 1.0f); 
    glTranslatef(-0.37f, -0.25f, 0.0f);
    glutSolidSphere(0.07, 30, 30); 
    glPopMatrix();

	//roda kanan
    glPushMatrix();
    glColor3f(0.0f, 0.0f, 0.0f); 
    glTranslatef(0.37f, -0.25f, 0.0f);
    glutSolidSphere(0.2, 30, 30); 
    glPopMatrix();
    
    //velg roda kiri
    glPushMatrix();
    glColor3f(1.0f, 1.0f, 1.0f); 
    glTranslatef(0.37f, -0.25f, 0.0f);
    glutSolidSphere(0.07, 30, 30); 
    glPopMatrix();
    
    

    glPopMatrix();
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();
    mobil2d();
    glutSwapBuffers();
}


int main(int argc, char** argv) {
    glutInit(&argc, argv);

    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutCreateWindow("Mobil 2D");
    glClearColor(0.596f,0.851f,1.0f,1.0f);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(-1.0, 1.0, -1.0, 1.0);

    glutDisplayFunc(display);
    glutMainLoop();

    return 0;
}

