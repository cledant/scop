/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scop_execute_mov.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/28 10:37:03 by cledant           #+#    #+#             */
/*   Updated: 2017/03/13 18:29:18 by cledant          ###   ########.fr       */
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
	if (env->input.p_key[GLFW_KEY_KP_SUBTRACT] == PRESSED)
	{
		env->input.scale /= 1.1f;
		if (scop_math_is_valid_float(env->input.scale) == 0 ||
				fpclassify(env->input.scale) == FP_ZERO)
			env->input.scale = 1;
	}
	if (env->input.p_key[GLFW_KEY_KP_ADD] == PRESSED)
	{
		env->input.scale *= 1.1f;
		if (scop_math_is_valid_float(env->input.scale) == 0 ||
				fpclassify(env->input.scale) == FP_ZERO)
			env->input.scale = 1;
	}
	if (env->input.p_key[GLFW_KEY_KP_0] == PRESSED)
	{
		if (env->input.timer > 0.25f)
		{
			env->input.wire = (env->input.wire == 0) ? 1 : 0;
			env->input.timer = 0.0f;
		}
	}
}
