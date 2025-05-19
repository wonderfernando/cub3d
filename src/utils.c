#include "cub3d.h"

int	count_char(const char *str, char c)
{
	int	count = 0;

	while (*str)
	{
		if (*str == c)
			count++;
		str++;
	}
	return (count);
}


void free_utils(void)
{
    free(init_cub()->data.north);
    free(init_cub()->data.south);
    free(init_cub()->data.west);
    free(init_cub()->data.east);
    if (init_cub()->data.fd != -1)
        close(init_cub()->data.fd);
    free_split(init_cub()->map.map);
}
void free_line(char  *line)
{
    free(line);
	free_utils();
	exit(1);
}

void print_error(const char *message, char *filename)
{
    if (filename)
        printf("ERROR: %s: %s\n", filename, message);
    else
        printf("ERROR: %s\n", message);
}

/*int validate_map(void)
{
    int i = 0;
    while (init_cub()->map.map[i] != NULL)
    {

        if (ft_strchr(init_cub()->map.map[i], ' ') != NULL)
        {
            print_error("MAPA INVÁLIDO, CARACTER \\t \n", init_cub()->map.map[i]);
            return 0;
        }
        i++;
    }
    return 1;
}*/

void print_cub(void)
{
    printf("NORTH: %s\n", init_cub()->data.north);
    printf("SOUTH: %s\n", init_cub()->data.south);
    printf("WEST: %s\n", init_cub()->data.west);
    printf("EAST: %s\n", init_cub()->data.east);
    printf("FLOOR COLOR: %d, %d, %d\n", init_cub()->data.floor_color[0], init_cub()->data.floor_color[1], init_cub()->data.floor_color[2]);
    printf("CEILING COLOR: %d, %d, %d\n", init_cub()->data.ceiling_color[0], init_cub()->data.ceiling_color[1], init_cub()->data.ceiling_color[2]);
}

char	*ft_strnew_space(int size)
{
	char	*temp;
	int	i;

	i = 0;
	temp = malloc(sizeof(*temp) * (size + 1));
	if (!temp)
		return (NULL);
	if (temp)
	{
		while (i < size)
		{
			temp[i] = ' ';
			i++;
		}
        temp[i] = '\0';
	}
	return (temp);
}