/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scop_cpy_cvrt_to_cur_vao.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/10 10:42:11 by cledant           #+#    #+#             */
/*   Updated: 2017/03/15 19:07:04 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

int		scop_cpy_cvrt_to_cur_vao(t_env *env)
{
	size_t		*f_index;

	if (env->obj.vao[env->obj.nb_vao - 1].nb_face + env->obj.nb_cvrt >=
			env->obj.vao[env->obj.nb_vao - 1].max_face)
	{
		if ((env->obj.vao[env->obj.nb_vao - 1].face_array =
				(t_face *)reallocf(env->obj.vao[env->obj.nb_vao - 1].face_array,
				sizeof(t_face) * (env->obj.vao[env->obj.nb_vao - 1].max_face +
				PRE_ALLOC))) == NULL)
			return (0);
		env->obj.vao[env->obj.nb_vao - 1].max_face += PRE_ALLOC;
	}
	f_index = &(env->obj.vao[env->obj.nb_vao - 1].nb_face);
	memcpy(&(env->obj.vao[env->obj.nb_vao - 1].face_array[*f_index]),
		&(env->obj.cvrt[0]), env->obj.nb_cvrt * sizeof(t_face));
	(*f_index) += env->obj.nb_cvrt;
	env->obj.nb_glpoint = 0;
	env->obj.nb_cvrt = 0;
	return (1);
}
