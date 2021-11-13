#include "pch.h"
#include "GLUTWindow.h"
#include "ShaderProgram.h"
#include <vector>
#include <array>
using namespace std;

#define LEVEL 5
int cnt;
float a = 0.08f;

int addPoint(const vector<array<float, 2>>& points, vector<float>& pos_data, vector<float>& color_data, vector<int>& weight, int sum, int max)
{
	if (weight.size() == points.size())
	{
		int n = weight.size();

		float x = 0.0f, y = 0.0f;
		for (int i = 0; i < weight.size(); i++)
		{
			x += points[i][0] * (((float)weight[i] / max - a) / (1 - a * n));
			y += points[i][1] * (((float)weight[i] / max - a) / (1 - a * n));
		}
		pos_data.push_back(x);
		pos_data.push_back(y);
		pos_data.push_back(0.0f);
		color_data.push_back(x);
		color_data.push_back(y);
		color_data.push_back(0.9f);

		x = 0.0f, y = 0.0f;
		for (int i = 0; i < weight.size(); i++)
		{
			x += points[i][0] * ((float)weight[i] / max);
			y += points[i][1] * ((float)weight[i] / max);
		}
		pos_data.push_back(x);
		pos_data.push_back(y);
		pos_data.push_back(0.0f);
		color_data.push_back(1 - x);
		color_data.push_back(1 - y);
		color_data.push_back(0.1f);

		return 6;
	}
	
	int s = 0;
	for (int i = 0; i <= max - sum; i++)
	{
		weight.push_back(i);
		s += addPoint(points, pos_data, color_data, weight, sum + i, max);
		weight.pop_back();
	}
	return s;
}

void init()
{
	glEnable(GL_DEPTH_TEST);

	GLuint abuffer;
	glGenVertexArrays(1, &abuffer);
	glBindVertexArray(abuffer);

	vector<array<float, 2>> points = { { 0.35f * 0.5f + 0.5f, -0.35f * 0.5f + 0.5f }, {0.0f * 0.5f + 0.5f, 0.6f * 0.5f + 0.5f }, {0.5f * 0.5f + 0.5f, 0.2f * 0.5f + 0.5f}, {-0.5f * 0.5f + 0.5f, 0.2f * 0.5f + 0.5f} };
	vector<float> pos_data, color_data;
	vector<int> weight;
	cnt = addPoint(points, pos_data, color_data, weight, 0, 20);
	GLfloat* pos_buffer_data = new GLfloat[cnt];
	GLfloat* color_buffer_data = new GLfloat[cnt];

	mat4 mat = mat4(
		5, 8, 4, 9,
		7, 2, 9, 6,
		6, 5, 0, 11,
		1, 2, 3, 4
	);
	mat = mat * mat * mat;
	vec4 vec = vec4(1, 2, 3, 4) * mat;
	cout << vec.x << ", " << vec.y << ", " << vec.z << ", " << vec.w << endl;

	for (int i = 0; i < cnt; i++)
	{
		pos_buffer_data[i] = pos_data[i];
		color_buffer_data[i] = color_data[i];
	}

	GLuint* buffer = new GLuint[2];
	glGenBuffers(2, buffer);

	glBindBuffer(GL_ARRAY_BUFFER, buffer[0]);
	glBufferData(GL_ARRAY_BUFFER, 4 * cnt, pos_buffer_data, GL_STATIC_DRAW);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);
	glEnableVertexAttribArray(0);

	glBindBuffer(GL_ARRAY_BUFFER, buffer[1]);
	glBufferData(GL_ARRAY_BUFFER, 4 * cnt, color_buffer_data, GL_STATIC_DRAW);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 0, 0);
	glEnableVertexAttribArray(1);
}

void display()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glDrawArrays(GL_POINTS, 0, cnt);
	glutSwapBuffers();
}

void mouseFunc(int button, int state, int x, int y)
{
	if (button == GLUT_MIDDLE_BUTTON && state == GLUT_DOWN)
		exit(0);
}

int main(int argc, char** argv)
{
	GLUTWindow* window = new GLUTWindow(argc, argv, display);
	ShaderProgram* shader = new ShaderProgram();

	glutMouseFunc(mouseFunc);

	init();
	window->Start();
}