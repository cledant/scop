/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scop_read_obj_cases.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/06 12:21:49 by cledant           #+#    #+#             */
/*   Updated: 2017/03/07 17:33:14 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

int		scop_read_obj_cases(t_obj_read *reader, t_env *env)
{
	static int		(*fct[8])(t_obj_read *, t_env *) = {scop_read_mtl_files,
		scop_obj_v, scop_obj_vt, scop_obj_vn, scop_obj_g,
		scop_obj_usemtl, scop_obj_f, scop_obj_o};

	return ((*fct[reader->counter])(reader, env));
}
