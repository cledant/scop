/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scop_glfw_init.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/05 13:29:18 by cledant           #+#    #+#             */
/*   Updated: 2017/03/05 14:33:29 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

int		scop_glfw_init(t_env *env)
{
	if (!glfwInit())
		return (0);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 1);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	if ((env->win.win = glfwCreateWindow(env->win.win_w, env->win.win_h,
			"Scop", NULL, NULL)) == NULL)
		return (0);
	glfwSetWindowCloseCallback(env->win.win, scop_glfw_close_callback);
	glfwMakeContextCurrent(env->win.win);
	glfwSetInputMode(env->win.win, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
	return (1);
}
