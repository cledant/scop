/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scop_cvrt_seek_vertex.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/09 21:54:53 by cledant           #+#    #+#             */
/*   Updated: 2017/03/09 21:54:55 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

int		scop_cvrt_seek_vertex(const t_glpoint *glpoint, t_face *face,
			t_obj *obj)
{
	if (glpoint->vertex > obj->nb_vpos)
		return (0);
	face->pos.x = obj->v_pos[glpoint->vertex - 1].x;
	face->pos.y = obj->v_pos[glpoint->vertex - 1].y;
	face->pos.z = obj->v_pos[glpoint->vertex - 1].z;
	return (1);
}
