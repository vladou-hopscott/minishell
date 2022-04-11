/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnafissi <vnafissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 16:43:34 by swillis           #+#    #+#             */
/*   Updated: 2022/04/11 18:42:59 by vnafissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "parsing.h"

//penser à faire une fonction pour initialiser toutes les variables à 0 ou NULL
void	init_values(t_sh *sh)
{
	sh->token_lst = NULL;
	sh->prompt = NULL;
	sh->p_index = 0;
}

void	reset_values(t_sh *sh)
{
	ft_set_null_free_list(&sh->token_lst);
}

void initialization(t_sh *sh)
{
	init_values(sh);
	while (1)
	{
		listen_prompt(sh); //générer un prompt avec readline() et enregistrer la commande tapée
		lexer(sh); //analyse lexicale de la commande
		init_values(sh);
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
