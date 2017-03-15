/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scop_cvrt_v_vn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/10 17:26:22 by cledant           #+#    #+#             */
/*   Updated: 2017/03/15 11:32:40 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

static inline int		subroutine_cvrt(size_t where, t_env *env)
{
	if (scop_cvrt_seek_vertex(env, where) == 0)
		return (0);
	if (scop_cvrt_seek_norm(env, where) == 0)
		return (0);
	(env->obj.nb_cvrt)++;
	return (1);
}

int						scop_cvrt_v_vn(t_env *env)
{
	size_t	counter;
	size_t	index;

	counter = 0;
	while (counter < env->obj.nb_glpoint - 2)
	{
		index = env->obj.nb_cvrt;
		if (env->obj.nb_cvrt + 3 >= env->obj.max_cvrt)
		{
			if ((env->obj.cvrt = (t_face *)reallocf(env->obj.cvrt,
					sizeof(t_face) * (PRE_ALLOC + env->obj.max_cvrt))) == NULL)
				return (0);
			env->obj.max_cvrt += PRE_ALLOC;
		}
		if (subroutine_cvrt(0, env) == 0)
			return (0);
		if (subroutine_cvrt(counter + 1, env) == 0)
			return (0);
		if (subroutine_cvrt(counter + 2, env) == 0)
			return (0);
		scop_create_triangle_tex(env, index);
		scop_create_triangle_color(env, index);
		counter++;
	}
	return (1);
}
