/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scop_strjoin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/07 12:24:40 by cledant           #+#    #+#             */
/*   Updated: 2017/03/07 13:05:11 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

char	*scop_strjoin(const char *s1, const char *s2)
{
	size_t		len;
	char		*ret;

	len = strlen(s1) + strlen(s2);
	if ((ret = (char *)malloc(sizeof(char) * (len + 1))) == NULL)
		return (NULL);
	memset(ret, 0, len + 1);
	strcat(ret, s1);
	strcat(ret, s2);
	return (ret);
}
