#include "so_long.h"

int main(int argc, char **argv){
	T_Var	var;
	
	if (!validMap(argc, argv))
		return (0);
	createWindow(&var);
	return (0);
}
