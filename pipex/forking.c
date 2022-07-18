#include "pipex.h"

int forking(char **argv, char *rute1, char *rute2, char **cmd1, char **cmd2)
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
		execve(rute1, cmd1, NULL);
		close(fd_pipe[1]);
	}
	else
	{
		close(fd_pipe[1]);
		outfile = open(argv[4], O_WRONLY);
		dup2(STDIN_FILENO,fd_pipe[0]);
		dup2(STDOUT_FILENO, outfile);
		execve(rute2, cmd2, NULL);
		close(fd_pipe[0]);
	}
	close(fd_pipe[1]);
	close(fd_pipe[2]);
	waitpid(process, NULL, 0);
	return (1);
}