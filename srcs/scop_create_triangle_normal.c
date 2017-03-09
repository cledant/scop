/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scop_create_triangle_normal.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/09 21:26:37 by cledant           #+#    #+#             */
/*   Updated: 2017/03/09 21:42:04 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

int		scop_create_triangle(t_face *face, const size_t pos)
{
	t_vec3		ab;
	t_vec3		ac;
	t_vec3		norm;

	scop_tvec3_set(&ab, face[pos + 1].pos.x - face[pos].pos.x,
		face[pos + 1].pos.y - face[pos].pos.y,
		face[pos + 1].pos.z - face[pos].pos.z);
	scop_tvec3_set(&ac, face[pos + 2].pos.x - face[pos].pos.x,
		face[pos + 2].pos.y - face[pos].pos.y,
		face[pos + 2].pos.z - face[pos].pos.z);
	scop_cross_prod(&norm, ab, ac);
	scop_normalize(&norm);
	scop_tvec3_set(&(face[pos].norm), norm.x, norm.y, norm.z);
	scop_tvec3_set(&(face[pos + 1].norm), norm.x, norm.y, norm.z);
	scop_tvec3_set(&(face[pos + 2].norm), norm.x, norm.y, norm.z);
	return (1);
}
