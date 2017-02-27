/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scop_mat4_set_rotation.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/27 11:12:35 by cledant           #+#    #+#             */
/*   Updated: 2017/02/27 19:10:42 by cledant          ###   ########.fr       */
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
	(*matrix)[0] = cosa + (1 - cosa) * axis.x * axis.x;
	(*matrix)[1] = axis.x * axis.y * (1 - cosa) - axis.z * sina;
	(*matrix)[2] = axis.x * axis.z * (1 - cosa) + axis.y * sina;
	(*matrix)[4] = axis.y * axis.x * (1 - cosa) + axis.z * sina;
	(*matrix)[5] = cosa + axis.y * axis.y * (1 - cosa);
	(*matrix)[6] = axis.y * axis.z * (1 - cosa) - axis.x * sina;
	(*matrix)[8] = axis.z * axis.x * (1 - cosa) - axis.y * sina;
	(*matrix)[9] = axis.z * axis.y * (1 - cosa) + axis.x * sina;
	(*matrix)[10] = cosa + axis.z * axis.z * (1 - cosa);
	(*matrix)[11] = 0.0f;
	(*matrix)[12] = 0.0f;
	(*matrix)[13] = 0.0f;
	(*matrix)[14] = 0.0f;
	(*matrix)[15] = 1.0f;
}
