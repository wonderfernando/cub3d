/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ferda-si <ferda-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 11:54:40 by ferda-si          #+#    #+#             */
/*   Updated: 2025/05/21 11:58:58 by ferda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	count_char(const char *str, char c)
{
	int	count;

	count = 0;
	while (*str)
	{
		if (*str == c)
			count++;
		str++;
	}
	return (count);
}

void	free_utils(void)
{
	free(init_cub()->data.north);
	free(init_cub()->data.south);
	free(init_cub()->data.west);
	free(init_cub()->data.east);
	if (init_cub()->data.fd != -1)
		close(init_cub()->data.fd);
	free_split(init_cub()->map.map);
}

void	free_line(char *line)
{
	free(line);
	free_utils();
	exit(1);
}

void	print_error(const char *message, char *filename)
{
	if (filename)
		printf("ERROR: %s: %s\n", filename, message);
	else
		printf("ERROR: %s\n", message);
}

char	*ft_strnew_space(int size)
{
	char	*temp;
	int		i;

	i = 0;
	temp = malloc(sizeof(*temp) * (size + 1));
	if (!temp)
		return (NULL);
	if (temp)
	{
		while (i < size)
		{
			temp[i] = ' ';
			i++;
		}
		temp[i] = '\0';
	}
	return (temp);
}
