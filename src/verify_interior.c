#include "cub3d.h"

void verfiy_line(char *line)
{
    char *str;

    str = line;
    while (ft_isspace(*str)) str++;
    if (ft_strncmp(str, "NO", 2) == 0)
    {
        str += 2;
        while (ft_isspace(*str)) str++;
        if (*str == '\0')
        {
            printf("ERROR: CAMINHO INVÁLIDO!\n");
            exit(1);
        }
        init_data()->north = (char *)malloc(ft_strlen(str) + 1);
        if (!init_data()->north)
        {
            printf("ERROR: Falha ao alocar memória para o caminho de 'NO'.\n");
            exit(1);
        }
        //ft_strncpy(init_cub()->data.north, str, ft_strlen(str));
       // init_cub()->data.north[ft_strlen(str)] = '\0';
        printf("Caminho para 'NO': %s\n", init_data()->north);
    }/*
    else if (ft_strncmp(str, "SO", 2) == 0)
    {
        str += 2;
        while (ft_isspace(*str)) str++;
        if (*str == '\0')
        {
            printf("ERROR: CAMINHO INVÁLIDO!\n");
            exit(1);
        }
        printf("%s", ft_strncpy(init_cub()->data.south, str, ft_strlen(str)));
    }
    else if (ft_strncmp(str, "WE", 2) == 0)
    {
        str += 2;
        while (ft_isspace(*str)) str++;
        if (*str == '\0')
        {
            printf("ERROR: CAMINHO INVÁLIDO!\n");
            exit(1);
        }
        printf("%s", ft_strncpy(init_cub()->data.west, str, ft_strlen(str)));
    }
    else if (ft_strncmp(str, "EA", 2) == 0)
    {
        str += 2;
        while (ft_isspace(*str)) str++;
        if (*str == '\0')
        {
            printf("ERROR: CAMINHO INVÁLIDO!\n");
            exit(1);
        }
        printf("%s", ft_strncpy(init_cub()->data.east, str, ft_strlen(str)));
    }*/
}

void    verfiy_interior(char **av)
{
   int fd;
   char *line;

   fd = on_file(av[1]);
   while ((line = get_next_line(fd)) != NULL)
    {
		//printf("%s", line);
        if (line[0] == '\n')
            continue;
        verfiy_line(line);
		free(line);
	}
	close(fd);

}