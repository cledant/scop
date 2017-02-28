/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scop_mat4_create_look_at.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/28 13:18:03 by cledant           #+#    #+#             */
/*   Updated: 2017/02/28 13:23:33 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

void	scop_mat4_create_look_at(t_mat4 *result, const t_vec3 cam_right,
			const t_vec3 cam_up, const t_vec3 cam_dir)
{
	(*result)[0][0] = cam_right.x;
	(*result)[0][1] = cam_right.y;
	(*result)[0][2] = cam_right.z;
	(*result)[0][3] = 0.0f;
	(*result)[1][0] = cam_up.x;
	(*result)[1][1] = cam_up.y;
	(*result)[1][2] = cam_up.z;
	(*result)[1][3] = 0.0f;
	(*result)[2][0] = cam_dir.x;
	(*result)[2][1] = cam_dir.y;
	(*result)[2][2] = cam_dir.z;
	(*result)[2][3] = 0.0f;
	(*result)[3][0] = 0.0f;
	(*result)[3][1] = 0.0f;
	(*result)[3][2] = 0.0f;
	(*result)[3][3] = 1.0f;
}
