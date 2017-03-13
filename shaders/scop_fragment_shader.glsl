#version 410 core

in vec2				vertex_tex;

uniform sampler2D	tex_tex;

out vec4	color;

void main (void)
{
	color = texture(tex_tex, vertex_tex);
//	color = vec4(1.0f, 1.0f, 1.0f, 1.0f);
}
