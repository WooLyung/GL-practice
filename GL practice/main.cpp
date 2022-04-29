#include "pch.h"
#include "GLUTWindow.h"
#include "ShaderProgram.h"
#include "main.h"
#include <math.h>
using namespace std;

GLUTWindow* window;
ShaderProgram* shader;

int n = 40;
GLuint ctm_param = 0;
GLuint pro_param = 0;

float f(float z, float x)
{
	return x / (z * z + 1);
}

void init()
{
	glEnable(GL_DEPTH_TEST);

	GLuint abuffer;
	GLfloat* pos_buffer_data = new GLfloat[n * n * 6 * 4];
	glGenVertexArrays(1, &abuffer);

	GLuint buffer;
	glBindVertexArray(abuffer);
	glGenBuffers(1, &buffer);
	glEnableVertexAttribArray(0);

	for (int x = 0, i = 0; x < n; x++)
	{
		for (int z = 0; z < n; z++, i++)
		{
			float x2 = (float)x / n * 20.0f - 10.0f;
			float z2 = (float)z / n * 20.0f - 10.0f;
			float interval = 20.0f / n;

			pos_buffer_data[i * 24 + 0] = x2;
			pos_buffer_data[i * 24 + 1] = z2;
			pos_buffer_data[i * 24 + 2] = f(x2, z2);
			pos_buffer_data[i * 24 + 3] = 1.0f;
			pos_buffer_data[i * 24 + 4] = x2 + interval;
			pos_buffer_data[i * 24 + 5] = z2;
			pos_buffer_data[i * 24 + 6] = f(x2 + interval, z2);
			pos_buffer_data[i * 24 + 7] = 1.0f;
			pos_buffer_data[i * 24 + 8] = x2;
			pos_buffer_data[i * 24 + 9] = z2 + interval;
			pos_buffer_data[i * 24 + 10] = f(x2, z2 + interval);
			pos_buffer_data[i * 24 + 11] = 1.0f;

			pos_buffer_data[i * 24 + 12] = x2 + interval;
			pos_buffer_data[i * 24 + 13] = z2 + interval;
			pos_buffer_data[i * 24 + 14] = f(x2 + interval, z2 + interval);
			pos_buffer_data[i * 24 + 15] = 1.0f;
			pos_buffer_data[i * 24 + 16] = x2 + interval;
			pos_buffer_data[i * 24 + 17] = z2;
			pos_buffer_data[i * 24 + 18] = f(x2 + interval, z2);
			pos_buffer_data[i * 24 + 19] = 1.0f;
			pos_buffer_data[i * 24 + 20] = x2;
			pos_buffer_data[i * 24 + 21] = z2 + interval;
			pos_buffer_data[i * 24 + 22] = f(x2, z2 + interval);
			pos_buffer_data[i * 24 + 23] = 1.0f;
		}
	}
		
	glBindBuffer(GL_ARRAY_BUFFER, buffer);
	glBufferData(GL_ARRAY_BUFFER, 4 * n * n * 6 * 4, pos_buffer_data, GL_STATIC_DRAW);
	glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, 0, 0);

	ctm_param = glGetUniformLocation(shader->getShaderProgram(), "mv");
	pro_param = glGetUniformLocation(shader->getShaderProgram(), "p");

	delete[] pos_buffer_data;
}

void display()
{
	mat4 l2w = mat4::Translate(0.0f, 0.0f, 0.0f) * mat4::Rotate(0.0f, 0.0f, 0.0f) * mat4::Scale(0.2f, 0.2f, 0.2f);
	mat4 w2c = mat4::Rotate(1.7f, 0.0f, 0.0f) * mat4::Translate(0.0f, -5.0f, 1.0f);
	mat4 frustum = mat4::Frustum(1.0f, 1.0f, 1.0f, 2.0f);
	float* ctm_buffer = (w2c * l2w).ToArray();
	float* pro_buffer = frustum.ToArray();

	glUniformMatrix4fv(ctm_param, 1, GL_TRUE, ctm_buffer);
	glUniformMatrix4fv(pro_param, 1, GL_TRUE, pro_buffer);

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glDrawArrays(GL_TRIANGLES, 0, n * n * 6 * 4);
	glutSwapBuffers();

	free(ctm_buffer);
	free(pro_buffer);
}

void mouseFunc(int button, int state, int x, int y)
{
	if (button == GLUT_MIDDLE_BUTTON && state == GLUT_DOWN)
		exit(0);
}

void idle()
{
	glutPostRedisplay();
}

int main(int argc, char** argv)
{
	window = new GLUTWindow(argc, argv, display);
	shader = new ShaderProgram();

	init();

	glutMouseFunc(mouseFunc);
	glutIdleFunc(idle);

	window->Start();
}