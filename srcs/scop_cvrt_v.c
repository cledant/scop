/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scop_cvrt_v.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/09 17:56:12 by cledant           #+#    #+#             */
/*   Updated: 2017/03/09 22:03:57 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

static int		subroutine_cvrt(size_t where, t_env *env)
{
	if (scop_cvrt_seek_vertex(env->obj.glpoint[where],
			env->obj.cvrt[env->obj.nb_cvrt], &(env->obj)) == 0) // verif
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
			//faire cas de realloc a faire ici
		if (subroutine_cvrt(0, env) == 0)
			return (0);
		if (subroutine_cvrt(counter + 1, env) == 0)
			return (0);
		if (subroutine_cvrt(counter + 2, env) == 0)
			return (0);
		scop_create_triangle_normal(env->obj.cvrt, env->obj.nb_cvrt); //verif
		counter++;
		env->obj.nb_cvrt += 3;
	}
	return (1);
}
