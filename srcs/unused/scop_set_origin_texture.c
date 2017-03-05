/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scop_set_origin_texture.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/01 17:07:47 by cledant           #+#    #+#             */
/*   Updated: 2017/03/01 18:37:00 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

void	scop_set_origin_texture(const char img_desc, t_env *env)
{
	unsigned char	res;

	res = img_desc & 0x30;
	res = res >> 4;
	env->tex_origin = res;
}
