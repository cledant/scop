/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scop_get_folder.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/07 11:31:00 by cledant           #+#    #+#             */
/*   Updated: 2017/03/07 12:08:28 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

char	*scop_get_folder(const char *arg)
{
	char	*last_sep;
	char	*ret;
	size_t	len;

	ret = NULL;
	if ((last_sep = strrchr(arg, '/')) != NULL)
	{
		len = last_sep - arg + 1;
		if ((ret = (char *)malloc(sizeof(char) * (len + 1))) == NULL)
			return (NULL);
		strncpy(ret, arg, len);
		ret[len] = '\0';
	}
	else
	{
		if ((ret = strdup("./")) == NULL)
			return (NULL);
	}
	return (ret);
}
