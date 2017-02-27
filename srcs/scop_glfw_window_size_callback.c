/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scop_glfw_window_size_callback.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/27 20:51:23 by cledant           #+#    #+#             */
/*   Updated: 2017/02/27 20:53:59 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

void	scop_glfw_window_size_callback(GLFWwindow *win, int w, int h)
{
	t_env	*env;

	env = (void *)win;
	env = scop_get_env(NULL);
	env->win_h = h;
	env->win_w = w;
}
