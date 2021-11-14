#include "pch.h"
#include "GLUTWindow.h"
#include "ShaderProgram.h"
#include <vector>
#include <array>
#include "main.h"
using namespace std;

GLuint buffer[2];
color4 quad_colors[36];
point4 quad_vertices[36];
int i = 0;

void quad(int a, int b, int c, int d, const point4* vertices, const color4* colors)
{
	quad_colors[i] = colors[a];
	quad_vertices[i] = vertices[a];
	i++;
	quad_colors[i] = colors[b];
	quad_vertices[i] = vertices[b];
	i++;
	quad_colors[i] = colors[c];
	quad_vertices[i] = vertices[c];
	i++;
	quad_colors[i] = colors[a];
	quad_vertices[i] = vertices[a];
	i++;
	quad_colors[i] = colors[c];
	quad_vertices[i] = vertices[c];
	i++;
	quad_colors[i] = colors[d];
	quad_vertices[i] = vertices[d];
	i++;
}

void init()
{
	glEnable(GL_DEPTH_TEST);

	GLuint abuffer;
	glGenVertexArrays(1, &abuffer);
	glBindVertexArray(abuffer);
	glGenBuffers(2, buffer);
	glEnableVertexAttribArray(0);
	glEnableVertexAttribArray(1);

	point4 vertices[8] = {
		point4(-1.0f, -1.0f, -1.0f, 1.0f), point4(1.0f, -1.0f, -1.0f, 1.0f),
		point4(1.0f, 1.0f, -1.0f, 1.0f), point4(-1.0f, 1.0f, -1.0f, 1.0f),
		point4(-1.0f, -1.0f, 1.0f, 1.0f), point4(1.0f, -1.0f, 1.0f, 1.0f),
		point4(1.0f, 1.0f, 1.0f, 1.0f), point4(-1.0f, 1.0f, 1.0f, 1.0f),
	};
	color4 colors[8] = {
		color4(0.0f, 0.0f, 0.0f, 1.0f),
		color4(0.0f, 0.0f, 1.0f, 1.0f),
		color4(0.0f, 1.0f, 0.0f, 1.0f),
		color4(0.0f, 1.0f, 1.0f, 1.0f),
		color4(1.0f, 0.0f, 0.0f, 1.0f),
		color4(1.0f, 0.0f, 1.0f, 1.0f),
		color4(1.0f, 1.0f, 0.0f, 1.0f),
		color4(1.0f, 1.0f, 1.0f, 1.0f)
	};

	quad(0, 3, 2, 1, vertices, colors);
	quad(2, 3, 7, 6, vertices, colors);
	quad(3, 0, 4, 7, vertices, colors);
	quad(1, 2, 6, 5, vertices, colors);
	quad(4, 5, 6, 7, vertices, colors);
	quad(5, 4, 0, 1, vertices, colors);
}

void render()
{
	GLfloat* pos_buffer_data = new GLfloat[144];
	GLfloat* color_buffer_data = new GLfloat[144];

	static vec3 angle = vec3::zero;
	angle += vec3(0.01f, 0.02f, 0.03f);

	mat4 rotX = mat4(
		1, 0, 0, 0,
		0, cos(angle.x), -sin(angle.x), 0,
		0, sin(angle.x), cos(angle.x), 0,
		0, 0, 0, 1
	);
	mat4 rotY = mat4(
		cos(angle.y), -sin(angle.y), 0, 0,
		sin(angle.y), cos(angle.y), 0, 0,
		0, 0, 1, 0,
		0, 0, 0, 1
	);
	mat4 rotZ = mat4(
		cos(angle.z), 0, sin(angle.z), 0,
		0, 1, 0, 0,
		-sin(angle.z), 0, cos(angle.z), 0,
		0, 0, 0, 1
	);

	for (int i = 0; i < 36; i++)
	{
		vec4 v = quad_vertices[i] * rotX * rotY * rotZ;

		pos_buffer_data[i * 4] = v.x;
		pos_buffer_data[i * 4 + 1] = v.y;
		pos_buffer_data[i * 4 + 2] = v.z;
		pos_buffer_data[i * 4 + 3] = v.w;
		color_buffer_data[i * 4] = quad_colors[i].x;
		color_buffer_data[i * 4 + 1] = quad_colors[i].y;
		color_buffer_data[i * 4 + 2] = quad_colors[i].z;
		color_buffer_data[i * 4 + 3] = quad_colors[i].w;
	}

	glBindBuffer(GL_ARRAY_BUFFER, buffer[0]);
	glBufferData(GL_ARRAY_BUFFER, 4 * 144, pos_buffer_data, GL_STATIC_DRAW);
	glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, 0, 0);

	glBindBuffer(GL_ARRAY_BUFFER, buffer[1]);
	glBufferData(GL_ARRAY_BUFFER, 4 * 144, color_buffer_data, GL_STATIC_DRAW);
	glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, 0, 0);

	delete[] pos_buffer_data;
	delete[] color_buffer_data;
}

void display()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glDrawArrays(GL_TRIANGLES, 0, 144);
	glutSwapBuffers();
}

void mouseFunc(int button, int state, int x, int y)
{
	if (button == GLUT_MIDDLE_BUTTON && state == GLUT_DOWN)
		exit(0);
}

void idle()
{
	render();
	glutPostRedisplay();
}

int main(int argc, char** argv)
{
	GLUTWindow* window = new GLUTWindow(argc, argv, display);
	ShaderProgram* shader = new ShaderProgram();

	init();
	render();

	glutMouseFunc(mouseFunc);
	glutIdleFunc(idle);

	window->Start();
}