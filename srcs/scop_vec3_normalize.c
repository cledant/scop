/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scop_vec3_normalize.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/27 12:07:30 by cledant           #+#    #+#             */
/*   Updated: 2017/02/27 16:26:32 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

void	scop_vec3_normalize(t_vec3 *param)
{
	float	norm;

	if ((norm = sqrtf(param->x * param->x + param->y * param->y
			+ param->z * param->z)) == 1.0f)
		return ;
	param->x = param->x / norm;
	param->y = param->y / norm;
	param->z = param->z / norm;
}
