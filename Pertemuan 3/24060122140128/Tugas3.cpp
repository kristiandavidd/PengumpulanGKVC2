//	Nama         : Rahman Hanif
//	NIM		     : 24060122140128
//	Deskripsi    : Membentuk tangan dan lengan dengan jari tangan



#include <gl/glut.h>

static int  bahu = 0,
siku = 0,
telapak = 0,
jariTelunjuk1 = 0,
jariTelunjuk2 = 0,
jariTengah1 = 0,
jariTengah2 = 0,
jariManis1 = 0,
jariManis2 = 0,
jariKecil1 = 0,
jariKecil2 = 0,
ibuJari = 0;
static float sudutKamera = 0.0f;
static float posisiKameraZ = -5.0f;

void inisialisasi(void) {
	GLfloat posisiCahaya[] = { 1.0, 1.0, 1.0, 0.0 };
	GLfloat kulitAmbien[] = { 0.89, 0.77, 0.6, 1.0 };  
	GLfloat kulitDifus[] = { 0.89, 0.77, 0.6, 1.0 };  
	GLfloat kulitSpekular[] = { 0.7, 0.7, 0.7, 1.0 };   
	GLfloat tanpaPancaran[] = { 0.0, 0.0, 0.0, 1.0 };

	glClearColor(0.255, 0.243, 0.199, 0.0);
	glShadeModel(GL_FLAT);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glLightfv(GL_LIGHT0, GL_POSITION, posisiCahaya);
	glMaterialfv(GL_FRONT, GL_AMBIENT, kulitAmbien);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, kulitDifus);
	glMaterialfv(GL_FRONT, GL_SPECULAR, kulitSpekular);
	glMaterialfv(GL_FRONT, GL_EMISSION, tanpaPancaran);
	glMaterialf(GL_FRONT, GL_SHININESS, 50.0);
}


void display(void) {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glPushMatrix();

	glTranslatef(0.0f, 0.0f, posisiKameraZ);
	glRotatef(sudutKamera, 0.0f, 1.0f, 0.0f);


	glPushMatrix();
	glTranslatef(-1.0, 0.0, 0.0);
	glRotatef((GLfloat)bahu, 0.0, 0.0, 1.0);
	glTranslatef(1.0, 0.0, 0.0);


	glPushMatrix();
	glScalef(2.0, 0.4, 1.0);
	glutWireCube(1.0);
	glPopMatrix();


	glTranslatef(1.0, 0.0, 0.0);
	glRotatef((GLfloat)siku, 0.0, 0.0, 1.0);
	glTranslatef(1.0, 0.0, 0.0);

	glPushMatrix();
	glScalef(2.0, 0.4, 1.0);
	glutWireCube(1.0);
	glPopMatrix();


	glTranslatef(1.0, 0.0, 0.0);
	glRotatef((GLfloat)telapak, 0.0, 0.0, 1.0);
	glTranslatef(0.5, 0.0, 0.0);

	glPushMatrix();
	glScalef(1.0, 0.4, 1.0);
	glutWireCube(1.0);
	glPopMatrix();


	glPushMatrix();
	glTranslatef(0.5, 0.0, 0.4);
	glRotatef((GLfloat)jariTelunjuk1, 0.0, 0.0, 1.0);
	glTranslatef(0.25, 0.0, 0.0);

	glPushMatrix();
	glScalef(0.5, 0.2, 0.20);
	glutWireCube(1.0);
	glPopMatrix();
	//Jari Telunjuk 2
	glTranslatef(0.25, 0.0, 0.0);
	glRotatef((GLfloat)jariTelunjuk2, 0.0, 0.0, 1.0);
	glTranslatef(0.25, 0.0, 0.0);

	glPushMatrix();
	glScalef(0.5, 0.2, 0.20);
	glutWireCube(1.0);
	glPopMatrix();
	glPopMatrix();

	//Jari Tengah 1
	glPushMatrix();
	glTranslatef(0.5, 0.0, 0.15);
	glRotatef((GLfloat)jariTengah1, 0.0, 0.0, 1.0);
	glTranslatef(0.25, 0.0, 0.0);

	glPushMatrix();
	glScalef(0.5, 0.2, 0.20);
	glutWireCube(1.0);
	glPopMatrix();
	//Jari Tengah 2
	glTranslatef(0.25, 0.0, 0.0);
	glRotatef((GLfloat)jariTengah2, 0.0, 0.0, 1.0);
	glTranslatef(0.25, 0.0, 0.0);

	glPushMatrix();
	glScalef(0.5, 0.2, 0.20);
	glutWireCube(1.0);
	glPopMatrix();
	glPopMatrix();
	//Jari Manis 1
	glPushMatrix();
	glTranslatef(0.5, 0.0, -0.1);
	glRotatef((GLfloat)jariManis1, 0.0, 0.0, 1.0);
	glTranslatef(0.25, 0.0, 0.0);

	glPushMatrix();
	glScalef(0.5, 0.2, 0.20);
	glutWireCube(1.0);
	glPopMatrix();
	//Jari Manis 2
	glTranslatef(0.25, 0.0, 0.0);
	glRotatef((GLfloat)jariManis2, 0.0, 0.0, 1.0);
	glTranslatef(0.25, 0.0, 0.0);

	glPushMatrix();
	glScalef(0.5, 0.2, 0.20);
	glutWireCube(1.0);
	glPopMatrix();
	glPopMatrix();
	//Jari Kecil 1
	glPushMatrix();
	glTranslatef(0.5, 0.0, -0.4);
	glRotatef((GLfloat)jariKecil1, 0.0, 0.0, 1.0);
	glTranslatef(0.25, 0.0, 0.0);

	glPushMatrix();
	glScalef(0.5, 0.2, 0.20);
	glutWireCube(1.0);
	glPopMatrix();
	//Jari Kecil 2
	glTranslatef(0.25, 0.0, 0.0);
	glRotatef((GLfloat)jariKecil2, 0.0, 0.0, 1.0);
	glTranslatef(0.25, 0.0, 0.0);

	glPushMatrix();
	glScalef(0.5, 0.2, 0.20);
	glutWireCube(1.0);
	glPopMatrix();
	glPopMatrix();
	//Ibu Jari
	glPushMatrix();
	glTranslatef(0.2, 0.0, 0.4);
	glRotatef((GLfloat)ibuJari, -1.0, 0.0, 0.0);
	glTranslatef(0.0, 0.0, 0.25);

	glPushMatrix();
	glScalef(0.2, 0.2, 0.50);
	glutWireCube(1.0);
	glPopMatrix();
	glPopMatrix();
	glPopMatrix();

	glPopMatrix(); // Selesai menggambar lengan
	glPopMatrix(); // Selesai rotasi kamera

	glutSwapBuffers();
}

void reshape(int w, int h) {
	glViewport(0, 0, (GLsizei)w, (GLsizei)h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(65.0, (GLfloat)w / (GLfloat)h, 1.0, 20.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

void kunciKeyboard(unsigned char tombol, int x, int y) {
	switch (tombol) {
	case 'a': bahu = (bahu + 5) % 360;
		glutPostRedisplay();
		break;
	case 'A': bahu = (bahu - 5) % 360;
		glutPostRedisplay();
		break;
	case 's': siku = (siku + 5) % 360;
		glutPostRedisplay();
		break;
	case 'S': siku = (siku - 5) % 360;
		glutPostRedisplay();
		break;
	case 'd': telapak = (telapak + 5) % 360;
		glutPostRedisplay();
		break;
	case 'D': telapak = (telapak - 5) % 360;
		glutPostRedisplay();
		break;
	case 'h': jariTelunjuk1 = (jariTelunjuk1 + 5) % 360;
		glutPostRedisplay();
		break;
	case 'H': jariTelunjuk1 = (jariTelunjuk1 - 5) % 360;
		glutPostRedisplay();
		break;
	case 'y': jariTelunjuk2 = (jariTelunjuk2 + 5) % 360;
		glutPostRedisplay();
		break;
	case 'Y': jariTelunjuk2 = (jariTelunjuk2 - 5) % 360;
		glutPostRedisplay();
		break;
	case 'j': jariTengah1 = (jariTengah1 + 5) % 360;
		glutPostRedisplay();
		break;
	case 'J': jariTengah1 = (jariTengah1 - 5) % 360;
		glutPostRedisplay();
		break;
	case 'u': jariTengah2 = (jariTengah2 + 5) % 360;
		glutPostRedisplay();
		break;
	case 'U': jariTengah2 = (jariTengah2 - 5) % 360;
		glutPostRedisplay();
		break;
	case 'k': jariManis1 = (jariManis1 + 5) % 360;
		glutPostRedisplay();
		break;
	case 'K': jariManis1 = (jariManis1 - 5) % 360;
		glutPostRedisplay();
		break;
	case 'i': jariManis2 = (jariManis2 + 5) % 360;
		glutPostRedisplay();
		break;
	case 'I': jariManis2 = (jariManis2 - 5) % 360;
		glutPostRedisplay();
		break;
	case 'l': jariKecil1 = (jariKecil1 + 5) % 360;
		glutPostRedisplay();
		break;
	case 'L': jariKecil1 = (jariKecil1 - 5) % 360;
		glutPostRedisplay();
		break;
	case 'o': jariKecil2 = (jariKecil2 + 5) % 360;
		glutPostRedisplay();
		break;
	case 'O': jariKecil2 = (jariKecil2 - 5) % 360;
		glutPostRedisplay();
		break;
	case 'w': ibuJari = (ibuJari + 5) % 360;
		glutPostRedisplay();
		break;
	case 'W': ibuJari = (ibuJari - 5) % 360;
		glutPostRedisplay();
		break;
	case 27: exit(0);
		break;
	default: break;
	}
}

void kunciSpecial(int tombol, int x, int y) {
	switch (tombol) {
	case GLUT_KEY_LEFT:
		sudutKamera += 5.0f;
		glutPostRedisplay();
		break;
	case GLUT_KEY_RIGHT:
		sudutKamera -= 5.0f;
		glutPostRedisplay();
		break;
	case GLUT_KEY_UP:
		posisiKameraZ += 0.5f;
		glutPostRedisplay();
		break;
	case GLUT_KEY_DOWN:
		posisiKameraZ -= 0.5f;
		glutPostRedisplay();
		break;
	}
}

int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(800, 600);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("Tangan dan Lengan Dinamis");
	inisialisasi();

	glEnable(GL_DEPTH_TEST);

	glutDisplayFunc(display);
	glColor3ub(255, 243, 199);
	glutReshapeFunc(reshape);
	glutKeyboardFunc(kunciKeyboard);
	glutSpecialFunc(kunciSpecial);

	glutMainLoop();
	return 0;
}

