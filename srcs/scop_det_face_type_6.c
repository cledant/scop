/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scop_det_face_type_6.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/08 17:57:41 by cledant           #+#    #+#             */
/*   Updated: 2017/03/15 15:05:08 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

static inline int		last_part(const char *prev_end)
{
	extern int		errno;
	long			dummy;
	char			*begin;
	char			*end;

	errno = 0;
	begin = (char *)(prev_end + 1);
	dummy = strtol(begin, &end, 10);
	if (errno == EINVAL || errno == ERANGE || dummy <= 0)
		return (0);
	if (*end == '\0')
		return (1);
	return (0);
}

int						scop_det_face_type_6(const char *str,
							const size_t cur_pos, const size_t size)
{
	extern int		errno;
	long			dummy;
	char			*begin;
	char			*end;
	size_t			new_pos;

	errno = 0;
	begin = (char *)str;
	dummy = strtol(begin, &end, 10);
	if (errno == EINVAL || errno == ERANGE || dummy <= 0)
		return (0);
	new_pos = str - end + 1 + cur_pos;
	if (*end != '/' || (new_pos + 1) > size || *(end + 1) == '\0')
		return (0);
	begin = end + 1;
	errno = 0;
	dummy = strtol(begin, &end, 10);
	if (errno == EINVAL || errno == ERANGE || dummy <= 0)
		return (0);
	new_pos = str - end + 1 + cur_pos;
	if (*end != '/' || (new_pos + 1) > size || *(end + 1) == '\0')
		return (0);
	return (last_part(end));
}
