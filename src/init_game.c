/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndelhomm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/20 12:54:01 by ndelhomm          #+#    #+#             */
/*   Updated: 2019/05/15 10:07:16 by ndelhomm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/filler.h"

/*
** Parses the line to know who's p1 and who's p2
*/

void	attribute_roles(t_struct *t)
{
	char	*line;

	line = ft_strdup("");
	get_next_line(0, &line);
	if (line == NULL)
		return ;
	else
	{
		t->myself = (ft_atoi(&line[10]) == 1) ? 'O' : 'X';
		free(line);
		line = NULL;
		t->rival = (t->myself == 'O') ? 'X' : 'O';
	}
}

/*
** Finds coords of 'O' and 'X'.
** Makes a strategy arbitrage depending on the rival's position
*/

void	get_position(t_struct *t)
{
	int		i;
	int		j;

	i = 0;
	while (i < t->board_y_h)
	{
		j = 0;
		while (j < t->board_x_w)
		{
			if (t->board[i][j] == t->rival)
			{
				t->rival_x_w = j;
				t->rival_y_h = i;
			}
			if (t->board[i][j] == t->myself)
			{
				t->my_x_w = j;
				t->my_y_h = i;
			}
			j++;
		}
		i++;
	}
	t->resolve = (t->rival_y_h > t->my_y_h) ? 1 : 0;
}
