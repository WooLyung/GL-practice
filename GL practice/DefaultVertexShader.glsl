#version 330 core
        
layout(location = 0) in vec4 aPos;
out vec4 color;
uniform mat4 m;
uniform mat4 c;
uniform mat4 p;
        
void main()
{
	gl_Position = p * c * m * aPos;
	color = vec4(aPos.x / 20.0f + 0.5f, 0.8f, aPos.y / 20.0f + 0.5f, 1.0f);
}