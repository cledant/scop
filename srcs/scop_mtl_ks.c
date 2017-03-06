/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scop_mtl_ks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/06 16:35:52 by cledant           #+#    #+#             */
/*   Updated: 2017/03/06 18:14:58 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

static int		read_third_component(const char *begin_ptr, t_obj_read *mtl,
					t_env *env)
{
	size_t		check;

	if ((check = begin_ptr - mtl->cpy_line) >= mtl->l_size ||
			*begin_ptr == '\0')
		return (0);
	env->obj.mat[env->obj.nb_mat - 1].spec_color.z = strtof(begin_ptr,
			NULL);
	if (scop_math_is_valid_float(env->obj.mat[env->obj.nb_mat - 1].spec_color.z)
			== 0)
		return (0);
	(mtl->valid_state[1]) = 0;
	return (1);
}

int				scop_mtl_ks(t_obj_read *mtl, t_env *env)
{
	size_t	check;
	char	*next_ptr;
	char	*begin_ptr;

	if (mtl->l_size < 3 || *(mtl->cpy_line + 3) == '\0')
		return (0);
	env->obj.mat[env->obj.nb_mat - 1].spec_color.x = strtof(mtl->cpy_line + 3,
			&next_ptr);
	if (scop_math_is_valid_float(env->obj.mat[env->obj.nb_mat - 1].spec_color.x)
			== 0)
		return (0);
	begin_ptr = next_ptr + 1;
	if ((check = begin_ptr - mtl->cpy_line) >= mtl->l_size ||
			*begin_ptr == '\0')
		return (0);
	env->obj.mat[env->obj.nb_mat - 1].spec_color.y = strtof(begin_ptr,
			&next_ptr);
	if (scop_math_is_valid_float(env->obj.mat[env->obj.nb_mat - 1].spec_color.y)
			== 0)
		return (0);
	begin_ptr = next_ptr + 1;
	if (read_third_component(begin_ptr, mtl, env) == 0)
		return (0);
	return (1);
}
