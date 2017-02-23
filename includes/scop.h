/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scop.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/23 12:28:43 by cledant           #+#    #+#             */
/*   Updated: 2017/02/23 18:52:04 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCOP_H
# define SCOP_H

# include <stdio.h>
# include <math.h>
# include <stdlib.h>
# include "glfw3.h"

typedef struct		s_env
{
	GLFWwindow		*win;
	int				win_h;
	int				win_w;
}					t_env;

void	scop_init_env(t_env *env);
int		scop_init_glfw(t_env *env);
void	scop_close_callback(GLFWwindow *win);
void	scop_error_callback(int error, const char *desc);
int		scop_exit(t_env *env);

#endif
