/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scop_gl_load_shader.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/24 12:58:39 by cledant           #+#    #+#             */
/*   Updated: 2017/02/24 14:06:54 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

static inline int	shader_fail(void)
{
	puts("FAIL !");
	return (0);
}

static inline char	*fail_read(char *code, FILE *stream)
{
	if (code != NULL)
		free(code);
	fclose(stream)
	return (NULL);
}

char				*read_shader_file(const char *path)
{
	FILE	*stream;
	char	*shader_code;
	long	size;

	shader_code = NULL;
	if ((stream = fopen(path, "r")) == NULL)
		return (NULL);
	if (fseek(stream, 0, SEEK_END) == -1)
		return (fail_read(shader_code, stream));
	if ((size = ftell(stream)) == -1)
		return (fail_read(shader_code, stream));
	if ((shader_code = (char *)malloc(sizeof(char) * size + 1)) == NULL)
		return (fail_read(shader_code, stream));
	if (fseek(stream, 0, SEEK_SET) == -1)
		return (fail_read(shader_code, stream));
	if (fread(shader_code, size, 1, stream) != size)
		return (fail_read(shader_code, stream));
	shader_code[size] = '\0';
	fclose(stream);
	return (shader_code);
}

int		scop_gl_load_shader(GLuint *shader, GLenum type, const char *path)
{
	char	*shader_code;
	GLint	success;

	shader_code = NULL;
	printf("Loading : %s ", path);
	putchar('.');
	if ((*shader = glCreateShader(type)) == 0)
		return (shader_fail());
	putchar('.');
	if ((shader_code = read_shader_file(path)) == NULL)
		return (shader_fail());
	putchar('.');
	glShaderSource(*shader, 1, &shader_code, NULL);
	glCompileShader(*shader);
	if (shader_code != NULL)
		free(shader_code);
	glGetShaderiv(*shader, GL_COMPILE_STATUS, &succes)
	if (!success)
		return (shader_fail());
	puts("OK !");
	return (1);
}
