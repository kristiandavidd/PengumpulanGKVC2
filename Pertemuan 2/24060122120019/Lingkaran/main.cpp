#include <GL/glut.h>
#include <math.h>

void Lingkaran(void){	// Membuat lingkaran 

	glClear(GL_COLOR_BUFFER_BIT);
		
		glBegin(GL_LINE_LOOP);
		
			GLint circle_points = 100;
			
			int i;
			float radius;
			#define PI 3.1415926535898
			
		    // Vertex lingkaran
		    for (int i = 0; i < circle_points; ++i) {
		        radius = 2 * PI * i / circle_points;
		        glVertex2f(cos(radius), sin(radius));
		    }
			
		glEnd();
	
	glFlush();
	
}

int main(int argc, char* argv[]){	// Main program
	
	glutInit(&argc, argv);
	glutInitWindowSize(640, 640);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
	
	glutCreateWindow("Lingkaran");
	glutDisplayFunc(Lingkaran);
	glClearColor(0.0f, 0.0f, 1.0f, 1.0f);
	
	glutMainLoop();
	
	return 0;
}

