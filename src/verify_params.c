/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verify_params.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ferda-si <ferda-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 10:45:05 by ferda-si          #+#    #+#             */
/*   Updated: 2025/05/21 15:26:26 by ferda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	verfiy(int ac, char **av)
{
	if (ac != 2)
	{
		printf("ERROR: NUMERO DE ARGUMENTOS INVÁLIDO!\n");
		exit(1);
	}
	verify_path_map(av);
}

int	vetor_length(char **vet)
{
	int	i;

	i = 0;
	while (vet[i] != NULL)
		i++;
	return (i);
}

void	error_path_map(char *str, char **path)
{
	free_split(path);
	printf("%s\n", str);
	exit(1);
}

void	verify_path_map(char **av)
{
	char	**path;

	path = ft_split(av[1], '.');
	if (vetor_length(path) == 0)
		error_path_map("ERROR: CAMINHO DE MAPA INVÁLIDO!", path);
	if (vetor_length(path) > 2)
		error_path_map("ERROR: CAMINHO DE MAPA INVÁLIDO!", path);
	if (ft_strncmp(path[vetor_length(path) - 1], "cub", 3) != 0)
		error_path_map("ERROR: EXTENSÃO INVÁLIDA!", path);
	free_split(path);
	close(on_file(av[1]));
}
