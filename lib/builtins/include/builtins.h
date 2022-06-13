/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vladimir <vladimir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 15:50:12 by swillis           #+#    #+#             */
/*   Updated: 2022/06/13 15:50:03 by vladimir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTINS_H
# define BUILTINS_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <errno.h>
# include <string.h>

//********** FILES **********//
char	**ft_freetbl(char **tbl, int pos);
char	**ft_split(char *s, char c);
char	*ft_strdup(char *src);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strjoin(char *s1, char *s2);
void	ft_putstr_fd(char *s, int fd);


//********** UTILS **********//
size_t	ft_strlen(char *str);
void	ft_putchar(char c);
void	ft_putstr(char *str);

//********** UTILS_ENV **********//
int		ft_tbllen(char **tbl);
char	**tbl_append(char **env, char *str);
int		env_findkeypos(char *key, char **env);
char	*env_findkeyvalue(char *key, char **env);
char	**env_export(char *key, char *value, char **env);

#endif
