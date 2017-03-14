/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scop_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/23 17:26:38 by cledant           #+#    #+#             */
/*   Updated: 2017/03/14 15:31:24 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

void	scop_gl_init_vao(t_env *env)
{
	size_t		counter;

	counter = 0;

	while (counter < env->obj.nb_vao)
	{
		if (env->obj.vao[counter].nb_face > 0)
		{
			glGenVertexArrays(1, &(env->obj.vao[counter].gl_vao));
			glGenBuffers(1, &(env->obj.vao[counter].gl_vbo));
			glBindVertexArray(env->obj.vao[counter].gl_vao);
			glBindBuffer(GL_ARRAY_BUFFER, env->obj.vao[counter].gl_vbo);
			glBufferData(GL_ARRAY_BUFFER,
				sizeof(GLfloat) * 8 * env->obj.vao[counter].nb_face,
				env->obj.vao[counter].face_array, GL_STATIC_DRAW);
			glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(GLfloat),
				(GLvoid *)0);
			glEnableVertexAttribArray(0);
			glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(GLfloat),
				(GLvoid *)(3 * sizeof(GLfloat)));
			glEnableVertexAttribArray(1);
			glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(GLfloat),
				(GLvoid *)(6 * sizeof(GLfloat)));
			glEnableVertexAttribArray(2);
			glBindVertexArray(0);
		}
		counter++;
	}
}

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
	printf("Vertex counter : %ld\n", counter);
	counter = 0;
	while (counter < env->obj.nb_norm)
	{
		printf("Norm : %f, %f, %f\n", env->obj.v_norm[counter].x,
			env->obj.v_norm[counter].y, env->obj.v_norm[counter].z);
		counter++;
	}
	printf("Norm counter : %ld\n", counter);
	counter = 0;
	while (counter < env->obj.nb_tex)
	{
		printf("Tex : %f, %f\n", env->obj.v_tex[counter].x,
			env->obj.v_tex[counter].y);
		counter++;
	}
	printf("Tex counter : %ld\n", counter);
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
	t_vec3	inv_model_tr;
	float	curr_time;
	size_t	counter;

	glUseProgram(env->shader.shader_prog);
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	glEnable(GL_DEPTH_TEST);
	glViewport(0, 0, env->win.win_w, env->win.win_h);
	//Should check if there is something in vao 0 to draw and then exit or not
	//print_parsing(env);
	scop_gl_init_vao(env);
	scop_mat4_set_translation(&(env->matrix.model_orig), env->obj.center);
	glUniformMatrix4fv(env->uniform.mat_model_orig, 1, GL_TRUE,
		(GLfloat *)&(env->matrix.model_orig));
	while (!glfwWindowShouldClose(env->win.win))
	{
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		//get_time
		counter = 0;
		curr_time = glfwGetTime();
		env->input.delta_time = curr_time - env->input.prev_time;
		env->input.prev_time = curr_time;
		//angle update
		if (env->input.toggle_rot == 1)
		{
			env->obj.auto_rot_angle += env->input.delta_time * 50.0f;
			if (env->obj.auto_rot_angle > 360.0f)
				env->obj.auto_rot_angle -= 720.0f;
		}
		if (env->input.timer < 1.0f)
			env->input.timer += env->input.delta_time;
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
		scop_mat4_set_rotation(&(env->matrix.model_auto_rot),
			env->obj.auto_rot_angle, (t_vec3){0.0f, 1.0f, 0.0f});
		scop_mat4_set_rotation(&(env->matrix.model_rot_theta),
			env->input.model_rot_theta, (t_vec3){1.0f, 0.0f, 0.0f});
		scop_mat4_set_rotation(&(env->matrix.model_rot_phi),
			env->input.model_rot_phi, (t_vec3){0.0f, 0.0f, 1.0f});
		scop_mat4_set_scale(&(env->matrix.scale), env->input.scale);
		inv_model_tr.x = -env->input.model_pos.x;
		inv_model_tr.y = -env->input.model_pos.y;
		inv_model_tr.z = -env->input.model_pos.z;
		scop_mat4_set_translation(&(env->matrix.model_tr), inv_model_tr);
		glUniformMatrix4fv(env->uniform.mat_view, 1, GL_TRUE,
			(GLfloat *)&(env->matrix.view));
		glUniformMatrix4fv(env->uniform.mat_proj, 1, GL_TRUE,
			(GLfloat *)&(env->matrix.proj));
		glUniformMatrix4fv(env->uniform.mat_model_auto_rot, 1, GL_TRUE,
			(GLfloat *)&(env->matrix.model_auto_rot));
		glUniformMatrix4fv(env->uniform.mat_model_rot_phi, 1, GL_TRUE,
			(GLfloat *)&(env->matrix.model_rot_phi));
		glUniformMatrix4fv(env->uniform.mat_model_rot_theta, 1, GL_TRUE,
			(GLfloat *)&(env->matrix.model_rot_theta));
		glUniformMatrix4fv(env->uniform.mat_model_tr, 1, GL_TRUE,
			(GLfloat *)&(env->matrix.model_tr));
		glUniformMatrix4fv(env->uniform.mat_scale, 1, GL_TRUE,
			(GLfloat *)&(env->matrix.scale));
		while (counter < env->obj.nb_vao)
		{
			//Use texture
			glActiveTexture(GL_TEXTURE0);
			glBindTexture(GL_TEXTURE_2D,
				env->obj.mat[env->obj.vao[counter].mat_id].gl_tex);
			glUniform1i(env->uniform.tex_tex, 0);
			glUniform1iv(env->uniform.var_tex_origin, 1,
				(GLint *)&(env->obj.mat[env->obj.vao[counter].mat_id].tex_origin));
			//Draw vertex
			glBindVertexArray(env->obj.vao[counter].gl_vao);
			(env->input.wire == 0) ? glDrawArrays(GL_TRIANGLES, 0,
				env->obj.vao[counter].nb_face) : glDrawArrays(GL_LINES, 0,
				env->obj.vao[counter].nb_face);
			glBindTexture(GL_TEXTURE_2D, 0);
			glBindVertexArray(0);
			counter++;
		}
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
