#version 410 core

layout (location = 0) in vec3 pos;
layout (location = 1) in vec3 color;
layout (location = 2) in vec2 texture;

uniform mat4	proj;
uniform mat4	view;
uniform mat4	model;

out vec3		vertex_color;
out vec2		vertex_tex;

void main (void)
{
	gl_Position = proj * view * model * vec4(pos.x, pos.y, pos.z, 1.0f);
	vertex_color = color;
	vertex_tex = vec2(texture.x, 1.0f - texture.y);
}
