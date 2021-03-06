/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scop_get_face_type_2.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/08 15:59:09 by cledant           #+#    #+#             */
/*   Updated: 2017/03/15 14:47:05 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

int		scop_get_face_type_2(char **str, const size_t cur_pos,
			const size_t size, t_glpoint *glpoint)
{
	extern int		errno;
	char			*begin;
	char			*end;
	size_t			new_pos;

	errno = 0;
	begin = *str;
	glpoint->vertex = strtol(*str, &end, 10);
	glpoint->tex = 0;
	glpoint->norm = 0;
	if (errno == EINVAL || errno == ERANGE || glpoint->vertex <= 0)
		return (0);
	new_pos = end - *str + 1 + cur_pos;
	if (*end == '\0' || (new_pos + 1) > size)
		return (0);
	if (*end == '/' && *(end + 1) == '\0')
	{
		*str = end + 1;
		return (1);
	}
	return (0);
}
