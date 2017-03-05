/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scop_load_texture.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/01 11:35:14 by cledant           #+#    #+#             */
/*   Updated: 2017/03/01 17:03:54 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

static char		*extract_tex(const char *file)
{
	t_tga_header	*head;
	char			*tex;
	size_t			size;
	size_t			counter;
	char			swap;

	counter = 0;
	head = (t_tga_header *)file;
	size = sizeof(char) * 3 * head->img_w * head->img_h;
	if ((tex = (char *)malloc(size)) == NULL)
		return (NULL);
	memcpy(tex, file + 18, size);
	while (counter < (head->img_w * head->img_h * 3))
	{
		swap = tex[counter];
		tex[counter] = tex[counter + 2];
		tex[counter + 2] = swap;
		counter += 3;
	}
	return (tex);
}

static char		*fail_load(char *file, FILE *stream)
{
	if (file != NULL)
		free(file);
	fclose(stream);
	return (NULL);
}

static char		*load_file(const char *path, long *size)
{
	FILE	*stream;
	char	*file;

	file = NULL;
	if ((stream = fopen(path, "r")) == NULL)
		return (NULL);
	if (fseek(stream, 0, SEEK_END) == -1)
		return (fail_load(file, stream));
	if ((*size = ftell(stream)) == -1)
		return (fail_load(file, stream));
	if ((file = (char *)malloc(sizeof(char) * *size)) == NULL)
		return (fail_load(file, stream));
	if (fseek(stream, 0, SEEK_SET) == -1)
		return (fail_load(file, stream));
	if (fread(file, *size, 1, stream) != 1)
		return (fail_load(file, stream));
	fclose(stream);
	return (file);
}

static char		*check_and_extract_file(const char *file, const long size,
					t_env *env)
{
	t_tga_header	*head;
	char			*tex;

	if (size < 18)
		return (NULL);
	head = (t_tga_header *)file;
	if (head->id_len != 0)
		return (NULL);
	if (head->color_map_type != 0)
		return (NULL);
	if (head->image_type != 2)
		return (NULL);
	if (head->pixel_depth != 24)
		return (NULL);
	if (head->img_w * head->img_h * 3 + 18 > size)
		return (NULL);
	if ((tex = extract_tex(file)) == NULL)
		return (NULL);
	env->tex_w = head->img_w;
	env->tex_h = head->img_h;
	scop_set_origin_texture(head->img_desc, env);
	return (tex);
}

char			*scop_load_texture(const char *path, t_env *env)
{
	long	file_size;
	char	*tex_file;
	char	*tex;

	if ((tex_file = load_file(path, &file_size)) == NULL)
	{
		printf("Scop : Texture : Can't open : %s\n", path);
		return (NULL);
	}
	if ((tex = check_and_extract_file(tex_file, file_size, env)) == NULL)
	{
		printf("Scop : Texture : Invalid file : %s\n", path);
		if (tex_file != NULL)
			free(tex_file);
		return (NULL);
	}
	if (tex_file != NULL)
		free(tex_file);
	return (tex);
}
