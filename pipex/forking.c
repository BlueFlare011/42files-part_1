#include "pipex.h"

int forking(int argc, char **argv)
{
	int		fd_pipe[2];
	int		infile;
	int		outfile;
	pid_t	process;

	if (pipe(fd_pipe) == -1)
		return (-1);
	process = fork();
	if (process == 0)
	{
		close(fd_pipe[0]);
		infile = open(argv[1], O_RDONLY);
		dup2(STDIN_FILENO, infile);
		dup2(STDOUT_FILENO, fd_pipe[1]);
		//execve("/usr/bin/grep", , NULL);
	}
	else
	{

	}
	return (1);
}