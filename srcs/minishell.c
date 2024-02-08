/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbastien <lbastien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 16:10:27 by lbastien          #+#    #+#             */
/*   Updated: 2024/02/08 19:31:08 by lbastien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	main(int argc, char **argv) //, char **envp)
{
	t_state	*state;

	state = init_state();
	if (argc > 1 || argv[1])
		perror("Minishell does not take any argument.");
	else
		run_shell(state);
	ft_exit("Reached end of main", state);
	return (0);
}

void	run_shell(t_state *state)
{
	char	*input;

	while (1)
	{
		input = readline("minishell_$> ");
		if (!input)
			ft_error("(Input) EOF reached or input error from Readline", state);
		else
		{
			add_history(input);
			ft_lexer(input, state);
			print_tokens(state->token_list);
			if (!state->error)
				ft_expander(state);
			print_tokens(state->token_list);
			// if (!state->error)
			// 	ft_parser(state);
			// if (!state->error)
			// 	ft_print_cmds(state->cmd_list);
		}
		reset_all(state);
		free(input);
	}
	clear_history();
}

t_state	*init_state(void)
{
	t_state	*new_state;

	new_state = malloc(sizeof(t_state));
	new_state->error = NULL;
	new_state->token_list = NULL;
	new_state->cmd_list = NULL;
	new_state->data = NULL;
	return (new_state);
}
