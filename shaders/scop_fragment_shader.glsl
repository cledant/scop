#version 410 core

in vec3				vertex_color;
in vec2				vertex_tex;

uniform sampler2D	tex;

out vec4	color;

void main (void)
{
	color = vec4(vertex_color, 1.0f) * texture(tex, vertex_tex);
}
