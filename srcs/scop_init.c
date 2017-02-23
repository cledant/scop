/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scop_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/23 17:26:38 by cledant           #+#    #+#             */
/*   Updated: 2017/02/23 18:52:52 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

int		scop_init_glfw(t_env *env)
{
	int		w;
	int		h;

	if (!glfwInit())
		return (0);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 1);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	if ((env->win = glfwCreateWindow(e->win_w, e->win_h, "Scop", NULL, NULL))
			== NULL)
		return (0);
	if (glfwSetWindowCloseCallback(win, scop_close_callback) == NULL)
		return (0);
	glfwMakeContextCurrent(win);
	glfwGetFramebufferSize(win, &w, &h);
	glViewport(0, 0, w, h);
	return (1);
}

void	scop_init_env(t_env *env)
{
	env->win = NULL;
	env->win_h = 720;
	env->win_w = 1280;
}

void	scop_main(t_env *env)
{
	glClearColor(0.2f, 0.3f, 0.3f, 0.1f);
	glClear(GL_COLOR_BUFFER_BIT);
	while (!glfwWindowShouldClose(e->win))
	{
		glfwPollEvents();
		glClear(GL_COLOR_BUFFER_BIT);
		glfwSwapBuffers(e->win);
	}
}

int		main(void)
{
	t_env		env;
	t_err		err;

	if ((glfwSetErrorCallback(scop_error_callback)) == NULL)
	{
		puts("Error setting error callback");
		return (0);
	}
	scop_init_env(&env);
	if ((err = scop_init_glfw(&env)) != ERR_NONE)
		return (scop_exit(&env));
	scop_main(&env);	
	return (scop_exit(&env));
}
