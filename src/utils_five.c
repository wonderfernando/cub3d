/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_five.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ferda-si <ferda-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 15:50:14 by ferda-si          #+#    #+#             */
/*   Updated: 2025/05/21 16:49:03 by ferda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_order_map(void)
{
	if (!init_cub()->data.north)
		return (0);
	if (!init_cub()->data.south)
		return (0);
	if (!init_cub()->data.west)
		return (0);
	if (!init_cub()->data.east)
		return (0);
	if (!is_valid_vetor(init_cub()->data.floor_color))
		return (0);
	if (!is_valid_vetor(init_cub()->data.ceiling_color))
		return (0);
	return (1);
}

void	check_begin_end_line(void)
{
	if (!valid_begin_end_line(init_cub()->map.map[0]))
		ft_error_exit("MAPA INVÁLIDO, CARACTER NÃO VALIDO\n", \
			init_cub()->map.map[0]);
	if (!valid_begin_end_line(init_cub()->map.map[init_cub()->map.height - 1]))
		ft_error_exit("MAPA INVÁLIDO, CARACTER NÃO VALIDO\n", \
			init_cub()->map.map[init_cub()->map.height - 1]);
}

void	init_verify(char **av)
{
	int	i;

	i = 0;
	init_cub()->data.fd = on_file(av[1]);
	check_tabs(on_file(av[1]));
	init_cub()->map.map = malloc(sizeof(char *) * (map_size(on_file(av[1])) \
	+ 1));
	while (i <= map_size(on_file(av[1])))
	{
		init_cub()->map.map[i] = NULL;
		i++;
	}
	init_cub()->map.height = 0;
}

void	fill_map(char *line)
{
	char	*teste;
	char	*tmp;
	char	*str;

	tmp = ft_strdup(remove_newline(line));
	str = ft_strnew_space(init_cub()->map.width - ft_strlen(tmp));
	teste = ft_strjoin(tmp, str);
	init_cub()->map.map[init_cub()->map.height] = teste;
	init_cub()->map.height++;
	free(tmp);
	free(str);
}
