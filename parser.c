/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndelhomm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/25 14:25:21 by ndelhomm          #+#    #+#             */
/*   Updated: 2019/03/25 14:25:33 by ndelhomm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"
#include <stdio.h>
#include <fcntl.h>


void	attribute_roles(t_struct *t)
{
	if (t->player == 1)
	{
		t->myself = MYSELF;
		t->rival = RIVAL;
	}
	else if (t->player == 2)
	{
		t->myself = MYSELF;
		t->rival = RIVAL;
	}
}

/*
** Identify players in order of apparition and assign them X or O.
*/

void	init_players(t_struct *t, int fd)
{
	char *line;
	
	line = NULL;
	if (get_next_line(fd, &line) && line) //fd a 0 : entree standard, ici on lit, on n'imprime pas 
	{
		if (ft_strncmp(line, "$$$ exec p", 9) == 0
		&& (line[10] == '1' || line[10] == '2') && !t->player)
		{
			printf("line = %s\n", line);
			if (ft_strstr(line, "p1"))
				t->player = 1;
			else if (ft_strstr(line, "p2"))
				t->player = 2;
		}
	}
	ft_strdel(&line);
	attribute_roles(t);
}

/*
** Get the board game dimension size by reading Plateau's info (height and width).
*/

int			allocate_and_fill_board(t_struct *t, int fd)
{
	int i;
	char *line;
	char	**board;

	line = NULL;
	i = 0;
	if (!(board = (char **)malloc(sizeof(char *) * (t->y_width + 1))))
		return (0);
	while (i < t->x_height + 1) 
	{
		//printf("ligne numero[%d]\n", i);
		get_next_line(fd, &line);
		board[i] = ft_strdup(&line[4]);
		i++;
	}
	i = 0;
	while (i < t->x_height)
	{
		printf("%s\n", board[i]);
		i++;
	}
	return (1);
}

void	get_struct_size(t_struct *t, int fd)
{
	char	*line;
	int		i;

	i = 0;
	line = NULL;
	if (get_next_line(fd, &line) > 0)
	{	
		while (!ft_isdigit(line[i]))
			i++;
		t->x_height = ft_atoi(&line[i]);
		while (ft_isdigit(line[i]))
			i++;
		t->y_width = ft_atoi(&line[i]);
		ft_strdel(&line);
	}
	printf("width : %d\n", t->y_width);
	printf("height : %d\n", t->x_height);
	allocate_and_fill_board(t, fd);
}



int	main(int argc, char **argv)
{
	t_struct		t={.x=0};
	int			fd;
	int			i;

	(void)argc;
	i = 0;
	fd = open(argv[1], O_RDONLY);

	init_players(&t, fd);
	
	get_struct_size(&t, fd);
	close(fd);
	printf("t.x : %d\n", t.x);
	printf("t.y : %d\n", t.y);
	printf("t.player : %d\n", t.player);
	printf("myself = %c && rival = %c\n", t.myself, t.rival);

	return (0);
}


// TODO : recuperer les infos du plateau
// TODO : recuperer les infos de la piece

// void			get_strat_pos(int i, t_map *map, char *str)
// {
// 	int			i2;
// 	static int	i3;

// 	if (i3 == map->map_size_y)
// 		return ;
// 	i3 = 0;
// 	while (++i3 < (map->map_size_y))
// 	{
// 		i2 = 0;
// 		while (++i2 < (map->map_size_x))
// 		{
// 			if ((map->map[i3][i2] == map->en[0] ||
// 				map->map[i3][i2] == map->en[1]))
// 			{
// 				map->pos_enemy_x = i2;
// 				map->pos_enemy_y = i3;
// 			}
// 			if ((map->map[i3][i2] == map->me[0] ||
// 				map->map[i3][i2] == map->me[1]))
// 			{
// 				map->my_pos_x = i2;
// 				map->my_pos_y = i3;
// 			}
// 		}
// 	}
// }

