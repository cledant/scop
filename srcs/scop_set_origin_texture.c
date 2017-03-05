/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scop_set_origin_texture.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/01 17:07:47 by cledant           #+#    #+#             */
/*   Updated: 2017/03/05 16:45:24 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

void	scop_set_origin_texture(const char img_desc, t_mat *mat)
{
	unsigned char	res;

	res = img_desc & 0x30;
	res = res >> 4;
	mat->tex_origin = res;
}
