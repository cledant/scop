/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scop_obj_o.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/07 17:35:12 by cledant           #+#    #+#             */
/*   Updated: 2017/03/07 17:46:41 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

int		scop_obj_o(t_obj_read *obj, t_env *env)
{
	if (env->obj.nb_obj == 0 && env->obj.nb_pos == 0)
	{
		(obj->valid_state)[0] = 0;
		(env->obj.nb_obj) = 1;
	}
	else if (env->obj.nb_obj == 1 && env->obj.nb_pos != 0)
	{
		(obj->valid_state)[0] = 0;
		(obj->valid_state)[1] = 0;
		(obj->valid_state)[2] = 0;
		(obj->valid_state)[3] = 0;
		(obj->valid_state)[4] = 0;
		(obj->valid_state)[5] = 0;
		(obj->valid_state)[6] = 0;
		(obj->valid_state)[7] = 0;
	}
	return (1);
}
