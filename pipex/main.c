#include "pipex.h"

int main(int argc, char **argv)
{
	(void)argc;
	(void)argv;
	int fd1 = open("test1.txt", O_RDWR);
	int fd2 = open("test2.txt", O_RDWR);
	int fd[2];
	fd[0] = fd1;
	fd[1] = fd2;
	pipe(fd);
	write(fd1, "Probando el pipe\n", 17);
	close(fd1);
	close(fd2);
	return (0);
}