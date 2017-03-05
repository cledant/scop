/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scop_gl_init_shaders.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/05 13:35:22 by cledant           #+#    #+#             */
/*   Updated: 2017/03/05 13:43:54 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

int		scop_gl_init_shaders(t_env *env)
{
	if (scop_gl_load_shader(&(env->shader.vertex_shader), GL_VERTEX_SHADER,
			"./shaders/scop_vertex_shader.glsl") == 0)
		return (0);
	if (scop_gl_load_shader(&(env->shader.fragment_shader), GL_FRAGMENT_SHADER,
			"./shaders/scop_fragment_shader.glsl") == 0)
		return (0);
	if (scop_gl_create_shader_program(env) == 0)
		return (0);
	return (1);
}
