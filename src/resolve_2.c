/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolve_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndelhomm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/01 10:22:45 by ndelhomm          #+#    #+#             */
/*   Updated: 2019/05/01 16:11:22 by ndelhomm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/filler.h"

/*
** Puts piece if and only if a '*' matches my player character one time
*/

int	put_piece(t_struct *t, int i, int j)
{
	int		contact;
	int		y;
	int		x;

	contact = 0;
	y = 0;
	while (y < t->piece_y_h)
	{
		x = 0;
		while (x < t->piece_x_w)
		{
			if (t->piece[y][x] == '*')
			{
				if (t->board[i + y][j + x] == t->myself ||
					t->board[i + y][j + x] == t->myself + 32)
					contact++;
				if (t->board[i + y][j + x] == t->rival ||
					t->board[i + y][j + x] == t->rival + 32)
					return (0);
			}
			x++;
		}
		y++;
	}
	return ((contact == 1) ? 1 : 0);
}

/*
** Sets conditions to put the piece
** Can't put it if piece is too large or if board is not wide engough
*/

int	try_piece(t_struct *t, int i, int j)
{
	if (i + t->piece_y_h > t->board_y_h)
		return (0);
	else if (j + t->piece_x_w > t->board_x_w)
		return (0);
	else if (put_piece(t, i, j) == 1)
	{
		t->coord_x = j;
		t->coord_y = i;
		return (1);
	}
	else
		return (0);
}

/*
** Choses the best algorithm to win on big_maps
*/

int	resolve_big_map(t_struct *t)
{
	if (rival_red_zone(t))
	{
		if (t->myself == 'O' || t->myself == 'O' + 32)
			return (resolve_big_up_right(t));
		else
			return (resolve_big_down_left(t));
	}
	else
		return (arbitrage(t));
}

int	resolve(t_struct *t)
{
	int resolution;

	resolution = 0;
	if (t->board_x_w * t->board_y_h > 400)
	{
		resolution = resolve_big_map(t);
		if (!resolution)
			return (arbitrage(t));
		else
			return (1);
	}
	else
		return (arbitrage(t));
}
