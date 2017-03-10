/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scop_cvrt_seek_norm.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/10 17:11:44 by cledant           #+#    #+#             */
/*   Updated: 2017/03/10 17:14:09 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

int		scop_cvrt_seek_norm(t_env *env, size_t where)
{
	long	index;

	if ((size_t)env->obj.glpoint[where].norm > env->obj.nb_norm)
		return (0);
	index = env->obj.glpoint[where].vertex - 1;
	env->obj.cvrt[env->obj.nb_cvrt].norm.x = env->obj.v_norm[index].x;
	env->obj.cvrt[env->obj.nb_cvrt].norm.y = env->obj.v_norm[index].y;
	env->obj.cvrt[env->obj.nb_cvrt].norm.z = env->obj.v_norm[index].z;
	return (1);
}
