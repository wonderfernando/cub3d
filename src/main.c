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

 


void load_map(char *path)
{
   char *line;
   int fd;

   fd = on_file(path);
   while ((line = get_next_line(fd)) != NULL)
   {
      if (is_map_line(line))
      {
        //vamos preencher o mapa aqui
         printf("Map line: %s", line);
      }
      free(line);
   }
}
int main(int ac, char **av)
{
   init_cub()->data.fd = -1;
   verfiy(ac, av);
   verfiy_interior(av);
   load_map(av[1]);
   free_utils();
}