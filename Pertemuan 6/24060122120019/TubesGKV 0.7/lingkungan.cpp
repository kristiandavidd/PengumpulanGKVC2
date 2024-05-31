#include "support.h"
#include "objek.h"

float r[] = {0.1,0.4,0.0,0.9,0.2,0.5,0.0,0.7,0.5,0.0};
float g[] = {0.2,0.0,0.4,0.5,0.2,0.0,0.3,0.9,0.0,0.2};
float b[] = {0.4,0.5,0.0,0.7,0.9,0.0,0.1,0.2,0.5,0.0};

//lantai dasar
void lantai(){
	glColor3f(0.2, 0.56, 0.10); //HIJAU RUMPUT
	glBegin(GL_QUADS);
    glVertex3f(-400, 0, 1000);
    glVertex3f(-400, 0, -1000);
    glVertex3f(400, 0, -1000);
    glVertex3f(400, 0, 1000);
    glEnd();
}

void aspal(float x){
	//ukuran aspal jalan
	glPushMatrix();
	glColor3f(0.3, 0.3, 0.3);
	glTranslatef(0.0, 0.1,0.0);
    glBegin(GL_QUADS);
    glVertex3f(-x, 0, 30);
    glVertex3f(-x, 0, -30);
    glVertex3f(x, 0, -20);
    glVertex3f(x, 0, 30);
    glEnd();
	glPopMatrix();

    //Strip marka
    int i;
    glPushMatrix();
    glColor3f(1, 1, 1);
    for(i = -x+10; i < x-50; i+= 50){
        glBegin(GL_QUADS);
        glVertex3f(i, 0.2, 2);
        glVertex3f(i, 0.2, -2);
        glVertex3f(i+30, 0.2, -2);
        glVertex3f(i+30, 0.2, 2);
        glEnd();
    }
    //strip terakhir dibuat lebih pendek jadinya tidak melebihi trotoar
    glBegin(GL_QUADS);
    glVertex3f(i, 0.2, 2);
    glVertex3f(i, 0.2, -2);
    glVertex3f(x-10, 0.2, -2);
    glVertex3f(x-10, 0.2, 2);
    glEnd();
    glPopMatrix();
}

void blokGedung(int R,int G,int B){
    glColor3d(r[R%10],g[G%50],b[B%50]);
    glPushMatrix();
        glTranslated(0,0,0);
        glutSolidCube(1);
    glPopMatrix();

    glColor3d(0,0,0);
    glPushMatrix();
        glTranslated(0,0,0.2);
        glScaled(1.001,0.3,0.3);
        glutSolidCube(1);
    glPopMatrix();

    glColor3d(0,0,0);
    glPushMatrix();
        glTranslated(0,0,-0.2);
        glScaled(1.001,0.3,0.3);
        glutSolidCube(1);
    glPopMatrix(); 

}

void gedung1(int n,int R,int G){
	glScalef(20,20,20);
	glTranslatef(0,0.5,0);
    glPushMatrix();
    	glTranslatef(0,0,-4);
		for(int i=0;i<n;i++){
	        glPushMatrix();
	            blokGedung(G,R,i);
	        glPopMatrix();
	    }
	glPopMatrix();
	
	glPushMatrix();
    	glTranslatef(0,1,-4);
		for(int i=0;i<n;i++){
	        glPushMatrix();
	            blokGedung(i,R,G);
	        glPopMatrix();
	    }
	glPopMatrix();
	
	glPushMatrix();
    	glTranslatef(0,2,-4);
		for(int i=0;i<n;i++){
	        glPushMatrix();
	            blokGedung(G,i,R);
	        glPopMatrix();
	    }
	glPopMatrix();
}

void gedung2(int n,int R,int G){
	glScalef(20,20,20);
	glTranslatef(0,0.5,0);
    glPushMatrix();
    	glTranslatef(0,0,-4);
		for(int i=0;i<n;i++){
	        glPushMatrix();
	            blokGedung(G,i,R);
	        glPopMatrix();
	    }
	glPopMatrix();
}

void gedung3(int n,int R,int G){
	glScalef(20,20,20);
	glTranslatef(0,0.5,0);
    glPushMatrix();
    	glTranslatef(0,0,-4);
		for(int i=0;i<n;i++){
	        glPushMatrix();
	            blokGedung(G,R,i);
	        glPopMatrix();
	    }
	glPopMatrix();
	
	glPushMatrix();
    	glTranslatef(0,1,-4);
		for(int i=0;i<n;i++){
	        glPushMatrix();
	            blokGedung(i,R,G);
	        glPopMatrix();
	    }
	glPopMatrix();
	
}

void kelompokGedungKiri(int n,int R,int G){
	glPushMatrix();
		glTranslatef(0,0,0);
		gedung2(n,R,G);
	glPopMatrix();
	
	glPushMatrix();
		glTranslatef(-2,0,-20);
		gedung2(R,n,G);
	glPopMatrix();
	
	glPushMatrix();
		glTranslatef(-1,0,-40);
		gedung1(R,G,n);
	glPopMatrix();
	
	glPushMatrix();
		glTranslatef(-3,0,-60);
		gedung3(G,R,n);
	glPopMatrix();
	
	glPushMatrix();
		glTranslatef(0,0,-80);
		gedung1(n,G,R);
	glPopMatrix(); 
}

void kelompokGedungKanan(int n,int R,int G){
	glPushMatrix();
		glTranslatef(0,0,0);
		gedung2(n,R,G);
	glPopMatrix();
	
	glPushMatrix();
		glTranslatef(2,0,-20);
		gedung1(R,n,G);
	glPopMatrix();
	
	glPushMatrix();
		glTranslatef(1,0,-40);
		gedung3(R,G,n);
	glPopMatrix();
	
	glPushMatrix();
		glTranslatef(3,0,-60);
		gedung2(G,R,n);
	glPopMatrix();
	
	glPushMatrix();
		glTranslatef(0,0,-80);
		gedung1(n,G,R);
	glPopMatrix();
}

void grupRumah(){
	glPushMatrix();
	glScalef(7, 7, 7);
	glRotated(0, 0, 0, 0);
	glTranslatef(0, 0, 20);
    // Garis hitam untuk pintu kuning
    glBegin(GL_LINE_LOOP);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(-0.5, 0.0, 2.0);
    glVertex3f(-0.5, -1.0, 2.0);
    glVertex3f(0.0, -0.8, 2.0);
    glVertex3f(0.0, -0.2, 2.0);
    glEnd();
    // Garis hitam untuk pintu putih di dalam dinding biru
    glBegin(GL_LINE_LOOP);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(-0.5, 0.0, 2.0);
    glVertex3f(-0.5, -1.0, 2.0);
    glVertex3f(0.5, -1.0, 2.0);
    glVertex3f(0.5, 0.0, 2.0);
    glEnd();
    // Pintu kuning di dalam pintu putih
    glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 0.0);
    glVertex3f(-0.5, 0.0, 2.0);
    glVertex3f(-0.5, -1.0, 2.0);
    glVertex3f(0.0, -0.8, 2.0);
    glVertex3f(0.0, -0.2, 2.0);
    glEnd();
    // Pintu putih di dalam dinding biru
    glBegin(GL_POLYGON);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(-0.5, 0.0, 2.0);
    glVertex3f(-0.5, -1.0, 2.0);
    glVertex3f(0.5, -1.0, 2.0);
    glVertex3f(0.5, 0.0, 2.0);
    glEnd();
    // Persegi panjang biru
    glBegin(GL_POLYGON);
    glColor3f(0.0, 0.0, 1.0);
    glVertex3f(-1.0, 1.0, 2.0);
    glVertex3f(-1.0, -1.0, 2.0);
    glVertex3f(1.0, -1.0, 2.0);
    glVertex3f(1.0, 1.0, 2.0);
    glEnd();
    // Segitiga merah
    glBegin(GL_POLYGON);
    glColor3f(1.0, 0.4, 0.0);
    glVertex3f(0.0, 2.0, 1.5);
    glVertex3f(-1.0, 1.0, 2.0);
    glVertex3f(1.0, 1.0, 2.0);
    glEnd();
    // Pembuang asap berwarna abu-abu
    glBegin(GL_QUADS);
    glColor3f(0.5, 0.3, 0.7);
    glVertex3f(0.3, 1.6, 0.0);
    glVertex3f(0.6, 1.3, 0.0);
    glVertex3f(0.6, 2.3, 0.0);
    glVertex3f(0.3, 2.3, 0.0);

    glVertex3f(0.3, 1.6, 0.3);
    glVertex3f(0.6, 1.3, 0.3);
    glVertex3f(0.6, 2.3, 0.3);
    glVertex3f(0.3, 2.3, 0.3);

    glVertex3f(0.3, 2.3, 0.0);
    glVertex3f(0.3, 2.3, 0.3);
    glVertex3f(0.3, 1.6, 0.3);
    glVertex3f(0.3, 1.6, 0.0);
    
    glVertex3f(0.6, 2.3, 0.0);
    glVertex3f(0.6, 1.3, 0.0);
    glVertex3f(0.6, 1.3, 0.3);
    glVertex3f(0.6, 2.3, 0.3);
    glEnd();
    // Atap merah
    glBegin(GL_POLYGON);
    glColor3f(1.0, 0.0, 0.0);
    glVertex3f(0.0, 2.0, 1.5);
    glVertex3f(1.0, 1.0, 2.0);
    glVertex3f(1.0, 1.0, -2.0);
    glVertex3f(0.0, 2.0, -1.5);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(1.0, 0.0, 0.0);
    glVertex3f(0.0, 2.0, 1.5);
    glVertex3f(-1.0, 1.0, 2.0);
    glVertex3f(-1.0, 1.0, -2.0);
    glVertex3f(0.0, 2.0, -1.5);
    glEnd();
    // Garis hitam berbentuk + pada jendela putih
    glBegin(GL_LINES);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(1.0, 0.5, 0.0);
    glVertex3f(1.0, -0.5, 0.0);
    glVertex3f(1.0, 0.0, 0.5);
    glVertex3f(1.0, 0.0, -0.5);
    glEnd();
    glBegin(GL_LINES);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(-1.0, 0.0, 0.5);
    glVertex3f(-1.0, 0.0, -0.5);
    glVertex3f(-1.0, 0.5, 0.0);
    glVertex3f(-1.0, -0.5, 0.0);
    glEnd();
    // Garis hitam berbentuk kotak untuk jendela putih
    glBegin(GL_LINE_LOOP);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(1.0, 0.5, 0.5);
    glVertex3f(1.0, -0.5, 0.5);
    glVertex3f(1.0, -0.5, -0.5);
    glVertex3f(1.0, 0.5, -0.5);
    glEnd();
    glBegin(GL_LINE_LOOP);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(-1.0, 0.5, 0.5);
    glVertex3f(-1.0, -0.5, 0.5);
    glVertex3f(-1.0, -0.5, -0.5);
    glVertex3f(-1.0, 0.5, -0.5);
    glEnd();
    // Jendela putih pada sisi kuning
    glBegin(GL_POLYGON);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(1.0, 0.5, 0.5);
    glVertex3f(1.0, -0.5, 0.5);
    glVertex3f(1.0, -0.5, -0.5);
    glVertex3f(1.0, 0.5, -0.5);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(-1.0, 0.5, 0.5);
    glVertex3f(-1.0, -0.5, 0.5);
    glVertex3f(-1.0, -0.5, -0.5);
    glVertex3f(-1.0, 0.5, -0.5);
    glEnd();
    // Sisi kuning
    glBegin(GL_POLYGON);
    glColor3f(1.0, 1.0, 0.0);
    glVertex3f(1.0, 1.0, 2.0);
    glVertex3f(1.0, -1.0, 2.0);
    glVertex3f(1.0, -1.0, -2.0);
    glVertex3f(1.0, 1.0, -2.0);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(1.0, 1.0, 0.0);
    glVertex3f(-1.0, 1.0, 2.0);
    glVertex3f(-1.0, -1.0, 2.0);
    glVertex3f(-1.0, -1.0, -2.0);
    glVertex3f(-1.0, 1.0, -2.0);
    glEnd();
    // Persegi panjang biru 
    glBegin(GL_POLYGON);
    glColor3f(0.0, 0.0, 1.0);
    glVertex3f(-1.0, 1.0, -2.0);
    glVertex3f(-1.0, -1.0, -2.0);
    glVertex3f(1.0, -1.0, -2.0);
    glVertex3f(1.0, 1.0, -2.0);
    glEnd();
    // Segitiga merah di belakang
    glBegin(GL_POLYGON);
    glColor3f(1.0, 0.4, 0.0);
    glVertex3f(0.0, 2.0, -1.5);
    glVertex3f(-1.0, 1.0, -2.0);
    glVertex3f(1.0, 1.0, -2.0);
    glEnd();
    glPopMatrix();
    
    glPushMatrix();
    glColor3f(0.8, 0.8, 0.8);
    glTranslatef(0, 0, 100);
    glutSolidCube(20);
    glPopMatrix();
}

void grupPohon() {
    Pohon pohon1(0, 0, 0, 1.5);
    Pohon pohon2(0, 0, 30, 1.5);
    Pohon pohon3(0, 0, 60, 1.5);
    
    // Menggambar pohon
    glPushMatrix();
    pohon1.pohonVersi1();
    glPopMatrix();

    glPushMatrix();
    pohon2.pohonVersi2();
    glPopMatrix();

    glPushMatrix();
    pohon3.pohonVersi3();
    glPopMatrix();
}

void grupAwan() {
    Awan awan1(-10, 20, 0, 1.5);
    Awan awan2(10, 25, -30, 1.2);
    Awan awan3(-20, 30, -60, 1.8);

    glPushMatrix();
    awan1.drawCloud();
    glPopMatrix();

    glPushMatrix();
    awan2.drawCloud();
    glPopMatrix();

    glPushMatrix();
    awan3.drawCloud();
    glPopMatrix();
}

void Jalan(){
    // Fungsi untuk membuat grid di "lantai"
    double i;
    const float Z_MIN = -50, Z_MAX = 50;
    const float X_MIN = -50, X_MAX = 50;
    const float gap = 10.0;

    //Push Pertama untuk lantai dasar dll agak kebawah
    glPushMatrix();
    glTranslatef(0.0, -0.5,0.0);

    //lantai dasar
    lantai();
    glPushMatrix();
    	glPushMatrix();
    		glTranslatef(-60,0,0);
    		grupRumah();
    		grupPohon();
    		kelompokGedungKiri(1,20,40);
    		grupAwan();
    	glPopMatrix();
		
		glPushMatrix();
			glTranslatef(60,0,0);
			grupRumah();
			grupPohon();
			kelompokGedungKanan(2,30,50);
			grupAwan();
 		glPopMatrix();
	glPopMatrix();
	
	glPushMatrix();
    	glPushMatrix();
    		glTranslatef(-60,0,-360);
    		grupRumah();
    		grupPohon();
    		kelompokGedungKiri(1,60,30);
    		grupAwan();
    	glPopMatrix();
		
		glPushMatrix();
			glTranslatef(60,0,-360);
			grupRumah();
			grupPohon();
			kelompokGedungKanan(6,16,10);
			grupAwan();
 		glPopMatrix();
	glPopMatrix();
	
	glPushMatrix();
    	glPushMatrix();
    		glTranslatef(-60,0,-720);
    		grupRumah();
    		grupPohon();
    		kelompokGedungKiri(1,60,30);
    		grupAwan();
    	glPopMatrix();
		
		glPushMatrix();
			glTranslatef(60,0,-720);
			grupRumah();
			grupPohon();
			kelompokGedungKanan(6,16,10);
			grupAwan();
 		glPopMatrix();
	glPopMatrix();
	
	glPushMatrix();
    	glPushMatrix();
    		glTranslatef(-60,0,360);
    		grupRumah();
    		grupPohon();
    		kelompokGedungKiri(5,30,20);
    		grupAwan();
    	glPopMatrix();
		
		glPushMatrix();
			glTranslatef(60,0,360);
			grupRumah();
			grupPohon();
			kelompokGedungKanan(8,14,20);
			grupAwan();
 		glPopMatrix();
	glPopMatrix();
	
	glPushMatrix();
    	glPushMatrix();
    		glTranslatef(-60,0,720);
    		grupRumah();
    		grupPohon();
    		kelompokGedungKiri(5,30,20);
    		grupAwan();
    	glPopMatrix();
		
		glPushMatrix();
			glTranslatef(60,0,720);
			grupRumah();
			grupPohon();
			kelompokGedungKanan(8,14,20);
			grupAwan();
 		glPopMatrix();
	glPopMatrix();

	//Push jalan 6
	glPushMatrix();
	//rotasi ke kanan
		glRotated(90, 0, 1, 0);
	//aspal
		aspal(1000);
    glPopMatrix();

	glPopMatrix();

}

