#include "so_long.h"

void break_all(T_Var *var)
{
	mlx_destroy_image(var->mlx, var->ness);
	mlx_destroy_image(var->mlx, var->object);
	mlx_destroy_image(var->mlx, var->hole);
	mlx_destroy_image(var->mlx, var->floor);
	mlx_destroy_image(var->mlx, var->exit);
	mlx_clear_window(var->mlx, var->win);
}

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