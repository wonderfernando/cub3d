/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ferda-si <ferda-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 10:44:22 by ferda-si          #+#    #+#             */
/*   Updated: 2025/05/21 10:44:23 by ferda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_cub	*init_cub(void)
{
	static t_cub	cub;

	return (&cub);
}

int	is_map_line(const char *line)
{
	while (*line && ft_isspace(*line))
		line++;
	if (*line == '\0' || *line == '\n')
		return (0);
	if (ft_strncmp(line, "NO ", 3) == 0 || ft_strncmp(line, "SO ", 3) == 0 || \
		ft_strncmp(line, "WE ", 3) == 0 || ft_strncmp(line, "EA ", 3) == 0 || \
		ft_strncmp(line, "F ", 2) == 0 || ft_strncmp(line, "C ", 2) == 0)
	{
		return (0);
	}
	return (1);
}

void	init_rgb(void)
{
	int	i;

	i = 0;
	while (i < 3)
	{
		init_cub()->data.floor_color[i] = -1;
		init_cub()->data.ceiling_color[i] = -1;
		i++;
	}
}

int	main(int ac, char **av)
{
	int	i;

	init_cub()->data.fd = -1;
	init_rgb();
	verfiy(ac, av);
	verfiy_interior(av);
	print_cub();
	i = 0;
	while (init_cub()->map.map[i] != NULL)
	{
		printf("%s\n", init_cub()->map.map[i]);
		i++;
	}
	free_utils();
	return (0);
}
