#include "cub3d.h"

void verify_path_textura(char *av)
{
    char **path;

    path = ft_split(av, '.');
    if (vetor_length(path) > 2)
    {
        printf("ERROR: CAMINHO DE TEXTURA INVÁLIDA: %s\n", av);
        exit(1);
    }
    if (ft_strncmp(path[vetor_length(path) - 1], "xpm", 3) != 0)
    {
        printf("ERROR: EXTENSÃO INVÁLIDA: %s\n", av);
        exit(1);
    }
    close(on_file(av));
}

void verfiy_line(char *line)
{
    char *str;

    str = line;
    while (ft_isspace(*str))
        str++;
    if (ft_strncmp(str, "NO ", 3) == 0)
    {
        str += 2;
        while (ft_isspace(*str)) str++;
        if (*str == '\0')
        {
            printf("ERROR: CAMINHO INVÁLIDO!\n");
            free(str);
            exit(1);
        }
        if (!file_exists(ft_strrchr(str, '\n')))
        {
            printf("not found %s\n", str);
        }

        init_data()->north = (char *)malloc(ft_strlen(str) + 1);
        if (!init_data()->north)
            verify_path_textura(str);
        init_cub()->data.north = (char *)malloc(ft_strlen(str) + 1);
        if (!init_cub()->data.north)
        {
            printf("ERROR: Falha ao alocar memória para o caminho de 'NO'.\n");
            free(line);
            exit(1);
        }
        printf("Caminho para 'NO': %s\n", init_data()->north);
    }
}

void verfiy_interior(char **av)
{
    int fd;
    char *line;

    fd = on_file(av[1]);
    while ((line = get_next_line(fd)) != NULL)
    {
        if (ft_strchr(line, '\t') != NULL)
        {
            free(line);
            printf("ERROR: MAPA INVÁLIDO, CARACTER \\t");
            close(fd);
            exit(1);
        }
        if (line[0] == '\n')
            continue;
        verfiy_line(line);
        free(line);
    }
    close(fd);
}
