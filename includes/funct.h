/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   funct.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbastien <lbastien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 16:22:23 by lbastien          #+#    #+#             */
/*   Updated: 2024/01/24 23:09:46 by lbastien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FUNCT_H
# define FUNCT_H
# include "minishell.h"
//Main
void	ru_shell(t_state *state);

//Lexer
void	ft_lexer(char *input, t_state *state);
void	ft_lexer_reader(t_token **item_list, char *input, t_state *state);
int		add_item(t_item **item_list, char *str);
t_item	*create_item(char *str);
void	ft_tokenise(t_token *item);
t_token	identify_token(char *str);

//Utils 
int		ft_strlen(const char *str);
int		is_whitespace(char c);

#endif