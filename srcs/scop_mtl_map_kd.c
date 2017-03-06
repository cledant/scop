/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scop_mtl_map_kd.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/06 15:07:16 by cledant           #+#    #+#             */
/*   Updated: 2017/03/06 15:28:51 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

int		scop_mtl_map_kd(t_obj_read *mtl, t_env *env)
{
	
	if (mtl->l_size < 7 || *(mtl->cpy_line + 7) == '\0')
		return (0);
	if ((env->obj.mat[env->obj.nb_mat - 1].map_kd = strdup(mtl->cpy_line + 7))
			== NULL)
		return (0);
	(mtl->valid_state[5]) = 0;
	return (1);
}
