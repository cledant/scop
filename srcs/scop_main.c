/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scop_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/23 17:26:38 by cledant           #+#    #+#             */
/*   Updated: 2017/03/16 17:43:22 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

static inline void		matrix_update_value(t_env *env)
{
	t_vec3	pos_front;
	t_vec3	inv_model_tr;

	scop_vec3_add(&pos_front, env->cam.pos, env->cam.front);
	scop_mat4_set_camera(&(env->matrix.view), env->cam.pos, pos_front,
		env->cam.up_vec);
	scop_mat4_set_perspective(&(env->matrix.proj), (t_vec4){env->win.fov,
		(GLfloat)env->win.win_w / (GLfloat)env->win.win_h, 0.1f, 100.0f});
	glViewport(0, 0, env->win.win_w, env->win.win_h);
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
}

static inline void		matrix_update_gfx(t_env *env)
{
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
	glUniform1iv(env->uniform.var_wiremode, 1, (GLint *)&(env->input.wire));
	glUniform1fv(env->uniform.var_color_transition, 1,
		(GLfloat *)&(env->obj.color_transition));
}

static inline void		update_angle_event_transition(t_env *env)
{
	if (env->input.toggle_rot == 1)
	{
		env->obj.auto_rot_angle += env->input.delta_time * 50.0f;
		if (env->obj.auto_rot_angle > 360.0f)
			env->obj.auto_rot_angle -= 720.0f;
	}
	if (env->input.timer < 1.0f)
		env->input.timer += env->input.delta_time;
	glfwPollEvents();
	scop_execute_mov(env);
	scop_execute_mouse_mov(env);
	if (env->input.toggle_color_transition == 0
		&& env->obj.color_transition > 0.0f)
	{
		env->obj.color_transition -= env->input.delta_time;
		if (env->obj.color_transition < 0.0f)
			env->obj.color_transition = 0.0f;
	}
	else if (env->input.toggle_color_transition == 1
		&& env->obj.color_transition < 1.0f)
	{
		env->obj.color_transition += env->input.delta_time;
		if (env->obj.color_transition > 1.0f)
			env->obj.color_transition = 1.0f;
	}
}

static inline void		draw_vao(t_env *env, const size_t counter)
{
	glActiveTexture(GL_TEXTURE0);
	if (env->obj.mat[env->obj.vao[counter].mat_id].diff_tex_path != NULL)
	{
		glBindTexture(GL_TEXTURE_2D,
			env->obj.mat[env->obj.vao[counter].mat_id].gl_tex);
		glUniform1i(env->uniform.tex_tex, 0);
		glUniform1iv(env->uniform.var_tex_origin, 1,
			(GLint *)&(env->obj.mat[env->obj.vao[counter].mat_id].
			tex_origin));
	}
	else
	{
		glBindTexture(GL_TEXTURE_2D, env->obj.mat[0].gl_tex);
		glUniform1i(env->uniform.tex_tex, 0);
		glUniform1iv(env->uniform.var_tex_origin, 1,
			(GLint *)&(env->obj.mat[0].tex_origin));
	}
	glBindVertexArray(env->obj.vao[counter].gl_vao);
	if (env->input.wire == 0)
		glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	else
		glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	glDrawArrays(GL_TRIANGLES, 0, env->obj.vao[counter].nb_face);
	glBindTexture(GL_TEXTURE_2D, 0);
	glBindVertexArray(0);
}

void					scop_main(t_env *env)
{
	float	curr_time;
	size_t	counter;

	scop_main_init(env);
	while (!glfwWindowShouldClose(env->win.win))
	{
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		counter = 0;
		curr_time = glfwGetTime();
		env->input.delta_time = curr_time - env->input.prev_time;
		env->input.prev_time = curr_time;
		update_angle_event_transition(env);
		matrix_update_value(env);
		matrix_update_gfx(env);
		while (counter < env->obj.nb_vao)
		{
			draw_vao(env, counter);
			counter++;
		}
		glfwSwapBuffers(env->win.win);
	}
}
