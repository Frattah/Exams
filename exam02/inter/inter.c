/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmonfre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 10:11:41 by frmonfre          #+#    #+#             */
/*   Updated: 2023/05/23 10:11:42 by frmonfre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	seen(char *str, char c, int i)
{
	while (--i >= 0)
		if (str[i] == c)
			return (1);
	return (0);
}

int	is_in(char *str, char c)
{
	int	i;

	i = -1;
	while (str[++i])
		if (str[i] == c)
			return (1);
	return (0);
}

int	main(int ac, char **av)
{
	int	i;

	if (ac != 3)
		return (write(1, "\n", 1));
	i = -1;
	while (av[1][++i])
		if (!seen(av[1], av[1][i], i) && is_in(av[2], av[1][i]))
			write(1, &av[1][i], 1);
}
