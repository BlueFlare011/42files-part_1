#include "push_swap.h"

static int fit_int(char *arg)
{
	int	correct;

	correct = 1;
	if ((arg[0] == '-') && (ft_strlen(arg) > 11))
		correct = 0;
	else if (ft_strlen(arg) > 10)
		correct = 0;
	//comprobar numericamente
	return (correct);
}

static int valid_num(char *arg)
{
	int	i;
	int	flag;

	i = 0;
	flag = arg[0] != '\0';
	while (arg[i] && flag)
	{
		if ((i == 0) && (arg[i] == '-'))
			i++;
		if (!ft_isalnum(arg[i]))
			flag = 0;
		i++;
	}
	return (flag);
}

int error_manager(char *arg, T_Stack *s)
{
	unsigned int	i;
	int				num;

	i = 0;
	if (!valid_num(arg) && !fit_int(arg))
	{
		write(1, "Error: Un argmento no es un numero valido\n", 42);
		return (0);
	}
	num = ft_atoi(arg);
	if (is_repeat(s, num))
	{
		write(1, "Error: hay un numero repetido\n", 30);
		return (0);
	}
	return (1);
}
