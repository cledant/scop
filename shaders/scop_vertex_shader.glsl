#version 410 core

layout (location = 0) in vec3 pos;
layout (location = 1) in vec3 norm;
layout (location = 2) in vec2 texture;

uniform mat4		proj;
uniform mat4		view;
uniform mat4		model_orig;
uniform mat4		model_rot;
uniform int			tex_origin;

out vec4			vertex_norm;
out vec2			vertex_tex;

void main (void)
{
	gl_Position = proj * view * model_rot  * model_orig *
		vec4(pos.x, pos.y, pos.z, 1.0f);
	vertex_norm = proj * view * model_rot  * model_orig *
		vec4(norm.x, norm.y, norm.z, 1.0f);
	if (tex_origin == 2)
		vertex_tex = vec2(texture.x, 1.0f - texture.y);
	else if (tex_origin == 0)
		vertex_tex = vec2(texture.x, texture.y);
	else if (tex_origin == 3)
		vertex_tex = vec2(1.0f - texture.x, 1.0f - texture.y);
	else if (tex_origin == 1)
		vertex_tex = vec2(1.0f - texture.x, texture.y);
}
