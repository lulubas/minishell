/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniecho.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agheredi <agheredi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 10:08:26 by agheredi          #+#    #+#             */
/*   Updated: 2024/03/01 10:54:23 by agheredi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	print_argecho(char **args, int fd_out, int i)
{
	while (args[i])
	{
		ft_putstr_fd(args[i], fd_out);
		i++;
		if (args[i])
			ft_putstr_fd(" ", fd_out);
	}
}

int	mini_echo(t_command *cmd)
{
	int	i;
	int	flag;

	i = 1;
	flag = 0;
	printf("mini_echo\n");
	if (!cmd->args[i])
	{
		ft_putstr_fd("\n", cmd->fd_out);
		return (0);
	}
	if (cmd->args && cmd->args[i][0] == '-'
		&& cmd->args[i][1] == 'n')
	{
		flag = 1;
		i++;
	}
	print_argecho(cmd->args, cmd->fd_out, i);
	if (flag == 0)
		ft_putstr_fd("\n", cmd->fd_out);
	return (0);
}
