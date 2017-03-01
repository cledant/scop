/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scop_glfw_mouse_pos_callback.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/28 18:13:07 by cledant           #+#    #+#             */
/*   Updated: 2017/03/01 11:10:49 by cledant          ###   ########.fr       */
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
		env->last_x = xpos;
		env->last_y = ypos;
		first = 1;
	}
	env->rot_x += ((xpos - env->last_x) * env->sensitivity);
	env->rot_y += ((ypos - env->last_y) * env->sensitivity);
	env->last_x = xpos;
	env->last_y = ypos;
}
