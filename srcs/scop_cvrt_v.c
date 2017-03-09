/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scop_cvrt_v.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/09 17:56:12 by cledant           #+#    #+#             */
/*   Updated: 2017/03/09 18:44:20 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

static int		subroutine_cvrt(size_t where)
{
	if (scop_cvrt_seek_vertex(env->obj.glpoint[where],
			&(env->obj.cvrt[env->obj.nb_cvrt])) == 0)
		return (0);
	(env->obj.nb_cvrt)++;
	return (1);
}

int				scop_cvrt_v(t_env *env)
{
	size_t	counter;

	counter = 0;
	while (counter < env->obj.nb_glpoint - 2)
	{
		if (env->obj.nb_cvrt + 3 >= env->obj.max_cvrt)
			realloc;
		if (subroutine_cvrt(0) == 0)
			return (0);
		if (subroutine_cvrt(counter + 1) == 0)
			return (0);
		if (subroutine_cvrt(counter + 2) == 0)
			return (0);
		scop_create_triangle_normal(env->obj.cvrt, env->obj.nb_cvrt - 3);
		counter++;
	}
	return (1);
}
