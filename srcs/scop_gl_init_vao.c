/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scop_gl_init_vao.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/16 17:05:37 by cledant           #+#    #+#             */
/*   Updated: 2017/03/16 17:11:31 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

static inline void			routine_vao(t_env *env, const size_t counter)
{
	glBindBuffer(GL_ARRAY_BUFFER, env->obj.vao[counter].gl_vbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof(t_face) *
		env->obj.vao[counter].nb_face, env->obj.vao[counter].face_array,
		GL_STATIC_DRAW);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(t_face),
		(GLvoid *)0);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(t_face),
		(GLvoid *)(3 * sizeof(GLfloat)));
	glEnableVertexAttribArray(1);
	glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, sizeof(t_face),
		(GLvoid *)(6 * sizeof(GLfloat)));
	glEnableVertexAttribArray(2);
	glVertexAttribPointer(3, 4, GL_FLOAT, GL_FALSE, sizeof(t_face),
		(GLvoid *)(8 * sizeof(GLfloat)));
	glEnableVertexAttribArray(3);
}

void						scop_gl_init_vao(t_env *env)
{
	size_t		counter;

	counter = 0;
	while (counter < env->obj.nb_vao)
	{
		if (env->obj.vao[counter].nb_face > 0)
		{
			glGenVertexArrays(1, &(env->obj.vao[counter].gl_vao));
			glGenBuffers(1, &(env->obj.vao[counter].gl_vbo));
			glBindVertexArray(env->obj.vao[counter].gl_vao);
			routine_vao(env, counter);
			glBindVertexArray(0);
		}
		counter++;
	}
}
