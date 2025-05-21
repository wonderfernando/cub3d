/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_validate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ferda-si <ferda-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 15:17:58 by ferda-si          #+#    #+#             */
/*   Updated: 2025/05/21 16:52:42 by ferda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	verify_path_textura(char *av, char *line)
{
	char	**path;

	path = ft_split(av, '.');
	if (vetor_length(path) > 2)
	{
		free_split(path);
		print_error("CAMINHO DE TEXTURA INVÁLIDO!", av);
		free_line(line);
	}
	if (ft_strncmp(path[vetor_length(path) - 1], "xpm", 3) != 0)
	{
		free_split(path);
		print_error("EXTENSÃO INVÁLIDA!", av);
		free_line(line);
	}
	free_split(path);
	close(on_file(av));
}

void	finalize_verify(void)
{
	check_resource();
	close(init_cub()->data.fd);
	if (init_cub()->map.height == 0)
		ft_error_exit("MAPA VAZIO", NULL);
	validate_map();
}

char	*remove_newline(char *str)
{
	int	len;

	len = strlen(str);
	if (len > 0 && str[len - 1] == '\n')
	{
		str[len - 1] = '\0';
	}
	return (str);
}

void	ft_free_exit(char *str, char *line)
{
	print_error(str, line);
	free_line(line);
}

void	verfiy_interior(char **av)
{
	char	*line;
	int		check_empty_line;

	check_empty_line = 0;
	init_verify(av);
	line = get_next_line(init_cub()->data.fd);
	while (line != NULL)
	{
		if (line_empty(line) && (init_cub()->map.height > 0))
			check_empty_line++;
		load_lines(line);
		if (is_map_line(line))
		{
			if (check_order_map() == 0)
				ft_free_exit("POSIÇÃO DO MAPA INVÁLIDO", line);
			if (check_empty_line > 0)
				ft_free_exit("MAPA INVÁLIDO, O MAPA NAO PODE ESTAR DIVIDO", \
					line);
			fill_map(line);
		}
		free(line);
		line = get_next_line(init_cub()->data.fd);
	}
	finalize_verify();
}
