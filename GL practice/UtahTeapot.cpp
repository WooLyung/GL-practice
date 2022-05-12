#include "UtahTeapot.h"

UtahTeapot::UtahTeapot()
{
	glGenVertexArrays(1, &VAO);
	glBindVertexArray(VAO);
	
	GLfloat pos_buffer_data[306][4];

	FILE* fp = fopen("utah.txt", "r");
	int num;
	GLfloat x, y, z;

	while (fscanf(fp, "%d %f %f %f", &num, &x, &y, &z) != EOF)
	{
		pos_buffer_data[num - 1][0] = x;
		pos_buffer_data[num - 1][1] = y;
		pos_buffer_data[num - 1][2] = z;
		pos_buffer_data[num - 1][3] = 1.0f;
	}

	fclose(fp);

	GLuint posBuffer;
	glGenBuffers(1, &posBuffer);

	glEnableVertexAttribArray(0);

	glBindBuffer(GL_ARRAY_BUFFER, posBuffer);
	glBufferData(GL_ARRAY_BUFFER, sizeof(pos_buffer_data), pos_buffer_data, GL_STATIC_DRAW);
	glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, 0, 0);
}

size_t UtahTeapot::getVAOcount()
{
	return 1;
}

GLuint* UtahTeapot::getVAOs()
{
	return &VAO;
}

void UtahTeapot::render(Vector3, Vector3, Vector3)
{
	glBindVertexArray(VAO);
	glDrawArrays(GL_POINTS, 0, 306);
}