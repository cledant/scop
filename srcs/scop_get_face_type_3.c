/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scop_get_face_type_3.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/09 13:16:10 by cledant           #+#    #+#             */
/*   Updated: 2017/03/09 14:47:54 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

int		scop_get_face_type_3(char **str, const size_t cur_pos,
			const size_t size, t_glpoint *glpoint)
{
	extern int		errno;
	char			*begin;
	char			*end;
	size_t			new_pos;

	errno = 0;
	begin = *str;
	glpoint->vertex = strtol(begin, &end, 10);
	glpoint->tex = 0;
	glpoint->norm = 0;
	if (errno == EINVAL || errno == ERANGE || glpoint->vertex <= 0)
		return (0);
	new_pos = end - *str + 1 + cur_pos;
	if (*end == '\0' || (new_pos + 2) > size)
		return (0);
	if (*end == '/' && *(end + 1) == '/' && *(end + 2) == '\0')
	{
		*str = end + 2;
		return (1);
	}
	return (0);
}
