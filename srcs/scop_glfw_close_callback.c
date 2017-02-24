/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scop_glfw_close_callback.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/23 17:28:40 by cledant           #+#    #+#             */
/*   Updated: 2017/02/24 12:56:29 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

void	scop_glfw_close_callback(GLFWwindow *win)
{
	glfwSetWindowShouldClose(win, GLFW_TRUE);
}
