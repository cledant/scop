/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scop_init_env.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/05 11:18:10 by cledant           #+#    #+#             */
/*   Updated: 2017/03/07 11:26:45 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

void	scop_init_env_win(t_env *env)
{
	env->win.win = NULL;
	env->win.win_h = 1000;
	env->win.win_w = 1000;
	env->win.fov = 45.0f;
}

void	scop_init_env_shader(t_env *env)
{
	env->shader.shader_prog = 0;
	env->shader.vertex_shader = 0;
	env->shader.fragment_shader = 0;
}

void	scop_init_env_uniform(t_env *env)
{
	env->uniform.proj = -1;
	env->uniform.model_orig = -1;
	env->uniform.model_rot = -1;
	env->uniform.view = -1;
	env->uniform.tex = -1;
	env->uniform.tex_origin = -1;
}

void	scop_init_env_input(t_env *env)
{
	memset(env->input.p_key, 0, sizeof(int) * 1024);
	env->input.cam_speed = 5.0f;
	env->input.rot_x = 0.0f;
	env->input.rot_y = 0.0f;
	env->input.sensitivity = 0.05f;
	env->input.delta_time = 0.0f;
	env->input.prev_time = 0.0f;
}

void	scop_init_env_camera(t_env *env)
{
	scop_vec3_set(&(env->cam.pos), 0.0f, 0.0f, -1.0f);
	scop_vec3_set(&(env->cam.target), 0.0f, 0.0f, 0.0f);
	scop_vec3_set(&(env->cam.up_vec), 0.0f, 1.0f, 0.0f);
	scop_vec3_set(&(env->cam.front), 1.0f, 0.0f, 0.0f);
}

void	scop_init_env_light(t_env *env)
{
	scop_vec3_set(&(env->light.pos), 0.0f, 0.0f, -1.0f);
	scop_vec3_set(&(env->light.color), 1.0f, 1.0f, 1.0f);
	env->light.p_amb = 0.1;
	env->light.p_diff = 0.8;
	env->light.p_spec = 0.5;
}

void	scop_init_env_obj(t_env *env)
{
	memset(&(env->obj), 0, sizeof(t_obj) * 1);
}

void	scop_init_env_matrix(t_env *env)
{
	t_vec3		pos_front;

	scop_mat4_set_perspective(&(env->matrix.proj), (t_vec4){env->win.fov,
		(GLfloat)env->win.win_w / (GLfloat)env->win.win_h, 0.1f,
		100.0f});
	scop_vec3_add(&pos_front, env->cam.pos, env->cam.front);
	scop_mat4_set_camera(&(env->matrix.view), env->cam.pos, pos_front,
			env->cam.up_vec);
	scop_mat4_set_identity(&(env->matrix.model_orig));
	scop_mat4_set_identity(&(env->matrix.model_rot));
}

void	scop_init_env(t_env *env)
{
	scop_init_env_win(env);
	scop_init_env_shader(env);
	scop_init_env_uniform(env);
	scop_init_env_obj(env);
	scop_init_env_light(env);
	scop_init_env_input(env);
	scop_init_env_camera(env);
	scop_init_env_matrix(env);
	env->folder = NULL;
}
