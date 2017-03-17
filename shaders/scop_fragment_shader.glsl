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
	color_transition = vertex_color;
	if (var_color_transition == 0.0f)
		color = color_transition;
	else if (var_color_transition == 1.0f)
	{
		color = alpha_test;
		if (var_wiremode == 0 && alpha_test.a < 0.5f)
			discard;
	}
	else
	{
		color = alpha_test * var_color_transition +
			color_transition * (1 - var_color_transition);
	}
	if (var_wiremode == 1)
		color.a = 1.0f;
}
