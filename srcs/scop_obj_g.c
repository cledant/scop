/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scop_obj_g.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/06 20:29:18 by cledant           #+#    #+#             */
/*   Updated: 2017/03/17 16:17:33 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

int		scop_obj_g(t_obj_read *obj, t_env *env)
{
	if (env->obj.nb_vao == MAX_VAO)
		return (0);
	if (env->obj.vao[env->obj.nb_vao - 1].nb_face == 0)
		return (1);
	if (scop_init_vao(env, env->obj.nb_vao) == 0)
		return (0);
	obj->valid_state[0] = 0;
	obj->valid_state[1] = 0;
	obj->valid_state[2] = 0;
	obj->valid_state[3] = 0;
	obj->valid_state[4] = 1;
	obj->valid_state[5] = 1;
	obj->valid_state[6] = 1;
	return (1);
}
