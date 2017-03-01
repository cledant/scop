/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scop_execute_mouse_mov.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/01 11:09:41 by cledant           #+#    #+#             */
/*   Updated: 2017/03/01 11:10:44 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

void	scop_execute_mouse_mov(t_env *env)
{
	if (env->rot_y > 89.0f)
		env->rot_y = 89.0f;
	if (env->rot_y < -89.0f)
		env->rot_y = -89.0f;
	env->front.x = cosf(scop_math_deg_to_rad(env->rot_x)) *
		cosf(scop_math_deg_to_rad(env->rot_y));
	env->front.y = sinf(scop_math_deg_to_rad(env->rot_y));
	env->front.z = sinf(scop_math_deg_to_rad(env->rot_x)) *
		cosf(scop_math_deg_to_rad(env->rot_y));
	scop_vec3_normalize(&(env->front));
}
