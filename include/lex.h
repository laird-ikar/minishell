/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lex.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bguyot <bguyot@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 07:43:54 by bguyot            #+#    #+#             */
/*   Updated: 2022/04/22 10:19:02 by bguyot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEX_H
# define LEX_H

# include "minishell.h"

typedef struct s_token	t_token;
typedef struct s_mshell	t_mshell;

void	set_token(t_token *token, char *content, int type);
void	expand(t_mshell *mshell, t_token token[MAX_TAB]);
int		is_cmd_char(char c);

#endif
