/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scop_get_faces.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/09 10:25:46 by cledant           #+#    #+#             */
/*   Updated: 2017/03/09 18:57:59 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

static int		enlarge_array(t_env *env)
{
	if ((env->obj.glpoint = (t_glpoint *)reallocf(env->obj.glpoint,
			sizeof(t_glpoint) * (env->obj.max_glpoint + PRE_ALLOC))) == NULL)
		return (0);
	env->obj.max_glpoint += PRE_ALLOC;
	return (1);
}

int				scop_get_faces(t_obj_read *obj, t_env *env,
					const int expected_type, const int group_type)
{
	size_t		cur_pos;
	char		*begin;

	if (obj->l_size < 2 || *(obj->cpy_line + 2) == '\0')
		return (0);
	cur_pos = 2;
	begin = obj->cpy_line + 2;
	while (1)
	{
		if (env->obj.nb_glpoint == env->obj.max_glpoint)
			if (enlarge_array(env) == 0)
				return (0);
		if (scop_get_glpoint(env, obj, &begin, expected_type) == 0)
			return (0);
		cur_pos = begin - obj->cpy_line + 1;
		if (cur_pos + 1 > obj->l_size || *(begin + 1) == '\0')
			break ;
		begin++;
	}
	if (scop_convert_glpoint_to_vao(env, group_type) == 0)
		return (0);
	env->obj.nb_glpoint = 0;
	return (1);
}
