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

void	ft_find_way(t_player *player)
{
	
}

void	ft_frst_check(t_player *player, int x, int y, int *con)
{
	if (x - player->piece.figp[0] < 0)
		(*con)++;
	if (y - player->piece.figp[1] < 0)
		(*con)++;
}

void	ft_setpiece(t_player *player, int x, int y)
{
	ft_putnbr(x - player->piece.figp[0]);
	ft_putchar(' ');
	ft_putnbr(y - player->piece.figp[1]);
	ft_putchar('\n');
	free(player->piece.data);
	free(player->fild.data);
	printf("I'm DONE!!!\n");
}