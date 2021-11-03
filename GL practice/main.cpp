#define GLEW_STATIC
#pragma comment(lib, "glew32s.lib")

#include <iostream>
#include <gl/glew.h>
#include <gl/glut.h>
using namespace std;

void display()
{
	GLuint abuffer;
	glGenVertexArrays(1, &abuffer);
	glBindVertexArray(abuffer);
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("simple OpenGL example");
	glewInit();
	glutDisplayFunc(display);
	glutMainLoop();
}