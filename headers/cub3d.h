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
    int    fd;
}   t_data;

typedef struct s_cub
{
    t_map   map;
    t_data  data;
    char    *line;
}   t_cub;

t_cub  *init_cub(void);
void free_split(char **split);
void    verfiy(int ac, char **av);
void    verify_path_map(char **av);
void verify_path_textura(char *av, char *line);
int		vetor_length(char **vet);
void    verfiy_interior(char **av);
int     on_file(char *filename);
char	*get_next_line(int fd);
int		file_exists(char *filename);
void verfiy_line(char *line, char *text);
void free_utils(void);
void print_error(const char *message, char *filename);
char    *deci_orint(char *str, char *text,char *line);
int	count_char(const char *str, char c);
int have_space_in_rgb(char **split);
int check_range_rgb(char **split, char *text);
void free_line(char  *line);
void print_cub(void);
int is_map_line(const char *line);
void validate_map(void);
char	*ft_strnew_space(int size);
void ft_error_exit(char *str, char *line);
#endif
