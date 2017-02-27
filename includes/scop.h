/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scop.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/23 12:28:43 by cledant           #+#    #+#             */
/*   Updated: 2017/02/27 20:51:43 by cledant          ###   ########.fr       */
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

# define PRESSED 1
# define RELEASED 0

typedef GLfloat		t_mat4[16];

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
	GLint			m_proj;
	GLint			m_model;
	GLint			m_view;
	int				p_key[1024];
	t_vec3			cam_pos;
	GLfloat			cam_speed;
}					t_env;

void	glBindVertexArray(GLuint arrays);
void	glGenVertexArrays(GLsizei n, GLuint *arrays);
void	scop_init_env(t_env *env);
void	*scop_get_env(void *addr);
int		scop_glfw_init(t_env *env);
void	scop_glfw_close_callback(GLFWwindow *win);
void	scop_glfw_error_callback(int error, const char *desc);
void	scop_glfw_window_size_callback(GLFWwindow *win, int w, int h);
void	scop_glfw_key_callback(GLFWwindow *win, int key, int scancode, int action,
			int mods);
int		scop_exit(t_env *env);
void	scop_test_vertex_init(t_env *env);
int		scop_gl_init_shaders(t_env *env);
int		scop_gl_init_matrix(t_env *env);
int		scop_gl_load_shader(GLuint *shader, GLenum s_type, const char *path);
int		scop_gl_create_shader_program(t_env *env);
void	scop_mat4_init(t_mat4 *matrix);
void	scop_mat4_set_translation(t_mat4 *matrix, const t_vec3 tr);
void	scop_mat4_set_rotation(t_mat4 *matrix, const float angle, t_vec3 axis);
void	scop_mat4_set_perspective(t_mat4 *matrix, const t_vec4 param);
void	scop_mat4_set_identity(t_mat4 *matrix);
void	scop_vec3_normalize(t_vec3 *param);
float	scop_math_deg_to_rad(const float deg);
void	debug_state(void);

#endif
