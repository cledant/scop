/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scop_vec3_set.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/28 11:45:41 by cledant           #+#    #+#             */
/*   Updated: 2017/02/28 13:38:32 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

void	scop_vec3_set(t_vec3 *vec, const float x, const float y, const float z)
{
	vec->x = x;
	vec->y = y;
	vec->z = z;
}
