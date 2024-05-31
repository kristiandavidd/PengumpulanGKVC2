#include <windows.h>
#include "support.h"

#include "tesla.h"
#include "lingkungan.h"
#include "objek.h"

float angle = 8.0;
float deltaAngle = 0.0;
float ratio;
float deltaMove = 0,h,w; //for debug cam
int bitmapHeight=12;

//debug and dev
int debugCamera = 0;

int play = 1;

//global var buat game mechanics
float speedX = 1.0, speedZ = 0.0; //pergerakan mobil
float temp;
float putaranMobil = 90.0; //jgn di set negatif
int gasDitekan = 0;
int setirDitekan = 0; //-1 kiri 1 kanan 0 tidak ditekan
float akselerasiBoost = 6; //Penambah kecepatan
float akselerasi = 0.03;
float deakselerasi = 0.05;
float cx=0.0, cy=0.0, cz=0.0;
float x=22.5f,y=10.0f,z=22.5f; // posisi awal kamera
float angleCam = 45.0; 
float lx=0.0f,ly=0.0f,lz=-1.0f;
float tx=0.0, ty=0.0, tz=-60.0; //posisi mobil jangan diubah
extern float cpDepanX, cpDepanZ, cpBelakangX, cpBelakangZ; //shared global variable collision point

float DodecahedronPosX[9] = {-4,0,4,-4,0,-4,4,-4,4};
float DodecahedronPosY[9] = {0.7,0.7,0.7,0.7,0.7,0.7,0.7,0.7,0.7};
float DodecahedronPosZ[9] = {-3,-10,-5,-3,-10,-5,-3,-10,-5};

//Renders
int bangunan = 1; //seluruh bangunan memakai ini, 0 = seluruh bangunan hilang
int BomCheck = 1;


void Reshape(int w1, int h1){
    // Fungsi reshape
    if(h1 == 0) h1 = 1;
    w = w1;
    h = h1;
    ratio = 1.0f * w / h;
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glViewport(0, 0, w, h);
    gluPerspective(45,ratio,0.1,500);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(tx, y, tz, x + lx,y + ly,z + lz, 0.0f,1.0f,0.0f);
}

void moveCamFlat(float i){
    //kamera ingame
    glLoadIdentity();
    i = i - 90;
    gluLookAt(tx+x*sin(i*M_PI/180), y, tz+z*cos(i*M_PI/180), tx, ty+y/2, tz, 0.0f,1.0f,0.0f);
}

void moveMeFlat(float i){
    //kamera debug
    // Fungsi ini untuk maju mundur kamera
    cx = cx + i*(lx)*0.1;
    cz = cz + i*(lz)*0.1;
    glLoadIdentity();
    gluLookAt(cx, y, cz, cx + lx,y + ly,cz + lz, 0.0f,1.0f,0.0f);
}

void moveMobil(float putaran, float deltaX){
    float deltaMundur = float(abs(180-putaran));
    tx = tx + (deltaX)*0.1*(90.0-deltaMundur)/-90;
    tz = tz + (deltaX)*0.1*-sin(putaran*M_PI/180)*(1-abs((90.0-deltaMundur)/-90));
}

int cekTabrakan(Objek objek, int *existance) {
    float oMinX, oMaxX, oMinZ, oMaxZ; //objek min x, objek max x, dll.
    //jarak dari kaca depan mobil ke koordinat ditengah(0,0,0) itu 10.3

    oMinX = objek.getX() - (objek.getSize()/2) - 5.9; //lebar mobil 11.8 (kiri 5.9, kanan 5.9);
    oMaxX = objek.getX() + (objek.getSize()/2) + 5.9;
    oMinZ = objek.getZ() - (objek.getSize()/2) - 5.9;
    oMaxZ = objek.getZ() + (objek.getSize()/2) + 5.9;

  
    if(cpDepanX >= oMinX && cpDepanX <= oMaxX && cpDepanZ >= oMinZ && cpDepanZ <= oMaxZ){
        if (!objek.getHitValue()){
            if (speedX>0){
                speedX = 0.0;
            }
        }else if (objek.getHitValue() == 5){
            play = 0;
            return 1;
        } else {
        	exit(0);
			return 1;	
        }
    }

    if(cpBelakangX >= oMinX && cpBelakangX <= oMaxX && cpBelakangZ >= oMinZ && cpBelakangZ <= oMaxZ){
         if (!objek.getHitValue()){
            if (speedX<0){
                speedX = 0.0;
            }
        }else if (objek.getHitValue() == 5){
            play = 0;
            return 1;
        } else {
        	exit(0);
			return 1;	
        }
    }
    return 0;
}

int cekTabrakanR(Objek objek, int *existance){
	float oMinXR=35.0;
	float oMaxXR=40.0;
	float oMinZR=-2000.0;
	float oMaxZR=0.0;
	
	glPushMatrix();
	    glBegin(GL_POLYGON);
	    glColor3f(1,0,0.8);
	    glVertex3f(oMaxXR,  0, oMaxZR);
	    glVertex3f(oMaxXR, 0, oMinZR);
	    glVertex3f(oMinXR,  0,oMinZR);
	    glVertex3f(oMinXR, 0, oMaxZR);
	    glEnd();
    glPopMatrix();
	
	if(cpDepanX >= oMinXR && cpDepanX <= oMaxXR && cpDepanZ >= oMinZR && cpDepanZ <= oMaxZR){
        if (!objek.getHitValue()){
            if (speedX>0){
                speedX = 0.0;
            }
        }else{
            *existance = 0;
            exit(0);
            return 1;
        }
    }
}

int cekTabrakanL(Objek objek, int *existance){
	float oMinXL=-40.0;
	float oMaxXL=-35.0;
	float oMinZL=-2000.0;
	float oMaxZL=0.0;
	
	glPushMatrix();
	    glBegin(GL_POLYGON);
	    glColor3f(1,0,0.8);
	    glVertex3f(oMaxXL,  0, oMaxZL);
	    glVertex3f(oMaxXL, 0, oMinZL);
	    glVertex3f(oMinXL,  0,oMinZL);
	    glVertex3f(oMinXL, 0, oMaxZL);
	    glEnd();
    glPopMatrix();
	
	if(cpDepanX >= oMinXL && cpDepanX <= oMaxXL && cpDepanZ >= oMinZL && cpDepanZ <= oMaxZL){
        if (!objek.getHitValue()){
            if (speedX>0){
                speedX = 0.0;
            }
        }else{
            *existance = 0;
            exit(0);
            return 1;
        }
    }
}

void renderBitmapString(float x,float y,float z,char *string) {
  char *c;

  glRasterPos3f(x, y,z);
  for (c=string; *c != '\0'; c++) {
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, *c);
  }
}

void RenderWord() {
    char s[100];
    glPushMatrix();
	    sprintf(s,"YOU WIN!!!");
	    glColor3f(0,0,0);
	    renderBitmapString(340, 340, 0,s); 
    glPopMatrix();
}


void setOrthographicProjection() {
	// switch to projection mode
	glMatrixMode(GL_PROJECTION);
	glPushMatrix();
	glLoadIdentity();
	// set a 2D orthographic projection
	gluOrtho2D(0, w, h, 0);
	glMatrixMode(GL_MODELVIEW);
}

void restorePerspectiveProjection() {
	glMatrixMode(GL_PROJECTION);
	glPopMatrix();
	glMatrixMode(GL_MODELVIEW);
}

void draw(int n){
	glPushMatrix();
		glTranslatef(0,0,-1000);
		Jalan();
	glPopMatrix();
	
	Tesla(putaranMobil, tx, ty, tz);

}

//gameplay mechanic
//render
void display() {
    glClearColor(0.95, 0.64, 0.37, 0); //Warna langit
		//pergerakan mobil
        if (speedX){
            moveMobil(putaranMobil, speedX*2);
        }
            if (speedX <= 14 && speedX > -2){ //speedX dan deltaMove harus sama
                speedX += akselerasi;
            }
			if (setirDitekan){
                putaranMobil -= setirDitekan/abs(setirDitekan);
                if (putaranMobil<0){
                    putaranMobil = 360 + putaranMobil;
                    if (angleCam<360){
                        angleCam += 360;
                    }
                }else if (putaranMobil>360){
                    putaranMobil -= 360;
                    if (angleCam>0){
                        angleCam -= 360;
                    }
                }
        	}

        //gerakan camera
	    if (abs(angleCam-putaranMobil)<1){
	            angleCam = putaranMobil;
	    	}else if(putaranMobil>0 && putaranMobil<360){
	            if (angleCam<putaranMobil){
	                angleCam+=0.75;
	            }else{
	                angleCam-=0.75;
	            }
	        }
	        moveCamFlat(angleCam);

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glEnable(GL_LIGHTING);
    
    int randomNumber;
	
	if (play == 1){
		if (BomCheck){
	        Bom rRender1(17.0, 3, -250, 5);
	        if (cekTabrakan(rRender1, &BomCheck)){
	            BomCheck = 1;
	        }
	    }
	    if (BomCheck){
	        Bom rRender2(-17.0, 3, -250, 5);
	        if (cekTabrakan(rRender2, &BomCheck)){
	            BomCheck = 1;
	        }
	    }
	    
		 if (BomCheck){
	        Bom rRender3(-1, 3, -420, 5);
	        if (cekTabrakan(rRender3, &BomCheck)){
	            BomCheck = 1;
	        }
	    } 
	     if (BomCheck){
	        Bom rRender4(-17, 3, -500, 5);
	        if (cekTabrakan(rRender4, &BomCheck)){
	            BomCheck = 1;
	        }
	    } 
	     if (BomCheck){
	        Bom rRender5(17, 3, -580, 5);
	        if (cekTabrakan(rRender5, &BomCheck)){
	            BomCheck = 1;
	        }
	    } 
	     if (BomCheck){
	        Bom rRender6(0, 3, -660, 5);
	        if (cekTabrakan(rRender6, &BomCheck)){
	            BomCheck = 1;
	        }
	    } 
	     if (BomCheck){
	        Bom rRender7(-17, 3, -740, 5);
	        if (cekTabrakan(rRender7, &BomCheck)){
	            BomCheck = 1;
	        }
	    } 
	     if (BomCheck){
	        Bom rRender8(17, 3, -820, 5);
	        if (cekTabrakan(rRender8, &BomCheck)){
	            BomCheck = 1;
	        }
	    } 
	     if (BomCheck){
	        Bom rRender9(-17, 3, -900, 5);
	        if (cekTabrakan(rRender9, &BomCheck)){
	            BomCheck = 1;
	        }
	    } 
	     if (BomCheck){
	        Bom rRender10(17, 3, -980, 5);
	        if (cekTabrakan(rRender10, &BomCheck)){
	            BomCheck = 1;
			}
		}
		 if (BomCheck){
	        Bom rRender11(1, 3, -1060, 5);
	        if (cekTabrakan(rRender11, &BomCheck)){
	            BomCheck = 1;
	        }
	    } 
	     if (BomCheck){
	        Bom rRender12(-17, 3, -1140, 5);
	        if (cekTabrakan(rRender12, &BomCheck)){
	            BomCheck = 1;
	        }
	    } 
	     if (BomCheck){
	        Bom rRender13(17, 3, -1220, 5);
	        if (cekTabrakan(rRender13, &BomCheck)){
	            BomCheck = 1;
	        }
	    } 
	     if (BomCheck){
	        Bom rRender14(0, 3, -1300, 5);
	        if (cekTabrakan(rRender14, &BomCheck)){
	            BomCheck = 1;
	        }
	    } 
	     if (BomCheck){
	        Bom rRender15(17, 3, -1380, 5);
	        if (cekTabrakan(rRender15, &BomCheck)){
	            BomCheck = 1;
	        }
	    } 
	     if (BomCheck){
	        Bom rRender16(-17, 3, -1460, 5);
	        if (cekTabrakan(rRender16, &BomCheck)){
	            BomCheck = 1;
	        }
	    } 
	     if (BomCheck){
	        Bom rRender17(17, 3, -1550, 5);
	        if (cekTabrakan(rRender17, &BomCheck)){
	            BomCheck = 1;
	        }
	    } 
	     if (BomCheck){
	        Bom rRender18(-1, 3, -1650, 5);
	        if (cekTabrakan(rRender18, &BomCheck)){
	            BomCheck = 1;
			}
		}
		 if (BomCheck){
	        Bom rRender19(-17, 3, -1800, 5);
	        if (cekTabrakan(rRender19, &BomCheck)){
	            BomCheck = 1;
	        }
	    } 
	     if (BomCheck){
	        Bom rRender20(17, 3, -1900, 5);
	        if (cekTabrakan(rRender20, &BomCheck)){
	            BomCheck = 1;
	        }
	    } 
	
	
	 	Batas1 batasBelakang(0,0,50,150,3,5,6);
	 	glPushMatrix();
	 		glRotatef(90,1,0,0);
	 		cekTabrakan (batasBelakang, &bangunan);
	 	glPopMatrix();
	 	
	 	Batas1 batasDepan(0,0,-2010,60,3,5,6);
	 	glPushMatrix();
	 		glRotatef(90,1,0,0);
	 		cekTabrakan (batasDepan, &bangunan);
	 	glPopMatrix();
	
	 	Batas2 batasKiri(-35,0,-1000,1000);	
	 	Batas2 batasKanan(35,0,-1000,1000);
	 	cekTabrakanR(batasKiri, &bangunan);
	 	cekTabrakanL(batasKanan, &bangunan);
	    
	    Portal Portal(0,3,-1950,10);
	    cekTabrakan (Portal, &bangunan);
	    
	    // Gambar Objek
		draw(1);	
	} else {
	    setOrthographicProjection();
	    	glPushMatrix();
	   			glLoadIdentity();
	    		RenderWord();
	    	glPopMatrix();
	    restorePerspectiveProjection();
	}
	glutSwapBuffers();
    glFlush();
}

// Fungsi ini akan dijalankan saat tombol keyboard ditekan dan belum dilepas
void pressKey(int key, int x, int y) {
        switch (key) {
            case GLUT_KEY_LEFT :
                if (gasDitekan>0){
                    setirDitekan = -1;
                }else if (gasDitekan<0){
                    setirDitekan = 1;
                }else{
                    setirDitekan = -1;
                }
            break;
            case GLUT_KEY_RIGHT :
                if (gasDitekan>0){
                    setirDitekan = 1;
                }else if (gasDitekan<0){
                    setirDitekan = -1;
                }else{
                    setirDitekan = 1;
                }
            break;
            case GLUT_KEY_UP :
            	if (speedX < 3.0){
            	akselerasi += akselerasiBoost;
				}
            break;
            case GLUT_KEY_DOWN :
            break;
        }
    }
    
// Fungsi ini akan dijalankan saat tekanan tombol keyboard dilepas
void releaseKey(int key, int x, int y) {
        switch (key) {
            case GLUT_KEY_LEFT:
                setirDitekan = 0;
            break;
            case GLUT_KEY_RIGHT :
                setirDitekan = 0;
            break;
            case GLUT_KEY_UP :
            	if (speedX>=2.0){
            		speedX -= deakselerasi;
            	}
            break;
            case GLUT_KEY_DOWN :
            break;
        }
    }

static void key(unsigned char key, int x, int y)
{
    switch (key)
    {
        case 'q':
            exit(0);
            break; 
	}
	    glutPostRedisplay();
}

// Variable untuk pencahayaan
const GLfloat light_ambient[] = { 0.5f, 0.5f, 0.5f, 0.0f };
const GLfloat light_diffuse[] = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat light_specular[] = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat light_position[] = { 0.0f, 20.0f, 10.0f, 1.0f };
const GLfloat mat_ambient[] = { 0.7f, 0.7f, 0.7f, 1.0f };
const GLfloat mat_diffuse[] = { 0.8f, 0.8f, 0.8f, 1.0f };
const GLfloat mat_specular[] = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat high_shininess[] = { 100.0f };

// Fungsi mengaktifkan pencahayaan
void lighting(){
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
void init(void){
    glEnable (GL_DEPTH_TEST);
    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
}

int main(int argc, char **argv){
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
    glutInitWindowPosition(100,100);
    glutInitWindowSize(840,680);
    glutCreateWindow("Tesla tabrak tabrak ok gas");
    glutIgnoreKeyRepeat(0); 
    glutSpecialFunc(pressKey);
    glutKeyboardFunc(key);
    glutSpecialUpFunc(releaseKey);
    glutDisplayFunc(display);
    glutIdleFunc(display); 
    glutReshapeFunc(Reshape);
    lighting();
    init();
    glutMainLoop();
    return(0);
}


