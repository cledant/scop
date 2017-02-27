/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scop.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/23 12:28:43 by cledant           #+#    #+#             */
/*   Updated: 2017/02/27 12:06:58 by cledant          ###   ########.fr       */
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

typedef float		t_mat4[16];

typedef struct		s_vec3
{
	float			x;
	float			y;
	float			z;
}					t_vec3;

typedef struct		s_vec4
{
	float			x;
	float			y;
	float			z;
	float			w;
}					t_vec4;

void	glBindVertexArray(GLuint arrays);
void	glGenVertexArrays(GLsizei n, GLuint *arrays);
void	scop_env_init(t_env *env);
int		scop_glfw_init(t_env *env);
void	scop_glfw_close_callback(GLFWwindow *win);
void	scop_glfw_error_callback(int error, const char *desc);
int		scop_exit(t_env *env);
void	scop_test_vertex_init(t_env *env);
int		scop_gl_init_shaders(t_env *env);
int		scop_gl_load_shader(GLuint *shader, GLenum s_type, const char *path);
int		scop_gl_create_shader_program(t_env *env);
void	scop_mat4_init(t_mat4 *matrix);
void	scop_mat4_set_translation(t_mat4 *matrix, const t_vec3 tr);
void	scop_mat4_set_rotation(t_mat4 *matrix, const float angle, t_vec3 axis);
void	scop_mat4_set_perspective(t_mat4 *matrix, const t_vec4 param);
void	scop_vec3_normalize(t_vec3 *vec);
float	scop_math_deg_to_rad(const float deg);
void	debug_state(void);

#endif
