#version 410 core

in vec2				vertex_tex;

uniform sampler2D	tex;

out vec4	color;

void main (void)
{
	color = texture(tex, vertex_tex);
}
