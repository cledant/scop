/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scop_execute_mov.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/28 10:37:03 by cledant           #+#    #+#             */
/*   Updated: 2017/03/05 14:31:00 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

void	scop_execute_mov(t_env *env)
{
	t_vec3		tmp;
	float		corr_cam_speed;

	corr_cam_speed = env->input.cam_speed * env->input.delta_time;
	if (env->input.p_key[GLFW_KEY_W] == PRESSED)
	{
		scop_vec3_multiply_const(&tmp, env->cam.front, corr_cam_speed);
		scop_vec3_add(&(env->cam.pos), env->cam.pos, tmp);
	}
	if (env->input.p_key[GLFW_KEY_S] == PRESSED)
	{
		scop_vec3_multiply_const(&tmp, env->cam.front, corr_cam_speed);
		scop_vec3_substract(&(env->cam.pos), env->cam.pos, tmp);
	}
	if (env->input.p_key[GLFW_KEY_A] == PRESSED)
	{
		scop_vec3_cross_prod(&tmp, env->cam.front, env->cam.up_vec);
		scop_vec3_normalize(&tmp);
		scop_vec3_multiply_const(&tmp, tmp, corr_cam_speed);
		scop_vec3_substract(&(env->cam.pos), env->cam.pos, tmp);
	}
	if (env->input.p_key[GLFW_KEY_D] == PRESSED)
	{
		scop_vec3_cross_prod(&tmp, env->cam.front, env->cam.up_vec);
		scop_vec3_normalize(&tmp);
		scop_vec3_multiply_const(&tmp, tmp, corr_cam_speed);
		scop_vec3_add(&(env->cam.pos), env->cam.pos, tmp);
	}
	if (env->input.p_key[GLFW_KEY_R] == PRESSED)
	{
		scop_vec3_multiply_const(&tmp, env->cam.up_vec, corr_cam_speed);
		scop_vec3_add(&(env->cam.pos), env->cam.pos, tmp);
	}
	if (env->input.p_key[GLFW_KEY_F] == PRESSED)
	{
		scop_vec3_multiply_const(&tmp, env->cam.up_vec, corr_cam_speed);
		scop_vec3_substract(&(env->cam.pos), env->cam.pos, tmp);
	}
}
