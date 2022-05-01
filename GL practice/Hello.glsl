#version 330 core
        
layout(location = 0) in vec4 aPos;
out vec4 color;
uniform mat4 mv;
uniform mat4 p;
        
void main()
{
	gl_Position = p * mv * aPos;
	color = vec4(aPos.x / 20.0f + 0.5f, aPos.y / 20.0f + 0.5f, 0.8f, 1.0f);
}