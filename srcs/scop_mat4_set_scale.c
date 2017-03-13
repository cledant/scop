/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scop_mat4_set_scale.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/13 16:58:15 by cledant           #+#    #+#             */
/*   Updated: 2017/03/13 17:29:38 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

void	scop_mat4_set_scale(t_mat4 *matrix, const float size)
{
	(*matrix)[0][0] = size;
	(*matrix)[0][1] = 0.0f;
	(*matrix)[0][2] = 0.0f;
	(*matrix)[0][3] = 0.0f;
	(*matrix)[1][0] = 0.0f;
	(*matrix)[1][1] = size;
	(*matrix)[1][2] = 0.0f;
	(*matrix)[1][3] = 0.0f;
	(*matrix)[2][0] = 0.0f;
	(*matrix)[2][1] = 0.0f;
	(*matrix)[2][2] = size;
	(*matrix)[2][3] = 0.0f;
	(*matrix)[3][0] = 0.0f;
	(*matrix)[3][1] = 0.0f;
	(*matrix)[3][2] = 0.0f;
	(*matrix)[3][3] = 1.0f;
}
