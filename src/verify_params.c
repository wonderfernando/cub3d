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
    path = ft_split("sdfdf.asdf", '.');
    while (path[i] != NULL)
    {
        printf("%s\n", path[i]);
        i++;
    }
    
}