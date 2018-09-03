/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_setinfo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daalexan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/02 11:42:28 by daalexan          #+#    #+#             */
/*   Updated: 2018/08/02 11:42:29 by daalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	free_mem_fild(t_fild *fild, int move)
{
	int		i;
	char	*str;

	if (!fild->data)
		return ;
	i = 0;
	while (i < fild->size.x)
	{
		str = fild->data[i] - move;
		ft_strdel(&str);
		i++;
	}
	ft_memdel((void **)&fild->data);
}

void	free_mem_piece(t_piece *piece, int move)
{
	int		i;
	char	*str;

	if (!piece->data)
		return ;
	i = 0;
	while (i < piece->size.x)
	{
		str = piece->data[i] - move;
		ft_strdel(&str);
		i++;
	}
	ft_memdel((void **)&piece->data);
}

void	check_curr_pos(t_player *p)
{
	if ((p->fild.starte.x - p->fild.startp.x) < 0)
	{
		p->current.x = 0;
	}
	else
	{
		p->current.x = (p->fild.size.x - 1);
	}
	if ((p->fild.starte.y - p->fild.startp.y) < 0)
	{
		p->current.y = 0;
	}
	else
	{
		p->current.y = (p->fild.size.y - 1);
	}
	p->fild.len = p->fild.size.x * p->fild.size.y;
	p->fild.init = 1;
}

void	ft_setpos(t_player *p)
{
	t_point	point;

	point.x = 0;
	while (point.x < p->fild.size.x)
	{
		point.y = 0;
		while (point.y < p->fild.size.y)
		{
			if (p->fild.data[point.x][point.y] == p->my)
				p->fild.startp = point;
			if (p->fild.data[point.x][point.y] == p->en)
				p->fild.starte = point;
			point.y++;
		}
		point.x++;
	}
	check_curr_pos(p);
}
