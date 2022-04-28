#include "pch.h"
#include "GLUTWindow.h"
#include "ShaderProgram.h"
#include "main.h"
#include <math.h>
using namespace std;

GLUTWindow* window;
ShaderProgram* shader;

GLuint abuffer[21];
GLuint abuffer2[21];
GLuint ctm_param = 0;
GLuint pro_param = 0;

float f(float z, float x)
{
	return x / (z * z + 1);
}

void init()
{
	glEnable(GL_DEPTH_TEST);

	GLfloat* pos_buffer_data = new GLfloat[84];
	glGenVertexArrays(21, abuffer);
	glGenVertexArrays(21, abuffer2);

	for (int x = -10; x <= 10; x++)
	{
		GLuint buffer;

		glBindVertexArray(abuffer[x + 10]);
		glGenBuffers(1, &buffer);
		glEnableVertexAttribArray(0);

		for (int z = -10, i = 0; z <= 10; z++, i++)
		{
			float y = f(x, z);

			pos_buffer_data[i * 4] = x;
			pos_buffer_data[i * 4 + 1] = z;
			pos_buffer_data[i * 4 + 2] = y;
			pos_buffer_data[i * 4 + 3] = 1.0f;
		}
		
		glBindBuffer(GL_ARRAY_BUFFER, buffer);
		glBufferData(GL_ARRAY_BUFFER, 4 * 84, pos_buffer_data, GL_STATIC_DRAW);
		glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, 0, 0);


		glBindVertexArray(abuffer2[x + 10]);
		glGenBuffers(1, &buffer);
		glEnableVertexAttribArray(0);

		for (int z = -10, i = 0; z <= 10; z++, i++)
		{
			float y = f(z, x);

			pos_buffer_data[i * 4] = z;
			pos_buffer_data[i * 4 + 1] = x;
			pos_buffer_data[i * 4 + 2] = y;
			pos_buffer_data[i * 4 + 3] = 1.0f;
		}

		glBindBuffer(GL_ARRAY_BUFFER, buffer);
		glBufferData(GL_ARRAY_BUFFER, 4 * 84, pos_buffer_data, GL_STATIC_DRAW);
		glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, 0, 0);
	}

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
	for (int i = 0; i <= 21; i++)
	{
		glBindVertexArray(abuffer[i]);
		glDrawArrays(GL_LINE_STRIP, 0, 21);
		glBindVertexArray(abuffer2[i]);
		glDrawArrays(GL_LINE_STRIP, 0, 21);
	}
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