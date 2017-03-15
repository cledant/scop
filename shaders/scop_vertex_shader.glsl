#version 410 core

layout (location = 0) in vec3 pos;
layout (location = 1) in vec3 norm;
layout (location = 2) in vec2 texture;
layout (location = 3) in vec4 color;

uniform mat4		mat_proj;
uniform mat4		mat_view;
uniform mat4		mat_model_orig;
uniform mat4		mat_model_auto_rot;
uniform mat4		mat_model_rot_phi;
uniform mat4		mat_model_rot_theta;
uniform mat4		mat_model_tr;
uniform mat4		mat_scale;
uniform int			var_tex_origin;

out vec4			vertex_norm;
out vec2			vertex_tex;
out	vec4			vertex_color;

void main (void)
{
	gl_Position = mat_proj * mat_view * mat_model_tr * mat_model_rot_theta *
		mat_model_rot_phi  * mat_model_auto_rot * mat_scale *
		mat_model_orig * vec4(pos.x, pos.y, pos.z, 1.0f);
	vertex_norm = mat_proj * mat_view * mat_model_tr  * mat_model_rot_theta *
		mat_model_rot_phi  * mat_model_auto_rot * mat_model_orig *
		vec4(norm.x, norm.y, norm.z, 1.0f);
	if (var_tex_origin == 2)
		vertex_tex = vec2(texture.x, 1.0f - texture.y);
	else if (var_tex_origin == 0)
		vertex_tex = vec2(texture.x, texture.y);
	else if (var_tex_origin == 3)
		vertex_tex = vec2(1.0f - texture.x, 1.0f - texture.y);
	else if (var_tex_origin == 1)
		vertex_tex = vec2(1.0f - texture.x, texture.y);
	vertex_color = color;
}
