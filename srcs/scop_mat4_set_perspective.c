/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scop_mat4_set_perspective.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/27 11:35:36 by cledant           #+#    #+#             */
/*   Updated: 2017/03/05 14:50:06 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

/*
** param.x = fov in degree
** param.y = ratio
** param.z = near
** param.w = far
*/

void	scop_mat4_set_perspective(t_mat4 *matrix, const t_vec4 param)
{
	float	rad_fov;
	float	tanhalffov;

	rad_fov = scop_math_deg_to_rad(param.x);
	tanhalffov = tanf(rad_fov / 2.0f);
	(*matrix)[0][0] = 1.0f / (param.y * tanhalffov);
	(*matrix)[0][1] = 0.0f;
	(*matrix)[0][2] = 0.0f;
	(*matrix)[0][3] = 0.0f;
	(*matrix)[1][0] = 0.0f;
	(*matrix)[1][1] = 1.0f / tanhalffov;
	(*matrix)[1][2] = 0.0f;
	(*matrix)[1][3] = 0.0f;
	(*matrix)[2][0] = 0.0f;
	(*matrix)[2][1] = 0.0f;
	(*matrix)[2][2] = (-param.z - param.w) / (param.w - param.z);
	(*matrix)[2][3] = (-2.0f * param.z * param.w) / (param.w - param.z);
	(*matrix)[3][0] = 0.0f;
	(*matrix)[3][1] = 0.0f;
	(*matrix)[3][2] = -1.0f;
	(*matrix)[3][3] = 1.0f;
}
