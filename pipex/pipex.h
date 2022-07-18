#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <sys/wait.h>
#include <string.h> //no apto
#include <stdio.h> //no apto
#include "Libft/libft.h"
#include "ft_printf/ft_printf.h"

int		forking(char **argv, char *rute1, char *rute2, char **cmd1, char **cmd2);
void	manage_path(char **envp, char **cmd1, char **cmd2, char **add1, char **add2);
#endif