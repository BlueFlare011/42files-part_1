#include "so_long.h"

void watch_leaks(void)
{
	system("leaks so_long");
}

int main(int argc, char **argv){
	atexit(watch_leaks);
	T_Var	var;
	T_Valid	valid;
	
	if (!valid_map(argc, argv, &valid, &var))
	{
		write(1, "Error\n", 6);
		return (0);
	}
	var.exit_bool = valid.obj;
	create_window(&var);
	return (0);
}
