/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scop_mat4_set_translation.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/27 10:49:48 by cledant           #+#    #+#             */
/*   Updated: 2017/02/28 09:19:49 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

void	scop_mat4_set_translation(t_mat4 *matrix, const t_vec3 tr)
{
	(*matrix)[0][0] = 1.0f;
	(*matrix)[0][1] = 0.0f;
	(*matrix)[0][2] = 0.0f;
	(*matrix)[0][3] = tr.x;
	(*matrix)[1][0] = 0.0f;
	(*matrix)[1][1] = 1.0f;
	(*matrix)[1][2] = 0.0f;
	(*matrix)[1][3] = tr.y;
	(*matrix)[2][0] = 0.0f;
	(*matrix)[2][1] = 0.0f;
	(*matrix)[2][2] = 1.0f;
	(*matrix)[2][3] = tr.z;
	(*matrix)[3][0] = 0.0f;
	(*matrix)[3][1] = 0.0f;
	(*matrix)[3][2] = 0.0f;
	(*matrix)[3][3] = 1.0f;
}
