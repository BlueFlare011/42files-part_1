#include "push_swap.h"

int is_num(char *arg)
{
	unsigned int	i;

	i = 0;
	while (arg[i] != '\0')
	{
		if (!ft_isdigit(arg[i]))
			return (0);
		i++;
	}
	return (1);
}

int isnt_int(char *arg)
{
	if (ft_strlen(arg) > 11)
		return (0);
	return (1);
}

int is_repeat(char **args, int len)
{
	int	i;
	int j;

	i = 0;
	j = 0;
	while (i < len)
	{
		while (j < len)
		{
			if (ft_strlen(args[i]) == ft_strlen(args[j]))
			{
				if (ft_strncmp(args[i], args[j], ft_strlen(args[i])) == 0)
					return (1);
			}
			j++;
		}
		i++;
	}
	return (0)
}

int error_manager(char **args, int len)
{
	unsigned int	i;

	i = 1;
	while (i < len)
	{
		if ((is_num(args[i]) || isnt_int(args[i])) && is_repeat(args, len))
		{
			ft_printf("Error\n");
			return (1);
		}
		i++;
	}
	return (0);
}