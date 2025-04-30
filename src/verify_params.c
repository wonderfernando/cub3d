#include "cub3d.h"

void    verfiy(int ac,char **av)
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

int on_file(char *filename)
{
    int fd;

    fd = open(filename, O_RDONLY);
    if (fd == -1)
    {
        printf("ERROR: ARQUIVO NÃO ENCONTRADO!\n");
        exit(1);
    }
    return (fd);
}

void verify_path_map(char **av)
{
    char    **path;

    path = ft_split(av[1], '.');

    path = ft_split(av[1], '.');
    if (vetor_length(path) > 2)
	{
		printf("ERROR: CAMINHO DE MAPA INVÁLIDO!\n");
		exit(1);
	}
    if (ft_strncmp(path[vetor_length(path) - 1], "cub", 3) != 0)
    {
        printf("ERROR: EXTENSÃO INVÁLIDA!\n");
        exit(1);
    }
    close(on_file(av[1]));

}
