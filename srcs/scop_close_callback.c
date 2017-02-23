/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scop_close_callback.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/23 17:28:40 by cledant           #+#    #+#             */
/*   Updated: 2017/02/23 18:39:50 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

void	scop_close_callback(GLFWwindow *win)
{
	glfwSetWindowShouldClose(win, GLFW_TRUE);
}
