/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndelhomm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/25 13:57:58 by ndelhomm          #+#    #+#             */
/*   Updated: 2019/03/25 13:58:01 by ndelhomm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include "libft/libft.h"

# define MYSELF 'o'
# define RIVAL  'x'

typedef struct	s_struct
{
	int		x;
	int		y;
	int		player;
	char	myself;
	char	rival;
	int		y_width;
	int		x_height;
}				t_struct;


#endif
