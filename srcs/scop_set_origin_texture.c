/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scop_set_origin_texture.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/01 17:07:47 by cledant           #+#    #+#             */
/*   Updated: 2017/03/01 17:48:03 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

void	scop_set_origin_texture(const char img_desc, t_env *env)
{
	unsigned char	res;

	res = img_desc & 0b00001100;
	res = res >> 2;
	env->tex_origin = res;
}
