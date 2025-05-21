/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map_three.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ferda-si <ferda-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 15:19:48 by ferda-si          #+#    #+#             */
/*   Updated: 2025/05/21 15:36:08 by ferda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	valid_begin_end_line(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] != ' ' && str[i] != '1')
			return (0);
		i++;
	}
	return (1);
}

int	valid_begin_end_str(char *str)
{
	if ((str[0] != '1' && str[0] != ' '))
		return (0);
	if ((str[strlen(str) - 1] != '1' && str[strlen(str) - 1] != ' '))
		return (0);
	return (1);
}

int	is_player_caracter(char c)
{
	if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
		return (1);
	return (0);
}

int	is_carcter_valid(char c)
{
	if (c == '0' || c == 'N' || c == 'S' || c == 'E' || c == 'W')
		return (1);
	return (0);
}

int	verfiy_number(char *str, char *text)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == ' ')
		{
			i++;
			continue ;
		}
		if (!ft_isdigit(str[i]))
			return (print_error("VALORES RGB INVÁLIDOS!", text), 0);
		i++;
	}
	i = 0;
	while (str[i] == ' ')
		i++;
	if (str[i] == '\0')
		return (print_error("VALORES RGB INVÁLIDOS!", text), 0);
	return (1);
}
