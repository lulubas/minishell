/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_builtins.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbastien <lbastien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 13:34:12 by agheredi          #+#    #+#             */
/*   Updated: 2024/01/31 18:42:39 by lbastien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

// int	ft_builtins(char **argv, char *envp)
// {
// 	int	exit_status;

// 	if (!ft_strncmp(argv[0], "cd", 3))
// 		exit_status = minicd(++argv, envp);
// 	else if (!ft_strncmp(argv[0], "pwd", 4))
// 		exit_status = minipwd();
// 	else if (!ft_strncmp(argv[0], "echo", 5))
// 		exit_status = minipwd();
// 	else if (!ft_strncmp(argv[0], "export", 7))
// 		exit_status = minipwd();
// 	else if (!ft_strncmp(argv[0], "unset", 6))
// 		exit_status = minipwd();
// 	else if (!ft_strncmp(argv[0], "env", 4))
// 		exit_status = minipwd();
// 	else if (!ft_strncmp(argv[0], "exit", 5))
// 		exit_status = minipwd();
// 	else
// 		exit_status = no_builtin();
// 	return (exit_status);
// }