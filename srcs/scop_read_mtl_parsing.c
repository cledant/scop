/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scop_read_mtl_parsing.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/06 12:10:59 by cledant           #+#    #+#             */
/*   Updated: 2017/03/06 18:10:44 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

static int			error_read_mtl(t_obj_read *mtl)
{
	printf("Scop : error reading .mtl file at line %ld\n", mtl->curr_line_nb);
	free(mtl->cpy_line);
	return (0);
}

static void			init_mtl_reader(t_obj_read *mtl)
{
	(mtl->valid_state)[0] = 1;
	(mtl->valid_state)[1] = 0;
	(mtl->valid_state)[2] = 0;
	(mtl->valid_state)[3] = 0;
	(mtl->valid_state)[4] = 0;
	(mtl->valid_state)[5] = 0;
	mtl->line = NULL;
	mtl->cpy_line = NULL;
	mtl->l_size = 0;
	mtl->counter = 0;
	mtl->ret = 0;
	mtl->curr_line_nb = 0;
}

int					scop_read_mtl_parsing(FILE *stream, t_env *env)
{
	static char		value[6][16] = {"newmtl", "Kd", "Ka", "Ks", "Ns", "map_Kd"};
	t_obj_read		mtl;

	init_mtl_reader(&mtl);
	while (getline(&(mtl.line), &(mtl.l_size), stream) != -1)
	{
		mtl.cpy_line = mtl.line;
		while (strsep(&(mtl.line), " ") != NULL)
			(void)value;
		while (mtl.counter < 6 && *(mtl.cpy_line) != '\0')
		{
			if (mtl.valid_state[mtl.counter] == 1 &&
					strcmp(value[mtl.counter], mtl.cpy_line) == 0)
				mtl.ret = scop_read_mtl_cases(&mtl, env);
			if (mtl.ret == 0)
				return (error_read_mtl(&mtl));
			(mtl.counter)++;
		}
		mtl.counter = 0;
		free(mtl.cpy_line);
		(mtl.curr_line_nb)++;
	}
	if (feof(stream) != 0)
		return (1);
	return (0);
}
