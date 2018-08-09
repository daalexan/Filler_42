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

void	try_pos(t_player *player, int *x, int *y)
{
	(void)player;
	(*x)--;
	(*y)--;
	//create this algorithm
}

int	ft_valid(t_player *player, int x, int y)
{
	int	i;
	int	j;
	int con;

	con = 0;
	i = player->piece.figp[0] - 1;
	while (++i < player->piece.size.x && con <= 1)
	{
		j = player->piece.figp[1] - 1;
		y = player->fild.startP[1];
		while (++j < player->piece.size.y)
		{
			if ((x >= player->fild.size.x || y >= player->fild.size.y) &&
				player->piece.data[i][j] == '*')
				con++;
			ft_frst_check(player, x, y, &con);
			printf("(%c (%d,%d), %c (%d,%d))\n", player->fild.data[x][y], x, y, player->piece.data[i][j], i, j);
			if ((player->fild.data[x][y] == 'X' || player->fild.data[x][y] == 'x' ||
				player->fild.data[x][y] == 'O' || player->fild.data[x][y] == 'o') &&
				(player->piece.data[i][j] == '*'))
				con++;
			y++;
		}
		x++;
	}
	return ((con == 1) ? (1) : (0));
}

void	ft_start(t_player *player)
{
	int x;
	int y;

	x = player->fild.startP[0];
	y = player->fild.startP[1];
	printf("pos1 = x=%d y=%d\n", x, y);
	printf("figp x = %d y = %d\n", player->piece.figp[0],player->piece.figp[1]);
	while (!ft_valid(player, x, y))
	{
		try_pos(player, &x, &y);
	}
	printf("Loop end\n");
	ft_setpiece(player, x, y);
}