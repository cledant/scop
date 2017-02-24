/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scop_gl_create_shader_program.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/24 15:49:15 by cledant           #+#    #+#             */
/*   Updated: 2017/02/24 16:09:16 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

int		scop_gl_create_shader_program(t_env *env)
{
	GLint	success;

	if ((env->shader_prog = glCreateProgram()) == 0)
		return (0);
	glAttachShader(env->shader_prog, env->vertex_shader);
	glAttachShader(env->shader_prog, env->vertex_shader);
	glLinkProgram(env->shader_prog);
	glGetProgramiv(env->shader_prog, GL_LINK_STATUS, &success);
	if (!success)
		return (0);
	return (1);
}
