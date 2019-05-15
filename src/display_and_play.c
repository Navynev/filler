/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_and_play.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndelhomm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/20 12:54:01 by ndelhomm          #+#    #+#             */
/*   Updated: 2019/05/12 13:31:27 by ndelhomm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/filler.h"

/*
** Sends to the VM the coords to put the piece
*/

void	display_coords(t_struct *t)
{
	if (t->gameover == 1)
	{
		t->end = 1;
		t->coord_x = 0;
		t->coord_y = 0;
		ft_putnbr(t->coord_y);
		ft_putchar(' ');
		ft_putnbr(t->coord_x);
		ft_putchar('\n');
	}
	else
	{
		ft_putnbr(t->coord_y);
		ft_putchar(' ');
		ft_putnbr(t->coord_x);
		ft_putchar('\n');
	}
}

/*
** Prepares next round's strategy:
** Splits the plateau in 4, and put piece diagonally to restrain
** the other player's zone.
*/

void	next_round(t_struct *t)
{
	if (t->resolve == 0)
		t->resolve = 3;
	else if (t->resolve == 1)
		t->resolve = 2;
	else if (t->resolve == 2)
		t->resolve = 1;
	else if (t->resolve == 3)
		t->resolve = 0;
}
