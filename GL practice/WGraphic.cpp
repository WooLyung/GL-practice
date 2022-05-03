#include "pch.h"
#include "WGraphic.h"
#include "Object.h"
#include "ShaderManager.h"
#include "MeshManager.h"
#include "TestMesh.h"

void WGraphic::shaderInit()
{
	camera->location = vec3(0.0f, -5.0f, 1.0f);
	camera->rotation = vec3(1.7f, 0.0f, 0.0f);
	camera->scale = vec3(1.0f, 1.0f, 1.0f);

	ShaderManager::getInstance()->addShader("default", "DefaultVertexShader.glsl", "DefaultFragmentShader.glsl");
	ShaderManager::getInstance()->addShader("hello", "Hello.glsl", "DefaultFragmentShader.glsl");
	MeshManager::getInstance()->addMesh("test", new TestMesh(20));
}

void WGraphic::init(WObjects* objects)
{
	shaderInit();

	this->objects = objects;

	glEnable(GL_DEPTH_TEST);
}

void WGraphic::render()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	for (Object* obj : objects->objects)
	{
		mat4 l2w = mat4::Translate(obj->location.x, obj->location.y, obj->location.z) * mat4::Rotate(obj->rotation.x, obj->rotation.y, obj->rotation.z) * mat4::Scale(obj->scale.x, obj->scale.y, obj->scale.z);
		mat4 w2c = mat4::Rotate(camera->rotation.x, camera->rotation.y, camera->rotation.z) * mat4::Translate(camera->location.x, camera->location.y, camera->location.z);
		mat4 frustum = mat4::Frustum(1.0f * camera->scale.x, 1.0f * camera->scale.y, 1.0f * camera->scale.z, 2.0f * camera->scale.z);

		float* ctm_buffer = (w2c * l2w).ToArray();
		float* pro_buffer = frustum.ToArray();
	
		glUniformMatrix4fv(obj->shader->getCTMparam(), 1, GL_TRUE, ctm_buffer);
		glUniformMatrix4fv(obj->shader->getPROparam(), 1, GL_TRUE, pro_buffer);
		glUseProgram(obj->shader->getProgram());

		obj->mesh->render();

		free(ctm_buffer);
		free(pro_buffer);
	}

	glutSwapBuffers();
}

void WGraphic::idle()
{
	glutPostRedisplay();
}