/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scop_mat4_set_rotation.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/27 11:12:35 by cledant           #+#    #+#             */
/*   Updated: 2017/02/28 10:07:12 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

void	scop_mat4_set_rotation(t_mat4 *matrix, const float angle, t_vec3 axis)
{
	float	cosa;
	float	sina;
	float	rad_angle;

	rad_angle = scop_math_deg_to_rad(angle);
	cosa = cosf(rad_angle);
	sina = sinf(rad_angle);
	scop_vec3_normalize(&axis);
	(*matrix)[0][0] = cosa + (1 - cosa) * axis.x * axis.x;
	(*matrix)[0][1] = axis.x * axis.y * (1 - cosa) - axis.z * sina;
	(*matrix)[0][2] = axis.x * axis.z * (1 - cosa) + axis.y * sina;
	(*matrix)[0][3] = 0.0f;
	(*matrix)[1][0] = axis.y * axis.x * (1 - cosa) + axis.z * sina;
	(*matrix)[1][1] = cosa + axis.y * axis.y * (1 - cosa);
	(*matrix)[1][2] = axis.y * axis.z * (1 - cosa) - axis.x * sina;
	(*matrix)[1][3] = 0.0f;
	(*matrix)[2][0] = axis.z * axis.x * (1 - cosa) - axis.y * sina;
	(*matrix)[2][1] = axis.z * axis.y * (1 - cosa) + axis.x * sina;
	(*matrix)[2][2] = cosa + axis.z * axis.z * (1 - cosa);
	(*matrix)[2][3] = 0.0f;
	(*matrix)[3][0] = 0.0f;
	(*matrix)[3][1] = 0.0f;
	(*matrix)[3][2] = 0.0f;
	(*matrix)[3][3] = 1.0f;
}
