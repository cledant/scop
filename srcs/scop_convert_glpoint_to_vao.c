/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scop_convert_glpoint_to_vao.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/09 17:39:19 by cledant           #+#    #+#             */
/*   Updated: 2017/03/09 18:46:17 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

int		scop_convert_glpoint_to_vao(t_env *env, const int group_type)
{
	static int	(*fct[4])(t_env *) = {scop_cvrt_v, scop_cvrt_v_vt,
		scop_cvrt_v_vt_vn, scop_cvrt_v_vn};

	if (env->obj.nb_glpoint <= 2)
		return (0);
	return ((*fct[group_type])(env));
}
