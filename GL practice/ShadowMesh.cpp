#include "ShadowMesh.h"
#include "ShaderManager.h"
#include "Shader.h"

vec3 light(2.0f, 2.0f, 2.0f);

static float f(float z, float x)
{
	return x / (z * z + 1);
}

ShadowMesh::ShadowMesh(int n)
{
	Shader* shader = ShaderManager::getInstance()->getShader("shadow");
	light_param = glGetUniformLocation(shader->getProgram(), "light");

	this->n = n;

	GLfloat* pos_buffer_data = new GLfloat[n * n * 6 * 4];
	glGenVertexArrays(1, &VAO);

	GLuint buffer;
	glBindVertexArray(VAO);
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

	delete[] pos_buffer_data;
}

GLuint* ShadowMesh::getVAOs()
{
	return &VAO;
}

size_t ShadowMesh::getVAOcount()
{
	return 1;
}

void ShadowMesh::render(Vector3 loc, Vector3 rot, Vector3 scale)
{
	float light_buffer[3] = { light.x, light.y, light.z };
	glUniform3fv(light_param, 1, light_buffer);

	glBindVertexArray(VAO);
	glDrawArrays(GL_TRIANGLES, 0, n * n * 6 * 4);
}