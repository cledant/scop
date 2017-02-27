/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scop_mat4_set_translation.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/27 10:49:48 by cledant           #+#    #+#             */
/*   Updated: 2017/02/27 19:14:09 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

void	scop_mat4_set_translation(t_mat4 *matrix, const t_vec3 tr)
{
	(*matrix)[0] = 1.0f;
	(*matrix)[1] = 0.0f;
	(*matrix)[2] = 0.0f;
	(*matrix)[3] = tr.x;
	(*matrix)[4] = 0.0f;
	(*matrix)[5] = 1.0f;
	(*matrix)[6] = 0.0f;
	(*matrix)[7] = tr.y;
	(*matrix)[8] = 0.0f;
	(*matrix)[9] = 0.0f;
	(*matrix)[10] = 1.0f;
	(*matrix)[11] = tr.z;
	(*matrix)[12] = 0.0f;
	(*matrix)[13] = 0.0f;
	(*matrix)[14] = 0.0f;
	(*matrix)[15] = 1.0f;
}
