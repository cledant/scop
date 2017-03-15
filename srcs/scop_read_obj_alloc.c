/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scop_read_obj_alloc.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/15 15:55:57 by cledant           #+#    #+#             */
/*   Updated: 2017/03/15 15:56:24 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

int		scop_read_obj_alloc(t_env *env)
{
	if ((env->obj.v_pos = (t_vec3 *)malloc(sizeof(t_vec3) * PRE_ALLOC)) == NULL)
		return (0);
	env->obj.max_pos = PRE_ALLOC;
	if ((env->obj.v_norm = (t_vec3 *)malloc(sizeof(t_vec3) * PRE_ALLOC))
			== NULL)
		return (0);
	env->obj.max_norm = PRE_ALLOC;
	if ((env->obj.v_tex = (t_vec2 *)malloc(sizeof(t_vec2) * PRE_ALLOC)) == NULL)
		return (0);
	env->obj.max_tex = PRE_ALLOC;
	if ((env->obj.glpoint = (t_glpoint *)malloc(sizeof(t_glpoint) * PRE_ALLOC))
			== NULL)
		return (0);
	env->obj.max_glpoint = PRE_ALLOC;
	if ((env->obj.cvrt = (t_face *)malloc(sizeof(t_face) * PRE_ALLOC))
			== NULL)
		return (0);
	env->obj.max_cvrt = PRE_ALLOC;
	return (1);
}
