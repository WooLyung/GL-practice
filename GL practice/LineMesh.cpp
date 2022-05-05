#include "LineMesh.h"

LineMesh::LineMesh()
{
	GLfloat* pos_buffer_data = new GLfloat[84];
	glGenVertexArrays(42, VAO);

	for (int x = -10; x <= 10; x++)
	{
		GLuint buffer;

		glBindVertexArray(VAO[x + 10]);
		glGenBuffers(1, &buffer);
		glEnableVertexAttribArray(0);

		for (int z = -10, i = 0; z <= 10; z++, i++)
		{
			float y = (float)z / (x * x + 1);

			pos_buffer_data[i * 4] = x;
			pos_buffer_data[i * 4 + 1] = z;
			pos_buffer_data[i * 4 + 2] = y;
			pos_buffer_data[i * 4 + 3] = 1.0f;
		}

		glBindBuffer(GL_ARRAY_BUFFER, buffer);
		glBufferData(GL_ARRAY_BUFFER, 4 * 84, pos_buffer_data, GL_STATIC_DRAW);
		glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, 0, 0);


		glBindVertexArray(VAO[x + 31]);
		glGenBuffers(1, &buffer);
		glEnableVertexAttribArray(0);

		for (int z = -10, i = 0; z <= 10; z++, i++)
		{
			float y = (float)x / (z * z + 1);

			pos_buffer_data[i * 4] = z;
			pos_buffer_data[i * 4 + 1] = x;
			pos_buffer_data[i * 4 + 2] = y;
			pos_buffer_data[i * 4 + 3] = 1.0f;
		}

		glBindBuffer(GL_ARRAY_BUFFER, buffer);
		glBufferData(GL_ARRAY_BUFFER, 4 * 84, pos_buffer_data, GL_STATIC_DRAW);
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
	return 42;
}

void LineMesh::render()
{
	for (int i = 0; i < 42; i++)
	{
		glBindVertexArray(VAO[i]);
		glDrawArrays(GL_LINE_STRIP, 0, 21);
	}
}