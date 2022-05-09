#include "GroundMesh.h"

GroundMesh::GroundMesh()
{
	GLfloat* pos_buffer_data = new GLfloat[4 * 4];
	glGenVertexArrays(1, &VAO);
	glBindVertexArray(VAO);

	GLuint buffer;
	glGenBuffers(1, &buffer);
	glEnableVertexAttribArray(0);

	// point #1
	pos_buffer_data[0] = 1.0f;
	pos_buffer_data[1] = 0.0f;
	pos_buffer_data[2] = -1.0f;
	pos_buffer_data[3] = 1.0f;

	// point #2
	pos_buffer_data[4] = 1.0f;
	pos_buffer_data[5] = 0.0f;
	pos_buffer_data[6] = 1.0f;
	pos_buffer_data[7] = 1.0f;

	// point #3
	pos_buffer_data[8] = -1.0f;
	pos_buffer_data[9] = 0.0f;
	pos_buffer_data[10] = -1.0f;
	pos_buffer_data[11] = 1.0f;

	// point #4
	pos_buffer_data[12] = -1.0f;
	pos_buffer_data[13] = 0.0f;
	pos_buffer_data[14] = 1.0f;
	pos_buffer_data[15] = 1.0f;

	glBindBuffer(GL_ARRAY_BUFFER, buffer);
	glBufferData(GL_ARRAY_BUFFER, 4 * 4 * 4, pos_buffer_data, GL_STATIC_DRAW);
	glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, 0, 0);

	delete[] pos_buffer_data;
}

size_t GroundMesh::getVAOcount()
{
	return 1;
}

GLuint* GroundMesh::getVAOs()
{
	return &VAO;
}

void GroundMesh::render(Vector3 loc, Vector3 rot, Vector3 scale)
{
	glBindVertexArray(VAO);
	glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);
}