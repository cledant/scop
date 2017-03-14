#version 410 core

in vec2				vertex_tex;

uniform sampler2D	tex_tex;
uniform int			var_wiremode;

out vec4	color;

vec4	alpha_test;

void main (void)
{
	alpha_test = texture(tex_tex, vertex_tex);
	if (var_wiremode == 0)
	{
		if (alpha_test.a < 0.5f)
			discard;
		color = alpha_test;
	}
	else
		color = vec4(alpha_test.x, alpha_test.y, alpha_test.z, 1.0f);
}
