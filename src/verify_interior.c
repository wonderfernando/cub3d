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

void fill_rgb(int value, int i, char *text)
{
	if (ft_strncmp(text, "F ", 2) == 0)
		init_cub()->data.floor_color[i] = value;
	else if (ft_strncmp(text, "C ", 2) == 0)
		init_cub()->data.ceiling_color[i] = value;
}

char *verfiy_number(char *str)
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
			print_error("VALORES RGB INVÁLIDOS!", str);
		i++;
	}
	return (str);
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
		if ((ft_atoi(verfiy_number(split[i])) < 0 || ft_atoi(verfiy_number(split[i])) > 255))
			return 0;
		fill_rgb(ft_atoi(split[i]), i, text);
		i++;
	}
	return (1);
}

void verify_rgb(char *str, char *text)
{
	char **split;

	split = ft_split(str, ',');
	if (vetor_length(split) != 3 || count_char(str, ',') != 2)
		print_error("VALORES RGB INVÁLIDOS!", str);
	if (have_space_in_rgb(split))
		print_error("INVALID RGB, SPACE IN NUMBER", str);
	if (!check_range_rgb(split, text))
		print_error("INTERVALO DE VALOR RGB ERRADO!", str);
	free_split(split);
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
	printf("Caminho para '%s': %s\n", text, tmp);
	return (tmp);
}

void verfiy_line_c_f(char *line, char *text)
{
	char *str;

	str = line;
	while (ft_isspace(*str))
		str++;
	if (ft_strncmp(str, text, 2) == 0)
	{
		str += 2;
		while (ft_isspace(*str))
			str++;
		if (*str == '\0')
			print_error("CAMINHO INVÁLIDO!", remove_newline(str));
		verify_rgb(remove_newline(str), text);
	}
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
			print_error("CAMINHO INVÁLIDO!", remove_newline(str));
		if (!file_exists(remove_newline(str)))
		{
			free(line); // tem que liberar o line antes de dar exit, porem o print_error tenta usar ele, dando um erro
			print_error("CAMINHO NÃO DA TEXTURA NÃO ENCONTRADO!", ""); // precisamos rever isso | criar uma funcao de exit que vai liberar todas as alocaoes. separar do print error
		}

		verify_path_textura(remove_newline(str));
		if (ft_strncmp(text, "NO ", 3) == 0)
			init_cub()->data.north = deci_orint(str, text, line);
		else if (ft_strncmp(text, "SO ", 3) == 0)
			init_cub()->data.south = deci_orint(str, text, line);
		else if (ft_strncmp(text, "WE ", 3) == 0)
			init_cub()->data.west = deci_orint(str, text, line);
		else if (ft_strncmp(text, "EA ", 3) == 0)
			init_cub()->data.east = deci_orint(str, text, line);
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
		if (ft_strchr(remove_newline(line), '\t') != NULL)
		{
			printf("ERROR: MAPA INVÁLIDO, CARACTER \\t \n");
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
		verfiy_line_c_f(line, "F ");
		verfiy_line_c_f(line, "C ");

		free(line);
	}
	close(fd);
}
