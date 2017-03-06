/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scop_mtl_ns.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/06 16:27:13 by cledant           #+#    #+#             */
/*   Updated: 2017/03/06 18:16:42 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

int		scop_mtl_ns(t_obj_read *mtl, t_env *env)
{
	if (mtl->l_size < 3 || *(mtl->cpy_line + 3) == '\0')
		return (0);
	env->obj.mat[env->obj.nb_mat - 1].shine = strtof(mtl->cpy_line + 3, NULL);
	if (scop_math_is_valid_float(env->obj.mat[env->obj.nb_mat - 1].shine) == 0)
		return (0);
	(mtl->valid_state[4]) = 0;
	return (1);
}
