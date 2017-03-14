#version 410 core

in vec2				vertex_tex;

uniform sampler2D	tex_tex;

out vec4	color;

vec4	alpha_test;

void main (void)
{
	alpha_test = texture(tex_tex, vertex_tex);
	if (alpha_test.a < 0.5)
		discard;
	color = alpha_test;
//	color = vec4(1.0f, 1.0f, 1.0f, 1.0f);
}
