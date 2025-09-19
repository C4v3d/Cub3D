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