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

void	log_player_data(t_player *p)
{
	fprintf(stderr, "────────────────・["GRN"Player data"RESET"]\n");
	fprintf(stderr, "\n");
	fprintf(stderr, "────────────────・["GRN"Position"RESET"]\n");
	fprintf(stderr, "x_coordinate :%f\n", p->pos[X]);
	fprintf(stderr, "y_coordinate :%f\n", p->pos[Y]);
	fprintf(stderr, "────────────────・["GRN"Direction"RESET"]\n");
	fprintf(stderr, "x_direction :%f\n", p->dir[X]);
	fprintf(stderr, "y_direction :%f\n", p->dir[Y]);
	fprintf(stderr, "────────────────・["GRN"AOV"RESET"]\n");
	fprintf(stderr, "aov :%f\n", p->aov);
}

void	log_data(t_main *cub)
{
	// fprintf(stderr, "────────────────・["GRN"Grid"RESET"]\n");
	// log_map(cub);
	log_player_data(&cub->plyr);

}
