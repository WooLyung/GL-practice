#include <vector>
#include "SphereMesh2.h"

static int depth = 4;

static void divide(point3 p1, point3 p2, point3 p3, vector<point3>& ps, int d = 0)
{
	if (d == depth)
	{
		ps.push_back(p1);
		ps.push_back(p2);
		ps.push_back(p3);
		return;
	}

	point3 v1, v2, v3;
	v1 = (p1 + p2).normallized();
	v2 = (p1 + p3).normallized();
	v3 = (p2 + p3).normallized();

	divide(p1, v2, v1, ps, d + 1);
	divide(p3, v3, v2, ps, d + 1);
	divide(p2, v1, v3, ps, d + 1);
	divide(v1, v2, v3, ps, d + 1);
}

SphereMesh2::SphereMesh2()
{
	material.ambient = color4(1.0f, 1.0f, 1.0f, 1.0f);

	vector<point3> ps;

	point3 v[4] = { 
		point3(0.0f, 0.0f, 1.0f), 
		point3(0.0f, 0.942809f, -0.333333f),
		point3(-0.816497f, -0.471405f, -0.333333f),
		point3(0.816497f, -0.471405f, -0.333333f)
	};

	divide(v[2], v[1], v[0], ps);
	divide(v[1], v[2], v[3], ps);
	divide(v[1], v[3], v[0], ps);
	divide(v[3], v[2], v[0], ps);

	glGenVertexArrays(1, &VAO);
	glBindVertexArray(VAO);
	vertexs = ps.size();

	GLfloat* pos_buffer_data = new GLfloat[vertexs * 4];

	int i = 0;
	for (auto p : ps)
	{
		pos_buffer_data[i * 4 + 0] = p.x;
		pos_buffer_data[i * 4 + 1] = p.y;
		pos_buffer_data[i * 4 + 2] = p.z;
		pos_buffer_data[i * 4 + 3] = 1.0f;

		i++;
	}

	GLuint posBuffer, colorBuffer;
	glGenBuffers(1, &posBuffer);
	glGenBuffers(1, &colorBuffer);

	glEnableVertexAttribArray(0);
	glEnableVertexAttribArray(1);

	glBindBuffer(GL_ARRAY_BUFFER, posBuffer);
	glBufferData(GL_ARRAY_BUFFER, vertexs * 16, pos_buffer_data, GL_STATIC_DRAW);
	glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, 0, 0);

	glBindBuffer(GL_ARRAY_BUFFER, colorBuffer);
	glBufferData(GL_ARRAY_BUFFER, vertexs * 16, pos_buffer_data, GL_STATIC_DRAW);
	glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, 0, 0);

	delete[] pos_buffer_data;
}

size_t SphereMesh2::getVAOcount()
{
	return 1;
}

GLuint* SphereMesh2::getVAOs()
{
	return &VAO;
}

void SphereMesh2::render(Vector3 loc, Vector3 rot, Vector3 scale)
{
	glBindVertexArray(VAO);
	glDrawArrays(GL_TRIANGLES, 0, vertexs);
}