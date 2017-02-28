/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scop_mat4_update_perspective.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/28 17:11:32 by cledant           #+#    #+#             */
/*   Updated: 2017/02/28 17:11:35 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

void scop_mat4_update_perspective(t_mat4 *matrix, const t_vec4 param)
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
	(*matrix)[0][0] = 1.0f / (param.y * tanhalffov);
	(*matrix)[1][1] = 1.0f / tanhalffov;
	(*matrix)[2][2] = (-param.z - param.w) / (param.w - param.z);
	(*matrix)[2][3] = (2.0f * param.z * param.w) / (param.w - param.z);
	(*matrix)[3][2] = -1.0f;
	(*matrix)[3][3] = 1.0f;
}
