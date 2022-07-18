#include "pipex.h"

char	*verify_commands(char **path, char *cmd) //path <-> cmd
{
	char	*commnd;
	int		i;
	int		flag;

	i = 0;
	flag = 0;
	while (path[i] && !flag)
	{
		commnd = ft_strjoin(path[i], cmd);
		if (access(commnd, X_OK) == 0)
			flag++;
		else
			free(commnd);
		i++;
	}
	if (!flag)
		commnd = NULL;
	return (commnd);
}

char	**create_path(char **envp)
{
	int		i;
	char	*path;
	char	**all_directions;

	i = 0;
	path = NULL;
	while (envp[i] && !path)
	{
		if (ft_strncmp(envp[i], "PATH=", 5) == 0)
			path = ft_substr(envp[i], 5, ft_strlen(envp[i]));
		i++;
	}
	all_directions = ft_split(path, ':');
	free(path);
	return (all_directions);
}

void	manage_path(char **envp, char **cmd1, char **cmd2, char **add1, char **add2)
{
	char	**path;
	char	*bnry1;
	char	*bnry2;

	path = create_path(envp);
	bnry1 = ft_strjoin("/", cmd1[0]);
	bnry2 = ft_strjoin("/", cmd2[0]);
	*add1 = verify_commands(path, bnry1);
	*add2 = verify_commands(path, bnry2);
	free(bnry1);
	free(bnry2);
}
