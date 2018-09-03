/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_showpiece.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daalexan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/09 15:54:06 by daalexan          #+#    #+#             */
/*   Updated: 2018/08/09 15:54:07 by daalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		ft_frst_check(t_player *p, int x, int y)
{
	if (x + p->piece.size.x > p->fild.size.x ||
		y + p->piece.size.y > p->fild.size.y)
	{
		return (1);
	}
	return (0);
}

int		check_pos(t_player p, int x, int y)
{
	if (x >= 0 && y >= 0 && x < p.fild.size.x && y < p.fild.size.y)
		return (1);
	else
		return (0);
}

int		ft_valid(t_player *p, int x, int y)
{
	t_point	point;

	if (ft_frst_check(p, x, y))
		return (1);
	p->stop = 0;
	point.x = 0;
	while (point.x < p->piece.size.x)
	{
		point.y = 0;
		while (point.y < p->piece.size.y)
		{
			if (p->piece.data[point.x][point.y] == '*' &&
				p->fild.data[x + point.x][y + point.y] == p->my &&
				++(p->stop) > 1)
				return (1);
			if (p->piece.data[point.x][point.y] == '*' &&
				p->fild.data[x + point.x][y + point.y] == p->en)
				return (1);
			point.y++;
		}
		point.x++;
	}
	return (p->stop < 1 ? 1 : 0);
}

int		try_pos(t_player *p, int x, int y, t_point *res)
{
	int	i;
	int	j;

	i = 0;
	while (i < p->piece.size.x)
	{
		j = 0;
		while (j < p->piece.size.y)
		{
			res->x = x - i;
			res->y = y - j;
			if (p->piece.data[i][j] == '*' && check_pos(*p, res->x, res->y) &&
				!ft_valid(p, res->x, res->y))
			{
				return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

void	ft_setpiece(t_player *p)
{
	t_point	finish;

	finish = find_pos(p);
	if (!check_pos(*p, finish.x, finish.y))
	{
		if (p->points_p)
			free(p->points_p);
		if (p->points_e)
			free(p->points_e);
		ft_putstr("0 0\n");
		exit(0);
	}
	else
	{
		ft_putnbr(finish.x);
		ft_putchar(' ');
		ft_putnbr(finish.y);
		ft_putchar('\n');
		if (p->points_p)
			free(p->points_p);
		if (p->points_e)
			free(p->points_e);
	}
}
