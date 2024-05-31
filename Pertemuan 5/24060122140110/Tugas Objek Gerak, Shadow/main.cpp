#include <math.h>
#include <stdio.h>
#include <GL/glut.h>

double rx = 0.0;
double ry = 0.0;
float l[] = { 0.0, 80.0, 0.0 }; // koordinat sumber cahaya
float n[] = { 0.0, -40.0, 0.0 };
float e[] = { 0.0, -60.0, 0.0 };

void help();

void drawObject()
{
    glPushMatrix();
    	glScalef(8, 8, 8);
        glPushMatrix();
        	glTranslatef(-0.3, 0.0, 0);
            // Badan mobil
            glPushMatrix();    
                glTranslatef(-0.9, 0.8, 0);               
                glScalef(4, 2, 4);  
                glColor3f(0.0, 0.05, 0.1);
                glutSolidCube(0.5);
			glPopMatrix();  
			glPushMatrix();    
                glTranslatef(1, 0.8, 0);               
                glScalef(6, 2, 4);  
                glColor3f(0.0, 0.05, 0.1);
                glutSolidCube(0.5);
			glPopMatrix();
			glPushMatrix(); 
                glTranslatef(-0.21, 1.4, 0);  
                glScalef(2.5, 6, 8);
				glColor3f(0.0, 0.05, 0.1);
                glutSolidCube(0.25);  
            glPopMatrix();
			// Lampu Utama
			glPushMatrix();    
                glTranslatef(-1.87, 1.0, -0.00);               
                glScalef(0.2, 0.31, 3.9);  
                glColor3f(1.0, 1.0, 0.0);
                glutSolidCube(0.5);
			glPopMatrix();
			// Lampu Rem
			glPushMatrix();    
                glTranslatef(2.5, 1.0, -0.00);               
                glScalef(0.2, 0.31, 3.9);  
                glColor3f(1.0, 0.0, 0.0);
                glutSolidCube(0.5);
			glPopMatrix();      
            // Kaca depan
            glPushMatrix(); 
                glTranslatef(-0.5, 1.33, -0.001);  
                glScalef(9, 11, 19);  
                glRotatef(228, 0, 0, 250); 
				glColor3f(0.75, 0.75, 0.75); 
                glutSolidCube(0.1);  
            glPopMatrix();
			// Kotak pada bagian atas badan mobil
            glPushMatrix(); 
                glTranslatef(1, 1.33, -0.001);  
                glScalef(6, 4, 3.9);  
                glColor3f(0.1, 0.1, 0.1);  
                glutSolidCube(0.5);  
            glPopMatrix();
			// Roda depan kiri 
            glTranslatef(0, 0.3, 0.5);  
            glPushMatrix();
                // Depan kiri
                glPushMatrix();
                    glTranslatef(-1.0, 0.1, 0.5);  
                    glColor3f(0.1, 0.1, 0.1); 
                    glutSolidTorus(0.16, 0.26, 20, 20);  
                glPopMatrix();
                // Velg depan kiri 
                glPushMatrix();
            		glTranslatef(-1.0, 0.1, 0.6);  
                	glScalef(0.8, 0.8, 0.1);
                	glColor3f(0.75, 0.75, 0.75);  
            		glutSolidSphere(0.2, 20, 20);
            	glPopMatrix();
                // Belakang kiri
                glPushMatrix();
                    glTranslatef(1.8, 0.1, 0.5);  
                    glColor3f(0.1, 0.1, 0.1); 
                    glutSolidTorus(0.16, 0.26, 20, 20);  
                glPopMatrix();
                // Velg belakang kiri
                glPushMatrix();
            		glTranslatef(1.8, 0.1, 0.6);  
                	glScalef(0.8, 0.8, 0.1);
                	glColor3f(0.75, 0.75, 0.75); 
            		glutSolidSphere(0.2, 20, 20);
            	glPopMatrix();
            glPopMatrix();
            // Roda depan kanan
            glTranslatef(0, 0.0, -1.0); 
            glPushMatrix(); 
                // Depan kanan
                glPushMatrix();
                    glTranslatef(-1.0, 0.1, -0.5);  
                    glColor3f(0.1, 0.1, 0.1); 
                    glutSolidTorus(0.16, 0.26, 20, 20);  
                glPopMatrix();
                // Velg depan kanan
                glPushMatrix();
            		glTranslatef(-1.0, 0.1, -0.6);  
                	glScalef(0.8, 0.8, 0.1);
                	glColor3f(0.75, 0.75, 0.75); 
            		glutSolidSphere(0.2, 20, 20);
            	glPopMatrix();
                // Belakang kanan
                glPushMatrix();
                    glTranslatef(1.8, 0.1, -0.5);  
                    glColor3f(0.1, 0.1, 0.1); 
                    glutSolidTorus(0.16, 0.26, 20, 20);  
                glPopMatrix();
                // Velg belakang kanan
                glPushMatrix();
            		glTranslatef(1.8, 0.1, -0.6);  
                	glScalef(0.8, 0.8, 0.1);
                	glColor3f(0.75, 0.75, 0.75); 
            		glutSolidSphere(0.2, 20, 20);
            	glPopMatrix();
            glPopMatrix();
        glPopMatrix();
    glPopMatrix();
}

// membuat proyeksi bayangan
void glShadowProjection(float * l, float * e, float * n)
{
    float d, c;
    float mat[16];
    d = n[0]*l[0] + n[1]*l[1] + n[2]*l[2];
    c = e[0]*n[0] + e[1]*n[1] + e[2]*n[2] - d;
    mat[0] = l[0]*n[0]+c; // membuat matrik. OpenGL menggunakan kolom matrik
    mat[4] = n[1]*l[0];
    mat[8] = n[2]*l[0];
    mat[12] = -l[0]*c-l[0]*d;
    mat[1] = n[0]*l[1]; 
    mat[5] = l[1]*n[1]+c;
    mat[9] = n[2]*l[1];
    mat[13] = -l[1]*c-l[1]*d;
    mat[2] = n[0]*l[2]; 
    mat[6] = n[1]*l[2];
    mat[10] = l[2]*n[2]+c;
    mat[14] = -l[2]*c-l[2]*d;
    mat[3] = n[0]; 
    mat[7] = n[1];
    mat[11] = n[2];
    mat[15] = -d;
    glMultMatrixf(mat); // kalikan matrik
}

void render()
{
    glClearColor(0.0,0.6,0.9,0.0);
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glLightfv(GL_LIGHT0, GL_POSITION, l);
    glDisable(GL_CULL_FACE);

    // Gambar lantai
    glColor3f(0.824, 0.706, 0.549); // Warna lantai
    glBegin(GL_QUADS);
    glNormal3f(0.0,1.0,0.0);
    glVertex3f(-1300.0,e[1]-0.1, 1300.0);
    glVertex3f( 1300.0,e[1]-0.1, 1300.0);
    glVertex3f( 1300.0,e[1]-0.1,-1300.0);
    glVertex3f(-1300.0,e[1]-0.1,-1300.0);
    glEnd();

    // Gambar objek tanpa bayangan
    glEnable(GL_LIGHTING);
    glColor3f(1.0, 0.0, 0.0); // Warna objek
    glPushMatrix();
    glRotatef(ry,0,1,0);
    glRotatef(rx,1,0,0);
    drawObject();
    glPopMatrix();

    // Matikan pencahayaan saat menggambar bayangan
    glDisable(GL_LIGHTING);

    // Gambar bayangan
    glPushMatrix();
    glShadowProjection(l,e,n); 
    glRotatef(ry,0,1,0);
    glRotatef(rx,1,0,0);
    glColor3f(0.4,0.4,0.4); // Warna bayangan
    drawObject();
    glPopMatrix();

    glutSwapBuffers();
}

void keypress(unsigned char c, int a, int b)
{
    if ( c==27 ) exit(0);
    else if ( c=='s' ) l[1]-=5.0;
    else if ( c=='w' ) l[1]+=5.0;
    else if ( c=='a' ) l[0]-=5.0;
    else if ( c=='d' ) l[0]+=5.0;
    else if ( c=='q' ) l[2]-=5.0;
    else if ( c=='e' ) l[2]+=5.0;
    else if ( c=='h' ) help();
}

void help()
{
    printf("proyeksi contoh bayangan sebuah obyek teapot\n");
}

void idle()
{
    rx+=0.02;
    ry+=0.02;
    render();
}

void resize(int w, int h)
{
    glViewport(0, 0, w, h);
}

int main(int argc, char * argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowPosition(300,30);
    glutCreateWindow("Shadow");
    glutReshapeFunc(resize);
    glutReshapeWindow(600,600);
    glutKeyboardFunc(keypress);
    glutDisplayFunc(render);
    glutIdleFunc(idle);
    glEnable(GL_NORMALIZE);
    glEnable(GL_LIGHTING);
    glEnable(GL_COLOR_MATERIAL);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_LIGHT0);
    glEnable(GL_TEXTURE_2D);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(60.0f, 1.0, 1.0, 400.0);
    // Reset koordinat sebelum dimodifikasi/diubah
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glTranslatef(0.0, 0.0, -150.0);
    glutMainLoop();
    return 0;
}
