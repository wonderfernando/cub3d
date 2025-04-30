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


void verify_path_map(char **av)
{
    char    **path;
    (void)av;
    int i = 0;
    path = ft_split(av[1], '.');
    while (path[i] != NULL)
    {
        printf("%s\n", path[i]);
        i++;
    }
    if (ft_strncmp(path[i-1], "cub", 3) != 0)
    {
        printf("ERROR: EXTENSÃO INVÁLIDA!\n");
        exit(1);
    }
}