#include "pipex.h"

int main(int argc, char **argv){
	if (argc < 5)
	{
		write(1, "Error: El numero de argumentos no es valido\n", 44);
		return (0);
	}
	return (0);
}
