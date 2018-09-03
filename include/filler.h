/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daalexan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/16 11:32:55 by daalexan          #+#    #+#             */
/*   Updated: 2018/08/16 11:33:09 by daalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include "libft.h"
# include <stdlib.h>
# define FT_MAX(x, y) ((x >= y) ? (x) : (y))
# define FT_MIN(x, y) ((x <= y) ? (x) : (y))

typedef	struct		s_point
{
	int				x;
	int				y;
}					t_point;

typedef struct		s_fild
{
	short			init;
	t_point			size;
	int				len;
	t_point			startp;
	t_point			starte;
	char			**data;
}					t_fild;

typedef struct		s_piece
{
	t_point			size;
	char			**data;
}					t_piece;

typedef struct		s_player
{
	int				stop;
	char			my;
	char			en;
	t_fild			fild;
	t_piece			piece;
	t_point			current;
	t_point			*points_p;
	int				player_c;
	t_point			*points_e;
	int				enemy_c;
}					t_player;

void				ft_setpos(t_player *player);
t_point				find_pos(t_player *p);
void				ft_setpiece(t_player *player);
int					ft_valid(t_player *player, int x, int y);
int					try_pos(t_player *p, int x, int y, t_point *res);
void				free_mem_piece(t_piece *piece, int move);
void				free_mem_fild(t_fild *fild, int move);
t_point				ft_move_right_down(t_player *p);
t_point				ft_move_left_down(t_player *p);
t_point				ft_move_right_up(t_player *p);
t_point				ft_move_left_up(t_player *p);

#endif
