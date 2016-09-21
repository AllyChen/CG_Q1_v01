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
	glRotatef(angle, 0, 1, 0);	
	glPolygonMode(GL_FRONT, GL_LINE);
	glPolygonMode(GL_BACK, GL_FILL);
	// Draw space
		DrawHexagram();
		DrawCircle();
		DrawMoon(0.6, 0);
		DrawMoon(0.45, 0.4);
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

	// Draw a triangle
	glBegin(GL_TRIANGLES);
	glColor3ub(255, 255, color * 200);
	for (int i = 0; i < 6; i += 2)
		glVertex3f(0.25 * cos(2 * Pi / 6 * i), 0.25 * sin(2 * Pi / 6 * i), 0.0f);
	glEnd();

	// Draw a triangle
	glBegin(GL_TRIANGLES);
	glColor3ub(255, 255, color * 200);
	for (int i = 1; i < 6; i+=2)
		glVertex3f(0.25 * cos(2 * Pi / 6 * i), 0.25 * sin(2 * Pi / 6 * i), 0.0f);
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

void DrawMoon(float x, float y) {

	float color = int(angle) % 50;

	glEnable(GL_DEPTH_TEST);

	glBegin(GL_POLYGON);
	glColor3ub(0, 0, 0);
	for (int i = 0; i < n; ++i)
		glVertex3f(0.06f * cos(2 * Pi / n*i) + x, 0.06f * sin(2 * Pi / n*i) + y + 0.05, 0.f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(255, 255, color * 200);
	for (int i = 0; i < n; ++i)
		glVertex3f(0.1f * cos(2 * Pi / n*i) + x, 0.1f * sin(2 * Pi / n*i) + y, 0.001f);
	glEnd();

	
}
