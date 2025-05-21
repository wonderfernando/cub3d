/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ferda-si <ferda-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 17:23:55 by ferda-si          #+#    #+#             */
/*   Updated: 2025/05/21 17:30:47 by ferda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H

# define CUB3D_H

# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include "../libft/libft.h"

typedef struct s_map
{
	char	**map;
	int		width;
	int		height;
}	t_map;

typedef struct s_data
{
	char	*north;
	char	*south;
	char	*west;
	char	*east;
	int		floor_color[3];
	int		ceiling_color[3];
	int		fd;
}	t_data;

typedef struct s_cub
{
	t_map	map;
	t_data	data;
	char	*line;
}	t_cub;

t_cub	*init_cub(void);
void	free_split(char **split);
void	verfiy(int ac, char **av);
void	verify_path_map(char **av);
void	verify_path_textura(char *av, char *line);
int		vetor_length(char **vet);
void	verfiy_interior(char **av);
int		on_file(char *filename);
char	*get_next_line(int fd);
int		file_exists(char *filename);
void	verfiy_line(char *line, char *text);
void	free_utils(void);
void	print_error(const char *message, char *filename);
char	*deci_orint(char *str, char *text, char *line);
int		count_char(const char *str, char c);
int		have_space_in_rgb(char **split);
int		check_range_rgb(char **split, char *text);
void	free_line(char *line);
void	print_cub(void);
int		is_map_line(const char *line);
void	validate_map(void);
char	*ft_strnew_space(int size);
void	ft_error_exit(char *str, char *line);
void	print_cub(void);
int		verfiy_number(char *str, char *text);
void	fill_rgb(int value, int i, char *text);
char	*remove_newline(char *str);
int		is_carcter_valid(char c);
int		is_player_caracter(char c);
void	check_begin_end_line(void);
void	verfiy_line_c_f(char *line, char *text);
int		valid_begin_end_str(char *str);
void	check_resource(void);
void	init_verify(char **av);
int		line_empty(char *line);
void	load_lines(char *line);
int		check_order_map(void);
void	fill_map(char *line);
int		is_valid_vetor(int vet[]);
int		valid_begin_end_line(char *str);
void	check_tabs(int fd);
int		map_size(int fd);
#endif