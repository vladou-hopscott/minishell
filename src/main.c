/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnafissi <vnafissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 16:43:34 by swillis           #+#    #+#             */
/*   Updated: 2022/04/07 18:31:36 by vnafissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "parsing.h"

void initialization(t_sh *sh)
{
	while (1)
	{
		show_prompt(sh);
	}
}

int	main(int ac, char **av)
{
	//Faut-il déclarer sh comme une variable globale (pour garder en mémoire les commandes successives ?)
	t_sh	sh;

	(void)ac;
	(void)av;

	initialization(&sh);

	//penser à free tout ce qui a été initialisé avec readline
	return (0);
}
