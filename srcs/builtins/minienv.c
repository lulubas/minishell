/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minienv.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agusheredia <agusheredia@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 12:10:07 by agheredi          #+#    #+#             */
/*   Updated: 2024/02/23 12:12:15 by agusheredia      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	mini_env(t_state *state, char ***env)
{
	int	i;
	//int	size;

	i = 0;
	//size = double_array_size(*env);
	while ((*env)[i])
	{
		ft_putendl_fd((*env)[i], state->cmd_list->fd_out);
		i++;
	}
	return (0);
}
