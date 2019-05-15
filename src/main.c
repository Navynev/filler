/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndelhomm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/25 14:25:21 by ndelhomm          #+#    #+#             */
/*   Updated: 2019/05/15 10:05:43 by ndelhomm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/filler.h"

void	free_piece(t_struct *t)
{
	int j;

	j = 0;
	while (j < t->piece_y_h)
		free(t->piece[j++]);
	free(t->piece);
}

void	free_board(t_struct *t)
{
	int i;

	i = 0;
	while (i < t->board_y_h)
		free(t->board[i++]);
	free(t->board);
}

void	free_bp(t_struct *t)
{
	free_board(t);
	free_piece(t);
}

void	init_struct(t_struct *t)
{
	t->myself = 0;
	t->rival = 0;
	t->board_x_w = 0;
	t->board_y_h = 0;
	t->board = NULL;
	t->piece_x_w = 0;
	t->piece_y_h = 0;
	t->piece = NULL;
	t->my_x_w = 0;
	t->my_y_h = 0;
	t->rival_x_w = 0;
	t->rival_y_h = 0;
	t->coord_x = 0;
	t->coord_y = 0;
	t->resolve = 0;
	t->gameover = 0;
	t->end = 0;
}

/*
** 1st gnl reads player info
** 2nd gnl reads plateau info at each round
*/

int		main(void)
{
	t_struct	t;

	init_struct(&t);
	attribute_roles(&t);
	while (1)
	{
		get_board_size(&t);
		get_board(&t);
		get_piece_size(&t);
		get_piece(&t);
		if (!resolve(&t))
			t.gameover = 1;
		next_round(&t);
		display_coords(&t);
		free_bp(&t);
		if (t.end)
		{
			break ;
		}
	}
	return (0);
}
