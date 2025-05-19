#include "cub3d.h"

t_cub *init_cub(void)
{
	static t_cub cub;

	return (&cub);
}

int is_map_line(const char *line)
{
	while (*line && ft_isspace(*line))
		line++;
	if (*line == '\0' || *line == '\n')
		return 0;
	if (ft_strncmp(line, "NO ", 3) == 0 || ft_strncmp(line, "SO ", 3) == 0 ||
		ft_strncmp(line, "WE ", 3) == 0 || ft_strncmp(line, "EA ", 3) == 0 ||
		line[0] == 'F' || line[0] == 'C')
	{
		return 0;
	}
	return 1;
}

void fill_RGB(void)
{
	int i;

	i = 0;
	while (i < 3)
	{
		init_cub()->data.floor_color[i] = -1;
		init_cub()->data.ceiling_color[i] = -1;
		i++;
	}
}

int main(int ac, char **av)
{
	int i;

	init_cub()->data.fd = -1;
	fill_RGB();
	verfiy(ac, av);
	verfiy_interior(av);
	//print_cub();
	i = 0;
	while (init_cub()->map.map[i] != NULL)
	{
		printf("%s\n", init_cub()->map.map[i]);
		i++;
	}
	free_utils();
}