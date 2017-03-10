/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scop_obj_v.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/06 19:28:16 by cledant           #+#    #+#             */
/*   Updated: 2017/03/10 14:28:43 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

static inline void	set_next(t_obj_read *obj, t_env *env)
{
	(obj->valid_state[0]) = 0;
	(obj->valid_state[1]) = 0;
	(obj->valid_state[2]) = 1;
	(obj->valid_state[3]) = 1;
	(obj->valid_state[4]) = 1;
	(obj->valid_state[5]) = 1;
	(obj->valid_state[6]) = 1;
	(env->obj.nb_tex)++;
}

static inline int	realloc_v_tex(t_env *env)
{
	if ((env->obj.v_tex = (t_vec2 *)reallocf(env->obj.v_tex, (env->obj.max_tex +
			PRE_ALLOC) * sizeof(t_vec2))) == NULL)
		return (0);
	env->obj.max_tex += PRE_ALLOC;
	return (1);
}

int				scop_obj_vt(t_obj_read *obj, t_env *env)
{
	size_t	check;
	char	*next_ptr;
	char	*begin_ptr;

	if (env->obj.nb_tex == env->obj.max_tex)
	{
		if (realloc_v_tex(env) == 0)
			return (0);
	}
	if (obj->l_size < 3 || *(obj->cpy_line + 3) == '\0')
		return (0);
	env->obj.v_tex[env->obj.nb_tex].x = strtof(obj->cpy_line + 3, &next_ptr);
	if (scop_math_is_valid_float(env->obj.v_tex[env->obj.nb_tex].x) == 0)
		return (0);
	begin_ptr = next_ptr + 1;
	if ((check = begin_ptr - obj->cpy_line) >= obj->l_size ||
			*begin_ptr == '\0')
		return (0);
	env->obj.v_tex[env->obj.nb_tex].y = strtof(begin_ptr, NULL);
	if (scop_math_is_valid_float(env->obj.v_tex[env->obj.nb_tex].y) == 0)
		return (0);
	set_next(obj, env);
	return (1);
}
