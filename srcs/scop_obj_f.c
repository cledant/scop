/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scop_obj_f.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/07 09:53:41 by cledant           #+#    #+#             */
/*   Updated: 2017/03/08 13:07:21 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

int		scop_obj_f(t_obj_read *obj, t_env *env)
{
	static int	expected_type = 0;
	static int	(*fct[4])(t_obj_read *, t_env *, int) = {scop_obj_face_v,
			scop_obj_face_v_vt, scop_obj_face_v_vt_vn, scop_obj_face_v_vn};
	int			type;

	if (obj->l_size < 2 || *(obj->cpy_line + 2) == '\0')
		return (0);
	if (env->obj.nb_norm == 0)
		if (scop_generate_normals(env) == 0)
			return (0);
	if (expected_type == 0)
		if ((expected_type = scop_check_face_type(obj->cpy_line + 2)) == -1)
			return (0)
	if ((type = scop_check_face_type(obj, env)) == -1)
		return (0);
	obj->valid_state[0] = 0;
	obj->valid_state[1] = 0;
	obj->valid_state[2] = 0;
	obj->valid_state[3] = 0;
	obj->valid_state[4] = 1;
	obj->valid_state[5] = 0;
	obj->valid_state[6] = 1;
	return ((*fct[type])(obj, env, type));
}
