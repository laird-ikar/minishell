/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bguyot <bguyot@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 08:01:37 by bguyot            #+#    #+#             */
/*   Updated: 2022/04/14 08:16:53 by bguyot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/parse.h"

void	ft_parse(t_command *command, t_token tokens[MAX_TAB])
{
	(void) command;
	// COMBAK: lex tester here
	while ((*tokens).type)
	{
		printf("type : %d\ncontent : %s\n\n", (*tokens).type, (*tokens).content);
		tokens++;
	}
	// TODO: all parse
}
