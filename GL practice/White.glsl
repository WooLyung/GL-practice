#version 330 core
        
layout(location = 0) in vec4 aPos;
out vec4 color;
uniform mat4 mv;
uniform mat4 p;
        
void main()
{
	gl_Position = p * mv * aPos;
	color = vec4(1, 1, 1, 1);
}