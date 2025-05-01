#ifndef CUB3D_H

#define CUB3D_H

# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include "../libft/libft.h"

typedef struct s_map
{
    char    **map;
    int     width;
    int     height;
}   t_map;

typedef struct s_data
{
    char    *north;
    char    *south;
    char    *west;
    char    *east;
    int     floor_color[3];
    int     ceiling_color[3];
}   t_data;

typedef struct s_cub
{
    t_map   map;
    t_data  data;
}   t_cub;

t_cub  *init_cub(void);
t_data  *init_data(void);
void    verfiy(int ac, char **av);
void    verify_path_map(char **av);
int		vetor_length(char **vet);
void    verfiy_interior(char **av);
int     on_file(char *filename);
char	*get_next_line(int fd);
#endif
