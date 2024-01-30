/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agheredi <agheredi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 16:10:27 by lbastien          #+#    #+#             */
/*   Updated: 2024/01/30 16:07:01 by agheredi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	main(int argc, char **argv) //, char **envp)
{
	t_state	*state;

	if (argc != 1 || argv[1])
		perror("The number of arguments is not valid.\n");
	state = init_state();
	//state->data->env = copy_env(envp);
	run_shell(state);
	return (1);
}

void	run_shell(t_state *state)
{
	char	*input;

	while (1)
	{
		input = readline("minishell_$> ");
		if (!input)
			ft_exit("(Input) returned an error or EOF", state);
//		add_history(input);
		ft_lexer(input, state);
		ft_parser(state);
//
		free(input);
	}
}

t_state	*init_state(void)
{
	t_state	*new_state;

	new_state = malloc(sizeof(t_state));
	new_state->should_terminate = false;
	new_state->token_list = NULL;
	new_state->cmd_list = NULL;
	new_state->data =  NULL;
	return (new_state);
}
