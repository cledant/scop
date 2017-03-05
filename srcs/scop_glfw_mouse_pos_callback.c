/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scop_glfw_mouse_pos_callback.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/28 18:13:07 by cledant           #+#    #+#             */
/*   Updated: 2017/03/05 14:10:37 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

void	scop_glfw_mouse_pos_callback(GLFWwindow *win, double xpos, double ypos)
{
	t_env			*env;
	static int		first = 0;

	(void)win;
	env = scop_get_env(NULL);
	if (first == 0)
	{
		env->input.last_x = xpos;
		env->input.last_y = ypos;
		first = 1;
	}
	env->input.rot_x += ((xpos - env->input.last_x) * env->input.sensitivity);
	env->input.rot_y += ((ypos - env->input.last_y) * env->input.sensitivity);
	env->input.last_x = xpos;
	env->input.last_y = ypos;
}
