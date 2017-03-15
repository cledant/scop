/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scop_create_triangle_tex.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/10 10:21:44 by cledant           #+#    #+#             */
/*   Updated: 2017/03/15 20:08:35 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

static inline void		cases_part3(t_env *env, const size_t index,
							const int type)
{
	if (type == 3)
	{
		scop_vec4_set(&(env->obj.cvrt[index].color), (t_vec4){0.4f, 0.4f,
			0.4f, 1.0f});
		scop_vec4_set(&(env->obj.cvrt[index + 1].color), (t_vec4){0.4f, 0.4f,
			0.4f, 1.0f});
		scop_vec4_set(&(env->obj.cvrt[index + 2].color), (t_vec4){0.4f, 0.4f,
			0.4f, 1.0f});
	}
	else if (type == 4)
	{
		scop_vec4_set(&(env->obj.cvrt[index].color), (t_vec4){0.2f, 0.2f,
			0.2f, 1.0f});
		scop_vec4_set(&(env->obj.cvrt[index + 1].color), (t_vec4){0.2f, 0.2f,
			0.2f, 1.0f});
		scop_vec4_set(&(env->obj.cvrt[index + 2].color), (t_vec4){0.2f, 0.2f,
			0.2f, 1.0f});
	}
}

static inline void		cases_part2(t_env *env, const size_t index,
							const int type)
{
	if (type == 1)
	{
		scop_vec4_set(&(env->obj.cvrt[index].color), (t_vec4){0.8f, 0.8f,
			0.8f, 1.0f});
		scop_vec4_set(&(env->obj.cvrt[index + 1].color), (t_vec4){0.8f, 0.8f,
			0.8f, 1.0f});
		scop_vec4_set(&(env->obj.cvrt[index + 2].color), (t_vec4){0.8f, 0.8f,
			0.8f, 1.0f});
	}
	else if (type == 2)
	{
		scop_vec4_set(&(env->obj.cvrt[index].color), (t_vec4){0.6f, 0.6f,
			0.6f, 1.0f});
		scop_vec4_set(&(env->obj.cvrt[index + 1].color), (t_vec4){0.6f, 0.6f,
			0.6f, 1.0f});
		scop_vec4_set(&(env->obj.cvrt[index + 2].color), (t_vec4){0.6f, 0.6f,
			0.6f, 1.0f});
	}
	else
		cases_part3(env, index, type);
}

int						scop_create_triangle_color(t_env *env,
							const size_t index)
{
	static int		type = 0;

	if (type == 0)
	{
		scop_vec4_set(&(env->obj.cvrt[index].color), (t_vec4){1.0f, 1.0f,
			1.0f, 1.0f});
		scop_vec4_set(&(env->obj.cvrt[index + 1].color), (t_vec4){1.0f, 1.0f,
			1.0f, 1.0f});
		scop_vec4_set(&(env->obj.cvrt[index + 2].color), (t_vec4){1.0f, 1.0f,
			1.0f, 1.0f});
	}
	else
		cases_part2(env, index, type);
	type++;
	if (type > 4)
		type = 0;
	return (1);
}
