/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scop_exit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/05 14:40:21 by cledant           #+#    #+#             */
/*   Updated: 2017/03/16 12:58:54 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

static inline void		clean_mat(t_env *env)
{
	size_t	counter;

	counter = 0;
	while (counter < env->obj.nb_mat)
	{
		if (counter == 0)
		{
			glDeleteTextures(1, &(env->obj.mat[0].gl_tex));
			if (env->obj.mat[0].diff_tex != NULL)
				free(env->obj.mat[0].diff_tex);
		}
		else
		{
			glDeleteTextures(1, &(env->obj.mat[counter].gl_tex));
			if (env->obj.mat[counter].diff_tex != NULL)
				free(env->obj.mat[counter].diff_tex);
			if (env->obj.mat[counter].diff_tex_path != NULL)
				free(env->obj.mat[counter].diff_tex_path);
			if (env->obj.mat[counter].name != NULL)
				free(env->obj.mat[counter].name);
		}
		counter++;
	}
}

static inline void		clean_vao(t_env *env)
{
	size_t	counter;

	counter = 0;
	while (counter < env->obj.nb_vao)
	{
		if (env->obj.vao[counter].max_face != 0 &&
				env->obj.vao[counter].face_array != NULL)
			free(env->obj.vao[counter].face_array);
		glDeleteBuffers(1, &(env->obj.vao[counter].gl_vbo));
		counter++;
	}
}

static inline void		clean_obj(t_env *env)
{
	if (env->obj.max_pos != 0 && env->obj.v_pos != NULL)
		free(env->obj.v_pos);
	if (env->obj.max_norm != 0 && env->obj.v_norm != NULL)
		free(env->obj.v_norm);
	if (env->obj.max_tex != 0 && env->obj.v_tex != NULL)
		free(env->obj.v_tex);
	if (env->obj.max_glpoint != 0 && env->obj.glpoint != NULL)
		free(env->obj.glpoint);
	if (env->obj.max_cvrt != 0 && env->obj.cvrt != NULL)
		free(env->obj.cvrt);
	clean_vao(env);
	clean_mat(env);
}

int						scop_exit(t_env *env)
{
	if (env->win.win != NULL)
		glfwDestroyWindow(env->win.win);
	glDeleteShader(env->shader.shader_prog);
	glDeleteShader(env->shader.vertex_shader);
	glDeleteShader(env->shader.fragment_shader);
	if (env->folder != NULL)
		free(env->folder);
	clean_obj(env);
	glfwTerminate();
	return (0);
}
