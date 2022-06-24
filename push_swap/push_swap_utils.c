#include "push_swap.h"

int	count_args(int argc, char **argv)
{
	int	sum;
	int	i;
	int	j;

	i = 1;
	sum = 0;
	while (i < argc && sum >= 0)
	{
		j = 0;
		while (j < strlen(argv[i]) && sum >= 0)
		{
			if (argv[i][j] == ' ')
				sum++;
			if (!((argv[i][j] >= 48) && (argv[i][j] <= 57))
				&& !(argv[i][j] == ' ') && !(argv[i][j] == '-'))
				sum = -2;
			j++;
		}
		i++;
		sum++;
	}
	return (sum);
}
