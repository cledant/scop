/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scop_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/23 17:26:38 by cledant           #+#    #+#             */
/*   Updated: 2017/02/27 12:30:16 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

int		scop_glfw_init(t_env *env)
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
	glfwSetWindowCloseCallback(env->win, scop_glfw_close_callback);
	glfwMakeContextCurrent(env->win);
	glViewport(0, 0, env->win_w, env->win_h);
	return (1);
}

void	scop_init_env(t_env *env)
{
	env->win = NULL;
	env->win_h = 1000;
	env->win_w = 1000;
	env->vbo = 0;
	env->vao = 0;
	env->ebo = 0;
	env->shader_prog = 0;
	env->vertex_shader = 0;
	env->fragment_shader = 0;
}

void	scop_test_vertex_init(t_env	*env)
{
	GLfloat vertices[] = {
		0.5f, 0.5f, 0.5f, 1.0f, 0.0f, 0.0f,
		0.5f, -0.5f, 0.5f, 0.0f, 1.0f, 0.0f,
		-0.5f, -0.5f, 0.5f, 0.0f, 0.0f, 1.0f,
		-0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f,
		0.5f, 0.5f, -0.5f, 0.0f, 0.0f, 1.0f,
		0.5f, -0.5f, -0.5f, 0.0f, 1.0f, 0.0f,
		-0.5f, -0.5f, -0.5f, 1.0f, 0.0f, 0.0f,
		-0.5f, 0.5f, -0.5f, 0.5f, 0.5f, 0.5f
	};
	GLuint indices[] = {
		0, 1, 3,
		1, 2, 3,
		0, 1, 5,
		0, 5, 4,
		2, 1, 6,
		1, 6, 5,
		2, 3, 6,
		3, 7, 6,
		0, 3, 7,
		0, 4, 7,
		7, 4, 6,
		4, 5, 6
	};
	t_mat4	model;
	t_mat4	view;
	t_mat4	proj;
	//Tout return du void !
	//Init
	glGenBuffers(1, &(env->vbo));  //nbr obj ds buffer
	glGenVertexArrays(1, &(env->vao));
	glGenBuffers(1, &(env->ebo));
	//Matrix init
	scop_mat4_init(&model);
	scop_mat4_init(&view);
	scop_mat4_init(&proj);
	//Matrix set value
	scop_mat4_set_translation(&view, (t_vec3){0.0f, 0.0f, -3.0f});
	scop_mat4_set_perspective(&proj, (t_vec4){45.0f,
		(GLfloat)env->win_w / (GLfloat)env->win_h, 0.1f, 100.0f});
	//Attrib
	glBindVertexArray(env->vao);
	glBindBuffer(GL_ARRAY_BUFFER, env->vbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, env->ebo);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (GLvoid *)0);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float),
		(GLvoid *)(3 * sizeof(GLfloat)));
	glEnableVertexAttribArray(1);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);
}

void	debug_state(void)
{
	GLenum		err;

	err = glGetError();
	if (err == GL_NO_ERROR)
		printf("No error\n");
	else if (err == GL_INVALID_ENUM)
		printf("Invalid enum\n");
	else if (err == GL_INVALID_VALUE)
		printf("Invalid value\n");
	else if (err == GL_INVALID_VALUE)
		printf("Invalid value\n");
	else if (err == GL_INVALID_OPERATION)
		printf("Invalid operation\n");
	else if (err == GL_INVALID_FRAMEBUFFER_OPERATION)
		printf("Invalid framebuffer operation\n");
	else if (err == GL_OUT_OF_MEMORY)
		printf("Out of memory\n");
	else if (err == GL_STACK_UNDERFLOW)
		printf("Stack Underflow\n");
	else if (err == GL_STACK_OVERFLOW)
		printf("Stack Overflow\n");
}

void	scop_main(t_env *env)
{
	scop_test_vertex_init(env);
	while (!glfwWindowShouldClose(env->win))
	{
		glfwPollEvents();
		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);
		glUseProgram(env->shader_prog);
		glBindVertexArray(env->vao);
		glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
		glBindVertexArray(0);
		glfwSwapBuffers(env->win);
	}
}


int		scop_gl_init_shaders(t_env *env)
{
	if (scop_gl_load_shader(&(env->vertex_shader), GL_VERTEX_SHADER,
			"./shaders/scop_vertex_shader.glsl") == 0)
		return (0);
	if (scop_gl_load_shader(&(env->fragment_shader), GL_FRAGMENT_SHADER,
			"./shaders/scop_fragment_shader.glsl") == 0)
		return (0);
	if (scop_gl_create_shader_program(env) == 0)
		return (0);
	return (1);
}


int		main(void)
{
	t_env		env;

	glfwSetErrorCallback(scop_glfw_error_callback);
	scop_init_env(&env);
	if (scop_glfw_init(&env) == 0)
		return (scop_exit(&env));
	if (scop_gl_init_shaders(&env) == 0)
		return (scop_exit(&env));
	scop_main(&env);
	return (scop_exit(&env));
}
