/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scop_math_deg_to_rad.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/27 11:47:02 by cledant           #+#    #+#             */
/*   Updated: 2017/02/27 11:51:01 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

float inline	scop_math_deg_to_rad(const float deg)
{
	return (deg * M_PI / 180.f);
}