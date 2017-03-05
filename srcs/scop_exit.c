/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scop_exit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/05 14:40:21 by cledant           #+#    #+#             */
/*   Updated: 2017/03/05 14:40:24 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

int		scop_exit(t_env *env)
{
	if (env->win.win != NULL)
		glfwDestroyWindow(env->win.win);
	glfwTerminate();
	return (0);
}
