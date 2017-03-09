/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scop_det_face_type_4.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/08 17:41:11 by cledant           #+#    #+#             */
/*   Updated: 2017/03/09 17:20:14 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

int		scop_get_face_type_4(char **str, const size_t cur_pos,
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
	if (*end != '/' || (new_pos + 1) > size || *(end + 1) == '\0')
		return (0);
	begin = end + 1;
	errno = 0;
	glpoint->tex = strtol(begin, &end, 10);
	glpoint->norm = 0;
	if (errno == EINVAL || errno == ERANGE || glpoint->tex <= 0)
		return (0);
	if (*end == '\0')
	{
		*str = end;
		return (1);
	}
	return (0);
}
