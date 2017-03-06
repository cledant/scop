/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scop_read_mtl_cases.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/06 12:24:27 by cledant           #+#    #+#             */
/*   Updated: 2017/03/06 12:51:04 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

int		scop_read_mtl_cases(t_obj_read *reader, t_env *env)
{
	static int		(*fct[6])(t_obj_read *, t_env *) = {scop_mtl_newmtl,
		scop_mtl_kd, scop_mtl_ka, scop_mtl_ks, scop_mtl_ns,
		scop_mtl_map_kd};

	return ((*fct[reader->counter])(reader, env));
}
