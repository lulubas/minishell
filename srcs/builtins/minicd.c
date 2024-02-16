/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minicd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbastien <lbastien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 13:48:46 by agheredi          #+#    #+#             */
/*   Updated: 2024/02/16 17:09:44 by lbastien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

char	*get_dir_var(t_state *state)
{
	char	*dir;

	dir = NULL;
	if (state->cmd_list->args_count == 1
		|| (ft_strncmp(state->cmd_list->args[1], "~", 2) == 0))
	{
		dir = get_var_env("HOME", state->data->env);
		if (!dir)
			ft_error_sms("cd HOME not set");
	}
	else
		dir = ft_strdup(state->cmd_list->args[1]);
	return (dir);
}

/*char	**update_cd(t_state *state)
{
	char	**nenv;
	//cambiar el valor de pwd a oldpwd y en pwd tomar el valor actual
	return (nenv);
}*/

int	minicd(t_state *state)
{
	char	*var;

	var = get_dir_var(state);
	printf("%s\n", var);
	if (!var)
		return (1);
	if (chdir(var) == -1)
		ft_error_perm(404, var);
	//state->data->env = update_cd(state);
	free(var);
	return (0);
}
