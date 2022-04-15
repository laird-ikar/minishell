/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lex.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bguyot <bguyot@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 07:43:54 by bguyot            #+#    #+#             */
/*   Updated: 2022/04/15 13:10:57 by bguyot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEX_H
# define LEX_H

# include "minishell.h"

typedef struct s_token	t_token;

void	set_token(t_token *token, char *content, int type);
int		is_cmd_char(char c);

#endif
