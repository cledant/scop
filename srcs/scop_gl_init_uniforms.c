/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scop_gl_init_uniforms.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/05 14:06:44 by cledant           #+#    #+#             */
/*   Updated: 2017/03/13 17:27:25 by cledant          ###   ########.fr       */
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
	if ((env->uniform.mat_model_rot = glGetUniformLocation(
			env->shader.shader_prog, "mat_model_rot")) == -1)
		return (uniforms_error("mat_model_rot"));
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
	return (1);
}
