/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbastien <lbastien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 16:50:48 by lbastien          #+#    #+#             */
/*   Updated: 2024/02/07 00:03:57 by lbastien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	ft_lexer(char *input, t_state *state)
{
	t_token	*token_list;

	token_list = NULL;
	create_tokens(&token_list, input, state);
	parse_type(token_list);
	state->token_list = token_list;
}

void	create_tokens(t_token **token_list, char *input, t_state *state)
{
	char	*token_str;
	char	*reader;

	reader = input;
	while (*reader && !state->error)
	{
		printf("char=%c", *reader);
		skip_whitespaces(&reader);
		if (is_quote(*reader))
			token_str = handle_quotes(&reader, state);
		else if (is_single_token(reader))
			token_str = ft_strndup(reader, 1);
		else if (is_double_token(reader))
			token_str = ft_strndup(reader, 2);
		else if (*reader == '\0')
			break ;
		else if (!ft_isalnum(*reader))
			ft_error("Unrecognized character in input", state);
		else
			token_str = handle_regular_expression(&reader, state);
		if (token_str)
		{
			add_token(token_list, token_str);
			reader += ft_strlen(token_str);
		}
		else
			ft_error("Failed to parse token", state);
	}
}

void	parse_type(t_token *token)
{
	char	*str;

	while (token)
	{
		str = token->str;
		if (ft_strlen(str) == 1)
		{
			if (*str == '|')
				token->type = PIPE;
			else if (*str == '<')
				token->type = INPUT;
			else if (*str == '>')
				token->type = OUTPUT;
			else
				token->type = WORD;
		}
		else if (ft_strlen(str) == 2)
		{
			if (*str == '<' && *(str + 1) == '<')
				token->type = HEREDOC;
			else if (*str == '>' && *(str + 1) == '>')
				token->type = APPEND;
			else
				token->type = WORD;
		}
		else
			token->type = WORD;
		token = token->next;
	}
}
