/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scop_vec4_set.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/15 12:19:34 by cledant           #+#    #+#             */
/*   Updated: 2017/03/15 12:21:09 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

void		scop_vec4_set(t_vec4 *vec, const t_vec4 a)
{
	vec->x = a.x;
	vec->y = a.y;
	vec->z = a.z;
	vec->w = a.w;
}
