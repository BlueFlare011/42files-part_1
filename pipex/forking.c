#include "pipex.h"

int forking(char **argv, t_pipy	*my_var)
{
	int		fd_pipe[2];
	pid_t	process;

	if (pipe(fd_pipe) == -1)
		return (-1);
	process = fork();
	if (process == -1)
		return (-1);
	if (process == 0)
	{
		close(fd_pipe[0]);
		dup2(my_var->infile, STDIN_FILENO);
		dup2(fd_pipe[1], STDOUT_FILENO);
		execve(my_var->path_cmd[0], my_var->command[0], NULL);
		close(fd_pipe[1]);
	}
	else
	{
		close(fd_pipe[1]);
		dup2(my_var->outfile, STDOUT_FILENO);
		dup2(fd_pipe[0], STDIN_FILENO);
		execve(my_var->path_cmd[1], my_var->command[1], NULL);
		close(fd_pipe[0]);
	}
	close(fd_pipe[1]);
	close(fd_pipe[2]);
	waitpid(process, NULL, 0);
	return (1);
}