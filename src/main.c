#include "cub3d.h"

t_data  *init_data(void)
{
   static t_data data;

   return (&data);
}

t_cub  *init_cub(void)
{
   static t_cub cub;

   return (&cub);
}
int main(int ac, char **av)
{
   verfiy(ac, av);
   verfiy_interior(av);
}