/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scop_gl_create_shader_program.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/24 15:49:15 by cledant           #+#    #+#             */
/*   Updated: 2017/02/24 18:32:38 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

int		scop_gl_create_shader_program(t_env *env)
{
	GLint	success;

	if ((env->shader_prog = glCreateProgram()) == 0)
	{
		puts("Scop : OpenGL : Error creating shader program");
		return (0);
	}
	glAttachShader(env->shader_prog, env->vertex_shader);
	glAttachShader(env->shader_prog, env->fragment_shader);
	glLinkProgram(env->shader_prog);
	glGetProgramiv(env->shader_prog, GL_LINK_STATUS, &success);
	if (!success)
	{
		puts("Scop : OpenGL : Error linking shader program");
		return (0);
	}
	return (1);
}
