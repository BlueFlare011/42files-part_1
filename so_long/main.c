#include "so_long.h"

int main(){
	Vdm	var;
	
	var.weight = 0;
	var.height = 0;
	var.mlx = mlx_init();
	var.mlx_win = mlx_new_window(var.mlx, 1000, 1000, "Map");
	var.img = mlx_xpm_file_to_image(var.mlx, "images/ness.xpm", &var.weight, &var.height);
	mlx_put_image_to_window(var.mlx,  var.mlx_win, var.img, 5, 5);
	mlx_loop(var.mlx);
	return (0);
}
/*
	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1000, 2000, "Hello world!");
	img = mlx_xpm_file_to_image(mlx, "./ness.xpm", &weight, &height);
	mlx_put_image_to_window(mlx,  mlx_win, img, 0, 0);

	mlx_loop(mlx);*/