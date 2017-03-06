/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scop_mtl_newmtl.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/06 13:09:52 by cledant           #+#    #+#             */
/*   Updated: 2017/03/06 18:16:57 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

int		scop_mtl_newmtl(t_obj_read *mtl, t_env *env)
{
	if (mtl->l_size < 7 || *(mtl->cpy_line + 7) == '\0')
		return (0);
	if ((env->obj.mat[env->obj.nb_mat].name = strdup(mtl->cpy_line + 7))
			== NULL)
		return (0);
	(env->obj.nb_mat)++;
	(mtl->valid_state[0]) = 1;
	(mtl->valid_state[1]) = 1;
	(mtl->valid_state[2]) = 1;
	(mtl->valid_state[3]) = 1;
	(mtl->valid_state[4]) = 1;
	(mtl->valid_state[5]) = 1;
	return (1);
}
