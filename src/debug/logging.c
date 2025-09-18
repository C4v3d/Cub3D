#include "../../include/cub3d.h"

void	log_data_scene(t_cub *cub)
{
	(void)cub;
	fprintf(stderr, "──────────────────────────・["CYN"data scene"RESET"]\n");
	fprintf(stderr, CYN"North"RESET" texture :	"GRN"%s"RESET"\n"
					CYN"South"RESET" texture :	"GRN"%s"RESET"\n"
					CYN"Est"RESET" texture :	"GRN"%s"RESET"\n"
					CYN"West"RESET" texture :	"GRN"%s"RESET"\n",
					cub->data_scene.textures.no,
					cub->data_scene.textures.so,
					cub->data_scene.textures.ea,
					cub->data_scene.textures.we);
}