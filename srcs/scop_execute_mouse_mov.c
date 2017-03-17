/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scop_execute_mouse_mov.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/01 11:09:41 by cledant           #+#    #+#             */
/*   Updated: 2017/03/17 15:44:35 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

void	scop_execute_mouse_mov(t_env *env)
{
	if (env->input.toggle_mouse == 1)
	{
		if (env->input.rot_y > 89.0f)
			env->input.rot_y = 89.0f;
		if (env->input.rot_y < -89.0f)
			env->input.rot_y = -89.0f;
		env->cam.front.x = cosf(scop_math_deg_to_rad(env->input.rot_x)) *
			cosf(scop_math_deg_to_rad(env->input.rot_y));
		env->cam.front.y = sinf(scop_math_deg_to_rad(env->input.rot_y));
		env->cam.front.z = sinf(scop_math_deg_to_rad(env->input.rot_x)) *
			cosf(scop_math_deg_to_rad(env->input.rot_y));
		scop_vec3_normalize(&(env->cam.front));
	}
}
