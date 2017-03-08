/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scop_get_env.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/27 19:49:21 by cledant           #+#    #+#             */
/*   Updated: 2017/03/08 16:28:39 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

void	*scop_get_env(const void *addr)
{
	static t_env	*env = NULL;
	static int		safety = 0;

	if (addr != NULL && safety == 0)
	{
		env = addr;
		safety = 1;
		return (env);
	}
	return (env);
}
