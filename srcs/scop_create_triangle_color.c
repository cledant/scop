/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scop_create_triangle_tex.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/10 10:21:44 by cledant           #+#    #+#             */
/*   Updated: 2017/03/15 11:44:13 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

int		scop_create_triangle_color(t_env *env, const size_t index)
{
	static int		type = 0;

	if (type == 0)
	{
		env->obj.cvrt[index].color.x = 1.0f;
		env->obj.cvrt[index].color.y = 1.0f;
		env->obj.cvrt[index].color.z = 1.0f;
		env->obj.cvrt[index + 1].color.x = 1.0f;
		env->obj.cvrt[index + 1].color.y = 1.0f;
		env->obj.cvrt[index + 1].color.z = 1.0f;
		env->obj.cvrt[index + 2].color.x = 1.0f;
		env->obj.cvrt[index + 2].color.y = 1.0f;
		env->obj.cvrt[index + 2].color.z = 1.0f;
	}
	else if (type == 1)
	{
		env->obj.cvrt[index].color.x = 0.8f;
		env->obj.cvrt[index].color.y = 0.8f;
		env->obj.cvrt[index].color.z = 0.8f;
		env->obj.cvrt[index + 1].color.x = 0.8f;
		env->obj.cvrt[index + 1].color.y = 0.8f;
		env->obj.cvrt[index + 1].color.z = 0.8f;
		env->obj.cvrt[index + 2].color.x = 0.8f;
		env->obj.cvrt[index + 2].color.y = 0.8f;
		env->obj.cvrt[index + 2].color.z = 0.8f;
	}
	else if (type == 2)
	{
		env->obj.cvrt[index].color.x = 0.6f;
		env->obj.cvrt[index].color.y = 0.6f;
		env->obj.cvrt[index].color.z = 0.6f;
		env->obj.cvrt[index + 1].color.x = 0.6f;
		env->obj.cvrt[index + 1].color.y = 0.6f;
		env->obj.cvrt[index + 1].color.z = 0.6f;
		env->obj.cvrt[index + 2].color.x = 0.6f;
		env->obj.cvrt[index + 2].color.y = 0.6f;
		env->obj.cvrt[index + 2].color.z = 0.6f;
	}
	else if (type == 3)
	{
		env->obj.cvrt[index].color.x = 0.4f;
		env->obj.cvrt[index].color.y = 0.4f;
		env->obj.cvrt[index].color.z = 0.4f;
		env->obj.cvrt[index + 1].color.x = 0.4f;
		env->obj.cvrt[index + 1].color.y = 0.4f;
		env->obj.cvrt[index + 1].color.z = 0.4f;
		env->obj.cvrt[index + 2].color.x = 0.4f;
		env->obj.cvrt[index + 2].color.y = 0.4f;
		env->obj.cvrt[index + 2].color.z = 0.4f;
	}
	else if (type == 4)
	{
		env->obj.cvrt[index].color.x = 0.2f;
		env->obj.cvrt[index].color.y = 0.2f;
		env->obj.cvrt[index].color.z = 0.2f;
		env->obj.cvrt[index + 1].color.x = 0.2f;
		env->obj.cvrt[index + 1].color.y = 0.2f;
		env->obj.cvrt[index + 1].color.z = 0.2f;
		env->obj.cvrt[index + 2].color.x = 0.2f;
		env->obj.cvrt[index + 2].color.y = 0.2f;
		env->obj.cvrt[index + 2].color.z = 0.2f;
	}
	type++;
	if (type > 4)
		type = 0;
	return (1);
}
