/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scop_det_face_type_6.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/08 17:57:41 by cledant           #+#    #+#             */
/*   Updated: 2017/03/15 15:02:35 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

static inline int		last_part(char **prev_end, t_glpoint *glpoint)
{
	extern int		errno;
	char			*begin;
	char			*end;

	errno = 0;
	begin = *prev_end + 1;
	glpoint->norm = strtol(begin, &end, 10);
	if (errno == EINVAL || errno == ERANGE || glpoint->norm <= 0)
		return (0);
	if (*end == '\0')
	{
		*prev_end = end;
		return (1);
	}
	return (0);
}

int						scop_get_face_type_6(char **str, const size_t cur_pos,
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
	new_pos = end - *str + 1 + cur_pos;
	if (*end != '/' || (new_pos + 1) > size || *(end + 1) == '\0')
		return (0);
	begin = end + 1;
	errno = 0;
	glpoint->tex = strtol(begin, &end, 10);
	if (errno == EINVAL || errno == ERANGE || glpoint->tex <= 0)
		return (0);
	new_pos = end - *str + 1 + cur_pos;
	if (*end != '/' || (new_pos + 1) > size || *(end + 1) == '\0')
		return (0);
	*str = end;
	return (last_part(str, glpoint));
}
