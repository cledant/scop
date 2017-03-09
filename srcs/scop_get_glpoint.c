/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scop_get_glpoint.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/09 12:19:33 by cledant           #+#    #+#             */
/*   Updated: 2017/03/09 13:08:58 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

int		scop_get_glpoint(t_env *env, t_obj_read *obj, char **begin,
			const int expected_type)
{
	static int (*fct[7])(char **, const size_t, const size_t,
		t_glpoint *) = {scop_get_face_type_1, scop_get_face_type_2,
		scop_get_face_type_3, scop_get_face_type_4, scop_get_face_type_5,
		scop_get_face_type_6, scop_get_face_type_7};

	if ((*fct[expected_type - 1])(begin, *begin - obj.cpy_line + 1,
			obj.l_size, &(env->obj.glpoint[env->obj.nb_glpoint])) == 0)
		return (0);
	env->obj.nb_glpoint += 1;
	return (1);
}
