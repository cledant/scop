/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scop_mat4_set_perspective.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/27 11:35:36 by cledant           #+#    #+#             */
/*   Updated: 2017/02/27 19:15:50 by cledant          ###   ########.fr       */
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
	(*matrix)[0] = 1.0f / (param.y * tanhalffov);
	(*matrix)[1] = 0.0f;
	(*matrix)[2] = 0.0f;
	(*matrix)[3] = 0.0f;
	(*matrix)[4] = 0.0f;
	(*matrix)[5] = 1.0f / tanhalffov;
	(*matrix)[6] = 0.0f;
	(*matrix)[7] = 0.0f;
	(*matrix)[8] = 0.0f;
	(*matrix)[9] = 0.0f;
	(*matrix)[10] = (-param.z - param.w) / (param.w - param.z);
	(*matrix)[11] = 1.0f;
	(*matrix)[12] = 0.0f;
	(*matrix)[13] = 0.0f;
	(*matrix)[14] = (2.0f * param.z * param.w) / (param.w - param.z);
	(*matrix)[15] = 1.0f;
}
