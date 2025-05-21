/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_two.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ferda-si <ferda-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 11:56:59 by ferda-si          #+#    #+#             */
/*   Updated: 2025/05/21 15:30:48 by ferda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	print_cub(void)
{
	printf("NORTH: %s\n", init_cub()->data.north);
	printf("SOUTH: %s\n", init_cub()->data.south);
	printf("WEST: %s\n", init_cub()->data.west);
	printf("EAST: %s\n", init_cub()->data.east);
	printf("FLOOR COLOR: %d, %d, %d\n", init_cub()->data.floor_color[0],
		init_cub()->data.floor_color[1], init_cub()->data.floor_color[2]);
	printf("CEILING COLOR: %d, %d, %d\n", init_cub()->data.ceiling_color[0],
		init_cub()->data.ceiling_color[1], init_cub()->data.ceiling_color[2]);
}

int	on_file(char *filename)
{
	int	fd;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		printf("ERROR: ARQUIVO NÃO ENCONTRADO!\n");
		exit(1);
	}
	return (fd);
}

int	file_exists(char *filename)
{
	int	fd;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (0);
	close(fd);
	return (1);
}

void	ft_error_exit(char *str, char *line)
{
	print_error(str, line);
	free_utils();
	exit(1);
}

void	free_split(char **split)
{
	int	i;

	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}
