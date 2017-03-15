/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scop_load_texture.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/01 11:35:14 by cledant           #+#    #+#             */
/*   Updated: 2017/03/15 15:01:03 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

static inline char		*extract_tex(const char *file, const size_t depth)
{
	t_tga_header	*head;
	char			*tex;
	size_t			size;
	size_t			counter;

	counter = 0;
	head = (t_tga_header *)file;
	if (depth == 24)
	{
		size = sizeof(char) * 3 * head->img_w * head->img_h;
		if ((tex = (char *)malloc(size)) == NULL)
			return (NULL);
		memcpy(tex, file + 18, size);
	}
	else
	{
		size = sizeof(char) * 4 * head->img_w * head->img_h;
		if ((tex = (char *)malloc(size)) == NULL)
			return (NULL);
		memcpy(tex, file + 18, size);
	}
	return (tex);
}

static inline char		*fail_load(char *file, FILE *stream)
{
	if (file != NULL)
		free(file);
	fclose(stream);
	return (NULL);
}

static inline char		*load_file(const char *path, long *size)
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

static inline char		*check_and_extract_file(const char *file,
							const long size, t_mat *mat)
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
	if (head->pixel_depth != 24 && head->pixel_depth != 32)
		return (NULL);
	if (head->img_w * head->img_h * 3 + 18 > size)
		return (NULL);
	if ((tex = extract_tex(file, head->pixel_depth)) == NULL)
		return (NULL);
	mat->tex_w = head->img_w;
	mat->tex_h = head->img_h;
	mat->depth = head->pixel_depth;
	scop_set_origin_texture(head->img_desc, mat);
	return (tex);
}

char					*scop_load_texture(const char *path, t_mat *mat)
{
	long	file_size;
	char	*tex_file;
	char	*tex;

	if ((tex_file = load_file(path, &file_size)) == NULL)
	{
		printf("Scop : Texture : Can't open : %s\n", path);
		return (NULL);
	}
	if ((tex = check_and_extract_file(tex_file, file_size, mat)) == NULL)
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
