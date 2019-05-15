/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndelhomm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/25 13:57:58 by ndelhomm          #+#    #+#             */
/*   Updated: 2019/05/12 13:41:04 by ndelhomm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include "../libft/libft.h"
# include "../include/filler.h"
# include <stdio.h>
# include <fcntl.h>

typedef struct	s_struct
{
	char	myself;
	char	rival;
	int		board_x_w;
	int		board_y_h;
	char	**board;
	int		piece_x_w;
	int		piece_y_h;
	char	**piece;
	int		my_x_w;
	int		my_y_h;
	int		rival_x_w;
	int		rival_y_h;
	int		coord_x;
	int		coord_y;
	int		resolve;
	int		gameover;
	int		end;
}				t_struct;

/*
** init_game.c
*/

void			attribute_roles(t_struct *t);
void			get_position(t_struct *t);

/*
** parse_and_fill.c
*/

void			get_board_size(t_struct *t);
int				get_board(t_struct *t);
void			get_piece_size(t_struct *t);
int				get_piece(t_struct *t);

/*
** resolve_1.c
*/

int				resolve_down_left(t_struct *t);
int				resolve_up_right(t_struct *t);
int				resolve_down_right(t_struct *t);
int				resolve_up_left(t_struct *t);
int				arbitrage(t_struct *t);
int				resolve(t_struct *t);

/*
** resolve_2.c
*/

int				put_piece(t_struct *t, int i, int j);
int				try_piece(t_struct *t, int i, int j);
int				resolve_big_map(t_struct *t);
int				resolve(t_struct *t);

/*
** resolve_big_map.c
*/

int				side_to_side(int x, int y, t_struct *t);
int				rival_red_zone(t_struct *t);
int				get_rival_pos(t_struct *t);
int				resolve_big_up_right(t_struct *t);
int				resolve_big_down_left(t_struct *t);

/*
** display_and_play.c
*/

void			display_coords(t_struct *t);
void			next_round(t_struct *t);

int				resolve_big_map(t_struct *t);
#endif
