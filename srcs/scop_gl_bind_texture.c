/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scop_gl_bind_texture.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/01 13:17:32 by cledant           #+#    #+#             */
/*   Updated: 2017/03/14 17:29:28 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

void	scop_gl_bind_texture(t_mat *mat)
{
	glGenTextures(1, &(mat->gl_tex));
	glBindTexture(GL_TEXTURE_2D, mat->gl_tex);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER,
		GL_LINEAR_MIPMAP_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	if (mat->depth == 24)
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, mat->tex_w, mat->tex_h, 0,
			GL_BGR, GL_UNSIGNED_BYTE, mat->diff_tex);
	else
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, mat->tex_w, mat->tex_h, 0,
			GL_BGRA, GL_UNSIGNED_BYTE, mat->diff_tex);
	glGenerateMipmap(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, 0);
}
