#include "pch.h"
#include "WGraphic.h"
#include "Object.h"
#include "ShaderManager.h"
#include "MeshManager.h"
#include "SphereMesh2.h"

void WGraphic::update()
{
}

void WGraphic::shaderInit()
{
	camera->location = vec3(0.0f, 0.0f, -3.0f);
	camera->rotation = vec3(0.0f, 0.0f, 0.0f);
	camera->scale = vec3(0.5f, 0.5f, 1.0f);

	ShaderManager::getInstance()->addShader("default", "DefaultVertexShader.glsl", "DefaultFragmentShader.glsl");
	MeshManager::getInstance()->addMesh("sphere", new SphereMesh2());
}

void WGraphic::init(WObjects* objects)
{
	shaderInit();

	this->objects = objects;

	glEnable(GL_DEPTH_TEST);
	glEnable(GL_POLYGON_OFFSET_FILL);
	glEnable(GL_CULL_FACE);

	glPolygonOffset(1.0f, 1.0f);
}

void WGraphic::render()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

	for (Object* obj : objects->objects)
	{
		mat4 l2w = mat4::Translate(obj->location.x, obj->location.y, obj->location.z) * mat4::Rotate(obj->rotation.x, obj->rotation.y, obj->rotation.z) * mat4::Scale(obj->scale.x, obj->scale.y, obj->scale.z);
		mat4 w2c = mat4::Rotate(camera->rotation.x, camera->rotation.y, camera->rotation.z) * mat4::Translate(camera->location.x, camera->location.y, camera->location.z);
		mat4 frustum = mat4::Frustum(1.0f * camera->scale.x, 1.0f * camera->scale.y, 1.0f * camera->scale.z, 2.0f * camera->scale.z);

		float* m_buffer = l2w.ToArray();
		float* c_buffer = w2c.ToArray();
		float* pro_buffer = frustum.ToArray();
	
		glUseProgram(obj->shader->getProgram());
		glUniformMatrix4fv(obj->shader->getCparam(), 1, GL_TRUE, c_buffer);
		glUniformMatrix4fv(obj->shader->getMparam(), 1, GL_TRUE, m_buffer);
		glUniformMatrix4fv(obj->shader->getPROparam(), 1, GL_TRUE, pro_buffer);

		obj->mesh->render(obj->location, obj->rotation, obj->scale);

		free(c_buffer);
		free(m_buffer);
		free(pro_buffer);
	}

	glutSwapBuffers();
}

void WGraphic::idle()
{
	glutPostRedisplay();
}