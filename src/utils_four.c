/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_for.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ferda-si <ferda-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 15:23:38 by ferda-si          #+#    #+#             */
/*   Updated: 2025/05/21 16:02:44 by ferda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	check_duplicate(char *str, char *text, char *line, char **orie)
{
	if (*orie)
	{
		print_error("TEXTURA DUPLICADA!", remove_newline(line));
		free_line(line);
	}
	else
		*orie = deci_orint(str, text, line);
}

void	dec_textura(char *str, char *text, char *line)
{
	if (ft_strncmp(text, "NO ", 3) == 0)
		check_duplicate(str, text, line, &init_cub()->data.north);
	else if (ft_strncmp(text, "SO ", 3) == 0)
		check_duplicate(str, text, line, &init_cub()->data.south);
	else if (ft_strncmp(text, "WE ", 3) == 0)
		check_duplicate(str, text, line, &init_cub()->data.west);
	else if (ft_strncmp(text, "EA ", 3) == 0)
		check_duplicate(str, text, line, &init_cub()->data.east);
}

void	verfiy_line(char *line, char *text)
{
	char	*str;

	str = line;
	while (ft_isspace(*str))
		str++;
	if (ft_strncmp(str, text, 3) == 0)
	{
		str += 2;
		while (ft_isspace(*str))
			str++;
		if (*str == '\0')
		{
			print_error("CAMINHO INVÁLIDO!", remove_newline(str));
			free_line(line);
		}
		if (!file_exists(remove_newline(str)))
		{
			print_error("TEXTURA NÃO ENCONTRADO!", remove_newline(str));
			free_line(line);
		}
		verify_path_textura(remove_newline(str), line);
		dec_textura(str, text, line);
	}
}

void	check_tabs(int fd)
{
	char	*line;
	int		count_line;

	count_line = 0;
	line = get_next_line(fd);
	while (line != NULL)
	{
		if (ft_strchr(remove_newline(line), '\t') != NULL)
		{
			printf("ERROR: MAPA INVÁLIDO, CARACTER\n");
			close(fd);
			free(line);
			exit(1);
		}
		free(line);
		count_line = 1;
		line = get_next_line(fd);
	}
	if (!count_line)
	{
		close(fd);
		print_error("MAPA VAZIO\n", NULL);
		exit(1);
	}
	close(fd);
}

void	check_resource(void)
{
	if (!init_cub()->data.north)
		ft_error_exit("TEXTURA NORTE NÀO ENCONTRADA!", NULL);
	if (!init_cub()->data.south)
		ft_error_exit("TEXTURA SUL NÀO ENCONTRADA!", NULL);
	if (!init_cub()->data.west)
		ft_error_exit("TEXTURA ESTE NÀO ENCONTRADA!", NULL);
	if (!init_cub()->data.east)
		ft_error_exit("TEXTURA OESTE NÀO ENCONTRADA!", NULL);
	if (!is_valid_vetor(init_cub()->data.floor_color))
		ft_error_exit("VALORES PARA F (CHÃO) NÃO DECLARADOS!", NULL);
	if (!is_valid_vetor(init_cub()->data.ceiling_color))
		ft_error_exit("VALORES PARA C (CÉU) NÃO DECLARADOS!", NULL);
}
