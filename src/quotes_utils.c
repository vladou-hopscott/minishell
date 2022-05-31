/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quotes_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnafissi <vnafissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 21:24:37 by vnafissi          #+#    #+#             */
/*   Updated: 2022/05/31 21:26:28 by vnafissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	check_quote_status_in_str(char c, int quote_status)
{
	if (quote_status == NO_QUOTE)
	{
		if (c == SINGLE_QUOTE)
			quote_status = SINGLE_QUOTE;
		else if (c == DOUBLE_QUOTE)
			quote_status = DOUBLE_QUOTE;
	}
	else if (quote_status == SINGLE_QUOTE)
	{
		if (c == SINGLE_QUOTE)
			quote_status = NO_QUOTE;
	}
	else if (quote_status == DOUBLE_QUOTE)
	{
		if (c == DOUBLE_QUOTE)
			quote_status = NO_QUOTE;
	}
	return (quote_status);
}

//check if there are unclosed quotes. if so, return error status 1
int	check_for_quotes(t_sh *sh)
{
	int	i;

	i = 0;
	while (sh->prompt && sh->prompt[i])
	{
		sh->p_quote = check_quote_status_in_str(sh->prompt[i], sh->p_quote);
		i++;
	}
	if (sh->p_quote != NO_QUOTE)
	{
		sh->error = 1;
		ft_putstr_fd("bash : unclosed quotes\n", 2);
		return (1);
	}
	return (0);
}
