/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scop_create_triangle_tex.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/10 10:21:44 by cledant           #+#    #+#             */
/*   Updated: 2017/03/10 11:03:29 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

int		scop_create_triangle_tex(t_env *env, const size_t index)
{
	static int		type = 0;

	if (type == 0)
	{
		env->obj.cvrt[index].tex.x = 0.0f;
		env->obj.cvrt[index].tex.y = 0.0f;
		env->obj.cvrt[index + 1].tex.x = 0.0f;
		env->obj.cvrt[index + 1].tex.y = 1.0f;
		env->obj.cvrt[index + 2].tex.x = 1.0f;
		env->obj.cvrt[index + 2].tex.y = 1.0f;
	}
	else
	{
		env->obj.cvrt[index].tex.x = 0.0f;
		env->obj.cvrt[index].tex.y = 0.0f;
		env->obj.cvrt[index + 1].tex.x = 1.0f;
		env->obj.cvrt[index + 1].tex.y = 1.0f;
		env->obj.cvrt[index + 2].tex.x = 1.0f;
		env->obj.cvrt[index + 2].tex.y = 0.0f;
	}
	type = (type == 0) ? 1 : 0;
	return (1);
}
