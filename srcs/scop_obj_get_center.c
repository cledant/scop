/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scop_obj_get_center.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/11 11:17:29 by cledant           #+#    #+#             */
/*   Updated: 2017/03/13 12:23:48 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

int		scop_obj_get_center(t_env *env)
{
	size_t	counter;

	counter = 0;
	while (counter < env->obj.nb_pos)
	{
		env->obj.center.x += env->obj.v_pos[counter].x;
		env->obj.center.y += env->obj.v_pos[counter].y;
		env->obj.center.z += env->obj.v_pos[counter].z;
		counter++;
	}
	if (scop_math_is_valid_float(env->obj.center.x) == 0)
		return (0);
	if (scop_math_is_valid_float(env->obj.center.y) == 0)
		return (0);
	if (scop_math_is_valid_float(env->obj.center.z) == 0)
		return (0);
	if (env->obj.nb_pos > 0)
	{
		env->obj.center.x /= -env->obj.nb_pos;
		env->obj.center.y /= -env->obj.nb_pos;
		env->obj.center.z /= -env->obj.nb_pos;
	}
	return (1);
}
