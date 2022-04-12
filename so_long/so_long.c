#include "so_long.h"

void	free_map(T_Var *var)
{
	int i;

	i = 0;
	while (i < var->size_y)
	{
		free(var->map[i]);
	}
	free(var->map);
}

int main(int argc, char **argv){
	T_Var	var;
	T_Valid	valid;
	
	if (!valid_map(argc, argv, &valid, &var))
	{
		write(1, "Error\n", 6);
		if (!var.map)
			free_map(&var);
		return (0);
	}
	create_window(&var);
	return (0);
}
