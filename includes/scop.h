/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scop.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/23 12:28:43 by cledant           #+#    #+#             */
/*   Updated: 2017/03/01 12:49:03 by cledant          ###   ########.fr       */
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

typedef GLfloat		t_mat4[4][4];

typedef struct		s_vec3
{
	GLfloat			x;
	GLfloat			y;
	GLfloat			z;
}					t_vec3;

typedef struct		s_vec4
{
	GLfloat			x;
	GLfloat			y;
	GLfloat			z;
	GLfloat			w;
}					t_vec4;

typedef struct		s_env
{
	GLFWwindow		*win;
	int				win_h;
	int				win_w;
	GLfloat			fov;
	GLuint			vbo;
	GLuint			vao;
	GLuint			ebo;
	GLuint			shader_prog;
	GLuint			vertex_shader;
	GLuint			fragment_shader;
	t_mat4			proj;
	t_mat4			model;
	t_mat4			view;
	GLint			m_proj;
	GLint			m_model;
	GLint			m_view;
	int				p_key[1024];
	t_vec3			pos;
	t_vec3			target;
	t_vec3			up_vec;
	t_vec3			front;
	GLfloat			cam_speed;
	GLfloat			sensitivity;
	GLfloat			last_x;
	GLfloat			last_y;
	GLfloat			rot_x;
	GLfloat			rot_y;
	GLfloat			delta_time;
	GLfloat			prev_time;
	char			*tex;
}					t_env;

typedef struct		s_tga_header
{
	unsigned char	id_len;
	unsigned char	color_map_type;
	unsigned char	image_type;
	unsigned char	unused_1;
	unsigned char	unused_2;
	unsigned char	unused_3;
	unsigned char	unused_4;
	unsigned char	unused_5;
	unsigned short	x_orig;
	unsigned short	y_orig;
	unsigned short	img_w;
	unsigned short	img_h;
	unsigned char	pixel_depth;
	unsigned char	img_desc;
}					t_tga_header;

void	glBindVertexArray(GLuint arrays);
void	glGenVertexArrays(GLsizei n, GLuint *arrays);
/*
** GLFW FUNCTIONS
*/
int		scop_glfw_init(t_env *env);
void	scop_glfw_close_callback(GLFWwindow *win);
void	scop_glfw_error_callback(int error, const char *desc);
void	scop_glfw_window_size_callback(GLFWwindow *win, int w, int h);
void	scop_glfw_mouse_pos_callback(GLFWwindow *win, double xpos, double ypos);
void	scop_glfw_key_callback(GLFWwindow *win, int key, int scancode, int action,
			int mods);
/*
** SHADER FUNCTIONS
*/
int		scop_gl_init_shaders(t_env *env);
int		scop_gl_init_matrix(t_env *env);
int		scop_gl_load_shader(GLuint *shader, GLenum s_type, const char *path);
int		scop_gl_create_shader_program(t_env *env);
/*
** MAT4 FUNCTIONS
*/
void	scop_mat4_init(t_mat4 *matrix);
void	scop_mat4_set_translation(t_mat4 *matrix, const t_vec3 tr);
void	scop_mat4_set_rotation(t_mat4 *matrix, const float angle, t_vec3 axis);
void	scop_mat4_set_perspective(t_mat4 *matrix, const t_vec4 param);
void	scop_mat4_set_identity(t_mat4 *matrix);
void	scop_mat4_set_camera(t_mat4 *view, const t_vec3 pos,
			const t_vec3 target, const t_vec3 vec_up);
void	scop_mat4_multiply(t_mat4 *result, const t_mat4 a, const t_mat4 b);
/*
** VEC3 FUNCTIONS
*/
void	scop_vec3_normalize(t_vec3 *param);
void	scop_vec3_set(t_vec3 *vec, const float x, const float y, const float z);
void	scop_vec3_substract(t_vec3 *result, const t_vec3 a, const t_vec3 b);
void	scop_vec3_add(t_vec3 *result, const t_vec3 a, const t_vec3 b);
void	scop_vec3_cross_prod(t_vec3 *result, const t_vec3 a, const t_vec3 b);
void	scop_vec3_multiply_const(t_vec3 *result, const t_vec3 a, const float cst);
/*
** MATH FUNCTIONS
*/
float	scop_math_deg_to_rad(const float deg);
float	scop_math_dot_product(const t_vec3 a, const t_vec3 b);
/*
** OTHER FUNCTION
*/
int		scop_exit(t_env *env);
void	scop_init_env(t_env *env);
void	*scop_get_env(void *addr);
void	scop_execute_mov(t_env *env);
void	scop_execute_mouse_mov(t_env *env);
void	scop_vector_init_env(t_env *env);
char	*scop_load_texture(const char *path);
/*
** TEST FUNCTIONS
*/
void	scop_test_vertex_init(t_env *env);
void	debug_state(void);
#endif
