/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scop_cvrt_seek_tex.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/10 17:21:33 by cledant           #+#    #+#             */
/*   Updated: 2017/03/13 14:49:32 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

int		scop_cvrt_seek_tex(t_env *env, size_t where)
{
	long	index;

	if ((size_t)env->obj.glpoint[where].tex > env->obj.nb_tex)
		return (0);
	index = env->obj.glpoint[where].tex - 1;
	env->obj.cvrt[env->obj.nb_cvrt].tex.x = env->obj.v_tex[index].x;
	env->obj.cvrt[env->obj.nb_cvrt].tex.y = env->obj.v_tex[index].y;
	return (1);
}
