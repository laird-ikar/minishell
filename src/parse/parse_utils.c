/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bguyot <bguyot@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 12:26:06 by bguyot            #+#    #+#             */
/*   Updated: 2022/05/09 07:23:55 by bguyot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/parse.h"

void	fd_in_limit(t_command *c, t_token tk[MAX_TAB], int *i)
{
	char	*line;

	if (tk[*i - 1].type == IN_LIMIT)
	{
		if (c->in_fd != 0)
			close(c->in_fd);
		c->in_fd = open("..__in", O_RDWR | O_CREAT | O_TRUNC,
				S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
		line = readline("> ");
		while (ft_strcmp(line, tk[*i].content))
		{
			write(c->in_fd, line, ft_strlen(line));
			write(c->in_fd, "\n", 1);
			line = readline("> ");
		}
		close(c->in_fd);
		c->in_fd = open("..__in.tmp", O_RDWR,
				S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
		c->do_read_stdin = 0;
	}
}
