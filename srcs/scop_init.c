/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scop_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/23 17:26:38 by cledant           #+#    #+#             */
/*   Updated: 2017/03/17 17:42:40 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

static inline void		display_keys(void)
{
	puts("===>Scop Keys<===");
	puts("WASDRF = Move Camera");
	puts("Mouse = Move Camera Angle");
	puts("M = Enable / Disable Mouse");
	puts("T = Enable / Disable Texture");
	puts("845679 = Move Model");
	puts("Arrows = Rotate model");
	puts("Space = stop auto-rotation");
	puts("Keypad + = Increase Model Size");
	puts("Keypad - = Decrease Model Size");
	puts("Keypad 0 = Wireframe mode");
	puts("ESC = Exit Scop");
}

static inline int		error_argv(int argc)
{
	if (argc < 2)
		display_keys();
	else if (argc > 2)
		puts("Scop : too much arguments");
	return (0);
}

static inline int		initialize_all(t_env *env, char **argv)
{
	scop_init_env(env);
	if ((env->folder = scop_get_folder(argv[1])) == NULL)
		return (0);
	if (scop_glfw_init(env) == 0)
		return (0);
	if (scop_gl_init_shaders(env) == 0)
		return (0);
	if (scop_gl_init_uniforms(env) == 0)
		return (0);
	if (scop_gl_init_first_mat(env) == 0)
		return (0);
	if (scop_init_vao(env, 0) == 0)
		return (0);
	if (scop_read_obj_files(env, argv[1]) == 0)
		return (0);
	return (1);
}

int						main(int argc, char **argv)
{
	t_env		env;

	if (argc != 2)
		return (error_argv(argc));
	scop_get_env(&env);
	glfwSetErrorCallback(scop_glfw_error_callback);
	if (initialize_all(&env, argv) == 0)
		return (scop_exit(&env));
	glfwSetKeyCallback(env.win.win, scop_glfw_key_callback);
	glfwSetCursorPosCallback(env.win.win, scop_glfw_mouse_pos_callback);
	glfwSetWindowSizeCallback(env.win.win, scop_glfw_window_size_callback);
	scop_main(&env);
	return (scop_exit(&env));
}
