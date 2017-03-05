/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scop_gl_init_first_mat.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/05 16:18:27 by cledant           #+#    #+#             */
/*   Updated: 2017/03/05 17:17:12 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

static inline int		error_first_mat(void)
{
	puts("Scop : Error openning default texture.");
	return (0);
}

int						scop_gl_init_first_mat(t_env *env)
{
	env->obj.mat[0].name = NULL;
	env->obj.mat[0].amb_color = (t_vec3){0.2f, 0.2f, 0.2f};
	env->obj.mat[0].diff_color = (t_vec3){0.8f, 0.8f, 0.8f};
	env->obj.mat[0].spec_color = (t_vec3){0.2f, 0.2f, 0.2f};
	env->obj.mat[0].shine = 156.25f;
	env->obj.mat[0].diff_tex_path = NULL;
	if ((env->obj.mat[0].diff_tex = scop_load_texture("./texture/renko_hg.tga",
			&(env->obj.mat[0]))) == NULL)
		return (error_first_mat());
	scop_gl_bind_texture(&(env->obj.mat[0]));
	env->obj.nb_mat = 1;
	return (1);
}
