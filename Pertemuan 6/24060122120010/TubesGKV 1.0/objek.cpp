#include "objek.h"
#include "support.h"

float muter = 0;
float rotate=0;

void Objek::setX(float x)
{
    bx = x;
}

void Objek::setY(float y)
{
    by = y;
}

void Objek::setZ(float z)
{
    bz = z;
}

void Objek::setSize(float s)
{
    bsize = s;
}

void Objek::setHitValue(int v){
    bhitval = v;
}

float Objek::getX()
{
    return bx;
}

float Objek::getY()
{
    return by;
}

float Objek::getZ()
{
    return bz;
}

float Objek::getSize()
{
    return bsize;
}

int Objek::getHitValue()
{
    return bhitval;
}

//Membuat batasan depan dan belakang agar mobil tidak bisa keluar dari jalan yang sudah ditentukan
Batas1::Batas1(float x, float y, float z, float s, float cr, float cg, float cb){
    setX(x);
    setY(y);
    setZ(z);
    setSize(s);
    setHitValue(0);
        glPushMatrix();
        glTranslatef(getX(),getY()+getSize(), getZ());
            glPushMatrix();
                glColor3f(cr, cg, cb);
            glPopMatrix();
        glPopMatrix();
}

// Membuat batasan kiri dan kanan agar mobil tidak bisa keluar dari jalan yang sudah ditentukan
Batas2::Batas2(float x, float y, float z, float s) {
    setX(x);
    setY(y);
    setZ(z);
    setSize(s);
    setHitValue(0);  
    glPushMatrix();
    glTranslatef(getX(), getY(), getZ());
    
    glPushMatrix();
    glColor3f(1.0, 1.0, 1.0); // Warna putih
    glScalef(1, 10, 2000);

    // Menggambar sebuah kotak (atau bentuk lainnya) sebagai batas
    glBegin(GL_QUADS);
        // Sisi depan
        glVertex3f(-0.5, -0.5, 0.5);
        glVertex3f(0.5, -0.5, 0.5);
        glVertex3f(0.5, 0.5, 0.5);
        glVertex3f(-0.5, 0.5, 0.5);
        // Sisi belakang
        glVertex3f(-0.5, -0.5, -0.5);
        glVertex3f(0.5, -0.5, -0.5);
        glVertex3f(0.5, 0.5, -0.5);
        glVertex3f(-0.5, 0.5, -0.5);
        // Sisi kiri
        glVertex3f(-0.5, -0.5, -0.5);
        glVertex3f(-0.5, -0.5, 0.5);
        glVertex3f(-0.5, 0.5, 0.5);
        glVertex3f(-0.5, 0.5, -0.5);
        // Sisi kanan
        glVertex3f(0.5, -0.5, -0.5);
        glVertex3f(0.5, -0.5, 0.5);
        glVertex3f(0.5, 0.5, 0.5);
        glVertex3f(0.5, 0.5, -0.5);
        // Sisi atas
        glVertex3f(-0.5, 0.5, -0.5);
        glVertex3f(0.5, 0.5, -0.5);
        glVertex3f(0.5, 0.5, 0.5);
        glVertex3f(-0.5, 0.5, 0.5);
        // Sisi bawah
        glVertex3f(-0.5, -0.5, -0.5);
        glVertex3f(0.5, -0.5, -0.5);
        glVertex3f(0.5, -0.5, 0.5);
        glVertex3f(-0.5, -0.5, 0.5);
    glEnd();

    glPopMatrix();
    glPopMatrix();
}


//pohon
Pohon::Pohon(float x, float y, float z, float s) {
    setX(x);
    setY(y);
    setZ(z);
    setSize(s);
    setHitValue(0);
}

void Pohon::pohonVersi1() {
    glPushMatrix();
    glTranslatef(getX(), getY(), getZ());
    glScalef(getSize(), getSize(), getSize());

    // Batang
    GLUquadricObj *pObj = gluNewQuadric();
    gluQuadricNormals(pObj, GLU_SMOOTH);
    glPushMatrix();
    glColor3ub(104, 70, 14);
    glRotated(270, 1, 0, 0);
    gluCylinder(pObj, 1.5, 0.5, 14, 5, 5);
    glPopMatrix();
    // Daun 1 atas
    glPushMatrix();
    glColor3ub(18, 118, 13);
    glScalef(2.3, 2.3, 2.3);
    glRotated(90, 0, 1, 0);
    glTranslatef(0, 5.4, 0);
    glutSolidDodecahedron();
    glPopMatrix();
    // Daun 2
    glPushMatrix();
    glColor3ub(0, 100, 0); //hijau sangat tua
    glScalef(2, 2, 2);
    glRotated(90, 0, 1, 0);
    glTranslatef(-1, 5, -1);
    glutSolidDodecahedron();
    glPopMatrix();
    // Daun 3
    glPushMatrix();
    glColor3ub(18, 118, 13);
    glScalef(1.5, 1.5, 1.5);
    glRotated(90, 0, 1, 0);
    glTranslatef(1, 5.8, 1);
    glutSolidDodecahedron();
    glPopMatrix();
    glPopMatrix();
    glFlush();
}

void Pohon::pohonVersi2() {
    glPushMatrix();
    glTranslatef(getX(), getY(), getZ());
    glScalef(getSize(), getSize(), getSize());

    // Batang
    GLUquadricObj *pObj = gluNewQuadric();
    gluQuadricNormals(pObj, GLU_SMOOTH);
    glPushMatrix();
    glScalef(1.5, 1.5, 1.5);
    glColor3ub(100, 50, 20);
    glRotated(270, 1, 0, 0);
    gluCylinder(pObj, 1.2, 0.4, 6, 5, 5);
    glPopMatrix();
    // Daun 1 bawah
    glPushMatrix();
    glColor3ub(0, 100, 0); //hijau sangat tua
    glScalef(1.8, 1.8, 1.8);
    glTranslatef(0, 3, 0);
    glRotated(-90, 1, 0, 0);
    glutSolidCone(2.5, 4, 20, 20);
    glPopMatrix();
    // Daun 2 tengah
    glPushMatrix();
    glColor3ub(34, 139, 34); //hijau tua
    glScalef(1.8, 1.8, 1.8);
    glTranslatef(0, 4.5, 0);
    glRotated(-90, 1, 0, 0);
    glutSolidCone(2.2, 3.8, 20, 20);
    glPopMatrix();
	// Daun 3 atas
    glPushMatrix();
    glColor3ub(60, 179, 75); //hijau sedang
    glScalef(1.8, 1.8, 1.8);
    glTranslatef(0, 6, 0);
    glRotated(-90, 1, 0, 0);
    glutSolidCone(2, 3.5, 20, 20);
    glPopMatrix();
    
    glPopMatrix();
    glFlush();
}

void Pohon::pohonVersi3() {
    glPushMatrix();
    glTranslatef(getX(), getY(), getZ());
    glScalef(getSize(), getSize(), getSize());

    // Batang
    GLUquadricObj *pObj = gluNewQuadric();
    gluQuadricNormals(pObj, GLU_SMOOTH);
    glPushMatrix();
    glColor3ub(120, 85, 25);
    glRotated(270, 1, 0, 0);
    glScalef(1.2, 1.2, 1.2);
    gluCylinder(pObj, 1.0, 0.3, 7, 5, 5);
    glPopMatrix();
    // Daun 1 bawah
    glPushMatrix();
    glColor3ub(34, 139, 34); //hijau tua
    glScalef(2, 2, 2);
    glRotated(90, 0, 1, 0);
    glTranslatef(0, 3.4, 0);
    glutSolidDodecahedron();
    glPopMatrix();
    // Daun 2 tengah
    glPushMatrix();
    glColor3ub(34, 139, 34); //hijau tua
    glScalef(1.8, 1.8, 1.8);
    glRotated(90, 0, 1, 0);
    glTranslatef(0, 5.8, 0);
    glutSolidDodecahedron();
    glPopMatrix();
    // Daun 3 atas
    glPushMatrix();
    glColor3ub(40, 159, 50); //hijau sedang
    glScalef(1.6, 1.6, 1.6);
    glRotated(90, 0, 1, 0);
    glTranslatef(0, 8.8, 0);
    glutSolidDodecahedron();
    glPopMatrix();
    
    glPopMatrix();
    glFlush();
}

Bom::Bom(float x, float y, float z, float s){
    muter += 0.5f;
	setX(x);
    setY(y);
    setZ(z);
    setSize(s);
    setHitValue(10);

    glPushMatrix();
    glTranslatef(getX(),getY(), getZ());
        glPushMatrix();
        glRotatef(muter, 1, 0, 0);
        glRotatef(muter, 1, 1, 1);
			glPushMatrix();
	            glColor3f(0.3,0.5,0.9); 
	            glScaled(3.5,3.5,3.5);
	            glutSolidSphere(2, 20, 20);
	            glPushMatrix();
	            glRotatef(50, 5, 6, 4);
	            glColor3f(0.8, 0.2, 0.2);
	            glutSolidCube(3);
	            glPopMatrix();
	        glPopMatrix();
        glPopMatrix();
    glPopMatrix();
}

// Awan
Awan::Awan(float x, float y, float z, float s) {
    setX(x);
    setY(y);
    setZ(z);
    setSize(s);
    setHitValue(0);
}

void Awan::drawCloud() {
    glPushMatrix();
    glTranslatef(getX(), getY(), getZ());
    glScalef(getSize(), getSize(), getSize());

    // gambar kumpulan awan
    glPushMatrix();
    glScalef(4, 4, 4);
    
    glPushMatrix();
    glColor3ub(255, 255, 255);
    glTranslatef(-2, 12, 0);
    glutSolidSphere(1.0, 20, 20);
    glPopMatrix();
    
    glPushMatrix();
    glColor3ub(255, 255, 255);
    glTranslatef(0, 12, 0);
    glutSolidSphere(1.2, 20, 20);
    glPopMatrix();

    glPushMatrix();
    glColor3ub(255, 255, 255);
    glTranslatef(2, 12, 0);
    glutSolidSphere(1.0, 20, 20);
    glPopMatrix();

    glPushMatrix();
    glColor3ub(255, 255, 255);
    glTranslatef(1, 11, 0);
    glutSolidSphere(0.8, 20, 20);
    glPopMatrix();

    glPushMatrix();
    glColor3ub(255, 255, 255);
    glTranslatef(-1, 11, 0);
    glutSolidSphere(0.8, 20, 20);
    glPopMatrix();
    glPopMatrix();

    glPopMatrix();
    glFlush();
}

Portal::Portal(float x, float y, float z, float s){
    rotate += 2.0f;
	setX(x);
    setY(y);
    setZ(z);
    setSize(s);
    setHitValue(5);

    glPushMatrix();
    glTranslatef(getX(),getY(), getZ());
    glRotatef(rotate, 0, 1, 0);
        glPushMatrix();
            glColor3f(0.4,0.8,0.2); 
			glutSolidTorus(2, 5, 5,15);
            glScaled(3,3,3);
            glColor3f(0.3, 0.5, 0.8);
			glutSolidTorus(3.5, 5, 5,15);
        glPopMatrix();
    glPopMatrix();
}
