/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scop_get_face_type_1.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/09 12:46:47 by cledant           #+#    #+#             */
/*   Updated: 2017/03/09 14:45:30 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

int		scop_get_face_type_1(char **str, const size_t cur_pos,
			const size_t size, t_glpoint *glpoint)
{
	extern int		errno;
	char			*end;

	errno = 0;
	(void)size;
	(void)cur_pos;
	glpoint->vertex = strtol(*str, &end, 10);
	glpoint->tex = 0;
	glpoint->norm = 0;
	if (errno == EINVAL || errno == ERANGE || glpoint->vertex <= 0)
		return (0);
	if (end == '\0')
	{
		*str = end;
		return (1);
	}
	return (0);
}
