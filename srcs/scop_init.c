/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scop_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/23 17:26:38 by cledant           #+#    #+#             */
/*   Updated: 2017/03/10 20:21:09 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

/*
void	scop_test_vertex_init(t_env	*env)
{
	GLfloat vertices[] = {
		-0.5f, -0.5f, -0.5f, 1.0f, 1.0f, 1.0f, 0.0f, 0.0f,
		 0.5f, -0.5f, -0.5f, 1.0f, 1.0f, 1.0f, 1.0f, 0.0f,
		 0.5f,  0.5f, -0.5f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f,
		 0.5f,  0.5f, -0.5f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f,
		-0.5f,  0.5f, -0.5f, 1.0f, 1.0f, 1.0f, 0.0f, 1.0f,
		-0.5f, -0.5f, -0.5f, 1.0f, 1.0f, 1.0f, 0.0f, 0.0f,

		-0.5f, -0.5f,  0.5f, 1.0f, 1.0f, 1.0f, 0.0f, 0.0f,
		 0.5f, -0.5f,  0.5f, 1.0f, 1.0f, 1.0f, 1.0f, 0.0f,
		 0.5f,  0.5f,  0.5f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f,
		 0.5f,  0.5f,  0.5f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f,
		-0.5f,  0.5f,  0.5f, 1.0f, 1.0f, 1.0f, 0.0f, 1.0f,
		-0.5f, -0.5f,  0.5f, 1.0f, 1.0f, 1.0f, 0.0f, 0.0f,

		-0.5f,  0.5f,  0.5f, 1.0f, 1.0f, 1.0f, 1.0f, 0.0f,
		-0.5f,  0.5f, -0.5f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f,
		-0.5f, -0.5f, -0.5f, 1.0f, 1.0f, 1.0f, 0.0f, 1.0f,
		-0.5f, -0.5f, -0.5f, 1.0f, 1.0f, 1.0f, 0.0f, 1.0f,
		-0.5f, -0.5f,  0.5f, 1.0f, 1.0f, 1.0f, 0.0f, 0.0f,
		-0.5f,  0.5f,  0.5f, 1.0f, 1.0f, 1.0f, 1.0f, 0.0f,

		 0.5f,  0.5f,  0.5f, 1.0f, 1.0f, 1.0f, 1.0f, 0.0f,
		 0.5f,  0.5f, -0.5f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f,
		 0.5f, -0.5f, -0.5f, 1.0f, 1.0f, 1.0f, 0.0f, 1.0f,
		 0.5f, -0.5f, -0.5f, 1.0f, 1.0f, 1.0f, 0.0f, 1.0f,
		 0.5f, -0.5f,  0.5f, 1.0f, 1.0f, 1.0f, 0.0f, 0.0f,
		 0.5f,  0.5f,  0.5f, 1.0f, 1.0f, 1.0f, 1.0f, 0.0f,

		-0.5f, -0.5f, -0.5f, 1.0f, 1.0f, 1.0f, 0.0f, 1.0f,
		 0.5f, -0.5f, -0.5f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f,
		 0.5f, -0.5f,  0.5f, 1.0f, 1.0f, 1.0f, 1.0f, 0.0f,
		 0.5f, -0.5f,  0.5f, 1.0f, 1.0f, 1.0f, 1.0f, 0.0f,
		-0.5f, -0.5f,  0.5f, 1.0f, 1.0f, 1.0f, 0.0f, 0.0f,
		-0.5f, -0.5f, -0.5f, 1.0f, 1.0f, 1.0f, 0.0f, 1.0f,

		-0.5f,  0.5f, -0.5f, 1.0f, 1.0f, 1.0f, 0.0f, 1.0f,
		 0.5f,  0.5f, -0.5f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f,
		 0.5f,  0.5f,  0.5f, 1.0f, 1.0f, 1.0f, 1.0f, 0.0f,
		 0.5f,  0.5f,  0.5f, 1.0f, 1.0f, 1.0f, 1.0f, 0.0f,
		-0.5f,  0.5f,  0.5f, 1.0f, 1.0f, 1.0f, 0.0f, 0.0f,
		-0.5f,  0.5f, -0.5f, 1.0f, 1.0f, 1.0f, 0.0f, 1.0f
	};
	GLuint indices[] = {
		0, 1, 2,
		3, 4, 5,
		6, 7, 8,
		9, 10, 11,
		12, 13, 14,
		15, 16, 17,
		18, 19, 20,
		21, 22, 23,
		24, 25, 26,
		27, 28, 29,
		30, 31, 32,
		33, 34, 35
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
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (GLvoid *)0);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float),
		(GLvoid *)(3 * sizeof(GLfloat)));
	glEnableVertexAttribArray(1);
	glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float),
		(GLvoid *)(6 * sizeof(GLfloat)));
	glEnableVertexAttribArray(2);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);
}*/

void	print_parsing(t_env *env)
{
	size_t	counter;
	size_t	c_vao;

	counter = 0;
	c_vao = 0;
	printf("===Parsing dump===\n");
	printf("VAO\n");
	while (counter < env->obj.nb_pos)
	{
		printf("Vertex : %f, %f, %f\n", env->obj.v_pos[counter].x,
			env->obj.v_pos[counter].y, env->obj.v_pos[counter].z);
		counter++;
	}
	counter = 0;
	while (counter < env->obj.nb_norm)
	{
		printf("Norm : %f, %f, %f\n", env->obj.v_norm[counter].x,
			env->obj.v_norm[counter].y, env->obj.v_norm[counter].z);
		counter++;
	}
	counter = 0;
	while (counter < env->obj.nb_tex)
	{
		printf("Tex : %f, %f\n", env->obj.v_tex[counter].x,
			env->obj.v_tex[counter].y);
		counter++;
	}
	counter = 0;
	while (c_vao < env->obj.nb_vao)
	{
		printf("VAO number %ld | nb of triangle : %ld\n",
			c_vao, env->obj.vao[c_vao].nb_face);
		while (counter < env->obj.vao[c_vao].nb_face)
		{
			printf("Tex : %f, %f, %f, %f, %f, %f, %f, %f\n",
				env->obj.vao[c_vao].face_array[counter].pos.x,
				env->obj.vao[c_vao].face_array[counter].pos.y,
				env->obj.vao[c_vao].face_array[counter].pos.z,
				env->obj.vao[c_vao].face_array[counter].norm.x,
				env->obj.vao[c_vao].face_array[counter].norm.y,
				env->obj.vao[c_vao].face_array[counter].norm.z,
				env->obj.vao[c_vao].face_array[counter].tex.x,
				env->obj.vao[c_vao].face_array[counter].tex.y);
			counter++;
		}
		counter = 0;
		c_vao++;
	}
	printf("===END PARSING===\n");
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
	t_vec3	pos_front;
	float	curr_time;

	glUseProgram(env->shader.shader_prog);
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	glEnable(GL_DEPTH_TEST);
	glViewport(0, 0, env->win.win_w, env->win.win_h);
	//Note secondaire : Calculer barycentrei de l obj + translater orig + ... + retour au centre ?
	//Should check if there is something in vao 0 to draw and then exit or not
	print_parsing(env);
	while (!glfwWindowShouldClose(env->win.win))
	{
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		//get_time
		curr_time = glfwGetTime();
		env->input.delta_time = curr_time - env->input.prev_time;
		env->input.prev_time = curr_time;
		//get events
		glfwPollEvents();
		scop_execute_mov(env);
		scop_execute_mouse_mov(env);
		//Maj matrix
		scop_vec3_add(&pos_front, env->cam.pos, env->cam.front);
		scop_mat4_set_camera(&(env->matrix.view), env->cam.pos, pos_front,
			env->cam.up_vec);
		scop_mat4_set_perspective(&(env->matrix.proj), (t_vec4){env->win.fov,
			(GLfloat)env->win.win_w / (GLfloat)env->win.win_h, 0.1f, 100.0f});
		scop_mat4_set_rotation(&(env->matrix.model_rot), env->input.prev_time
			* 50.0f, (t_vec3){0.0f, 0.0f, 1.0f});
		glUniformMatrix4fv(env->uniform.view, 1, GL_TRUE,
			(GLfloat *)&(env->matrix.view));
		glUniformMatrix4fv(env->uniform.proj, 1, GL_TRUE,
			(GLfloat *)&(env->matrix.proj));
		//Use texture
/*		glActiveTexture(GL_TEXTURE0);
		glBindTexture(GL_TEXTURE_2D, env->texture);
		glUniform1i(env->u_tex, 0);
		glUniform1iv(env->u_tex_origin, 1, (GLint *)&(env->tex_origin));
		//Draw vertex
		glBindVertexArray(env->vao);
		while (counter < 10)
		{
			scop_mat4_set_translation(&(env->model), cube_pos[counter]);
			glUniformMatrix4fv(env->u_model, 1, GL_TRUE, (GLfloat *)&(env->model));
			glDrawElements(GL_TRIANGLES, 3 * 12, GL_UNSIGNED_INT, 0);
			counter++;
		}
		glBindVertexArray(0);*/
		glfwSwapBuffers(env->win.win);
	}
}

static inline int		error_argv(int argc)
{
	if (argc < 2)
		puts("Scop : no file");
	else if (argc > 2)
		puts("Scop : too much arguments");
	return (0);
}

int						main(int argc, char **argv)
{
	t_env		env;

	if (argc != 2)
		return (error_argv(argc));
	scop_get_env(&env);
	glfwSetErrorCallback(scop_glfw_error_callback);
	scop_init_env(&env);
	if ((env.folder = scop_get_folder(argv[1])) == NULL)
		return (scop_exit(&env));
	if (scop_glfw_init(&env) == 0)
		return (scop_exit(&env));
	if (scop_gl_init_shaders(&env) == 0)
		return (scop_exit(&env));
	if (scop_gl_init_uniforms(&env) == 0)
		return (scop_exit(&env));
	if (scop_gl_init_first_mat(&env) == 0)
		return (scop_exit(&env));
	if (scop_init_vao(&env, 0) == 0)
		return (scop_exit(&env));
	if (scop_read_obj_files(&env, argv[1]) == 0)
		return (scop_exit(&env));
	glfwSetKeyCallback(env.win.win, scop_glfw_key_callback);
	glfwSetCursorPosCallback(env.win.win, scop_glfw_mouse_pos_callback);
	glfwSetWindowSizeCallback(env.win.win, scop_glfw_window_size_callback);
	scop_main(&env);
	return (scop_exit(&env));
}
