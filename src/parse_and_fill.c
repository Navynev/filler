/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_and_fill.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndelhomm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/20 12:54:01 by ndelhomm          #+#    #+#             */
/*   Updated: 2019/05/15 10:07:57 by ndelhomm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/filler.h"

/*
** Reads piece's dimensions (width and height)
*/

void	get_piece_size(t_struct *t)
{
	int		i;
	char	*line;

	i = 0;
	line = NULL;
	get_next_line(0, &line);
	if (ft_strncmp(line, "Piece", 4) == 0)
	{
		while (!ft_isdigit(line[i]))
			i++;
		t->piece_y_h = ft_atoi(&line[i]);
		while (ft_isdigit(line[i]))
			i++;
		t->piece_x_w = ft_atoi(&line[i]);
	}
	ft_strdel(&line);
}

/*
** Allocates memory for the piece
** Fills the empty piece by the piece sent by the VM
*/

int		get_piece(t_struct *t)
{
	int		i;
	char	*line;

	i = 0;
	line = NULL;
	t->piece = (char **)malloc(sizeof(char *) * (t->piece_y_h + 1));
	if (!t->piece)
		return (-1);
	while (i < t->piece_y_h)
	{
		get_next_line(0, &line);
		t->piece[i] = (char *)malloc(sizeof(char *) * (t->piece_x_w + 1));
		t->piece[i] = ft_strcpy(t->piece[i], (const char *)line);
		i++;
	}
	ft_strdel(&line);
	return (0);
}

/*
** Reads plateau's dimensions (width and height)
*/

void	get_board_size(t_struct *t)
{
	int		i;
	char	*line;

	i = 0;
	line = NULL;
	get_next_line(0, &line);
	if (ft_strncmp(line, "Plateau", 6) == 0)
	{
		while (!ft_isdigit(line[i]))
			i++;
		t->board_y_h = ft_atoi(&line[i]);
		while (ft_isdigit(line[i]))
			i++;
		t->board_x_w = ft_atoi(&line[i]);
	}
	ft_strdel(&line);
}

/*
** 1st gnl skip the line after the plateau
** Allocates memory for the board
** Fills the empty plateau by the updated plateau sent by the VM
*/

int		get_board(t_struct *t)
{
	int		i;
	char	*line;

	i = 0;
	line = NULL;
	get_next_line(0, &line);
	ft_strdel(&line);
	t->board = malloc(sizeof(char *) * (t->board_y_h + 1));
	if (!t->board)
		return (-1);
	while (i < t->board_y_h)
	{
		if (get_next_line(0, &line) != 1)
			return (-1);
		if (ft_isdigit(line[0]))
		{
			t->board[i] = ft_strdup(&line[4]);
			ft_strdel(&line);
		}
		i++;
	}
	if (t->rival_x_w == 0 && t->rival_y_h == 0
			&& t->my_x_w == 0 && t->my_y_h == 0)
		get_position(t);
	return (0);
}
