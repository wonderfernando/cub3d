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


int file_exists(char *filename)
{
    int fd;

    fd = open(filename, O_RDONLY);
    if (fd == -1)
        return (0);
    close(fd);
    return (1);
}

void free_split(char **split)
{
    int i;

    i = 0;
    while (split[i])
    {
        free(split[i]);
        i++;
    }
    free(split);
}

void verify_path_map(char **av)
{
    char    **path;

    path = ft_split(av[1], '.');
    if (vetor_length(path) > 2)
	{
		printf("ERROR: CAMINHO DE MAPA INVÁLIDO!\n");
		free_split(path);
        exit(1);
	}
    if (ft_strncmp(path[vetor_length(path) - 1], "cub", 3) != 0)
    {
        printf("ERROR: EXTENSÃO INVÁLIDA!\n");
        free_split(path);
        exit(1);
    }
    free_split(path);
    close(on_file(av[1]));
}
