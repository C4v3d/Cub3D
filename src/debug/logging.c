#include "../../include/cub3d.h"

void	log_colors(t_main *cub)
{
	fprintf(stderr, "────────────────・["GRN"Ceiling color"RESET"]\n");
	fprintf(stderr, RED"R"RESET":	%d\n", cub->gfx.colors[CEILING]->r);
	fprintf(stderr, GRN"G"RESET":	%d\n", cub->gfx.colors[CEILING]->g);
	fprintf(stderr, BLU"B"RESET":	%d\n", cub->gfx.colors[CEILING]->b);
	fprintf(stderr, "HEX:	%#06x", cub->gfx.colors[CEILING]->color);
	fprintf(stderr, "\n");
	fprintf(stderr, "────────────────・["GRN"Floor color"RESET"]\n");
	fprintf(stderr, RED"R"RESET":	%d\n", cub->gfx.colors[FLOOR]->r);
	fprintf(stderr, GRN"G"RESET":	%d\n", cub->gfx.colors[FLOOR]->g);
	fprintf(stderr, BLU"B"RESET":	%d\n", cub->gfx.colors[FLOOR]->b);
	fprintf(stderr, "HEX:	%#06x", cub->gfx.colors[FLOOR]->color);
}

void	log_map(t_main *cub)
{
	int	i = 0;

	while (cub->map.grid[i])
		fprintf(stderr, "%s\n", cub->map.grid[i++]);
}

void	log_map_data(t_main *cub)
{
	fprintf(stderr, "────────────────・["GRN"Grid"RESET"]\n");
	log_map(cub);
	fprintf(stderr, "────────────────・["GRN"Dimention"RESET"]\n");
	fprintf(stderr, "X :%ld\n", cub->map.dim[X]);
	fprintf(stderr, "Y :%ld\n", cub->map.dim[Y]);
	fprintf(stderr, "────────────────・["GRN"Player Start Position"RESET"]\n");
	fprintf(stderr, "Player start X :%f\n", cub->plyr.pos->x);
	fprintf(stderr, "Player start Y :%f\n", cub->plyr.pos->y);
	fprintf(stderr, "────────────────・["GRN"Player Start Orientation"RESET"]\n");
	fprintf(stderr, "Player orientation :%ld\n", cub->map.plyr_start_ori);
}