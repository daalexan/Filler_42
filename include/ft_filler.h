/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_filler.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daalexan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/25 16:17:30 by daalexan          #+#    #+#             */
/*   Updated: 2018/07/25 16:17:33 by daalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FILLER_H
# define FT_FILLER_H

# include "libft.h"
# include <stdio.h>
# include <stdlib.h>

typedef	struct		s_move
{
	int				size;
	int				x;
	int				y;
	int				x1;
	int				y1;
}					t_move;

typedef	struct		s_point
{
	int				x;
	int				y;
}					t_point;

typedef struct 		s_fild	
{
	short			init;
	t_point			size;
	int				startP[2];
	int				startE[2];
	char			**data;
}					t_fild;

typedef struct		s_piece 
{
	t_point			size;
	int				figp[2];
	int				figwh[2];
	char			**data;
}					t_piece;

typedef struct		s_player
{
	int				stop;
	char			my;
	char			en;
	t_fild			fild;
	t_piece			piece;
	t_move			move;
}					t_player;

void				ft_setpos(t_player *player);
void				ft_parse_figpX(t_piece *piece);
void				ft_parse_figpY(t_piece *piece);
void				ft_start(t_player *player);
void				ft_setpiece(t_player *player, int x, int y);
int					ft_check_player(char *piece, t_player *player);
void				ft_find_way(t_player *player, int size);
int					ft_valid(t_player *player, int x, int y);

#endif