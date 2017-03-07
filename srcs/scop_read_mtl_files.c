/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scop_read_mtl_files.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/06 12:09:30 by cledant           #+#    #+#             */
/*   Updated: 2017/03/07 11:18:08 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

static inline int	error_mtllib(char *file, FILE *stream, int cases)
{
	perror("Scop :");
	if (cases == 0)
		puts("Scop : Error max material reached");
	else if (cases == 1)
		puts("Scop : Error seeking .mtl file name");
	else if (cases == 2)
		printf("Scop : Error openning : %s", file);
	else if (cases == 3)
		printf("Scop : Error parsing : %s", file);
	else if (cases == 4)
		printf("Scop : Error loading texture for : %s", file);
	if (file == NULL)
		free(file);
	if (stream != NULL)
		fclose(stream);
	return (0);
}

static inline char	*seek_second_arg(char *str, const size_t max)
{
	size_t		counter;
	char		*cpy_str;

	counter = 7;
	str = str + 7;
	cpy_str = str;
	while (counter < (max - 1) && *str != '\0' && *str != '\n')
	{
		str++;
		counter++;
	}
	if (counter - 7 == 0)
		return (NULL);
	return (cpy_str);
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
		return (error_mtllib(NULL, NULL, 0));
	if ((file = seek_second_arg(reader->cpy_line, reader->l_size)) == NULL)
		return (error_mtllib(NULL, NULL, 1));
	if ((stream = fopen(file, "r")) == NULL)
		return (error_mtllib(file, NULL, 2));
	if (scop_read_mtl_parsing(stream, env) == 0)
		return (error_mtllib(file, stream, 3));
	if (load_textures(env) == 0)
		return (error_mtllib(file, stream, 4));
	fclose(stream);
	reader->valid_state[1] = 0;
	return (1);
}
