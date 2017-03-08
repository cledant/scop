/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scop_det_face_type_1.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/08 15:59:09 by cledant           #+#    #+#             */
/*   Updated: 2017/03/08 17:48:52 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

int		scop_det_face_type_1(const char *str, const size_t cur_pos,
			const size_t size)
{
	extern int		errno;
	long			dummy;
	char			*begin;
	char			*end;

	errno = 0;
	begin = str;
	(void)size;
	(void)cur_pos;
	dummy = strtol(begin, &end, 10);
	if (errno == EINVAL || errno == ERANGE || dummy <= 0)
		return (0);
	if (end == '\0')
		return (1);
	return (0);
}
