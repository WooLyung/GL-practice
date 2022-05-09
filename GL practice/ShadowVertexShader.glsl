#version 330 core
        
layout(location = 0) in vec4 aPos;
uniform vec3 light;
uniform mat4 m;
uniform mat4 c;
uniform mat4 p;
        
void main()
{
    vec4 pos = m * aPos;
    pos = vec4(pos.x,
            0.2f,
            pos.z,
            pos.w);
	gl_Position = p * pos;
}