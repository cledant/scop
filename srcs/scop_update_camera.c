/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scop_update_camera.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/28 13:37:45 by cledant           #+#    #+#             */
/*   Updated: 2017/02/28 13:40:59 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

void	scop_update_camera(t_env *env)
{
	scop_vec3_add(&(env->cam_pos), env->cam_pos, env->cam_front);
	scop_vec3_substract(&(env->cam_dir), env->cam_pos, env->cam_target);
	scop_vec3_normalize(&(env->cam_dir));
	scop_vec3_cross_prod(&(env->cam_right), env->up_vec, env->cam_dir);
	scop_vec3_normalize(&(env->cam_right));
	scop_vec3_cross_prod(&(env->cam_up), env->cam_dir, env->cam_right);
	scop_mat4_create_look_at(&(env->look_at), env->cam_right, env->cam_up,
			env->cam_dir);
	scop_mat4_set_translation(&(env->reverse_pos), (t_vec3){-env->cam_pos.x,
			-env->cam_pos.y, -env->cam_pos.z});
	scop_mat4_multiply(&(env->view), env->look_at, env->reverse_pos);
}
