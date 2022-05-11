#include "SphereMesh.h"

static int n = 32;

SphereMesh::SphereMesh()
{
	VAO = new GLuint[n];
	glGenVertexArrays(n, VAO);

	// top
	{
		GLfloat* pos_buffer_data = new GLfloat[n * 8 + 8];
		glBindVertexArray(VAO[0]);

		// center
		pos_buffer_data[0] = 0.0f;
		pos_buffer_data[1] = 1.0f;
		pos_buffer_data[2] = 0.0f;
		pos_buffer_data[3] = 1.0f;

		float y = cosf(PI / n);
		float r = sinf(PI / n);
		for (int i = 0; i < 2 * n + 1; i++)
		{
			float angle = PI / n * i;
			pos_buffer_data[i * 4 + 4] = cosf(angle) * r;
			pos_buffer_data[i * 4 + 5] = y;
			pos_buffer_data[i * 4 + 6] = sinf(angle) * r;
			pos_buffer_data[i * 4 + 7] = 1.0f;
		}

		GLuint posBuffer, colorBuffer;
		glGenBuffers(1, &posBuffer);
		glGenBuffers(1, &colorBuffer);

		glEnableVertexAttribArray(0);
		glEnableVertexAttribArray(1);

		glBindBuffer(GL_ARRAY_BUFFER, posBuffer);
		glBufferData(GL_ARRAY_BUFFER, (n * 8 + 8) * 4, pos_buffer_data, GL_STATIC_DRAW);
		glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, 0, 0);

		glBindBuffer(GL_ARRAY_BUFFER, colorBuffer);
		glBufferData(GL_ARRAY_BUFFER, (n * 8 + 8) * 4, pos_buffer_data, GL_STATIC_DRAW);
		glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, 0, 0);

		delete[] pos_buffer_data;
	}

	// bottom
	{
		GLfloat* pos_buffer_data = new GLfloat[n * 8 + 8];
		glBindVertexArray(VAO[n - 1]);

		// center
		pos_buffer_data[0] = 0.0f;
		pos_buffer_data[1] = -1.0f;
		pos_buffer_data[2] = 0.0f;
		pos_buffer_data[3] = 1.0f;

		float y = -cosf(PI / n);
		float r = sinf(PI / n);
		for (int i = 0; i < 2 * n + 1; i++)
		{
			float angle = PI / n * i;
			pos_buffer_data[i * 4 + 4] = cosf(angle) * r;
			pos_buffer_data[i * 4 + 5] = y;
			pos_buffer_data[i * 4 + 6] = sinf(angle) * r;
			pos_buffer_data[i * 4 + 7] = 1.0f;
		}

		GLuint posBuffer, colorBuffer;
		glGenBuffers(1, &posBuffer);
		glGenBuffers(1, &colorBuffer);

		glEnableVertexAttribArray(0);
		glEnableVertexAttribArray(1);

		glBindBuffer(GL_ARRAY_BUFFER, posBuffer);
		glBufferData(GL_ARRAY_BUFFER, (n * 8 + 8) * 4, pos_buffer_data, GL_STATIC_DRAW);
		glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, 0, 0);

		glBindBuffer(GL_ARRAY_BUFFER, colorBuffer);
		glBufferData(GL_ARRAY_BUFFER, (n * 8 + 8) * 4, pos_buffer_data, GL_STATIC_DRAW);
		glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, 0, 0);

		delete[] pos_buffer_data;
	}

	// middle
	{
		for (int m = 1; m < n - 1; m++)
		{
			GLfloat* pos_buffer_data = new GLfloat[n * 16 + 8];
			glBindVertexArray(VAO[m]);

			float y = cosf(PI / n * m);
			float y2 = cosf(PI / n * (m + 1));

			float r = sinf(PI / n * m);
			float r2 = sinf(PI / n * (m + 1));

			for (int i = 0; i < 2 * n + 1; i++)
			{
				float angle = PI / n * i;

				pos_buffer_data[i * 8 + 0] = cosf(angle) * r;
				pos_buffer_data[i * 8 + 1] = y;
				pos_buffer_data[i * 8 + 2] = sinf(angle) * r;
				pos_buffer_data[i * 8 + 3] = 1.0f;

				pos_buffer_data[i * 8 + 4] = cosf(angle) * r2;
				pos_buffer_data[i * 8 + 5] = y2;
				pos_buffer_data[i * 8 + 6] = sinf(angle) * r2;
				pos_buffer_data[i * 8 + 7] = 1.0f;
			}

			GLuint posBuffer, colorBuffer;
			glGenBuffers(1, &posBuffer);
			glGenBuffers(1, &colorBuffer);

			glEnableVertexAttribArray(0);
			glEnableVertexAttribArray(1);

			glBindBuffer(GL_ARRAY_BUFFER, posBuffer);
			glBufferData(GL_ARRAY_BUFFER, (n * 16 + 8) * 4, pos_buffer_data, GL_STATIC_DRAW);
			glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, 0, 0);

			glBindBuffer(GL_ARRAY_BUFFER, colorBuffer);
			glBufferData(GL_ARRAY_BUFFER, (n * 16 + 8) * 4, pos_buffer_data, GL_STATIC_DRAW);
			glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, 0, 0);

			delete[] pos_buffer_data;
		}
	}
}

size_t SphereMesh::getVAOcount()
{
	return n;
}

GLuint* SphereMesh::getVAOs()
{
	return VAO;
}

void SphereMesh::render(Vector3 loc, Vector3 rot, Vector3 scale)
{
	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	glCullFace(GL_BACK);

	glBindVertexArray(VAO[0]);
	glDrawArrays(GL_TRIANGLE_FAN, 0, 2 * n + 2);

	glBindVertexArray(VAO[n - 1]);
	glDrawArrays(GL_TRIANGLE_FAN, 0, 2 * n + 2);

	for (int i = 1; i < n - 1; i++)
	{
		glBindVertexArray(VAO[i]);
		glDrawArrays(GL_TRIANGLE_STRIP, 0, 4 * n + 2);
	}
}

SphereMesh::~SphereMesh()
{
	delete[] VAO;
}