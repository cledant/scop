/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scop_gl_init_uniforms.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/05 14:06:44 by cledant           #+#    #+#             */
/*   Updated: 2017/03/15 10:33:26 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

static inline int	uniforms_error(char *name)
{
	printf("Scop : GL : Could not get info about this variable : %s\n",
		name);
	return (0);
}

int					scop_gl_init_uniforms(t_env *env)
{
	if ((env->uniform.mat_model_orig = glGetUniformLocation(
			env->shader.shader_prog, "mat_model_orig")) == -1)
		return (uniforms_error("mat_model_orig"));
	if ((env->uniform.mat_model_auto_rot = glGetUniformLocation(
			env->shader.shader_prog, "mat_model_auto_rot")) == -1)
		return (uniforms_error("mat_model_auto_rot"));
	if ((env->uniform.mat_model_rot_phi = glGetUniformLocation(
			env->shader.shader_prog, "mat_model_rot_phi")) == -1)
		return (uniforms_error("mat_model_rot_phi"));
	if ((env->uniform.mat_model_rot_theta = glGetUniformLocation(
			env->shader.shader_prog, "mat_model_rot_theta")) == -1)
		return (uniforms_error("mat_model_rot_theta"));
	if ((env->uniform.mat_model_tr = glGetUniformLocation(
			env->shader.shader_prog, "mat_model_tr")) == -1)
		return (uniforms_error("mat_model_tr"));
	if ((env->uniform.mat_proj = glGetUniformLocation(
			env->shader.shader_prog, "mat_proj")) == -1)
		return (uniforms_error("mat_proj"));
	if ((env->uniform.mat_view = glGetUniformLocation(
			env->shader.shader_prog, "mat_view")) == -1)
		return (uniforms_error("mat_view"));
	if ((env->uniform.mat_scale = glGetUniformLocation(
			env->shader.shader_prog, "mat_scale")) == -1)
		return (uniforms_error("mat_scale"));
	if ((env->uniform.tex_tex = glGetUniformLocation(
			env->shader.shader_prog, "tex_tex")) == -1)
		return (uniforms_error("tex_tex"));
	if ((env->uniform.var_tex_origin = glGetUniformLocation(
			env->shader.shader_prog, "var_tex_origin")) == -1)
		return (uniforms_error("var_tex_origin"));
	if ((env->uniform.var_wiremode = glGetUniformLocation(
			env->shader.shader_prog, "var_wiremode")) == -1)
		return (uniforms_error("var_wiremode"));
	if ((env->uniform.var_color_transition = glGetUniformLocation(
			env->shader.shader_prog, "var_color_transition")) == -1)
		return (uniforms_error("var_color_transition"));
	return (1);
}
