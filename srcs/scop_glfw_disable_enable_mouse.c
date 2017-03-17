/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scop_glfw_disable_enable_mouse.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/17 14:38:13 by cledant           #+#    #+#             */
/*   Updated: 2017/03/17 15:49:42 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

void		scop_glfw_disable_enable_mouse(t_env *env)
{
	env->input.toggle_mouse = (env->input.toggle_mouse == 1) ? 0 : 1;
	(env->input.toggle_mouse == 1) ? glfwSetInputMode(env->win.win,
		GLFW_CURSOR, GLFW_CURSOR_DISABLED) : glfwSetInputMode(env->win.win,
		GLFW_CURSOR, GLFW_CURSOR_NORMAL);
	env->input.timer = 0.0f;
}
