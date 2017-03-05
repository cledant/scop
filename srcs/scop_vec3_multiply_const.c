/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scop_vec3_multiply_const.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/28 13:12:08 by cledant           #+#    #+#             */
/*   Updated: 2017/03/05 14:43:36 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

void	scop_vec3_multiply_const(t_vec3 *result, const t_vec3 a,
			const float cst)
{
	result->x = a.x * cst;
	result->y = a.y * cst;
	result->z = a.z * cst;
}
