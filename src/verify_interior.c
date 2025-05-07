#include "cub3d.h"

char *remove_newline(char *str)
{
    int len = strlen(str);

    if (len > 0 && str[len - 1] == '\n')
    {
        str[len - 1] = '\0';
    }
    return (str);
}

void verify_path_textura(char *av)
{
    char **path;

    path = ft_split(av, '.');
    if (vetor_length(path) > 2)
    {
        free_split(path);
        print_error("CAMINHO DE TEXTURA INVÁLIDO!", av);
    }
    if (ft_strncmp(path[vetor_length(path) - 1], "xpm", 3) != 0)
    {
        free_split(path);
        print_error("EXTENSÃO INVÁLIDA!", av);
    }
    free_split(path);
    close(on_file(av));
}

void verfiy_line(char *line, char *text)
{
    char *str;

    str = line;
    while (ft_isspace(*str))
        str++;
    if (ft_strncmp(str, text, 3) == 0)
    {
        str += 2;
        while (ft_isspace(*str)) str++;
        if (*str == '\0')
            print_error("CAMINHO INVÁLIDO!", remove_newline(str));
        if (!file_exists(remove_newline(str)))
            print_error("CAMINHO NÃO ENCONTRADO!", remove_newline(str));
        init_cub()->data.north = (char *)malloc(ft_strlen(remove_newline(str)) + 1);
        if (!init_cub()->data.north)
        {
            printf("ERROR: Falha ao alocar memória para o caminho de '%s'.\n", text);
            free(line);
            free_utils();
            exit(1);
        }
        if (!init_cub()->data.north)
            verify_path_textura(remove_newline(str));
        ft_strcpy(init_cub()->data.north, remove_newline(str));
        printf("Caminho para '%s': %s\n",text, init_cub()->data.north);
    }
}

void verfiy_interior(char **av)
{
    int fd;
    char *line;


    fd = on_file(av[1]);
    init_cub()->data.fd = fd;
    while ((line = get_next_line(fd)) != NULL)
    {
        if (ft_strchr(line, '\t') != NULL)
        {
            printf("ERROR: MAPA INVÁLIDO, CARACTER \\t");
            free(line);
            free_utils();
            close(fd);
            exit(1);
        }
        if (line[0] == '\n')
        {
            free(line);
            continue;
        }
        verfiy_line(line, "NO ");
        verfiy_line(line, "SO ");
        verfiy_line(line, "WE ");
        verfiy_line(line, "EA ");
       
        free(line);
    }
    close(fd);
}
