/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scop_init_vao.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/07 09:27:19 by cledant           #+#    #+#             */
/*   Updated: 2017/03/07 09:53:11 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

int		scop_init_vao(t_env *env, size_t id)
{
	if ((env->obj.vao[id].face_array =
			(t_face *)malloc(sizeof(t_face) * PRE_ALLOC)) == NULL)
		return (0);
	env->obj.vao[id].nb_face = 0;
	env->obj.vao[id].max_face = PRE_ALLOC;
	env->obj.vao[id].mat_id = 0;
	(env->obj.nb_vao)++;
	return (1);
}
