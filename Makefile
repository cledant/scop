# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cledant <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/11/26 10:40:13 by cledant           #+#    #+#              #
#    Updated: 2017/03/06 13:11:03 by cledant          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

##Ajouter plus tard la compile de glfw

CC = gcc

CFLAGS = -Werror -Wall -Wextra -O2

OBJ_DIR_NAME = obj

LIBS = -lglfw3

FRAMEWORK = -framework OpenGL -framework Cocoa -framework IOkit -framework CoreVideo

INCLUDES_GLFW = ./glfw/include/GLFW

GLFW_PATH = ./glfw/src

SRCS_NAME = scop_init.c scop_glfw_close_callback.c scop_glfw_error_callback.c \
			scop_exit.c scop_gl_load_shader.c scop_gl_create_shader_program.c \
			scop_mat4_init.c scop_mat4_set_translation.c scop_mat4_set_rotation.c \
			scop_mat4_set_perspective.c scop_math_deg_to_rad.c \
			scop_vec3_normalize.c scop_mat4_set_identity.c scop_get_env.c \
			scop_glfw_key_callback.c  scop_glfw_window_size_callback.c \
			scop_vec3_set.c scop_vec3_substract.c scop_vec3_add.c \
			scop_vec3_cross_prod.c scop_vec3_multiply_const.c \
			scop_execute_mov.c scop_mat4_set_camera.c \
			scop_math_dot_product.c scop_glfw_mouse_pos_callback.c \
			scop_execute_mouse_mov.c scop_init_env.c scop_glfw_init.c \
			scop_gl_init_shaders.c scop_gl_init_uniforms.c scop_load_texture.c \
			scop_set_origin_texture.c scop_gl_bind_texture.c \
			scop_gl_init_first_mat.c scop_read_obj_files.c scop_read_obj_cases.c \
			scop_read_mtl_files.c scop_read_mtl_parsing.c scop_read_mtl_cases.c \
			scop_mtl_newmtl.c

INCLUDES = ./includes

SRCS_PATH = ./srcs

OBJ_SRCS = $(SRCS_NAME:%.c=$(OBJ_DIR_NAME)/%.o)

NAME = scop

all : $(NAME)

$(OBJ_DIR_NAME) :
	mkdir $(OBJ_DIR_NAME)

$(NAME) : $(OBJ_SRCS)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS) -L$(GLFW_PATH) $(FRAMEWORK)

$(OBJ_DIR_NAME)/%.o : $(SRCS_PATH)/%.c $(OBJ_DIR_NAME)
	$(CC) -o $@ -c $< $(CFLAGS) -I$(INCLUDES) -I$(INCLUDES_GLFW)

clean :
	rm -rf $(OBJ_DIR_NAME)

fclean : clean
	rm -rf $(NAME)

re : fclean all

.PHONY : all clean fclean re
