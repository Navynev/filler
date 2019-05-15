/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolve_big_map.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndelhomm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/01 10:22:45 by ndelhomm          #+#    #+#             */
/*   Updated: 2019/05/01 16:10:33 by ndelhomm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/filler.h"

/*
** Finds out where the rival is, in a 3*3 square around you
*/

int	side_to_side(int x, int y, t_struct *t)
{
	int		i;
	int		j;
	char	rival;

	rival = t->rival;
	j = y - 1;
	while (j > -1 && j < t->board_y_h && j <= y + 1)
	{
		i = x - 1;
		while (i > -1 && i < t->board_x_w && i <= x + 1)
		{
			if (t->board[j][i] == rival || t->board[j][i] == rival + 32)
				return (1);
			i++;
		}
		j++;
	}
	return (0);
}

int	rival_red_zone(t_struct *t)
{
	int x;
	int y;

	y = 0;
	while (y < t->board_y_h)
	{
		x = 0;
		while (x < t->board_x_w)
		{
			if ((t->board[y][x] == t->myself ||
				t->board[y][x] == t->myself + 32) && side_to_side(x, y, t))
				return (1);
			x++;
		}
		y++;
	}
	return (0);
}

int	get_rival_pos(t_struct *t)
{
	int x;
	int y;

	y = 0;
	while (y < t->piece_y_h)
	{
		x = 0;
		while (x < t->piece_x_w)
		{
			if (t->piece[y][x] == '*' &&
				side_to_side(x + t->coord_x, y + t->coord_y, t))
				return (1);
			x++;
		}
		y++;
	}
	return (0);
}

/*
** Browses the board from the top down, from right to left
*/

int	resolve_big_up_right(t_struct *t)
{
	t->coord_y = 0;
	while (t->coord_y < t->board_y_h)
	{
		t->coord_x = t->board_x_w;
		while (t->coord_x > 0)
		{
			if (try_piece(t, t->coord_y, t->coord_x) &&
				get_rival_pos(t))
				return (1);
			t->coord_x--;
		}
		t->coord_y++;
	}
	return (0);
}

/*
** Browses the board from the bottom up, from left to right
*/

int	resolve_big_down_left(t_struct *t)
{
	t->coord_y = t->board_y_h;
	while (t->coord_y > 0)
	{
		t->coord_x = 0;
		while (t->coord_x < t->board_x_w)
		{
			if (try_piece(t, t->coord_y, t->coord_x) &&
				get_rival_pos(t))
				return (1);
			t->coord_x++;
		}
		t->coord_y--;
	}
	return (0);
}
