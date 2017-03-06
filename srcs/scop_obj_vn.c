/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scop_obj_vn.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/06 19:28:16 by cledant           #+#    #+#             */
/*   Updated: 2017/03/06 20:22:24 by cledant          ###   ########.fr       */
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
	env->obj.v_norm[env->obj.nb_norm].z = strtof(begin_ptr, NULL);
	if (scop_math_is_valid_float(env->obj.v_norm[env->obj.nb_norm].z) == 0)
		return (0);
	(obj->valid_state[0]) = 0;
	(obj->valid_state[1]) = 0;
	(obj->valid_state[2]) = 0;
	(obj->valid_state[3]) = 1;
	(obj->valid_state[4]) = 1;
	(obj->valid_state[5]) = 1;
	(obj->valid_state[6]) = 1;
	(env->obj.nb_norm)++;
	return (1);
}

static inline int	realloc_v_norm(t_env *env)
{
	if ((env->obj.v_norm = (t_vec3 *)reallocf(env->obj.v_norm,
			(env->obj.max_norm + PRE_ALLOC) * sizeof(t_vec3))) == NULL)
		return (0);
	env->obj.max_norm += PRE_ALLOC;
	return (1);
}

int				scop_obj_vn(t_obj_read *obj, t_env *env)
{
	size_t	check;
	char	*next_ptr;
	char	*begin_ptr;

	if (env->obj.nb_norm == env->obj.max_norm)
	{
		if (realloc_v_norm(env) == 0)
			return (0);
	}
	if (obj->l_size < 2 || *(obj->cpy_line + 2) == '\0')
		return (0);
	env->obj.v_norm[env->obj.nb_norm].x = strtof(obj->cpy_line + 2, &next_ptr);
	if (scop_math_is_valid_float(env->obj.v_norm[env->obj.nb_norm].x) == 0)
		return (0);
	begin_ptr = next_ptr + 1;
	if ((check = begin_ptr - obj->cpy_line) >= obj->l_size ||
			*begin_ptr == '\0')
		return (0);
	env->obj.v_norm[env->obj.nb_norm].y = strtof(begin_ptr, &next_ptr);
	if (scop_math_is_valid_float(env->obj.v_norm[env->obj.nb_norm].y) == 0)
		return (0);
	begin_ptr = next_ptr + 1;
	if (read_third_component(begin_ptr, obj, env) == 0)
		return (0);
	return (1);
}
