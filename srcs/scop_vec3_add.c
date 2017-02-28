/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scop_vec3_add.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/28 12:47:22 by cledant           #+#    #+#             */
/*   Updated: 2017/02/28 12:47:36 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

void	scop_vec3_add(t_vec3 *result, const t_vec3 a, const t_vec3 b)
{
	result->x = a.x + b.x;
	result->y = a.y + b.y;
	result->z = a.z + b.z;
}
