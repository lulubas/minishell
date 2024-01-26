/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbastien <lbastien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 17:00:00 by lbastien          #+#    #+#             */
/*   Updated: 2024/01/26 16:13:02 by lbastien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	free_cmds(t_command *cmd_list)
{
	t_command	*tmp;

	tmp = cmd_list;
	while (tmp)
	{
		cmd_list = cmd_list->next;
		free_cmd(tmp);
		tmp = cmd_list;
	}
}

void	free_cmd(t_command *cmd)
{
	if (cmd)
	{
		if (cmd->command)
			free(cmd->command);
		if (cmd->args)
			free_args(cmd);
		if (cmd->tokens)
			free_tokens(cmd->tokens);
		free(cmd);
		cmd = NULL;
	}
}

void	free_tokens(t_token	*tokens)
{
	t_token	*tmp;

	tmp = tokens;
	while (tmp)
	{
		tokens = tokens->next;
		free_token(tmp);
		tmp = tokens;
	}
}

void	free_token(t_token *node)
{
	if (node)
	{
		if (node->str)
			free(node->str);
		free(node);
		node = NULL;
	}
}

void	free_args(t_command *cmd)
{
	int	i;

	i = 0;
	while (i < cmd->args_count)
		free(cmd->args[i++]);
	free(cmd->args);
}