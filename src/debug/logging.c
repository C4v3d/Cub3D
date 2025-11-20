#include "../../include/cub3d.h"

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

void	log_color(t_color *p)
{
	fprintf(stderr, "────────────────・["GRN"Roof Color"RESET"]\n");
	fprintf(stderr, "\n");
	fprintf(stderr, "────────────────・["GRN"R"RESET"]\n");
	fprintf(stderr, "%d\n", p->r);
	fprintf(stderr, "────────────────・["GRN"G"RESET"]\n");
	fprintf(stderr, "%d\n", p->g);
	fprintf(stderr, "────────────────・["GRN"B"RESET"]\n");
	fprintf(stderr, "%d\n", p->b);
}

void	log_data(t_main *cub)
{
	// fprintf(stderr, "────────────────・["GRN"Grid"RESET"]\n");
	log_map(cub);
	log_player_data(&cub->plyr);
	log_color(cub->gfx.colors[FLOOR]);
	log_color(cub->gfx.colors[CEILING]);
}
