/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scop_read_obj_files.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/05 15:06:36 by cledant           #+#    #+#             */
/*   Updated: 2017/03/05 15:23:52 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

static inline int		error_obj(const char *path)
{
	printf("Scop : error openning obj file : %s\n", path);
	if (stream != NULL)
		fclose(stream);
	return (0);
}

int						scop_read_obj_files(t_env *env, const char *path)
{
	FILE	*stream;

	if (stream = fopen(path, "r") == NULL)
		return (error_obj(path, stream));
	fclose(stream);
	return (1);
}
