/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scop_mat4_init.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/27 10:45:30 by cledant           #+#    #+#             */
/*   Updated: 2017/02/27 10:47:08 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

void	scop_mat4_init(t_mat4 *matrix)
{
	(*matrix)[0] = 0.0f;
	(*matrix)[1] = 0.0f;
	(*matrix)[2] = 0.0f;
	(*matrix)[3] = 0.0f;
	(*matrix)[4] = 0.0f;
	(*matrix)[5] = 0.0f;
	(*matrix)[6] = 0.0f;
	(*matrix)[7] = 0.0f;
	(*matrix)[8] = 0.0f;
	(*matrix)[9] = 0.0f;
	(*matrix)[10] = 0.0f;
	(*matrix)[11] = 0.0f;
	(*matrix)[12] = 0.0f;
	(*matrix)[13] = 0.0f;
	(*matrix)[14] = 0.0f;
	(*matrix)[15] = 1.0f;
}
