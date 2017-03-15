/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scop_cpy_cvrt_to_cur_vao.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/10 10:42:11 by cledant           #+#    #+#             */
/*   Updated: 2017/03/15 10:55:35 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

int		scop_cpy_cvrt_to_cur_vao(t_env *env)
{
	size_t		*f_index;
	size_t		counter;

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
	counter = 0;
	f_index = &(env->obj.vao[env->obj.nb_vao - 1].nb_face);
	while (counter < env->obj.nb_cvrt)
	{
		(*f_index)++;
		env->obj.vao[env->obj.nb_vao - 1].face_array[*f_index - 1].pos.x =
			env->obj.cvrt[counter].pos.x;
		env->obj.vao[env->obj.nb_vao - 1].face_array[*f_index - 1].pos.y =
			env->obj.cvrt[counter].pos.y;
		env->obj.vao[env->obj.nb_vao - 1].face_array[*f_index - 1].pos.z =
			env->obj.cvrt[counter].pos.z;
		env->obj.vao[env->obj.nb_vao - 1].face_array[*f_index - 1].norm.x =
			env->obj.cvrt[counter].norm.x;
		env->obj.vao[env->obj.nb_vao - 1].face_array[*f_index - 1].norm.y =
			env->obj.cvrt[counter].norm.y;
		env->obj.vao[env->obj.nb_vao - 1].face_array[*f_index - 1].norm.z =
			env->obj.cvrt[counter].norm.z;
		env->obj.vao[env->obj.nb_vao - 1].face_array[*f_index - 1].tex.x =
			env->obj.cvrt[counter].tex.x;
		env->obj.vao[env->obj.nb_vao - 1].face_array[*f_index - 1].tex.y =
			env->obj.cvrt[counter].tex.y;
		env->obj.vao[env->obj.nb_vao - 1].face_array[*f_index - 1].color.x =
			env->obj.cvrt[counter].color.x;
		env->obj.vao[env->obj.nb_vao - 1].face_array[*f_index - 1].color.y =
			env->obj.cvrt[counter].color.y;
		env->obj.vao[env->obj.nb_vao - 1].face_array[*f_index - 1].color.z =
			env->obj.cvrt[counter].color.z;
		counter++;
	}
	env->obj.nb_glpoint = 0;
	env->obj.nb_cvrt = 0;
	return (1);
}
