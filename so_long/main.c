#include "so_long.h"

int main(int argc, char **argv){
	Vdm	var;
	
	(void)argv;
	(void)argc;
	/*if (argc != 2)
		return (ft_error());*/
	var.mlx = mlx_init();
	createWindow(&var);
	mlx_loop(var.mlx);
	return (0);
}
