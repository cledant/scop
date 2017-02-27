/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scop_vec3_normalize.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/27 12:07:30 by cledant           #+#    #+#             */
/*   Updated: 2017/02/27 12:11:49 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

void	scop_vec3_normalize(t_vec3 *vec)
{
	float	norm;

	if ((norm = sqrtf(param.x + param.y + param.z)) == 1.0f)
		return ;
	param.x = param.x / norm;
	param.y = param.y / norm;
	param.z = param.z / norm;
}
