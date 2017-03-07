/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scop_delete_return_line.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/07 11:09:15 by cledant           #+#    #+#             */
/*   Updated: 2017/03/07 11:17:09 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

void	scop_delete_return_line(char *str)
{
	char	*loc;

	loc = strchr(str, '\n');
	if (loc != NULL)
		*loc = '\0';
}
