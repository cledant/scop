/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scop_cpy_cvrt_to_cur_vao.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/10 10:42:11 by cledant           #+#    #+#             */
/*   Updated: 2017/03/10 10:44:47 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

int		scop_cpy_cvrt_to_cur_vao(t_env *env)
{
	env->obj.nb_glpoint = 0;
	env->obj.nb_cvrt = 0;
	return (1);
}
