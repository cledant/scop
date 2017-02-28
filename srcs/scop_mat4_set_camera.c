/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scop_mat4_set_camera.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/28 16:40:00 by cledant           #+#    #+#             */
/*   Updated: 2017/02/28 18:50:20 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

void	scop_mat4_set_camera(t_mat4 *view, const t_vec3 pos,
			const t_vec3 target, const t_vec3 vec_up)
{
	t_vec3	dir;
	t_vec3	right;
	t_vec3	cam_up;

	scop_vec3_substract(&dir, target, pos);
	scop_vec3_normalize(&dir);
	scop_vec3_cross_prod(&right, dir, vec_up);
	scop_vec3_normalize(&right);
	scop_vec3_cross_prod(&cam_up, right, dir);
	(*view)[0][0] = right.x;
	(*view)[0][1] = right.y;
	(*view)[0][2] = right.z;
	(*view)[0][3] = -scop_math_dot_product(right, pos);
	(*view)[1][0] = cam_up.x;
	(*view)[1][1] = cam_up.y;
	(*view)[1][2] = cam_up.z;
	(*view)[1][3] = -scop_math_dot_product(cam_up, pos);
	(*view)[2][0] = -dir.x;
	(*view)[2][1] = -dir.y;
	(*view)[2][2] = -dir.z;
	(*view)[2][3] = scop_math_dot_product(dir, pos);
	(*view)[3][0] = 0.0f;
	(*view)[3][1] = 0.0f;
	(*view)[3][2] = 0.0f;
	(*view)[3][3] = 1.0f;
}
