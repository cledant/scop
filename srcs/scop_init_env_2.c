/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scop_init_env.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/05 11:18:10 by cledant           #+#    #+#             */
/*   Updated: 2017/03/15 20:50:45 by cledant          ###   ########.fr       */
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
	env->uniform.mat_proj = -1;
	env->uniform.mat_model_orig = -1;
	env->uniform.mat_model_auto_rot = -1;
	env->uniform.mat_view = -1;
	env->uniform.mat_scale = -1;
	env->uniform.mat_model_rot_theta = -1;
	env->uniform.mat_model_rot_phi = -1;
	env->uniform.mat_model_tr = -1;
	env->uniform.tex_tex = -1;
	env->uniform.var_tex_origin = -1;
	env->uniform.var_wiremode = -1;
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
	env->input.scale = 1.0f;
	env->input.timer = 1.1f;
	env->input.wire = 0;
	env->input.toggle_rot = 1;
	env->input.toggle_color_transition = 0;
	env->input.model_rot_theta = 0.0f;
	env->input.model_rot_phi = 0.0f;
	scop_vec3_set(&(env->input.model_pos), 0.0f, 0.0f, 0.0f);
}
