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
}

void print_error(char *message, char *filename)
{
    if (filename)
        printf("ERROR: %s: %s\n", filename, message);
    else
        printf("ERROR: %s\n", message);
    free_utils();
    exit(1);
}
