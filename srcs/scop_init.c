/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scop_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/23 17:26:38 by cledant           #+#    #+#             */
/*   Updated: 2017/02/23 20:59:13 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

int		scop_init_glfw(t_env *env)
{
	if (!glfwInit())
		return (0);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 1);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	if ((env->win = glfwCreateWindow(env->win_w, env->win_h, "Scop", NULL,
			NULL)) == NULL)
		return (0);
	glfwSetWindowCloseCallback(env->win, scop_close_callback);
	glfwMakeContextCurrent(env->win);
	glViewport(0, 0, env->win_w, env->win_h);
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
	while (!glfwWindowShouldClose(env->win))
	{
		glfwPollEvents();
		glClear(GL_COLOR_BUFFER_BIT);
		glfwSwapBuffers(env->win);
	}
}

int		main(void)
{
	t_env		env;

	glfwSetErrorCallback(scop_error_callback);
	scop_init_env(&env);
	if (scop_init_glfw(&env) == 0)
		return (scop_exit(&env));
	scop_main(&env);	
	return (scop_exit(&env));
}
