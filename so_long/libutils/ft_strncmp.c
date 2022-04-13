#include "../so_long.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned int	i;

	i = 0;
	while ((i < n) && s2[i] && s1[i])
	{
		if (s2[i] != s1[i])
			return ((unsigned const char)s1[i] - (unsigned const char)s2[i]);
		i++;
	}
	if (i != n)
		return ((unsigned const char)s1[i] - (unsigned const char)s2[i]);
	return (0);
}
