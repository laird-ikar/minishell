/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lex.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bguyot <bguyot@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 07:43:54 by bguyot            #+#    #+#             */
/*   Updated: 2022/04/14 09:38:46 by bguyot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEX_H
# define LEX_H

# include "minishell.h"

void	set_token(t_token *token, char *content, int type);
int		is_cmd_char(char c);

#endif
