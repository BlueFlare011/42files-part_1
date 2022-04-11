#include "so_long.h"

void create_images(T_Var *var)
{
	var->width = 80;
	var->height = 80;
	var->ness = mlx_xpm_file_to_image(var->mlx, "images/nessSprite.xpm",	//ness
	&var->width, &var->height);
	var->floor = mlx_xpm_file_to_image(var->mlx, "images/floorSprite.xpm",	//floor
	&var->width, &var->height);
	var->exit = mlx_xpm_file_to_image(var->mlx, "images/exitSprite.xpm",	//exit
	&var->width, &var->height);
	var->hole = mlx_xpm_file_to_image(var->mlx, "images/holeSprite.xpm",	//hole
	&var->width, &var->height);
	var->object = mlx_xpm_file_to_image(var->mlx, "images/objectSprite.xpm",	//object
	&var->width, &var->height);
}