/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scop_read_obj_files.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/05 15:06:36 by cledant           #+#    #+#             */
/*   Updated: 2017/03/10 18:49:12 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

static inline int		error_obj(const char *path, FILE *stream)
{
	printf("Scop : error openning obj file : %s\n", path);
	if (stream != NULL)
		fclose(stream);
	return (0);
}

static inline void		init_reader(t_obj_read *reader)
{
	(reader->valid_state)[0] = 1;
	(reader->valid_state)[1] = 1;
	(reader->valid_state)[2] = 0;
	(reader->valid_state)[3] = 0;
	(reader->valid_state)[4] = 0;
	(reader->valid_state)[5] = 0;
	(reader->valid_state)[6] = 0;
	(reader->valid_state)[7] = 1;
	reader->line = NULL;
	reader->cpy_line = NULL;
	reader->l_size = 0;
	reader->counter = 0;
	reader->ret = 0;
	reader->curr_line_nb = 1;
}

static inline int		error_read(t_obj_read *reader)
{
	printf("Scop : error reading file .obj at line %ld\n",
		reader->curr_line_nb);
	free(reader->cpy_line);
	return (0);
}

static inline int		read_file(FILE *stream, t_env *env, t_obj_read *reader)
{
	static char	value[8][16] = {"mtllib", "v", "vt", "vn", "g", "usemtl", "f",
									"o"};

	while (getline(&(reader->line), &(reader->l_size), stream) != -1)
	{
		scop_delete_return_line(reader->line);
		reader->cpy_line = reader->line;
		while (strsep(&(reader->line), " ") != NULL)
			(void)value;
		while (reader->counter < 7 && *(reader->cpy_line) != '\0')
		{
			if (reader->valid_state[reader->counter] == 1 &&
					strcmp(value[reader->counter], reader->cpy_line) == 0)
				if ((reader->ret = scop_read_obj_cases(reader, env)) == 0)
					return (error_read(reader));
			(reader->counter)++;
		}
		reader->counter = 0;
		free(reader->cpy_line);
		(reader->curr_line_nb)++;
	}
	if (feof(stream) != 0)
		return (1);
	return (0);
}

int						scop_read_obj_files(t_env *env, const char *path)
{
	FILE	*stream;
	t_obj_read	reader;

	if ((stream = fopen(path, "r")) == NULL)
		return (error_obj(path, stream));
	if ((env->obj.v_pos = (t_vec3 *)malloc(sizeof(t_vec3) * PRE_ALLOC)) == NULL)
		return (error_obj(path, stream));
	env->obj.max_pos = PRE_ALLOC;
	if ((env->obj.v_norm = (t_vec3 *)malloc(sizeof(t_vec3) * PRE_ALLOC))
			== NULL)
		return (error_obj(path, stream));
	env->obj.max_norm = PRE_ALLOC;
	if ((env->obj.v_tex = (t_vec2 *)malloc(sizeof(t_vec2) * PRE_ALLOC)) == NULL)
		return (error_obj(path, stream));
	env->obj.max_tex = PRE_ALLOC;
	if ((env->obj.glpoint = (t_glpoint *)malloc(sizeof(t_glpoint) * PRE_ALLOC))
			== NULL)
		return (error_obj(path, stream));
	env->obj.max_glpoint = PRE_ALLOC;
	if ((env->obj.cvrt = (t_face *)malloc(sizeof(t_face) * PRE_ALLOC))
			== NULL)
		return (error_obj(path, stream));
	env->obj.max_cvrt = PRE_ALLOC;
	init_reader(&reader);
	if (read_file(stream, env, &reader) == 0)
		return (error_obj(path, stream));
	fclose(stream);
	return (1);
}
