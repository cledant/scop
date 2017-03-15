/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scop_obj_v.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/06 19:28:16 by cledant           #+#    #+#             */
/*   Updated: 2017/03/15 15:58:29 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

static inline int	read_third_component(const char *begin_ptr, t_obj_read *obj,
						t_env *env)
{
	size_t	check;

	if ((check = begin_ptr - obj->cpy_line) >= obj->l_size ||
			*begin_ptr == '\0')
		return (0);
	env->obj.v_pos[env->obj.nb_pos].z = strtof(begin_ptr, NULL);
	if (scop_math_is_valid_float(env->obj.v_pos[env->obj.nb_pos].z) == 0)
		return (0);
	(obj->valid_state[0]) = 0;
	(obj->valid_state[1]) = 1;
	(obj->valid_state[2]) = 1;
	(obj->valid_state[3]) = 1;
	(obj->valid_state[4]) = 1;
	(obj->valid_state[5]) = 1;
	(obj->valid_state[6]) = 1;
	(env->obj.nb_pos)++;
	(env->obj.nb_obj) = 1;
	return (1);
}

static inline int	realloc_v_pos(t_env *env)
{
	if ((env->obj.v_pos = (t_vec3 *)reallocf(env->obj.v_pos,
			(env->obj.max_pos + PRE_ALLOC) * sizeof(t_vec3))) == NULL)
		return (0);
	env->obj.max_pos += PRE_ALLOC;
	return (1);
}

int					scop_obj_v(t_obj_read *obj, t_env *env)
{
	size_t	check;
	char	*next_ptr;
	char	*begin_ptr;

	if (env->obj.nb_pos == env->obj.max_pos)
	{
		if (realloc_v_pos(env) == 0)
			return (0);
	}
	if (obj->l_size < 2 || *(obj->cpy_line + 2) == '\0')
		return (0);
	env->obj.v_pos[env->obj.nb_pos].x = strtof(obj->cpy_line + 2, &next_ptr);
	if (scop_math_is_valid_float(env->obj.v_pos[env->obj.nb_pos].x) == 0)
		return (0);
	begin_ptr = next_ptr + 1;
	if ((check = begin_ptr - obj->cpy_line) >= obj->l_size ||
			*begin_ptr == '\0')
		return (0);
	env->obj.v_pos[env->obj.nb_pos].y = strtof(begin_ptr, &next_ptr);
	if (scop_math_is_valid_float(env->obj.v_pos[env->obj.nb_pos].y) == 0)
		return (0);
	begin_ptr = next_ptr + 1;
	if (read_third_component(begin_ptr, obj, env) == 0)
		return (0);
	return (1);
}
