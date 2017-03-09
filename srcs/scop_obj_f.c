/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scop_obj_f.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/07 09:53:41 by cledant           #+#    #+#             */
/*   Updated: 2017/03/09 10:32:09 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

int		scop_obj_f(t_obj_read *obj, t_env *env)
{
	static int	expected_type = 0;
	static int	(*fct[4])(t_obj_read *, t_env *, int) = {scop_obj_face_v,
			scop_obj_face_v_vt, scop_obj_face_v_vt_vn, scop_obj_face_v_vn};
	int			type;

	if (expected_type == 0)
		if ((expected_type = scop_determine_face_type(obj)) == -1)
			return (0);
	if (expected_type == 1 || expected_type == 2 || expected_type == 3)
		type = 0;
	else if (expected_type == 4 || expected_type == 5)
		type = 1;
	else if (expected_type == 6)
		type = 2;
	else if (expected_type == 7)
		type = 3;
	obj->valid_state[0] = 0;
	obj->valid_state[1] = 0;
	obj->valid_state[2] = 0;
	obj->valid_state[3] = 0;
	obj->valid_state[4] = 1;
	obj->valid_state[5] = 0;
	obj->valid_state[6] = 1;
	return ((*fct[type])(obj, env, expected_type));
}
