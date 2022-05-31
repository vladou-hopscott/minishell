/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnafissi <vnafissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 21:39:05 by vnafissi          #+#    #+#             */
/*   Updated: 2022/05/31 21:41:59 by vnafissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <signal.h>
# include <stdarg.h>
# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <stdlib.h>
# include "libft.h"
# include "ft_printf.h"
# include "parsing.h"
# include "pipex.h"
# include "env_manager.h"

//********************** STRUCTURES **********************//

//structure principale du programme
typedef struct s_sh
{
	char			**env;
	t_token			*token_lst;
	t_cmd_line		*cmd_line_lst;
	char			*prompt;
	int				p_index;
	int				p_quote;
	int				error;
}	t_sh;

//********************** GLOBAL VAR **********************//
// extern char	**g_env;

//********************** FUNCTIONS **********************//

//********** INITIALIZATION **********//
void		init_values(t_sh *sh);
void		free_values(t_sh *sh, int free_env);

//********** PROMPT **********//
void		listen_prompt(t_sh *sh);

//********** LEXER **********//
void		lexer(t_sh *sh);
void		tokenizer(t_sh *sh);
char		*process_string_token(t_sh *sh, char *prompt);
void		process_redirect_token(t_sh *sh);
void		update_token_type_str(t_sh *sh);
void		check_syntax_errors(t_sh *sh);

//********** PARSER **********//
void		parser(t_sh *s);
t_cmd_line	*add_back_cmd_line(t_cmd_line *list);
t_cmd_line	*create_cmd_line(void);
void		update_elems_cmd_lines(t_sh *sh);
int			update_cmd(t_cmd_line **cmd_line);
int			update_args(t_cmd_line **cmd_line);
int			count_arg_tokens(t_token *li);
int			update_fdin(t_cmd_line **cmd_line);
int			update_fdout(t_cmd_line **cmd_line);
void		process_quotes_in_tokens(t_cmd_line **cmd_line);
char		*process_quotes_in_token(char **value);
void		expand_envvars_in_tokens(t_cmd_line **cmd_line);
char		*expand_envvars_in_token(char **value);
char		*expand_envvar(char *str, int *i, int *j,
				char **s1, t_quote quote_status);
char		*delimit_envvar(char *str);
t_token		*tokenize_within_token(t_token **token);
t_token		*create_tokens_within_tokens(t_token **token, char *str);
void		update_token_type_heredoc_limit(t_sh *sh);
void		update_tokens_hd_limit(t_cmd_line **cmd_line);
void		print_parser_result(t_sh *sh);

//********** SIGNALS **********//
void		handle_signals(void);

//********** QUOTES **********//
int			check_for_quotes(t_sh *sh);
int			check_quote_status_in_str(char c, int quote_status);
void		interpret_remove_quotes(t_sh *sh);

//********** LINKED LIST TOKENS **********//
t_token		*create_token(t_token_type type, char *value);
t_token		*add_back_token(t_token *list, t_token_type type, char *value);
void		print_tokens(t_token *li);
void		ft_set_null_free_list(t_token **a_list);
t_token		*add_middle_token(t_token *current, t_token_type type, char *value);

//********** HERE DOCUMENTS **********//
int			heredoc(char *delimitor, t_cmd_line **cmd_line);
int			initialize_heredoc(t_cmd_line **cmd_line);
int			run_children(char *delimitor);
char		*read_heredoc_line(t_cmd_line **cmd_line,
				int quotes, char *delimitor);
char		*expand_heredoc_line(char **str);

//********** UTILS **********//
int			str_has_only_spaces(char *str);
int			str_has_charset(char *str, char *charset);
int			str_has_quotes(char *str);
int			str_has_dollar_without_quotes(char *str);
int			str_has_space_without_quotes(char *str);

//********** EXECUTOR **********//
char		**executor(t_token *token, char **env);

#endif
