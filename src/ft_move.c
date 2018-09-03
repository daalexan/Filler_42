/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daalexan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/14 11:19:06 by daalexan          #+#    #+#             */
/*   Updated: 2018/08/14 11:19:08 by daalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

t_point		ft_move_right_down(t_player *p)
{
	t_point	point;
	t_point	res;

	point.x = p->current.x;
	while (point.x < p->fild.size.x)
	{
		point.y = p->current.y;
		while (point.y < p->fild.size.y)
		{
			if (p->fild.data[point.x][point.y] == p->my &&
				try_pos(p, point.x, point.y, &res))
			{
				return (res);
			}
			if (p->current.y == 0)
				point.y += 1;
			else
				point.y -= 1;
		}
		if (p->current.x == 0)
			point.x += 1;
		else
			point.x -= 1;
	}
	return (point);
}

t_point		ft_move_left_down(t_player *p)
{
	t_point	point;
	t_point	res;

	point.x = p->current.x;
	while (point.x < p->fild.size.x)
	{
		point.y = p->current.y;
		while (point.y >= 0)
		{
			if (p->fild.data[point.x][point.y] == p->my &&
				try_pos(p, point.x, point.y, &res))
			{
				return (res);
			}
			if (p->current.y == 0)
				point.y += 1;
			else
				point.y -= 1;
		}
		if (p->current.x == 0)
			point.x += 1;
		else
			point.x -= 1;
	}
	return (point);
}

t_point		ft_move_right_up(t_player *p)
{
	t_point	point;
	t_point	res;

	point.x = p->current.x;
	while (point.x >= 0)
	{
		point.y = p->current.y;
		while (point.y < p->fild.size.y)
		{
			if (p->fild.data[point.x][point.y] == p->my &&
				try_pos(p, point.x, point.y, &res))
			{
				return (res);
			}
			if (p->current.y == 0)
				point.y += 1;
			else
				point.y -= 1;
		}
		if (p->current.x == 0)
			point.x += 1;
		else
			point.x -= 1;
	}
	return (point);
}

t_point		ft_move_left_up(t_player *p)
{
	t_point	point;
	t_point	res;

	point.x = p->current.x;
	while (point.x >= 0)
	{
		point.y = p->current.y;
		while (point.y >= 0)
		{
			if (p->fild.data[point.x][point.y] == p->my &&
				try_pos(p, point.x, point.y, &res))
			{
				return (res);
			}
			if (p->current.y == 0)
				point.y += 1;
			else
				point.y -= 1;
		}
		if (p->current.x == 0)
			point.x += 1;
		else
			point.x -= 1;
	}
	return (point);
}
