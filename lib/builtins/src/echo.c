/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swillis <swillis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 20:02:28 by swillis           #+#    #+#             */
/*   Updated: 2022/04/18 21:36:02 by swillis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

int	main(int ac, char **av)
{
	int	i;
	int	ntrail;

	ntrail = 1;
	i = 1;
	while (i < ac)
	{
		if ((ntrail == 1) && (ft_strncmp(av[i], "-n", 2) == 0))
			ntrail = 0;
		else if ((i > 1) && (ft_strncmp(av[i], "-n", 2) == 0) \
								&& (ft_strncmp(av[i - 1], "-n", 2) == 0))
			ntrail = 0;
		else
		{
			ft_putstr(av[i]);
			if (i < ac - 1)
				ft_putchar(' ');
		}
		i++;
	}
	if (ntrail)
		ft_putchar('\n');
	return (0);
}
