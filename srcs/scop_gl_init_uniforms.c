/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scop_gl_init_uniforms.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/05 14:06:44 by cledant           #+#    #+#             */
/*   Updated: 2017/03/05 15:22:17 by cledant          ###   ########.fr       */
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
	if ((env->uniform.model_orig = glGetUniformLocation(env->shader.shader_prog,
			"model_orig")) == -1)
		return (uniforms_error("model_orig"));
	if ((env->uniform.model_rot = glGetUniformLocation(env->shader.shader_prog,
			"model_rot")) == -1)
		return (uniforms_error("model_rot"));
	if ((env->uniform.proj = glGetUniformLocation(env->shader.shader_prog,
			"proj")) == -1)
		return (uniforms_error("proj"));
	if ((env->uniform.view = glGetUniformLocation(env->shader.shader_prog,
			"view")) == -1)
		return (uniforms_error("view"));
	if ((env->uniform.tex = glGetUniformLocation(env->shader.shader_prog,
			"tex")) == -1)
		return (uniforms_error("tex"));
	if ((env->uniform.tex_origin = glGetUniformLocation(env->shader.shader_prog,
			"tex_origin")) == -1)
		return (uniforms_error("tex_origin"));
	return (1);
}
