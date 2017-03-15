#version 410 core

in vec2				vertex_tex;
in vec4				vertex_color;

uniform sampler2D	tex_tex;
uniform int			var_wiremode;
uniform float		var_color_transition;

out vec4			color;

vec4				alpha_test;
vec4				color_transition;

void main (void)
{
	alpha_test = texture(tex_tex, vertex_tex);
	if (var_wiremode == 0 && alpha_test.a < 0.5f)
			discard;
	color_transition = vertex_color;
	alpha_test.xyzw = alpha_test.xyzw * (1 - var_color_transition);
	color = alpha_test * color_transition;
	color = vertex_color;
	if (var_wiremode == 1)
		color.a = 1.0f;
}
