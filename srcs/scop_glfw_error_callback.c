/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scop_glfw_error_callback.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/23 18:39:58 by cledant           #+#    #+#             */
/*   Updated: 2017/02/24 12:56:51 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

void	scop_glfw_error_callback(int error, const char *desc)
{
	printf("Scop : GLFW Error number : %d\n%s\n", error, desc);
}
