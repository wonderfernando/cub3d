/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valide_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ferda-si <ferda-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 10:44:05 by ferda-si          #+#    #+#             */
/*   Updated: 2025/05/21 15:53:49 by ferda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	valid_caract_line(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] != ' ' && str[i] != '1' && !is_carcter_valid(str[i]))
			return (0);
		i++;
	}
	return (1);
}

void	verfiy_space(int i, int j)
{
	if (init_cub()->map.map[i - 1][j] == ' ')
		ft_error_exit("MAPA INVÁLIDO, TEM ESPACO ONDE NAO DEVIA\n", \
		init_cub()->map.map[i - 1]);
	if (init_cub()->map.map[i + 1][j] == ' ')
		ft_error_exit("MAPA INVÁLIDO, TEM ESPACO ONDE NAO DEVIA\n", \
		init_cub()->map.map[i + 1]);
	if (init_cub()->map.map[i][j - 1] == ' ')
		ft_error_exit("MAPA INVÁLIDO, TEM ESPACO ONDE NAO DEVIA\n", \
		init_cub()->map.map[i]);
	if (init_cub()->map.map[i][j + 1] == ' ')
		ft_error_exit("MAPA INVÁLIDO, TEM ESPACO ONDE NAO DEVIA\n", \
		init_cub()->map.map[i]);
}

void	is_valid_player(char **map)
{
	int	i;
	int	j;
	int	found;

	i = 0;
	found = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (is_player_caracter(map[i][j]))
				found++;
			j++;
		}
		i++;
	}
	if (found > 1 || found == 0)
		ft_error_exit("DEVE TER UM PLAYER!", NULL);
}

void	validate_map(void)
{
	int	i;
	int	j;

	i = 1;
	check_begin_end_line();
	while (i < (init_cub()->map.height - 1))
	{
		if (!valid_begin_end_str(init_cub()->map.map[i]))
			ft_error_exit("MAPA INVÁLIDO, CARACTER NÃO VALIDO NO \
				INICIO OU FIM DA STRING\n", init_cub()->map.map[i]);
		j = 0;
		if (!valid_caract_line(init_cub()->map.map[i]))
			ft_error_exit("MAPA INVÁLIDO, CARACTER \
				 NÃO VALIDO\n", init_cub()->map.map[i]);
		while (init_cub()->map.map[i][j] != '\0')
		{
			if (is_carcter_valid(init_cub()->map.map[i][j]))
				verfiy_space(i, j);
			j++;
		}
		i++;
	}
	is_valid_player(init_cub()->map.map);
}

void	load_lines(char *line)
{
	verfiy_line(line, "NO ");
	verfiy_line(line, "SO ");
	verfiy_line(line, "WE ");
	verfiy_line(line, "EA ");
	verfiy_line_c_f(line, "F ");
	verfiy_line_c_f(line, "C ");
}
