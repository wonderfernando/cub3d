#include "cub3d.h"

t_cub  *init_cub(void)
{
   static t_cub cub;

   return (&cub);
}
int main(int ac, char **av)
{
   init_cub()->data.fd = -1;
   verfiy(ac, av);
   verfiy_interior(av);
   free_utils();
}