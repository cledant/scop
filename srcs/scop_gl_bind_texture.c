/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scop_gl_bind_texture.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/01 13:17:32 by cledant           #+#    #+#             */
/*   Updated: 2017/03/01 13:29:43 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

void	scop_gl_bind_texture(t_env *env)
{
	glGenTextures(1, &(env->texture));
	glBindTexture(GL_TEXTURE_2D, env->texture);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, env->tex_w, env->tex_h, 0, GL_RGB,
			GL_UNSIGNED_BYTE, env->tex);
	glGenerateMipmap(GL_TEXTURE_2D);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glBindTexture(GL_TEXTURE_2D, 0);
}
