/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scop.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/23 12:28:43 by cledant           #+#    #+#             */
/*   Updated: 2017/03/18 11:46:58 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCOP_H
# define SCOP_H

# define GLFW_INCLUDE_GLCOREARB

# include <stdio.h>
# include <math.h>
# include <stdlib.h>
# include <string.h>
# include <sys/errno.h>
# include "glfw3.h"

# define PRESSED 1
# define RELEASED 0

# define BOT_LEFT 0
# define BOT_RIGHT 1
# define TOP_LEFT 2
# define TOP_RIGHT 3

# define GRP_V 0
# define GRP_V_VT 1
# define GRP_V_VT_VN 2
# define GRP_V_VN 3

# define MAX_VAO 128
# define MAX_MAT 128

# define PRE_ALLOC 512

typedef GLfloat		t_mat4[4][4];

typedef struct		s_vec2
{
	GLfloat			x;
	GLfloat			y;
}					t_vec2;

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

typedef struct		s_face
{
	t_vec3			pos;
	t_vec3			norm;
	t_vec2			tex;
	t_vec4			color;
}					t_face;

typedef struct		s_vao
{
	t_face			*face_array;
	GLuint			gl_vao;
	GLuint			gl_vbo;
	size_t			nb_face;
	size_t			max_face;
	size_t			mat_id;
}					t_vao;

typedef struct		s_mat
{
	char			*name;
	t_vec3			amb_color;
	t_vec3			diff_color;
	t_vec3			spec_color;
	GLfloat			shine;
	char			*diff_tex_path;
	char			*diff_tex;
	size_t			tex_h;
	size_t			tex_w;
	int				tex_origin;
	GLuint			gl_tex;
	size_t			depth;
}					t_mat;

typedef struct		s_glpoint
{
	long			vertex;
	long			tex;
	long			norm;
}					t_glpoint;

typedef struct		s_obj
{
	t_vec3			*v_pos;
	size_t			nb_pos;
	size_t			max_pos;
	t_vec3			*v_norm;
	size_t			nb_norm;
	size_t			max_norm;
	t_vec2			*v_tex;
	size_t			nb_tex;
	size_t			max_tex;
	t_mat			mat[MAX_MAT];
	size_t			nb_mat;
	t_vao			vao[MAX_VAO];
	size_t			nb_vao;
	size_t			nb_obj;
	t_glpoint		*glpoint;
	size_t			nb_glpoint;
	size_t			max_glpoint;
	t_face			*cvrt;
	size_t			nb_cvrt;
	size_t			max_cvrt;
	int				group_type;
	t_vec3			center;
	GLfloat			auto_rot_angle;
	GLfloat			color_transition;
}					t_obj;

typedef struct		s_win
{
	GLFWwindow		*win;
	int				win_h;
	int				win_w;
	GLfloat			fov;
}					t_win;

typedef struct		s_shader
{
	GLuint			shader_prog;
	GLuint			vertex_shader;
	GLuint			fragment_shader;
}					t_shader;

typedef struct		s_light
{
	t_vec3			pos;
	t_vec3			color;
	GLfloat			p_amb;
	GLfloat			p_diff;
	GLfloat			p_spec;
}					t_light;

typedef struct		s_matrix
{
	t_mat4			proj;
	t_mat4			model_orig;
	t_mat4			model_auto_rot;
	t_mat4			model_rot_phi;
	t_mat4			model_rot_theta;
	t_mat4			model_tr;
	t_mat4			view;
	t_mat4			scale;
}					t_matrix;

typedef struct		s_uniform
{
	GLint			mat_proj;
	GLint			mat_model_orig;
	GLint			mat_model_auto_rot;
	GLint			mat_view;
	GLint			mat_scale;
	GLint			mat_model_rot_theta;
	GLint			mat_model_rot_phi;
	GLint			mat_model_tr;
	GLint			tex_tex;
	GLint			var_tex_origin;
	GLint			var_wiremode;
	GLint			var_color_transition;
}					t_uniform;

typedef struct		s_camera
{
	t_vec3			pos;
	t_vec3			target;
	t_vec3			up_vec;
	t_vec3			front;
}					t_camera;

typedef struct		s_input
{
	int				p_key[1024];
	GLfloat			cam_speed;
	GLfloat			sensitivity;
	GLfloat			last_x;
	GLfloat			last_y;
	GLfloat			rot_x;
	GLfloat			rot_y;
	GLfloat			delta_time;
	GLfloat			prev_time;
	GLfloat			scale;
	GLfloat			timer;
	int				wire;
	int				toggle_rot;
	int				toggle_color_transition;
	int				toggle_mouse;
	GLfloat			model_rot_phi;
	GLfloat			model_rot_theta;
	t_vec3			model_pos;
}					t_input;

typedef struct		s_env
{
	t_win			win;
	t_shader		shader;
	t_uniform		uniform;
	t_obj			obj;
	t_light			light;
	t_input			input;
	t_camera		cam;
	t_matrix		matrix;
	char			*folder;
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

typedef struct		s_obj_read
{
	char			*line;
	char			*cpy_line;
	size_t			l_size;
	int				valid_state[8];
	size_t			counter;
	size_t			ret;
	size_t			curr_line_nb;
}					t_obj_read;

/*
** GLFW FUNCTIONS
*/
int					scop_glfw_init(t_env *env);
void				scop_glfw_close_callback(GLFWwindow *win);
void				scop_glfw_error_callback(int error, const char *desc);
void				scop_glfw_window_size_callback(GLFWwindow *win, int w,
						int h);
void				scop_glfw_mouse_pos_callback(GLFWwindow *win, double xpos,
						double ypos);
void				scop_glfw_key_callback(GLFWwindow *win, int key,
						int scancode, int action, int mods);
void				scop_glfw_disable_enable_mouse(t_env *env);
/*
** SHADER FUNCTIONS
*/
int					scop_gl_init_shaders(t_env *env);
int					scop_gl_load_shader(GLuint *shader, GLenum s_type,
						const char *path);
int					scop_gl_create_shader_program(t_env *env);
/*
** MAT4 FUNCTIONS
*/
void				scop_mat4_init(t_mat4 *matrix);
void				scop_mat4_set_translation(t_mat4 *matrix, const t_vec3 tr);
void				scop_mat4_set_rotation(t_mat4 *matrix, const float angle,
						t_vec3 axis);
void				scop_mat4_set_perspective(t_mat4 *matrix,
						const t_vec4 param);
void				scop_mat4_set_identity(t_mat4 *matrix);
void				scop_mat4_set_camera(t_mat4 *view, const t_vec3 pos,
						const t_vec3 target, const t_vec3 vec_up);
void				scop_mat4_multiply(t_mat4 *result, const t_mat4 a,
						const t_mat4 b);
void				scop_mat4_set_scale(t_mat4 *matrix, const float size);
/*
** VEC3 FUNCTIONS
*/
void				scop_vec3_normalize(t_vec3 *param);
void				scop_vec3_set(t_vec3 *vec, const float x, const float y,
						const float z);
void				scop_vec3_substract(t_vec3 *result, const t_vec3 a,
						const t_vec3 b);
void				scop_vec3_add(t_vec3 *result, const t_vec3 a,
						const t_vec3 b);
void				scop_vec3_cross_prod(t_vec3 *result, const t_vec3 a,
						const t_vec3 b);
void				scop_vec3_multiply_const(t_vec3 *result, const t_vec3 a,
						const float cst);
/*
** VEC4 FUNCTIONS
*/
void				scop_vec4_set(t_vec4 *vec, const t_vec4 a);
/*
** MATH FUNCTIONS
*/
float				scop_math_deg_to_rad(const float deg);
float				scop_math_dot_product(const t_vec3 a, const t_vec3 b);
int					scop_math_is_valid_float(const float nbr);
/*
** ENV INIT FUNCTIONS
*/
void				scop_init_env(t_env *env);
void				scop_init_env_win(t_env *env);
void				scop_init_env_shader(t_env *env);
void				scop_init_env_uniform(t_env *env);
void				scop_init_env_obj(t_env *env);
void				scop_init_env_light(t_env *env);
void				scop_init_env_input(t_env *env);
void				scop_init_env_camera(t_env *env);
void				scop_init_env_matrix(t_env *env);
int					scop_init_vao(t_env *env, const size_t id);
/*
** OBJ FILE PARSER FUNCTIONS
*/
int					scop_read_obj_files(t_env *env, const char *path);
int					scop_read_obj_alloc(t_env *env);
int					scop_read_obj_cases(t_obj_read *reader, t_env *env);
int					scop_obj_v(t_obj_read *obj, t_env *env);
int					scop_obj_vt(t_obj_read *obj, t_env *env);
int					scop_obj_vn(t_obj_read *obj, t_env *env);
int					scop_obj_g(t_obj_read *obj, t_env *env);
int					scop_obj_usemtl(t_obj_read *obj, t_env *env);
int					scop_obj_f(t_obj_read *obj, t_env *env);
int					scop_obj_o(t_obj_read *obj, t_env *env);
int					scop_determine_face_type(t_obj_read *obj);
int					scop_det_face_type_1(const char *str, const size_t cur_pos,
						const size_t size);
int					scop_det_face_type_2(const char *str, const size_t cur_pos,
						const size_t size);
int					scop_det_face_type_3(const char *str, const size_t cur_pos,
						const size_t size);
int					scop_det_face_type_4(const char *str, const size_t cur_pos,
						const size_t size);
int					scop_det_face_type_5(const char *str, const size_t cur_pos,
						const size_t size);
int					scop_det_face_type_6(const char *str, const size_t cur_pos,
						const size_t size);
int					scop_det_face_type_7(const char *str, const size_t cur_pos,
						const size_t size);
int					scop_get_faces(t_obj_read *obj, t_env *env,
						const int expected_type, const int group_type);
int					scop_get_glpoint(t_env *env, t_obj_read *obj, char **begin,
						const int expected_type);
int					scop_get_face_type_1(char **str, const size_t cur_pos,
						const size_t size, t_glpoint *glpoint);
int					scop_get_face_type_2(char **str, const size_t cur_pos,
						const size_t size, t_glpoint *glpoint);
int					scop_get_face_type_3(char **str, const size_t cur_pos,
						const size_t size, t_glpoint *glpoint);
int					scop_get_face_type_4(char **str, const size_t cur_pos,
						const size_t size, t_glpoint *glpoint);
int					scop_get_face_type_5(char **str, const size_t cur_pos,
						const size_t size, t_glpoint *glpoint);
int					scop_get_face_type_6(char **str, const size_t cur_pos,
						const size_t size, t_glpoint *glpoint);
int					scop_get_face_type_7(char **str, const size_t cur_pos,
						const size_t size, t_glpoint *glpoint);
int					scop_convert_glpoint_to_vao(t_env *env,
						const int group_type);
int					scop_cvrt_v(t_env *env);
int					scop_cvrt_v_vt_vn(t_env *env);
int					scop_cvrt_v_vn(t_env *env);
int					scop_cvrt_v_vt(t_env *env);
int					scop_cvrt_seek_vertex(t_env *env, const size_t where);
int					scop_cvrt_seek_norm(t_env *env, const size_t where);
int					scop_cvrt_seek_tex(t_env *env, const size_t where);
int					scop_create_triangle_normal(t_env *env, const size_t index);
int					scop_create_triangle_tex(t_env *env, const size_t index);
int					scop_create_triangle_color(t_env *env, const size_t index);
int					scop_cpy_cvrt_to_cur_vao(t_env *env);
int					scop_obj_get_center(t_env *env);
/*
** MTL FILE PARSER FUNCTIONS
*/
int					scop_read_mtl_files(t_obj_read *reader, t_env *env);
int					scop_read_mtl_parsing(FILE *stream, t_env *env);
int					scop_read_mtl_cases(t_obj_read *reader, t_env *env);
int					scop_mtl_newmtl(t_obj_read *mtl, t_env *env);
int					scop_mtl_kd(t_obj_read *mtl, t_env *env);
int					scop_mtl_ka(t_obj_read *mtl, t_env *env);
int					scop_mtl_ks(t_obj_read *mtl, t_env *env);
int					scop_mtl_ns(t_obj_read *mtl, t_env *env);
int					scop_mtl_map_kd(t_obj_read *mtl, t_env *env);
/*
** UPDATE FROM INPUTS FUNCTIONS
*/
void				scop_execute_mov(t_env *env);
void				scop_execute_mouse_mov(t_env *env);
/*
** TEXTURE FUNCTIONS
*/
int					scop_gl_init_first_mat(t_env *env);
char				*scop_load_texture(const char *path, t_mat *mat);
void				scop_set_origin_texture(const char image_desc, t_mat *mat);
void				scop_gl_bind_texture(t_mat *mat);
/*
** OTHER FUNCTIONS
*/
void				scop_main(t_env *env);
void				scop_main_init(t_env *env);
int					scop_exit(t_env *env);
void				*scop_get_env(void *addr);
int					scop_gl_init_uniforms(t_env *env);
void				scop_gl_init_vao(t_env *env);
void				scop_delete_return_line(char *str);
char				*scop_get_folder(const char *arg);
char				*scop_strjoin(const char *s1, const char *s2);
#endif
