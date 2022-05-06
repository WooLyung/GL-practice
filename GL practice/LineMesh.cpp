#include "LineMesh.h"

LineMesh::LineMesh()
{
	GLfloat* pos_buffer_data = new GLfloat[41 * 4];
	glGenVertexArrays(41 * 2, VAO);

	for (int x0 = -20; x0 <= 20; x0++)
	{
		GLuint buffer;

		glBindVertexArray(VAO[x0 + 20]);
		glGenBuffers(1, &buffer);
		glEnableVertexAttribArray(0);

		for (int z0 = -20, i = 0; z0 <= 20; z0++, i++)
		{
			float x = x0 * 0.5f;
			float z = z0 * 0.5f;
			float y = z / (x * x + 1);

			pos_buffer_data[i * 4] = x;
			pos_buffer_data[i * 4 + 1] = z;
			pos_buffer_data[i * 4 + 2] = y;
			pos_buffer_data[i * 4 + 3] = 1.0f;
		}

		glBindBuffer(GL_ARRAY_BUFFER, buffer);
		glBufferData(GL_ARRAY_BUFFER, 41 * 4 * 4, pos_buffer_data, GL_STATIC_DRAW);
		glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, 0, 0);

		glBindVertexArray(VAO[x0 + 20 + 41]);
		glGenBuffers(1, &buffer);
		glEnableVertexAttribArray(0);

		for (int z0 = -20, i = 0; z0 <= 20; z0++, i++)
		{
			float x = x0 * 0.5f;
			float z = z0 * 0.5f;
			float y = x / (z * z + 1);

			pos_buffer_data[i * 4] = z;
			pos_buffer_data[i * 4 + 1] = x;
			pos_buffer_data[i * 4 + 2] = y;
			pos_buffer_data[i * 4 + 3] = 1.0f;
		}

		glBindBuffer(GL_ARRAY_BUFFER, buffer);
		glBufferData(GL_ARRAY_BUFFER, 41 * 4 * 4, pos_buffer_data, GL_STATIC_DRAW);
		glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, 0, 0);
	}

	delete[] pos_buffer_data;
}

GLuint* LineMesh::getVAOs()
{
	return VAO;
}

size_t LineMesh::getVAOcount()
{
	return 41 * 2;
}

void LineMesh::render()
{
	for (int i = 0; i < 41 * 2; i++)
	{
		glBindVertexArray(VAO[i]);
		glDrawArrays(GL_LINE_STRIP, 0, 41);
	}
}