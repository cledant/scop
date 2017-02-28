/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scop_vec3_substract.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/28 11:54:13 by cledant           #+#    #+#             */
/*   Updated: 2017/02/28 11:59:55 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

void	scop_vec3_substract(t_vec3 *result, const t_vec3 a, const t_vec3 b)
{
	result->x = a.x - b.x;
	result->y = a.y - b.y;
	result->z = a.z - b.z;
}
