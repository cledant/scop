/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scop_execute_mov.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/28 10:37:03 by cledant           #+#    #+#             */
/*   Updated: 2017/02/28 13:40:17 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

void	scop_execute_mov(t_env *env)
{
	t_vec3		tmp;

	if (env->p_key[GLFW_KEY_W] == PRESSED)
	{
		scop_vec3_multiply_const(&tmp, env->cam_front, env->cam_speed);
		scop_vec3_add(&(env->cam_pos), env->cam_pos, tmp);
	}
	if (env->p_key[GLFW_KEY_S] == PRESSED)
	{
		scop_vec3_multiply_const(&tmp, env->cam_front, env->cam_speed);
		scop_vec3_substract(&(env->cam_pos), env->cam_pos, tmp);
	}
	if (env->p_key[GLFW_KEY_A] == PRESSED)
	{
		scop_vec3_cross_prod(&tmp, env->cam_front, env->cam_up);
		scop_vec3_normalize(&tmp);
		scop_vec3_multiply_const(&tmp, tmp, env->cam_speed);
		scop_vec3_substract(&(env->cam_pos), env->cam_pos, tmp);
	}
	if (env->p_key[GLFW_KEY_D] == PRESSED)
	{
		scop_vec3_cross_prod(&tmp, env->cam_front, env->cam_up);
		scop_vec3_normalize(&tmp);
		scop_vec3_multiply_const(&tmp, tmp, env->cam_speed);
		scop_vec3_add(&(env->cam_pos), env->cam_pos, tmp);
	}
}
