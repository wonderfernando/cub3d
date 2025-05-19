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

void verify_path_textura(char *av, char *line)
{
	char **path;

	path = ft_split(av, '.');
	if (vetor_length(path) > 2)
	{
		free_split(path);
		print_error("CAMINHO DE TEXTURA INVÁLIDO!", av);
		free_line(line);
	}
	if (ft_strncmp(path[vetor_length(path) - 1], "xpm", 3) != 0)
	{
		free_split(path);
		print_error("EXTENSÃO INVÁLIDA!", av);
		free_line(line);
	}
	free_split(path);
	close(on_file(av));
}

void fill_rgb(int value, int i, char *text)
{
	if (ft_strncmp(text, "F ", 2) == 0)
		init_cub()->data.floor_color[i] = value;
	else if (ft_strncmp(text, "C ", 2) == 0)
		init_cub()->data.ceiling_color[i] = value;
}

int verfiy_number(char *str, char *text)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] == ' ')
		{
			i++;
			continue;
		}
		if (!ft_isdigit(str[i]))
			return (print_error("VALORES RGB INVÁLIDOS!", text), 0);
		i++;
	}
	i = 0;
	while (str[i] == ' ')
		i++;
	if (str[i] == '\0')
		return (print_error("VALORES RGB INVÁLIDOS!", text), 0);
	return (1);
}

int have_space_in_rgb(char **split)
{
	int i;
	int found;
	int j;

	found = 0;
	i = 0;
	while (split[i] != NULL)
	{
		j = 0;
		found = 0;
		while (split[i][j])
		{
			if (ft_isdigit(split[i][j]))
			{
				if (found && split[i][j - 1] == ' ')
					return (1);
				found = 1;
			}
			j++;
		}
		i++;
	}
	return (0);
}

int check_range_rgb(char **split, char *text)
{
	int i;

	i = 0;
	while (split[i])
	{
		if (!verfiy_number(split[i], text))
			return (0);
		if ((ft_atoi(split[i]) < 0 || ft_atoi(split[i]) > 255))
			return (print_error("INTERVALO DE VALOR RGB ERRADO!",text), 0);
		fill_rgb(ft_atoi(split[i]), i, text);
		i++;
	}
	return (1);
}

int verify_rgb(char *str, char *text)
{
	char **split;

	split = ft_split(str, ',');
	if (vetor_length(split) != 3 || count_char(str, ',') != 2)
	{
		free_split(split);
		print_error("VALORES RGB INVÁLIDOS!", str);
		return (0);
	}
	if (have_space_in_rgb(split))
	{
		free_split(split);
		print_error("INVALID RGB, SPACE IN NUMBER", str);
		return (0);
	}
	if (!check_range_rgb(split, text))
	{
		free_split(split);
		return (0);
	}
	free_split(split);
	return (1);
}

char *deci_orint(char *str, char *text, char *line)
{
	char *tmp = NULL;

	tmp = ft_strdup(remove_newline(str));
	if (!tmp)
	{
		printf("ERROR: Falha ao alocar memória para o caminho de '%s'.\n", text);
		free(line);
		free_utils();
		exit(1);
	}
	return (tmp);
}

int is_valid_vetor(int vet[])
{
	if (vet[0] == -1 && vet[1] == -1 && vet[2] == -1)
		return (0);
	return (1);	
}

int check_duplicate_1(char *line, int val[], int aux)
{
	int i;
	int count_c;

	i = 0;
	count_c = 0;
	while (i < 3)
	{
		if (val[i] != -1)
			count_c++;
		i++;
	}
	if (count_c == 3 && aux == 0)
	{
		print_error("VALOR RGB DUPLICADO!", remove_newline(line));
		free_line(line);
	}
	return (1);
}


void verfiy_line_c_f(char *line, char *text)
{
	char *str;

	str = line;
	while (ft_isspace(*str))
		str++;
	if (ft_strncmp(str, text, 2) == 0)
	{	
		if (!ft_strncmp(str, "F ", 2))
			check_duplicate_1(line, init_cub()->data.floor_color, 0);
		if (!ft_strncmp(str, "C ", 2))
			check_duplicate_1(line, init_cub()->data.ceiling_color, 0);
		str += 2;
		while (ft_isspace(*str))
			str++;
		if (*str == '\0')
			print_error("CAMINHO INVÁLIDO!", remove_newline(str));
		if (!verify_rgb(remove_newline(str), text))
			free_line(line);
	}
}

void check_duplicate(char *str, char *text, char *line, char **orie)
{
	if (*orie)
	{
		print_error("TEXTURA DUPLICADA!", remove_newline(line));
		free_line(line);
	}
	else
		*orie = deci_orint(str, text, line);
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
		while (ft_isspace(*str))
			str++;
		if (*str == '\0')
		{
			print_error("CAMINHO INVÁLIDO!", remove_newline(str));
			free_line(line);
		}
		if (!file_exists(remove_newline(str)))
		{
			print_error("TEXTURA NÃO ENCONTRADO!", remove_newline(str));
			free_line(line);
		}
		verify_path_textura(remove_newline(str), line);
		if (ft_strncmp(text, "NO ", 3) == 0)
			check_duplicate(str, text, line, &init_cub()->data.north);
		else if (ft_strncmp(text, "SO ", 3) == 0)
			check_duplicate(str, text, line, &init_cub()->data.south);
		else if (ft_strncmp(text, "WE ", 3) == 0)
			check_duplicate(str, text, line, &init_cub()->data.west);
		else if (ft_strncmp(text, "EA ", 3) == 0)
			check_duplicate(str, text, line, &init_cub()->data.east);
	}
}

void check_tabs(int fd)
{
	char *line;
	int count_line;

	count_line = 0;
	line = NULL;
	while ((line = get_next_line(fd)) != NULL)
	{
		if (ft_strchr(remove_newline(line), '\t') != NULL)
		{
			printf("ERROR: MAPA INVÁLIDO, CARACTER\n");
			close(fd);
			free(line);
			exit(1);
		}
		free(line);
		count_line = 1;
	}
	if (!count_line)
	{
		close(fd);
		print_error("MAPA VAZIO\n", NULL);
		exit(1);
	}
	close(fd);
}

int map_size(int fd)
{
	int i = 0;
	char *line;
	int max;

	max = 0;
	while ((line = get_next_line(fd)) != NULL)
	{
		if (is_map_line(line))
		{
			if ((int)ft_strlen(line) > max)
				max = ft_strlen(line);
			i++;
		}
		free(line);
	}
	init_cub()->map.width = max;
	return i;
}
void check_resource(void)
{
	if (!init_cub()->data.north)
		ft_error_exit("TEXTURA NORTE NÀO ENCONTRADA!", NULL);
	if (!init_cub()->data.south)
		ft_error_exit("TEXTURA SUL NÀO ENCONTRADA!", NULL);
	if (!init_cub()->data.west)
		ft_error_exit("TEXTURA ESTE NÀO ENCONTRADA!", NULL);
	if (!init_cub()->data.east)
		ft_error_exit("TEXTURA OESTE NÀO ENCONTRADA!", NULL);
	if (!is_valid_vetor(init_cub()->data.floor_color))
		ft_error_exit("VALORES PARA F (CHÃO) NÃO DECLARADOS!", NULL);
	if (!is_valid_vetor(init_cub()->data.ceiling_color))
		ft_error_exit("VALORES PARA C (CÉU) NÃO DECLARADOS!", NULL);
}

int check_order_map(void)
{
	if (!init_cub()->data.north)
		return (0);
	if (!init_cub()->data.south)
		return (0);
	if (!init_cub()->data.west)
		return (0);
	if (!init_cub()->data.east)
		return (0);
	if (!is_valid_vetor(init_cub()->data.floor_color))
		return (0);
	if (!is_valid_vetor(init_cub()->data.ceiling_color))
		return (0);
	return (1);
}
void load_lines(char *line)
{
	verfiy_line(line, "NO ");
	verfiy_line(line, "SO ");
	verfiy_line(line, "WE ");
	verfiy_line(line, "EA ");
	verfiy_line_c_f(line, "F ");
	verfiy_line_c_f(line, "C ");
}

void verfiy_interior(char **av)
{
	int fd;
	char *line;
	char *tmp;
	char *str;
	int i = 0;
	fd = on_file(av[1]);
	init_cub()->data.fd = fd;
	check_tabs(on_file(av[1]));
	init_cub()->map.map = malloc(sizeof(char *) * (map_size(on_file(av[1])) + 1));
	while (i <= map_size(on_file(av[1])))
	{
		init_cub()->map.map[i] = NULL;
		i++;
	}
	init_cub()->map.height = 0;
	while ((line = get_next_line(fd)) != NULL)
	{
		if (ft_strncmp(line, "\0",1) == 0)
		{
			printf("BARRA N\n");
		}
		
		if (line[0] == '\n' && init_cub()->map.height != 0)
		{
			printf("ERROR: MAPA INVÁLIDOR\n");
		}
	/* 	{
			free(line);
			continue;
		} */
		load_lines(line);
		if (is_map_line(line))
		{
			if (check_order_map() == 0)
			{
				print_error("POSIÇÃO DO MAPA INVÁLIDO", line);
				free_line(line);
			}
			tmp = ft_strdup(remove_newline(line));
			str = ft_strnew_space(init_cub()->map.width - ft_strlen(tmp));
			init_cub()->map.map[init_cub()->map.height] = ft_strjoin(tmp, str);
			init_cub()->map.height++;
			free(tmp);
			free(str);
		}
		free(line);
	}

	check_resource();
	close(fd);
	if (init_cub()->map.height == 0)
	{
		print_error("MAPA VAZIO", NULL);
		free_utils();
		exit(1);
	}
	validate_map();
}
