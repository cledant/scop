/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scop_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/23 17:26:38 by cledant           #+#    #+#             */
/*   Updated: 2017/02/28 13:37:20 by cledant          ###   ########.fr       */
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
	return (1);
}

void	scop_init_env(t_env *env)
{
	env->win = NULL;
	env->win_h = 1000;
	env->win_w = 1000;
	env->fov = 90.0f;
	env->vbo = 0;
	env->vao = 0;
	env->ebo = 0;
	env->shader_prog = 0;
	env->vertex_shader = 0;
	env->fragment_shader = 0;
	env->m_proj = -1;
	env->m_model = -1;
	env->m_view = -1;
	bzero(env->p_key, sizeof(int) * 1024);
	env->cam_speed = 0.01f;
}

void	scop_test_vertex_init(t_env	*env)
{
	GLfloat vertices[] = {
		0.5f, 0.5f, 0.5f, 1.0f, 0.0f, 0.0f,
		0.5f, -0.5f, 0.5f, 0.0f, 1.0f, 0.0f,
		-0.5f, -0.5f, 0.5f, 0.0f, 0.0f, 1.0f,
		-0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f,
		0.5f, 0.5f, -0.5f, 0.0f, 0.0f, 1.0f,
		0.5f, -0.5f, -0.5f, 0.0f, 0.5f, 0.5f,
		-0.5f, -0.5f, -0.5f, 0.5f, 0.0f, 0.5f,
		-0.5f, 0.5f, -0.5f, 0.5f, 0.5f, 0.0f
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
	//Tout return du void !
	//Init
	glGenBuffers(1, &(env->vbo));  //nbr obj ds buffer
	glGenVertexArrays(1, &(env->vao));
	glGenBuffers(1, &(env->ebo));
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
	t_vec3	cube_pos[10] = {
		(t_vec3){0.0f, 0.0f, 0.0f},
		(t_vec3){2.0f, 5.0f, -15.0f},
		(t_vec3){-1.5f, -2.2f, -2.5f},
		(t_vec3){-3.8f, -2.0f, -12.3f},
		(t_vec3){2.4f, -0.4f, -3.5f},
		(t_vec3){-1.7f, 3.0f, -7.5f},
		(t_vec3){1.3f, -2.0f, -2.5f},
		(t_vec3){1.5f, 2.0f, -2.5f},
		(t_vec3){1.5f, 0.2f, -1.5f},
		(t_vec3){-1.3f, 1.0f, -1.5f}};
	size_t	counter;

	glUseProgram(env->shader_prog);
	scop_test_vertex_init(env);
	glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
	//Matrix set value
	//Note secondaire : Calculer barycentrei de l obj + translater orig + ... + retour au centre ?
	scop_mat4_set_perspective(&(env->proj), (t_vec4){env->fov,
		(GLfloat)env->win_w / (GLfloat)env->win_h, 0.1f, 100.0f});
	scop_mat4_init(&(env->view));
	//Matrix Bind values
	while (!glfwWindowShouldClose(env->win))
	{
		counter = 0;
		glfwPollEvents();
		scop_execute_mov(env);
		scop_update_camera(env);
		scop_mat4_update_perspective(&(env->proj), (t_vec4){env->fov,
			(GLfloat)env->win_w / (GLfloat)env->win_h, 0.1f, 100.0f});
		glUniformMatrix4fv(env->m_view, 1, GL_TRUE, (GLfloat *)&(env->view));
		glUniformMatrix4fv(env->m_proj, 1, GL_TRUE, (GLfloat *)&(env->proj));
		//Draw vertex
		glBindVertexArray(env->vao);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		while (counter < 10)
		{
			scop_mat4_set_translation(&(env->model), cube_pos[counter]);
			glUniformMatrix4fv(env->m_model, 1, GL_TRUE, (GLfloat *)&(env->model));
			glDrawElements(GL_TRIANGLES, 3 * 12, GL_UNSIGNED_INT, 0);
			counter++;
		}
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

int		scop_gl_init_matrix(t_env *env)
{
	if ((env->m_model = glGetUniformLocation(env->shader_prog, "model")) == -1)
		return (0);
	if ((env->m_proj = glGetUniformLocation(env->shader_prog, "proj")) == -1)
		return (0);
	if ((env->m_view = glGetUniformLocation(env->shader_prog, "view")) == -1)
		return (0);
	return (1);
}

void	scop_vector_init(t_env *env)
{
	scop_vec3_set(&(env->cam_pos), 0.0f, 0.0f, 2.0f);
	scop_vec3_set(&(env->cam_target), 0.0f, 0.0f, 0.0f);
	scop_vec3_set(&(env->up_vec), 0.0f, 1.0f, 0.0f);
	scop_vec3_set(&(env->cam_dir), 0.0f, 0.0f, 0.0f);
	scop_vec3_set(&(env->cam_right), 0.0f, 0.0f, 0.0f);
	scop_vec3_set(&(env->cam_up), 0.0f, 0.0f, 0.0f);
	scop_vec3_set(&(env->cam_front), 0.0f, 0.0f, -1.0f);
}

int		main(void)
{
	t_env		env;

	scop_get_env(&env);
	glfwSetErrorCallback(scop_glfw_error_callback);
	scop_init_env(&env);
	if (scop_glfw_init(&env) == 0)
		return (scop_exit(&env));
	glViewport(0, 0, env.win_w, env.win_h);
	glEnable(GL_DEPTH_TEST);
	if (scop_gl_init_shaders(&env) == 0)
		return (scop_exit(&env));
	if (scop_gl_init_matrix(&env) == 0)
		return (scop_exit(&env));
	scop_vector_init(&env);
	glfwSetKeyCallback(env.win, scop_glfw_key_callback);
	glfwSetWindowSizeCallback(env.win, scop_glfw_window_size_callback);
	scop_main(&env);
	return (scop_exit(&env));
}
