/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verify_interior.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ferda-si <ferda-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 10:44:00 by ferda-si          #+#    #+#             */
/*   Updated: 2025/05/21 15:26:06 by ferda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	have_space_in_rgb(char **split)
{
	int	found;
	int	i;
	int	j;

	found = 0;
	i = 0;
	while (split[i] != NULL)
	{
		j = 0;
		found = 0;
		while (split[i][j])
		{
			if (ft_isdigit(split[i][j]))
			{
				if (found && split[i][j - 1] == ' ')
					return (1);
				found = 1;
			}
			j++;
		}
		i++;
	}
	return (0);
}

int	check_range_rgb(char **split, char *text)
{
	int	i;

	i = 0;
	while (split[i])
	{
		if (!verfiy_number(split[i], text))
			return (0);
		if ((ft_atoi(split[i]) < 0 || ft_atoi(split[i]) > 255))
			return (print_error("INTERVALO DE VALOR RGB ERRADO!", text), 0);
		fill_rgb(ft_atoi(split[i]), i, text);
		i++;
	}
	return (1);
}

int	verify_rgb(char *str, char *text)
{
	char	**split;

	split = ft_split(str, ',');
	if (vetor_length(split) != 3 || count_char(str, ',') != 2)
	{
		free_split(split);
		print_error("VALORES RGB INVÁLIDOS!", str);
		return (0);
	}
	if (have_space_in_rgb(split))
	{
		free_split(split);
		print_error("INVALID RGB, SPACE IN NUMBER", str);
		return (0);
	}
	if (!check_range_rgb(split, text))
	{
		free_split(split);
		return (0);
	}
	free_split(split);
	return (1);
}

int	check_duplicate_1(char *line, int val[], int aux)
{
	int	i;
	int	count_c;

	i = 0;
	count_c = 0;
	while (i < 3)
	{
		if (val[i] != -1)
			count_c++;
		i++;
	}
	if (count_c == 3 && aux == 0)
	{
		print_error("VALOR RGB DUPLICADO!", remove_newline(line));
		free_line(line);
	}
	return (1);
}

void	verfiy_line_c_f(char *line, char *text)
{
	char	*str;

	str = line;
	while (ft_isspace(*str))
		str++;
	if (ft_strncmp(str, text, 2) == 0)
	{
		if (!ft_strncmp(str, "F ", 2))
			check_duplicate_1(line, init_cub()->data.floor_color, 0);
		if (!ft_strncmp(str, "C ", 2))
			check_duplicate_1(line, init_cub()->data.ceiling_color, 0);
		str += 2;
		while (ft_isspace(*str))
			str++;
		if (*str == '\0')
			print_error("CAMINHO INVÁLIDO!", remove_newline(str));
		if (!verify_rgb(remove_newline(str), text))
			free_line(line);
	}
}
