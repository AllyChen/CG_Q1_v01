#include "main.h"

int main(int argc, char* argv[])
{
	// Create a new window
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH);
	glutInitWindowPosition(100, 100);
	glutInitWindowSize(800, 800);
	glutCreateWindow("Ally_CG_Q1");

	// Register callback functions
	glutReshapeFunc(Reshape);
	glutDisplayFunc(Display);
	//glutIdleFunc(My_Display);
	glutTimerFunc(10, Time, 0);

	Init();

	// Entering main loop
	glutMainLoop();

}

void Init()
{
	// Setup background color
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

	// Enable depth testing
	glEnable(GL_DEPTH_TEST);

	// Disable lighting
	glDisable(GL_LIGHTING);

}

void Reshape(int w, int h)
{
	GLfloat aspectRatio = (GLfloat)w / (GLfloat)h;

	// Prevent a divide by zero
	if (h == 0)
		h = 1;

	// Set viewport to window dimensions
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45.0f, aspectRatio, 0.1f, 100.0f);
	glTranslatef(0.0f, 0.0f, -2.0f);
	//glOrtho(-1.0, 1.0, -1.0, 1.0, -10, 10);
	glMatrixMode(GL_MODELVIEW);

}

void Display()
{
	// Clear the window with current clearing color 
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glPushMatrix();
	glRotatef(angle, 0, 0, 1);
	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	// Draw space
		DrawHexagram();
		DrawCircle();
	glPopMatrix();

	

	// Flush drawing commands
	glutSwapBuffers();
}

void Time(int t)
{
	glutTimerFunc(10, Time, 0);
	angle ++;
	glutPostRedisplay();
}

void DrawHexagram()
{
	float color = int(angle) % 50;
	printf("color :  %f \n", color);

	// Draw a triangle
	glBegin(GL_TRIANGLES);
	glColor3ub(255, 255, color * 200);
	glVertex3fv(point1);
	glColor3ub(255, 255, color * 200);
	glVertex3fv(point2);
	glColor3ub(255, 255, color * 200);
	glVertex3fv(point3);
	glEnd();

	// Draw a triangle
	glBegin(GL_TRIANGLES);
	glColor3ub(255, 255, color * 200);
	glVertex3fv(point4);
	glColor3ub(255, 255, color * 200);
	glVertex3fv(point5);
	glColor3ub(255, 255, color * 200);
	glVertex3fv(point6);
	glEnd();
}

void DrawCircle() {
	
	glBegin(GL_POINTS);
	for (int i = 0; i < n; ++i) 
		glVertex2f(0.5f * cos(2 * Pi / n*i), 0.5f * sin(2 * Pi / n*i));	
	glEnd();
	
	glBegin(GL_POINTS);
	for (int i = 0; i < n; ++i)
		glVertex2f(0.7f * cos(2 * Pi / n*i), 0.7f * sin(2 * Pi / n*i));
	glEnd();

}
