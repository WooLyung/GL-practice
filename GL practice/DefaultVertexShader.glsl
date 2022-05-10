#version 330 core
        
layout(location = 0) in vec4 aPos;
layout(location = 1) in vec4 in_color;

out vec4 color;
uniform mat4 m;
uniform mat4 c;
uniform mat4 p;
        
void main()
{
	gl_Position = p * c * m * aPos;
	color = (in_color + vec4(1.0f, 1.0f, 1.0f, 0.0f)) / 2.0f;
}