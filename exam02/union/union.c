#include <unistd.h>

int	seen(char *str, char c, int i)
{
	while (i-- >= 0)
		if (c == str[i])
			return (1);
	return (0);
}

int	main(int ac, char **av)
{
	int	i;
	int	j;

	if (ac != 3)
		return (write(1, "\n", 1));
	i = -1;
	j = -1;
	while (av[1][++i])
	{
		if (!seen(av[1], av[1][i], i))
			write(1, &av[1][i], 1);
	}
	while (av[2][++j])
	{
		if (!seen(av[2], av[2][j], j)
			&& !seen(av[1], av[2][j], i))
			write(1, &av[2][j], 1);
	}
	write(1, "\n", 1);
}
