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

#include "filler.h"

int		check_len(t_point p1, t_point p2)
{
	int	resy;
	int	resx;

	resx = FT_MAX(p1.x, p2.x) - FT_MIN(p1.x, p2.x);
	resy = FT_MAX(p1.y, p2.y) - FT_MIN(p1.y, p2.y);
	return (resx + resy);
}

void	create_points(t_player *p, int size)
{
	t_point	point;

	p->player_c = 0;
	p->enemy_c = 0;
	point.x = 0;
	if (!(p->points_p = (t_point*)malloc(size * sizeof(t_point))))
		exit(0);
	if (!(p->points_e = (t_point*)malloc(size * sizeof(t_point))))
		exit(0);
	ft_bzero(p->points_p, size * sizeof(t_point));
	ft_bzero(p->points_e, size * sizeof(t_point));
	while (point.x < p->fild.size.x)
	{
		point.y = 0;
		while (point.y < p->fild.size.y)
		{
			if (p->fild.data[point.x][point.y] == p->my)
				p->points_p[p->player_c++] = point;
			else if (p->fild.data[point.x][point.y] == p->en)
				p->points_e[p->enemy_c++] = point;
			point.y++;
		}
		point.x++;
	}
}

t_point	search_side(t_player *p)
{
	t_point	end;

	end.x = 0;
	end.y = 0;
	if (p->current.x == 0 && p->current.y == 0)
		return (ft_move_right_down(p));
	else if (p->current.x == 0 && p->current.y != 0)
		return (ft_move_left_down(p));
	else if (p->current.x != 0 && p->current.y == 0)
		return (ft_move_right_up(p));
	else if (p->current.x != 0 && p->current.y != 0)
		return (ft_move_left_up(p));
	else
		return (end);
}

t_point	find_pos(t_player *p)
{
	int		i;
	int		j;
	t_point	res;
	t_point	point;
	int		lenght;

	lenght = p->fild.len;
	create_points(p, lenght);
	i = 0;
	while (i < p->player_c)
	{
		j = 0;
		while (j < p->enemy_c)
		{
			if (try_pos(p, p->points_p[i].x, p->points_p[i].y, &res) &&
				check_len(p->points_p[i], p->points_e[j]) <= lenght)
			{
				lenght = check_len(p->points_p[i], p->points_e[j]);
				point = res;
			}
			j++;
		}
		i++;
	}
	return ((lenght != p->fild.len) ? (point) : (search_side(p)));
}
