/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scop_determine_face_type.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/08 15:51:37 by cledant           #+#    #+#             */
/*   Updated: 2017/03/08 17:21:47 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

int		scop_determine_face_type(t_obj_read *obj)
{
	size_t		counter;
	static int	(*fct[7])(const char *, const size_t, const size_t) = {
		scop_det_face_type_1, scop_det_face_type_2, scop_det_face_type_3,
		scop_det_face_type_4, scop_det_face_type_5, scop_det_face_type_6,
		scop_det_face_type_7};

	if (obj->l_size < 2 || *(obj->cpy_line + 2) == '\0')
		return (-1);
	counter = 0;
	while (counter < 7)
	{
		if ((*fct[counter])(env->cpy_obj + 2, 2, env->l_size) == 1)
			return (counter + 1);
		counter++;
	}
	return (-1);
}
