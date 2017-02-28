/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scop_vec3_cross_prod.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/28 12:47:56 by cledant           #+#    #+#             */
/*   Updated: 2017/02/28 12:50:29 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

void	scop_vec3_cross_prod(t_vec3 *result, const t_vec3 a, const t_vec3 b)
{
	result->x = a.y * b.z - a.z * b.y;
	result->y = a.z * b.x - a.x * b.z;
	result->z = a.x * b.y - a.y * b.x;
}
