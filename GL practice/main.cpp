#define GLEW_STATIC
#pragma comment(lib, "glew32s.lib")
#include <gl/glew.h>
#include <gl/glut.h>
#include <math.h>
#include <iostream>
using namespace std;

#define LEVEL 7
GLfloat* pos_buffer_data = nullptr;
int index = 0;

void addTriangle(float x1, float y1, float x2, float y2, float x3, float y3, int level)
{
	if (level == LEVEL)
	{
		pos_buffer_data[index * 9] = x1;
		pos_buffer_data[index * 9 + 1] = y1;
		pos_buffer_data[index * 9 + 2] = 0.0f;
		pos_buffer_data[index * 9 + 3] = x2;
		pos_buffer_data[index * 9 + 4] = y2;
		pos_buffer_data[index * 9 + 5] = 0.0f;
		pos_buffer_data[index * 9 + 6] = x3;
		pos_buffer_data[index * 9 + 7] = y3;
		pos_buffer_data[index * 9 + 8] = 0.0f;
		index++;
		return;
	}

	addTriangle(x1, y1, (x1 + x2) * 0.5f, (y1 + y2) * 0.5f, (x1 + x3) * 0.5f, (y1 + y3) * 0.5f, level + 1);
	addTriangle(x2, y2, (x1 + x2) * 0.5f, (y1 + y2) * 0.5f, (x2 + x3) * 0.5f, (y2 + y3) * 0.5f, level + 1);
	addTriangle(x3, y3, (x3 + x2) * 0.5f, (y3 + y2) * 0.5f, (x1 + x3) * 0.5f, (y1 + y3) * 0.5f, level + 1);
}

void init()
{
	GLuint abuffer;
	glGenVertexArrays(1, &abuffer);
	glBindVertexArray(abuffer);

	pos_buffer_data = new GLfloat[pow(3, LEVEL + 1)];
	addTriangle(-1.0f, -1.0f, 1.0f, -1.0f, 0.0f, 1.0f, 1);

	GLuint buffer;
	glGenBuffers(1, &buffer);

	glBindBuffer(GL_ARRAY_BUFFER, buffer);
	glBufferData(GL_ARRAY_BUFFER, sizeof(GLfloat) * pow(3, LEVEL + 1), pos_buffer_data, GL_STATIC_DRAW);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);
}

void display()
{
	glClear(GL_COLOR_BUFFER_BIT);

	glEnableVertexAttribArray(0);
	glDrawArrays(GL_TRIANGLES, 0, pow(3, LEVEL + 1));
	glDisableVertexAttribArray(0);

	glFlush();
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("simple OpenGL example");
	glewInit();
	init();
	glutDisplayFunc(display);
	glutMainLoop();
}