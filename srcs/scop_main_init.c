/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scop_main_init.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/16 17:39:50 by cledant           #+#    #+#             */
/*   Updated: 2017/03/16 17:43:37 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

void					scop_main_init(t_env *env)
{
	glUseProgram(env->shader.shader_prog);
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	glEnable(GL_DEPTH_TEST);
	scop_gl_init_vao(env);
	scop_mat4_set_translation(&(env->matrix.model_orig), env->obj.center);
	glUniformMatrix4fv(env->uniform.mat_model_orig, 1, GL_TRUE,
		(GLfloat *)&(env->matrix.model_orig));
}
