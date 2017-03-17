/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scop_obj_usemtl.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/07 08:25:36 by cledant           #+#    #+#             */
/*   Updated: 2017/03/17 16:21:34 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

int			scop_obj_usemtl(t_obj_read *obj, t_env *env)
{
	size_t	counter;

	if (obj->l_size < 7 || *(obj->cpy_line + 7) == '\0')
		return (0);
	counter = 1;
	if (scop_obj_g(obj, env) == 0)
		return (0);
	while (counter < env->obj.nb_mat)
	{
		if (strcmp(obj->cpy_line + 7, env->obj.mat[counter].name) == 0)
		{
			env->obj.vao[env->obj.nb_vao - 1].mat_id = counter;
			return (1);
		}
		counter++;
	}
	obj->valid_state[0] = 0;
	obj->valid_state[1] = 0;
	obj->valid_state[2] = 0;
	obj->valid_state[3] = 0;
	obj->valid_state[4] = 1;
	obj->valid_state[5] = 1;
	obj->valid_state[6] = 1;
	return (0);
}
