#include "../../include/cub3d.h"

void	log_data_scene(t_prog *pr)
{
	(void)pr;
	fprintf(stderr, "──────────────────────────・["CYN"data scene"RESET"]\n");
	fprintf(stderr, CYN"North"RESET" texture :	"GRN"%s"RESET"\n"
					CYN"South"RESET" texture :	"GRN"%s"RESET"\n"
					CYN"Est"RESET" texture :	"GRN"%s"RESET"\n"
					CYN"West"RESET" texture :	"GRN"%s"RESET"\n",
					pr->parser->data_scene->textures.no,
					pr->parser->data_scene->textures.so,
					pr->parser->data_scene->textures.ea,
					pr->parser->data_scene->textures.we);
}