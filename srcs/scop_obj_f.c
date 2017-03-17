/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scop_obj_f.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/07 09:53:41 by cledant           #+#    #+#             */
/*   Updated: 2017/03/17 16:24:16 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

int		scop_obj_f(t_obj_read *obj, t_env *env)
{
	static int	expected_type = 0;

	if (expected_type == 0)
	{
		if ((expected_type = scop_determine_face_type(obj)) == -1)
			return (0);
		if (expected_type == 1 || expected_type == 2 || expected_type == 3)
			env->obj.group_type = GRP_V;
		else if (expected_type == 4 || expected_type == 5)
			env->obj.group_type = GRP_V_VT;
		else if (expected_type == 6)
			env->obj.group_type = GRP_V_VT_VN;
		else if (expected_type == 7)
			env->obj.group_type = GRP_V_VN;
		else
			return (0);
	}
	obj->valid_state[0] = 0;
	obj->valid_state[1] = 0;
	obj->valid_state[2] = 0;
	obj->valid_state[3] = 0;
	obj->valid_state[4] = 1;
	obj->valid_state[5] = 1;
	obj->valid_state[6] = 1;
	return (scop_get_faces(obj, env, expected_type, env->obj.group_type));
}
