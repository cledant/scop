/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scop_read_mtl_files.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/06 12:09:30 by cledant           #+#    #+#             */
/*   Updated: 2017/03/06 20:26:09 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

static inline int	error_mtllib(char *file, FILE *stream)
{
	if (file == NULL)
		puts("Scop : Error openning .mtl file");
	else
	{
		printf("Scop : Error parsing : %s", file);
		free(file);
	}
	if (stream != NULL)
		fclose(stream);
	return (0);
}

static inline char	*seek_second_arg(char *str, const size_t max)
{
	size_t		counter;

	counter = 7;
	str = str + 7;
	while (counter < (max - 1) && *str != '\0')
		counter++;
	if (counter - 7 == 0)
		return (NULL);
	return (str);
}

static inline int	load_textures(t_env *env)
{
	size_t		counter;

	counter = 1;
	while (counter < env->obj.nb_mat)
	{
		if (env->obj.mat[counter].diff_tex_path != NULL)
		{
			if ((env->obj.mat[counter].diff_tex =
					scop_load_texture(env->obj.mat[counter].diff_tex_path,
					&(env->obj.mat[counter]))) == NULL)
				return (0);
			scop_gl_bind_texture(&(env->obj.mat[counter]));
		}
		counter++;
	}
	return (1);
}

int					scop_read_mtl_files(t_obj_read *reader, t_env *env)
{
	char	*file;
	FILE	*stream;

	if (env->obj.nb_mat == MAX_MAT)
		return (error_mtllib(NULL, NULL));
	if ((file = seek_second_arg(reader->cpy_line, reader->l_size)) == NULL)
		return (error_mtllib(NULL, NULL));
	if ((stream = fopen(file, "r")) == NULL)
		return (error_mtllib(file, NULL));
	if (scop_read_mtl_parsing(stream, env) == 0)
		return (error_mtllib(file, stream));
	if (load_textures(env) == 0)
		return (error_mtllib(file, stream));
	fclose(stream);
	reader->valid_state[1] = 0;
	return (1);
}
