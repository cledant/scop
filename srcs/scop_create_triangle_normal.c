/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scop_create_triangle_normal.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/09 21:26:37 by cledant           #+#    #+#             */
/*   Updated: 2017/03/10 10:06:59 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

int		scop_create_triangle_normal(t_env *env, const size_t index)
{
	t_vec3		ab;
	t_vec3		ac;
	t_vec3		norm;

	scop_tvec3_set(&ab, env->obj.cvrt[index + 1].pos.x -
		env->obj.cvrt[index].pos.x, env->obj.cvrt[index + 1].pos.y -
		env->obj.cvrt[index].pos.y, env->obj.cvrt[index + 1].pos.z -
		env->obj.cvrt[index].pos.z);
	scop_tvec3_set(&ac, env->obj.cvrt[index + 2].pos.x -
		env->obj.cvrt[index].pos.x, env->obj.cvrt[index + 2].pos.y -
		env->obj.cvrt[index].pos.y, env->obj.cvrt[index + 2].pos.z -
		env->obj.cvrt[index].pos.z);
	scop_cross_prod(&norm, ab, ac);
	scop_tvec3_set(&(env->obj.cvrt[index].norm), norm.x, norm.y, norm.z);
	scop_tvec3_set(&(env->obj.cvrt[index + 1].norm), norm.x, norm.y, norm.z);
	scop_tvec3_set(&(env->obj.cvrt[index + 2].norm), norm.x, norm.y, norm.z);
	return (1);
}
