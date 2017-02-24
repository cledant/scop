/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scop.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/23 12:28:43 by cledant           #+#    #+#             */
/*   Updated: 2017/02/24 17:52:04 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCOP_H
# define SCOP_H

# include <OpenGL/gl.h>
# include <stdio.h>
# include <math.h>
# include <stdlib.h>
# include <string.h>
# include "glfw3.h"


typedef struct		s_env
{
	GLFWwindow		*win;
	int				win_h;
	int				win_w;
	GLuint			vbo;
	GLuint			vao;
	GLuint			ebo;
	GLuint			shader_prog;
	GLuint			vertex_shader;
	GLuint			fragment_shader;
}					t_env;

void	scop_env_init(t_env *env);
int		scop_glfw_init(t_env *env);
void	scop_glfw_close_callback(GLFWwindow *win);
void	scop_glfw_error_callback(int error, const char *desc);
int		scop_exit(t_env *env);
void	scop_test_vertex_init(t_env *env);
int		scop_gl_init_shaders(t_env *env);
int		scop_gl_load_shader(GLuint *shader, GLenum s_type, const char *path);
int		scop_gl_create_shader_program(t_env *env);

#endif
