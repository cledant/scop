/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/23 12:37:43 by cledant           #+#    #+#             */
/*   Updated: 2017/02/23 15:16:45 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

void	test_fct(GLFWwindow *win)
{
	glfwSetWindowShouldClose(win, GLFW_TRUE);
}

int		main(void)
{
	GLFWwindow	*win;
	int			h;
	int			w;

	if (!glfwInit())
	{
		printf("GLFW INIT FAILED !\n");
		return (0);
	}
	printf("Init OK !\n");
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 1);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	if ((win = glfwCreateWindow(1280, 720, "This is Test!", NULL, NULL)) == NULL)
	{
		printf("WINDOW CREATION FAILED !\n");
		glfwTerminate();
		return (0);
	}
	glfwSetWindowCloseCallback(win, test_fct);
	glfwMakeContextCurrent(win);
	glfwGetFramebufferSize(win, &w, &h);
	glViewport(0, 0, w, h);
	while (!glfwWindowShouldClose(win))
	{
		glfwPollEvents();
		glClearColor(0.2f, 0.3f, 0.3f, 0.1f);
		glClear(GL_COLOR_BUFFER_BIT);
		glfwSwapBuffers(win);
	}
	glfwDestroyWindow(win);
	glfwTerminate();
	return (0);
}
