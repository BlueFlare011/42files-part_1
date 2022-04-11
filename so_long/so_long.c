#include "so_long.h"

int main(int argc, char **argv){
	T_Var	var;
	T_Valid	valid;
	
	if (!valid_map(argc, argv, &valid))
	{
		write(1, "Error\n", 6);
		return (0);
	}
	create_window(&var, &valid);
	return (0);
}
