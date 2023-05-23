#include <unistd.h>

int	is_in(char *s, char c, int i)
{
	int	j;

	j = -1;
	while (s[++j] && j < i)
		if (s[j] == c)
			return (1);
	return (0);
}

int	main(int ac, char **av)
{
	int	i;

	if (ac != 3)
		return (1);
	i = -1;
	while (av[1][++i] && av[2][i])
	{
		if (av[1][i] == av[2][i] && !is_in(av[1], av[1][i], i))
			write(1, av[1] + i, 1);
	}
	write(1, "\n", 1);
}
