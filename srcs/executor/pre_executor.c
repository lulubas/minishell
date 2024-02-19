/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pre_executor.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbastien <lbastien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 10:28:05 by agheredi          #+#    #+#             */
/*   Updated: 2024/02/19 12:27:37 by lbastien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	pre_executor(t_state *state)
{
	int	exit_code;

	if (state->data->commands == 1)
		one_cmd(state);
	else
	{
		ft_init_pipes(state);
		multiple_cmd(state);
	}
}

void	exc_one_cmd(t_state *state)
{
	char	*path;
	char	**all_path;

	all_path = ft_parse_path(state->data->env);
	path = get_path(all_path, state->cmd_list->command);
	printf("%s\n", path);
	if (path == NULL)
		ft_error_perm(NOCMD, state->cmd_list->command);
	execve(path, state->cmd_list->args, state->data->env);
}

int	one_cmd(t_state *state)
{
	int	exit_code;
	int	pid;
	int	status;

	exit_code = 0;
	if (state->cmd_list->is_builtin == 0)
	{
		exit_code = ft_builtins(state);
		return (exit_code);
	}
	else
	{
		pid = fork();
		if (pid < 0)
			ft_error_sms("Error en fork");
		if (pid == 0)
			exc_one_cmd(state);
		waitpid(pid, &status, 0);
		//if (WEXITSTATUS(status) != 0)
		//	exit(WEXITSTATUS(status));
	}
	return (exit_code);
}

int	pre_executor(t_state *state)
{
	int	exit_code;

	is_builtins(state);
	if (state->data->pipes == 0)
		exit_code = one_cmd(state);
	else
	{
		exit_code = 0;
		printf("mas de un comando\n");
		//malloc de los pid
		//executor
	}
	return (exit_code);
}
