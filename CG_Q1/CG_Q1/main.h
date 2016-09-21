#include <iostream>
#include <glut.h>

void Init();
void Reshape(int w, int h);
void Display();
void DrawHexagram();
void DrawCircle();
void DrawMoon(float x, float y);
void Time(int t);

GLfloat point1[] = { 0.0, 0.4, 0.0 };
GLfloat point2[] = { 0.3, -0.2, 0.0 };
GLfloat point3[] = { -0.3, -0.2, 0.0 };
GLfloat point4[] = { 0.0, -0.4, 0.0 };
GLfloat point5[] = { -0.3, 0.2, 0.0 };
GLfloat point6[] = { 0.3, 0.2, 0.0 };

const int n = 10000;
float Pi = 3.1415f;
float angle = 0;
