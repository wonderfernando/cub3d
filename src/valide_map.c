#include "cub3d.h"

int valid_begin_end_line(char *str)
{
    int i;

    i = 0;
    while (str[i])
    {
        if (str[i] != ' ' && str[i] != '1')
        {
            printf("lod %d", i);
            return (0);
        }
        i++;
    }
    return (1);
}

int is_player_caracter(char c)
{
    if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
        return (1);
    return (0);
}

int is_carcter_valid(char c)
{
    if (c == '0' || c == 'N' || c == 'S' || c == 'E' || c == 'W')
        return (1);
    return (0);
}
int valid_caract_line(char *str)
{
    int i;

    i = 0;
    while (str[i])
    {
        if (str[i] != ' ' && str[i] != '1' && !is_carcter_valid(str[i]))
            return (0);
        i++;
    }
    return (1);
}

void verfiy_space(int i, int j)
{
    if (init_cub()->map.map[i - 1][j] == ' ')
        ft_error_exit("MAPA INVÁLIDO, TEM ESPACO ONDE NAO DEVIA \n", init_cub()->map.map[i - 1]);
    if (init_cub()->map.map[i + 1][j] == ' ')
        ft_error_exit("MAPA INVÁLIDO, TEM ESPACO ONDE NAO DEVIA \n", init_cub()->map.map[i + 1]);
    if (init_cub()->map.map[i][j - 1] == ' ')
        ft_error_exit("MAPA INVÁLIDO, TEM ESPACO ONDE NAO DEVIA \n", init_cub()->map.map[i]);
    if (init_cub()->map.map[i][j + 1] == ' ')
        ft_error_exit("MAPA INVÁLIDO, TEM ESPACO ONDE NAO DEVIA \n", init_cub()->map.map[i]);
}

void is_valid_player(char **map)
{
    int i;
    int j;
    int found;

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
void ft_error_exit(char *str, char *line)
{
    print_error(str, line);
    free_utils();
    exit(1);
}

void validate_map(void)
{
    int i;
    int j;

    i = 1;
    if (!valid_begin_end_line(init_cub()->map.map[0]))
        ft_error_exit("MAPA INVÁLIDO, CARACTER NÃO VALIDO1 \n", init_cub()->map.map[0]);
    if (!valid_begin_end_line(init_cub()->map.map[init_cub()->map.height - 1]))
        ft_error_exit("MAPA INVÁLIDO, CARACTER NÃO VALIDO2 \n", init_cub()->map.map[init_cub()->map.height - 1]);
    while (i < (init_cub()->map.height - 1))
    {
        j = 0;
        if (!valid_caract_line(init_cub()->map.map[i]))
            ft_error_exit("MAPA INVÁLIDO, CARACTER NÃO VALIDO3 \n", init_cub()->map.map[i]);
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
