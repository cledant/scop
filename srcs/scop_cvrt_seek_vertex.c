/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scop_cvrt_seek_vertex.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/09 21:54:53 by cledant           #+#    #+#             */
/*   Updated: 2017/03/10 17:11:08 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

int		scop_cvrt_seek_vertex(t_env *env, size_t where)
{
	long	index;

	if ((size_t)env->obj.glpoint[where].vertex > env->obj.nb_pos)
		return (0);
	index = env->obj.glpoint[where].vertex - 1;
	env->obj.cvrt[env->obj.nb_cvrt].pos.x = env->obj.v_pos[index].x;
	env->obj.cvrt[env->obj.nb_cvrt].pos.y = env->obj.v_pos[index].y;
	env->obj.cvrt[env->obj.nb_cvrt].pos.z = env->obj.v_pos[index].z;
	return (1);
}
