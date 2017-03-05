/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scop_glfw_key_callback.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/27 19:39:39 by cledant           #+#    #+#             */
/*   Updated: 2017/03/05 14:50:40 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

void	scop_glfw_key_callback(GLFWwindow *win, int key, int scancode,
			int action, int mods)
{
	t_env	*env;

	(void)scancode;
	(void)mods;
	env = scop_get_env(NULL);
	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
		glfwSetWindowShouldClose(win, GL_TRUE);
	if (key >= 0 && key < 1024)
	{
		if (action == GLFW_PRESS)
			env->input.p_key[key] = PRESSED;
		else if (action == GLFW_RELEASE)
			env->input.p_key[key] = RELEASED;
	}
}
