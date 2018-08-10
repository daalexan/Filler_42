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

#include "ft_filler.h"

void	ft_find_way(t_player *player, int size)
{
	player->move.size = size;
	player->move.x = player->fild.startP[0];
	player->move.y = player->fild.startP[1];
	player->move.x1 = player->fild.startP[0];
	player->move.y1 = player->fild.startP[1];
	player->move.x -= player->move.size;
	player->move.y -= player->move.size;
	player->move.x1 += player->move.size;
	player->move.y1 += player->move.size;
}

int	ft_check_player(char *piece, t_player *player)
{
	char	*str;

	str = "daalexan";
	while (*piece)
	{
		if (*piece == *str)
		{
			while (*piece++ == *str++)
			{
				if (*str == '\0')
				{
					if (get_next_line(0, &piece) && piece && 
					!ft_strncmp(piece, "$$$ exec p", 9) &&
					(piece[10] == '1' || piece[10] == '2'))
					{
						player->my = (piece[10] == '1') ? 'O' : 'X';
						player->en = (piece[10] == '1') ? 'X' : 'O';
						return (1);		
					}
				}
			}
		}
		piece++;
	}
	return (0);
}

void	ft_frst_check(t_player *p, int x, int y, int i, int j)
{
	if (x - p->piece.figp[0] < 0)
		p->stop++;
	if (y - p->piece.figp[1] < 0)
		p->stop++;
	if ((x >= p->fild.size.x || y >= p->fild.size.y) &&
		p->piece.data[i][j] == '*')
			p->stop++;
}

int	ft_valid(t_player *p, int x, int start)
{
	int	i;
	int	j;
	int y;

	p->stop = 0;
	y = start;
	i = p->piece.figp[0] - 1;
	while (++i < p->piece.size.x && p->stop <= 1)
	{
		j = p->piece.figp[1] - 1;
		y = start;
		while (++j < p->piece.size.y)
		{
			printf("(%c (%d,%d), %c (%d,%d))\n", p->fild.data[x][y], x, y, p->piece.data[i][j], i, j);
			ft_frst_check(p, x, y, i, j);
			if ((p->fild.data[x][y] == 'X' || p->fild.data[x][y] == 'x' ||
				p->fild.data[x][y] == 'O' || p->fild.data[x][y] == 'o') &&
				(p->piece.data[i][j] == '*'))
					p->stop++;
			y++;
		}
		x++;
	}
	return ((p->stop == 1) ? (1) : (0));
}

void	ft_setpiece(t_player *player, int x, int y)
{
	if (!ft_valid(player, x, y))
	{
		ft_putstr("0 0\n");
		exit(0);
	}
	ft_putnbr(x - player->piece.figp[0]);
	ft_putchar(' ');
	ft_putnbr(y - player->piece.figp[1]);
	ft_putchar('\n');
	free(player->piece.data);
	free(player->fild.data);
	printf("I'm DONE!!!\n");
}
