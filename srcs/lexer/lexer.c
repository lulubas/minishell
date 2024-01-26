/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbastien <lbastien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 16:50:48 by lbastien          #+#    #+#             */
/*   Updated: 2024/01/26 15:48:52 by lbastien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	ft_lexer(char *input, t_state *state)
{
	t_token	*token_list;
	t_token	*tmp;

	token_list = NULL;
	ft_lexer_reader(&token_list, input, state);
	tmp = token_list;
	while (tmp)
	{
		tokenise(tmp);
		tmp = tmp->next;
	}
	state->token_list = token_list;
}

void	ft_lexer_reader(t_token **token_list, char *input, t_state *state)
{
	int		length;
	char	*token_str;
	char	*reader;
	int		i;

	length = 0;
	i = 0;
	reader = input;
	while (*reader)
	{
		while (*reader && is_whitespace(*reader))
			reader++;
		while (*reader && !is_whitespace(reader[length]))
			length++;
		if (!*reader)
			break ;
		token_str = strndup(reader, length);
		if (!token_str)
			ft_exit("(Lexer) Failed to malloc token_str\n", state);
		if (add_token(&token_list, token_str))
			ft_exit("(Lexer) Failed to add token", state);
		reader += length;
		length = 0;
	}
}

void	tokenise(t_token *token)
{
	char	*str;

	str = token->str;
	if (ft_strlen(str) == 1)
	{
		if (*str == '|')
			token->token = PIPE;
		else if (*str == '<')
			token->token = INPUT;
		else if (*str == '>')
			token->token = OUTPUT;
		else
			token->token = WORD;
	}
	else if (ft_strlen(str) == 2)
	{
		if (*str == '<' && *(str + 1) == '<')
			token->token = HEREDOC;
		else if (*str == '>' && *(str + 1) == '>')
			token->token = APPEND;
		else
			token->token = WORD;
	}
	else
		token->token = WORD;
}