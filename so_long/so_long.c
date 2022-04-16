#include "so_long.h"

void watch_leaks(void)
{
	system("leaks so_long"); //leak checker
}

int main(int argc, char **argv){
	// atexit(watch_leaks);
	t_Var	var; //declaracion de los strcuts generico y de validacion
	t_Valid	valid;
	
	if (!valid_map(argc, argv, &valid, &var)) //si el mapa no es valido no va a ejecutar y lanzara un mensaje de error
	{
		write(1, "Error\n", 6);
		return (0);
	}
	var.exit_bool = valid.obj;
	create_window(&var);
	return (0);
}
