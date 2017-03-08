/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scop_det_face_type_3.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/08 17:32:13 by cledant           #+#    #+#             */
/*   Updated: 2017/03/08 18:16:37 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

int		scop_det_face_type_3(const char *str, const size_t cur_pos,
			const size_t size)
{
	extern int		errno;
	long			dummy;
	char			*begin;
	char			*end;
	size_t			new_pos;

	errno = 0;
	begin = str;
	dummy = strtol(begin, &end, 10);
	if (errno == EINVAL || errno == ERANGE || dummy <= 0)
		return (0);
	new_pos = str - end + 1 + cur_pos;
	if (*end == '\0' || (new_pos + 2) > size)
		return (0);
	if (*end == '/' && *(end + 1) == '/' && *(end + 2) == '\0')
		return (1);
	return (0);
}
