/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolve_1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndelhomm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/20 12:54:01 by ndelhomm          #+#    #+#             */
/*   Updated: 2019/05/01 15:53:41 by ndelhomm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/filler.h"

/*
** Browses the board from the top down, from left to right
*/

int		resolve_up_left(t_struct *t)
{
	int		i;
	int		j;

	i = 0;
	while (i < t->board_y_h)
	{
		j = 0;
		while (j < t->board_x_w)
		{
			if (try_piece(t, i, j) == 1)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

/*
** Browses the board from the top down, from right to left
*/

int		resolve_up_right(t_struct *t)
{
	int		i;
	int		j;

	i = 0;
	while (i < t->board_y_h)
	{
		j = t->board_x_w;
		while (j > 0)
		{
			if (try_piece(t, i, j) == 1)
				return (1);
			j--;
		}
		i++;
	}
	return (0);
}

/*
** Browses the board from the bottom up, from left to right
*/

int		resolve_down_left(t_struct *t)
{
	int		i;
	int		j;

	i = t->board_y_h;
	while (i > 0)
	{
		j = 0;
		while (j < t->board_x_w)
		{
			if (try_piece(t, i, j) == 1)
				return (1);
			j++;
		}
		i--;
	}
	return (0);
}

/*
** Browses the board from the bottom up, from right to left
*/

int		resolve_down_right(t_struct *t)
{
	int		i;
	int		j;

	i = t->board_y_h;
	while (i > 0)
	{
		j = t->board_x_w;
		while (j > 0)
		{
			if (try_piece(t, i, j) == 1)
				return (1);
			j--;
		}
		i--;
	}
	return (0);
}

int		arbitrage(t_struct *t)
{
	if (t->resolve == 0)
		return (resolve_up_left(t));
	else if (t->resolve == 1)
		return (resolve_down_right(t));
	else if (t->resolve == 2)
		return (resolve_up_right(t));
	else if (t->resolve == 3)
		return (resolve_down_left(t));
	else
		return (0);
}
