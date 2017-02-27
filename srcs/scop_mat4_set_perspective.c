/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scop_mat4_set_perspective.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/27 11:35:36 by cledant           #+#    #+#             */
/*   Updated: 2017/02/27 12:36:51 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

void scop_mat4_set_perspective(t_mat4 *matrix, const t_vec4 param)
{
	/*
	** param.x = fov in degree
	** param.y = ratio
	** param.z = near
	** param.w = far
	*/
	float	rad_fov;
	float	tanhalffov;

	rad_fov = scop_math_deg_to_rad(param.x);
	tanhalffov = tanf(rad_fov / 2.0f);
	(*matrix)[0] = 1.0f / (rad_fov * tanhalffov);
	(*matrix)[5] = 1.0f / tanhalffov;
	(*matrix)[10] = -(param.z + param.w) / (param.w - param.z);
	(*matrix)[11] = -1.0f;
	(*matrix)[14] = -(2.0f * param.z * param.w) / (param.w - param.z);
}
