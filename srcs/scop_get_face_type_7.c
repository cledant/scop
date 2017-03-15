/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scop_get_face_type_7.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/08 17:32:13 by cledant           #+#    #+#             */
/*   Updated: 2017/03/15 15:05:41 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

static inline int		succes_ret(char **str, char *end)
{
	*str = end;
	return (1);
}

int						scop_get_face_type_7(char **str, const size_t cur_pos,
							const size_t size, t_glpoint *glpoint)
{
	extern int		errno;
	char			*begin;
	char			*end;
	size_t			new_pos;

	errno = 0;
	begin = *str;
	glpoint->vertex = strtol(begin, &end, 10);
	if (errno == EINVAL || errno == ERANGE || glpoint->vertex <= 0)
		return (0);
	new_pos = *str - end + 1 + cur_pos;
	if (*end == '\0' || (new_pos + 2) > size)
		return (0);
	if (*end != '/' || *(end + 1) != '/' || *(end + 2) == '\0')
		return (0);
	errno = 0;
	begin = end + 2;
	glpoint->norm = strtol(begin, &end, 10);
	if (errno == EINVAL || errno == ERANGE || glpoint->norm <= 0)
		return (0);
	if (*end == '\0')
		return (succes_ret(str, end));
	return (0);
}
