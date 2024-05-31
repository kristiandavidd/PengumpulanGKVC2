/*
 * Nama : Muhammad Luthfan Lazuardi
 * NIM : 24060122120010
 * Tanggal : 17 Maret 2024
*/

#include <math.h>
#include <GL/glut.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

float angle = 0.0, deltaAngle = 0.0, ratio;
float x = 0.0f, y = 1.75f, z = 15.0f; 
float lx = 0.0f, ly = 0.0f, lz = -1.0f;
int deltaMove = 0, h, w;
int bitmapHeight = 12;

void Reshape(int w1, int h1)
{
    // Fungsi reshape
    if (h1 == 0) h1 = 1;
    w = w1;
    h = h1;
    ratio = 1.0f * w / h;
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glViewport(0, 0, w, h);
    gluPerspective(45, ratio, 0.1, 1000);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(
        x, y, z,
        x + lx, y + ly, z + lz,
        0.0f, 1.0f, 0.0f);
}

void orientMe(float ang)
{
    // Fungsi memutar arah kamera (kiri/kanan)
    lx = sin(ang);
    lz = -cos(ang);
    glLoadIdentity();
    gluLookAt(x, y, z,
              x + lx, y + ly, z + lz,
              0.0f, 1.0f, 0.0f);
}

void moveMeFlat(int i)
{
    // Fungsi maju mundur kamera
    x = x + i * (lx)*0.003;
    z = z + i * (lz)*0.003;
    glLoadIdentity();
    gluLookAt(x, y, z,
              x + lx, y + ly, z + lz,
              0.0f, 1.0f, 0.0f);
}

void Grid()
{
    // Fungsi membuat grid di "lantai"
    double i;
    const float Z_MIN = -50, Z_MAX = 50;
    const float X_MIN = -50, X_MAX = 50;
    const float gap = 1.5;
    glColor3f(0.5, 0.5, 0.5);
    glBegin(GL_LINES);
    for (i = Z_MIN; i < Z_MAX; i += gap)
    {
        glVertex3f(i, 0, Z_MIN);
        glVertex3f(i, 0, Z_MAX);
    }
    for (i = X_MIN; i < X_MAX; i += gap)
    {
        glVertex3f(X_MIN, 0, i);
        glVertex3f(X_MAX, 0, i);
    }
    glEnd();
}

void Mobil(){
    glPushMatrix();
    	glScalef(1.6, 1.6, 1.6);
        glPushMatrix();
        	glTranslatef(-0.3, 0.0, 0);
            // Bagian badan mobil depan
            glPushMatrix();    
                glTranslatef(-0.9, 0.8, 0);               
                glScalef(4, 2, 4);  
                glColor3f(1.0, 0.0, 0.0);
                glutSolidCube(0.5);
			glPopMatrix();  
			
			//Bagian atas kotak
            glPushMatrix(); 
                glTranslatef(-0.21, 1.4, 0);  
                glScalef(2.5, 6, 8);
				glColor3f(1.0, 0.0, 0.0);  
                glutSolidCube(0.25);  
            glPopMatrix();
            
            //bagian atas kaca depan
            glPushMatrix(); 
                glTranslatef(-0.48, 1.31, -0.001);  
                glScalef(7, 12, 20);  
                glRotatef(230, 0, 0, 250); 
				glColor3f(1.0, 0.0, 0.0); 
                glutSolidCube(0.1);  
            glPopMatrix();
            
            //jendela samping 1
            glPushMatrix(); 
                glTranslatef(-0.21, 1.4, 0.03);  
                glScalef(1.8, 4.5, 7.8);
				glColor3f(1.0, 1.0, 1.0);  
                glutSolidCube(0.25);  
            glPopMatrix();
            glPushMatrix(); 
                glTranslatef(-0.4, 1.34, 0.03);  
                glScalef(5.8, 8.8, 19.5);  
                glRotatef(230, 0, 0, 250); 
				glColor3f(1.0, 1.0, 1.0); 
                glutSolidCube(0.1);  
            glPopMatrix();
            glPushMatrix(); 
                glTranslatef(-0.4, 1, 0.02);  
                glScalef(3.6, 2.3, 8);
				glColor3f(1.0, 0.0, 0.0);  
                glutSolidCube(0.25);  
            glPopMatrix();
            
            //jendela samping 2
            glPushMatrix(); 
                glTranslatef(-0.21, 1.4, -0.03);  
                glScalef(1.8, 4.5, 7.8);
				glColor3f(1.0, 1.0, 1.0);  
                glutSolidCube(0.25);  
            glPopMatrix();
            glPushMatrix(); 
                glTranslatef(-0.4, 1.34, -0.03);  
                glScalef(5.8, 8.8, 19.5);  
                glRotatef(230, 0, 0, 250); 
				glColor3f(1.0, 1.0, 1.0); 
                glutSolidCube(0.1);  
            glPopMatrix();
            glPushMatrix(); 
                glTranslatef(-0.4, 1, -0.02);  
                glScalef(3.6, 2.3, 8);
				glColor3f(1.0, 0.0, 0.0);  
                glutSolidCube(0.25);  
            glPopMatrix();
            
            // kaca depan
            glPushMatrix(); 
                glTranslatef(-0.5, 1.33, -0.001);  
                glScalef(7, 11, 19);  
                glRotatef(230, 0, 0, 250); 
				glColor3f(0.66, 0.66, 0.66); 
                glutSolidCube(0.1);  
            glPopMatrix();
            
            // sekat kaca depan
            glPushMatrix(); 
                glTranslatef(-0.523, 1.32, -0.001);  
                glScalef(7, 10.6, 0.8);  
                glRotatef(230, 0, 0, 250); 
				glColor3f(1.0, 0.0, 0.0); 
                glutSolidCube(0.1);  
            glPopMatrix();
            
            // bumper depan
            glPushMatrix();    
                glTranslatef(-1.9, 0.88, 0.22);               
                glScalef(0.2, 1.5, 0.75);  
                glColor3f(0.55, 0.55, 0.55);
                glutSolidCube(0.5);
			glPopMatrix(); 
            glPushMatrix();    
                glTranslatef(-1.9, 0.88, -0.22);               
                glScalef(0.2, 1.5, 0.75);  
                glColor3f(0.55, 0.55, 0.55);
                glutSolidCube(0.5);
			glPopMatrix(); 
			
			// lampu sorot 1
			glPushMatrix();    
                glTranslatef(-1.87, 1.0, 0.7);               
                glScalef(0.2, 0.31, 0.75);  
                glColor3f(1.0, 1.0, 1.0);
                glutSolidCube(0.5);
			glPopMatrix(); 
			glPushMatrix();    
                glTranslatef(-1.87, 1.18, 0.7);               
                glScalef(0.2, 0.31, 0.75);  
                glColor3f(1.0, 1.0, 1.0);
                glutSolidCube(0.5);
			glPopMatrix(); 
			
			// lampu sorot 1
			glPushMatrix();    
                glTranslatef(-1.87, 1.0, -0.7);               
                glScalef(0.2, 0.31, 0.75);  
                glColor3f(1.0, 1.0, 1.0);
                glutSolidCube(0.5);
			glPopMatrix(); 
			glPushMatrix();    
                glTranslatef(-1.87, 1.18, -0.7);               
                glScalef(0.2, 0.31, 0.75);  
                glColor3f(1.0, 1.0, 1.0);
                glutSolidCube(0.5);
			glPopMatrix(); 
            
            // Sein 1
            glPushMatrix();
            glPushMatrix();
            	glTranslatef(-1.9, 0.83, 0.55);  
                glScalef(0.1, 0.3, 0.3);
                glColor3f(1.0, 1.0, 1.0); 
            	glutSolidSphere(0.2, 20, 20);
            glPopMatrix();
            
            glPushMatrix();
            	glTranslatef(-1.9, 0.83, 0.68);  
                glScalef(0.1, 0.3, 0.3);
                glColor3f(1.0, 1.0, 1.0); 
            	glutSolidSphere(0.2, 20, 20);
            glPopMatrix();
            glPopMatrix();
            
            // Sein 2
            glPushMatrix();
            glPushMatrix();
            	glTranslatef(-1.9, 0.83, -0.55);  
                glScalef(0.1, 0.3, 0.3);
                glColor3f(1.0, 1.0, 1.0); 
            	glutSolidSphere(0.2, 20, 20);
            glPopMatrix();
            
            glPushMatrix();
            	glTranslatef(-1.9, 0.83, -0.68);  
                glScalef(0.1, 0.3, 0.3);
                glColor3f(1.0, 1.0, 1.0); 
            	glutSolidSphere(0.2, 20, 20);
            glPopMatrix();
            glPopMatrix();
            
        	//Bagian box belakang
            glPushMatrix(); 
                glTranslatef(0.2, 1.525, 0);  
                glScalef(2, 5, 8);
				glColor3f(1.0, 0.0, 0.0);  
                glutSolidCube(0.25);  
            glPopMatrix();
            
            // knalpot kiri
            glPushMatrix(); 
                glTranslatef(0.15, 1.325, 1);  
                glScalef(0.6, 8, 0.5);
				glColor3f(0.5, 0.5, 0.5);  
                glutSolidCube(0.25);  
            glPopMatrix();
            glPushMatrix(); 
                glTranslatef(0.15, 2.5, 1);  
                glScalef(0.3, 2, 0.4);
				glColor3f(0.6, 0.6, 0.6);  
                glutSolidCube(0.25);  
            glPopMatrix();
            
             // knalpot kanan
            glPushMatrix(); 
                glTranslatef(0.15, 1.325, -1);  
                glScalef(0.6, 8, 0.5);
				glColor3f(0.5, 0.5, 0.5);  
                glutSolidCube(0.25);  
            glPopMatrix();
            glPushMatrix(); 
                glTranslatef(0.15, 2.5, -1);  
                glScalef(0.3, 2, 0.4);
				glColor3f(0.6, 0.6, 0.6);  
                glutSolidCube(0.25);  
            glPopMatrix();
        
        	// penyambung 
        	glPushMatrix();    
                glTranslatef(0, 0.58, 0);               
                glScalef(4, 1, 3.6);
				glColor3f(0.3, 0.3, 0.3);   
                glutSolidCube(0.5);
			glPopMatrix(); 
			
			// bagian belakang 
        	glPushMatrix();    
                glTranslatef(2, 0.65, 0);               
                glScalef(5.5, 1.5, 4);
				glColor3f(0.45, 0.45, 0.45);  
                glutSolidCube(0.5);
			glPopMatrix(); 
			
			 // Sein belakang 1
            glPushMatrix();
            glPushMatrix();
            	glTranslatef(3.38, 0.83, 0.8);  
                glScalef(0.1, 0.3, 0.3);
                glColor3f(1.0, 1.0, 1.0); 
            	glutSolidSphere(0.2, 20, 20);
            glPopMatrix();
            
            glPushMatrix();
            	glTranslatef(3.38, 0.83, 0.66);  
                glScalef(0.1, 0.3, 0.3);
                glColor3f(1.0, 1.0, 1.0); 
            	glutSolidSphere(0.2, 20, 20);
            glPopMatrix();
            glPopMatrix();
            
            // Sein belakang 2
            glPushMatrix();
            glPushMatrix();
            	glTranslatef(3.38, 0.83, -0.8);  
                glScalef(0.1, 0.3, 0.3);
                glColor3f(1.0, 1.0, 1.0); 
            	glutSolidSphere(0.2, 20, 20);
            glPopMatrix();
            
            glPushMatrix();
            	glTranslatef(3.38, 0.83, -0.66);  
                glScalef(0.1, 0.3, 0.3);
                glColor3f(1.0, 1.0, 1.0); 
            	glutSolidSphere(0.2, 20, 20);
            glPopMatrix();
            glPopMatrix();
            
            
            // Roda samping kiri 
            glTranslatef(0, 0.3, 0.5);  
            glPushMatrix();
            //glTranslatef(0, 0.3, 0.5);
                // depan kiri
                glPushMatrix();
                    glTranslatef(-1.0, 0.1, 0.5);  
                    glColor3f(0.1, 0.1, 0.1);  
                    glutSolidTorus(0.16, 0.26, 20, 20);  
                glPopMatrix();
                
                //velg depan kiri 1
                glPushMatrix();
            		glTranslatef(-1.0, 0.1, 0.6);  
                	glScalef(0.8, 0.8, 0.1);
                	glColor3f(0.6, 0.6, 0.6); 
            		glutSolidSphere(0.2, 20, 20);
            	glPopMatrix();
                
                // belakang kiri 1
                glPushMatrix();
                    glTranslatef(1.8, 0.1, 0.5);  
                    glColor3f(0.1, 0.1, 0.1);  
                    glutSolidTorus(0.16, 0.26, 20, 20);  
                glPopMatrix();
                
                // velg belakang kiri 1
                glPushMatrix();
            		glTranslatef(1.8, 0.1, 0.6);  
                	glScalef(0.8, 0.8, 0.1);
                	glColor3f(0.6, 0.6, 0.6); 
            		glutSolidSphere(0.2, 20, 20);
            	glPopMatrix();
                
                // belakang kiri 2
                glPushMatrix();
                    glTranslatef(2.8, 0.1, 0.5);  
                    glColor3f(0.1, 0.1, 0.1);  
                    glutSolidTorus(0.16, 0.26, 20, 20); 
                glPopMatrix();
                
                // velg belakang kiri 1
                glPushMatrix();
            		glTranslatef(2.8, 0.1, 0.6);  
                	glScalef(0.8, 0.8, 0.1);
                	glColor3f(0.6, 0.6, 0.6); 
            		glutSolidSphere(0.2, 20, 20);
            	glPopMatrix();
            glPopMatrix();
            
            
            // Roda samping kanan
            glTranslatef(0, 0.0, -1.0); 
            glPushMatrix(); 
            	// depan kanan
                glPushMatrix();
                    glTranslatef(-1.0, 0.1, -0.5);  
                    glColor3f(0.1, 0.1, 0.1);  
                    glutSolidTorus(0.16, 0.26, 20, 20);  
                glPopMatrix();
                
                //velg depan kanan 
                glPushMatrix();
            		glTranslatef(-1.0, 0.1, -0.6);  
                	glScalef(0.8, 0.8, 0.1);
                	glColor3f(0.6, 0.6, 0.6); 
            		glutSolidSphere(0.2, 20, 20);
            	glPopMatrix();
                
                // belakang kanan 1
                glPushMatrix();
                    glTranslatef(1.8, 0.1, -0.5);  
                    glColor3f(0.1, 0.1, 0.1); 
                    glutSolidTorus(0.16, 0.26, 20, 20); 
                glPopMatrix();
                
                // velg belakang kanan 1
                glPushMatrix();
            		glTranslatef(1.8, 0.1, -0.6);  
                	glScalef(0.8, 0.8, 0.1);
                	glColor3f(0.6, 0.6, 0.6); 
            		glutSolidSphere(0.2, 20, 20);
            	glPopMatrix();
                
                // belakang kanan 2
                glPushMatrix();
                    glTranslatef(2.8, 0.1, -0.5);  
                    glColor3f(0.1, 0.1, 0.1); 
                    glutSolidTorus(0.16, 0.26, 20, 20); 
                glPopMatrix();
                
                // velg belakang kanan 2
                glPushMatrix();
            		glTranslatef(2.8, 0.1, -0.6);  
                	glScalef(0.8, 0.8, 0.1);
                	glColor3f(0.6, 0.6, 0.6); 
            		glutSolidSphere(0.2, 20, 20);
            	glPopMatrix();
            glPopMatrix();
        glPopMatrix();
    glPopMatrix();
}



void display()
{
    // Kalau move dan angle tidak nol, gerakkan kamera
    if (deltaMove)
        moveMeFlat(deltaMove);
    if (deltaAngle)
    {
        angle += deltaAngle;
        orientMe(angle);
    }
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    // Gambar grid
    Grid();
    // Gambar objek di sini
    Mobil();
    glutSwapBuffers();
    glFlush();
}

void pressKey(int key, int x, int y)
{
    // Fungsi ini akan dijalankan saat tombol keyboard ditekan dan belum dilepas
    // Selama tombol ditekan, variabel angle dan move diubah => kamera bergerak
    switch (key)
    {
    case GLUT_KEY_LEFT:
        deltaAngle = -0.0005f;
        break;
    case GLUT_KEY_RIGHT:
        deltaAngle = 0.0005f;
        break;
    case GLUT_KEY_UP:
        deltaMove = 1;
        break;
    case GLUT_KEY_DOWN:
        deltaMove = -1;
        break;
    }
}

void releaseKey(int key, int x, int y)
{
    // Fungsi ini akan dijalankan saat tekanan tombol keyboard dilepas
    // Saat tombol dilepas, variabel angle dan move diset nol => kamera berhenti
    switch (key)
    {
    case GLUT_KEY_LEFT:
        if (deltaAngle < 0.0f)
            deltaAngle = 0.0f;
        break;
    case GLUT_KEY_RIGHT:
        if (deltaAngle > 0.0f)
            deltaAngle = 0.0f;
        break;
    case GLUT_KEY_UP:
        if (deltaMove > 0)
            deltaMove = 0;
        break;
    case GLUT_KEY_DOWN:
        if (deltaMove < 0)
            deltaMove = 0;
        break;
    }
}

// Variable untuk pencahayaan
const GLfloat light_ambient[] = {0.5f, 0.5f, 0.5f, 0.0f};
const GLfloat light_diffuse[] = {1.0f, 1.0f, 1.0f, 1.0f};
const GLfloat light_specular[] = {1.0f, 1.0f, 1.0f, 1.0f};
const GLfloat light_position[] = {0.0f, 20.0f, 10.0f, 1.0f};
const GLfloat mat_ambient[] = {0.7f, 0.7f, 0.7f, 1.0f};
const GLfloat mat_diffuse[] = {0.8f, 0.8f, 0.8f, 1.0f};
const GLfloat mat_specular[] = {1.0f, 1.0f, 1.0f, 1.0f};
const GLfloat high_shininess[] = {100.0f};

void lighting()
{
    // Fungsi mengaktifkan pencahayaan
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LESS);
    glEnable(GL_LIGHT0);
    glEnable(GL_NORMALIZE);
    glEnable(GL_COLOR_MATERIAL);
    glEnable(GL_LIGHTING);
    glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);
    glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
    glLightfv(GL_LIGHT0, GL_POSITION, light_position);
    glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, high_shininess);
}

void init(void)
{
    glEnable(GL_DEPTH_TEST);
    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
    glutInitWindowPosition(100, 100);
    glutInitWindowSize(740, 580);
    glutCreateWindow("OPTIMUSSSSS 3D");
    glutIgnoreKeyRepeat(1); 
    glutSpecialFunc(pressKey);
    glutSpecialUpFunc(releaseKey);
    glutDisplayFunc(display);
    glutIdleFunc(display); 
    glutReshapeFunc(Reshape);
    lighting();
    init();
    glutMainLoop();
    return (0);
}
