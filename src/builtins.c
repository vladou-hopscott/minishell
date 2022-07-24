/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vladimir <vladimir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 11:37:07 by vnafissi          #+#    #+#             */
/*   Updated: 2022/07/24 23:57:05 by vladimir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern t_sh	g_sh;

// ======================= ECHO ====================================

int	find_first_arg_to_print(int ac, char **av, int *ntrail)
{
	int	i;
	int	j;

	i = 1;
	while ((i < ac) && (av[i][0] == '-'))
	{
		j = 1;
		while (av[i][j] == 'n')
			j++;
		if (j != (int)ft_strlen(av[i]))
			break ;
		*ntrail = 0;
		i++;
	}
	return (i);
}

void	builtin_echo(int ac, char **av, int fdout)
{
	int	i;
	int	ntrail;

	ntrail = 1;
	i = find_first_arg_to_print(ac, av, &ntrail);
	if (i < ac)
		ft_putstr_fd(av[i++], fdout);
	while (i < ac)
	{
		ft_putchar_fd(' ', fdout);
		ft_putstr_fd(av[i++], fdout);
	}
	if (ntrail)
		ft_putchar_fd('\n', fdout);
	ft_free_values_exit(&g_sh, SUCCESS, 1);
}

// ======================= PWD ====================================

void	builtin_pwd(int ac, int fdout)
{
	char	*pwd;
	char	*buf;
	char	*err1;
	char	*err2;
	char	*err3;

	(void)ac;
	err1 = "pwd: error retrieving current directory: getcwd: ";
	err2 = "cannot access parent directories: No such file or directory\n";
	buf = getcwd(NULL, 0);
	if (!buf)
	{
		err3 = ft_strjoin(err1, err2);
		ft_putstr_fd(err3, 2);
		set_error_exit_status(&g_sh, FAILURE);
		free(err3);
		ft_free_values_exit(&g_sh, FAILURE, 1);
	}
	pwd = ft_strdup(buf);
	free(buf);
	ft_putstr_fd(pwd, fdout);
	ft_putchar_fd('\n', fdout);
	free(pwd);
	ft_free_values_exit(&g_sh, SUCCESS, 1);
}

// ======================= EXIT ====================================

void	builtin_exit(int ac, char **av)
{
	if (ac == 1)
	{
		printf("ac==1\n");
		if (!g_sh.has_pipe)
		{
			printf("g_sh.has_pipe=%d\n", g_sh.has_pipe);
			ft_putstr_fd("exit\n", STDOUT_FILENO);
			ft_free_values_exit(&g_sh, g_sh.exit_status, 1);
		}
	}
	else
	{
		if (str_is_long_long(av[1]))
		{
			if (ac > 2)
			{
				if (!g_sh.has_pipe)
					ft_putstr_fd("exit\n", STDOUT_FILENO);
				ft_putstr_fd("minishell: exit: too many arguments\n", 2);
				set_error_exit_status(&g_sh, FAILURE);
			}
			else
				ft_free_values_exit(&g_sh, ft_atoll(av[1]), 1);
		}
		else
			err_exit_invalid(&g_sh, av[1]);
	}
}
/*
	if (ac > 2)
	{
		ft_putstr_fd("minishell: exit: too many arguments\n", 2);
		set_error_exit_status(&g_sh, FAILURE);
	}
	else if (!g_sh.has_pipe)
	{
		ft_putstr_fd("exit\n", STDOUT_FILENO);
		if (ac == 1)
			ft_free_values_exit(&g_sh, g_sh.exit_status, 1);
		else if (ac == 2)
		{
			if (str_is_long_long(av[1]))
				ft_free_values_exit(&g_sh, ft_atoll(av[1]), 1);
			else
				err_exit_invalid(&g_sh, av[1]);
		}
		ft_free_values_exit(&g_sh, FAILURE, 1);
	}
	*/