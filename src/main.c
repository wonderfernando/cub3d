#include "cub3d.h"

t_data  *init_data(void)
{
   static t_data data;

   return (&data);
}

t_cub  *init_cub(void)
{
   static t_cub cub;

   cub.map.map = NULL;
   cub.map.width = 0;
   cub.map.height = 0;
   cub.data.north = NULL;
   cub.data.south = NULL;
   cub.data.west = NULL;
   cub.data.east = NULL;
   cub.data.floor_color[0] = 0;
   cub.data.floor_color[1] = 0;
   cub.data.floor_color[2] = 0;
   cub.data.ceiling_color[0] = 0;
   cub.data.ceiling_color[1] = 0;
   cub.data.ceiling_color[2] = 0;
   return (&cub);
}
int main(int ac, char **av)
{
   verfiy(ac, av);
   verfiy_interior(av);
}