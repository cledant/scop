/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scop_mat4_set_translation.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/27 10:49:48 by cledant           #+#    #+#             */
/*   Updated: 2017/02/27 12:30:43 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

void	scop_mat4_set_translation(t_mat4 *matrix, const t_vec3 tr)
{
	(*matrix)[3] = tr.x;
	(*matrix)[7] = tr.y;
	(*matrix)[11] = tr.z;
}
