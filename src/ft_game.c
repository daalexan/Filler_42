/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_game.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daalexan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/08 09:42:18 by daalexan          #+#    #+#             */
/*   Updated: 2018/08/08 09:42:20 by daalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_filler.h"

int		loopy(t_player *p, int p1, int p2, int on)
{
	printf("loopY p1 = %d p2 = %d on = %d\n", p1, p2, on);
	while (p1 <= p2)
	{
		printf("points (%d)\n", p1);
		if (ft_valid(p, on, p1))
		{
			p->move.x = on;
			p->move.y = p1;
			return (1);
		}
		p1++;
	}
	return (0);
}

int		loopx(t_player *p, int p1, int p2, int on)
{
	printf("loopX p1 = %d p2 = %d on = %d\n", p1, p2, on);
	while (p1 <= p2)
	{
		printf("points (%d)\n", p1);
		if (ft_valid(p, p1, on))
		{
			p->move.x = p1;
			p->move.y = on;
			return (1);
		}
		p1++;
	}
	return (0);
}

void	try_pos(t_player *p, int *x, int *y)
{
	while (p->move.x >= 0 && p->move.y >= 0 &&
		p->move.x < p->fild.size.x && p->move.y < p->fild.size.y)
	{
		ft_find_way(p, p->move.size);
		printf("FIRST\n");
		if (loopy(p, p->move.y, p->move.y1, p->move.x))
			break ;
		printf("Second\n");
		if (loopy(p, p->move.y, p->move.y1, p->move.x1))
			break ;
		printf("Third\n");
		if (loopx(p, p->move.x, p->move.x1, p->move.y))
			break ;
		printf("fourth\n");
		if (loopx(p, p->move.x, p->move.x1, p->move.y1))
			break ;
		printf("fifth\n");
		p->move.size++;
	}
	(*x) = p->move.x;
	(*y) = p->move.y;
	printf("X = %d Y = %d StartX = %d StartY = %d\n", *x, *y, p->fild.startP[0], p->fild.startP[1]);
}

void	ft_start(t_player *player)
{
	int x;
	int y;

	x = player->fild.startP[0];
	y = player->fild.startP[1];
	//printf("pos1 = x=%d y=%d\n", x, y);
	//printf("figp x = %d y = %d\n", player->piece.figp[0],player->piece.figp[1]);
	try_pos(player, &x, &y);
	//printf("Loop end\n");
	ft_setpiece(player, x, y);
}