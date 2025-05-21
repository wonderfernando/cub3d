/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_map_three.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ferda-si <ferda-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 15:21:05 by ferda-si          #+#    #+#             */
/*   Updated: 2025/05/21 16:03:33 by ferda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	fill_rgb(int value, int i, char *text)
{
	if (ft_strncmp(text, "F ", 2) == 0)
		init_cub()->data.floor_color[i] = value;
	else if (ft_strncmp(text, "C ", 2) == 0)
		init_cub()->data.ceiling_color[i] = value;
}

int	map_size(int fd)
{
	char	*line;
	int		i;
	int		max;

	max = 0;
	i = 0;
	line = get_next_line(fd);
	while (line != NULL)
	{
		if (is_map_line(line))
		{
			if ((int)ft_strlen(line) > max)
				max = ft_strlen(line);
			i++;
		}
		free(line);
		line = get_next_line(fd);
	}
	init_cub()->map.width = max;
	return (i);
}

int	line_empty(char *line)
{
	int	i;

	i = 0;
	if (line[0] == '\0')
		return (1);
	while (ft_isspace(line[i]))
		i++;
	if (line[i] == '\0')
		return (1);
	return (0);
}

char	*deci_orint(char *str, char *text, char *line)
{
	char	*tmp;

	tmp = NULL;
	tmp = ft_strdup(remove_newline(str));
	if (!tmp)
	{
		printf("ERROR: Falha ao alocar memória para o caminho de '%s'.\n", text);
		free(line);
		free_utils();
		exit(1);
	}
	return (tmp);
}

int	is_valid_vetor(int vet[])
{
	if (vet[0] == -1 && vet[1] == -1 && vet[2] == -1)
		return (0);
	return (1);
}
