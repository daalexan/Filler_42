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

#include "ft_filler.h"

void	ft_setpos(t_player *player)
{
	int		i;
	int		j;

	i = 0;
	while (i < player->fild.size[0])
	{
		j = 0;
		while (player->fild.data[i][j] != '\0')
		{
			if (player->fild.data[i][j] == player->my)
			{
				player->fild.start[0] = i;
				player->fild.start[1] = j;
			}
			j++;
		}
		i++;
	}
	player->fild.init = 1;
}

void	ft_parse_figpX(t_piece *piece)
{
	int	i;
	int j;
	int cur;

	i = -1;
	piece->figp[0] = 1000;
	while (++i < piece->size[0])
	{
		j = 0;
		while (piece->data[i][j] != '\0')
		{
			if (piece->data[i][j] == '*')
			{
				cur = j;
				break ;
			}
			j++;
		}
		// if (piece->data[i][j + 1] == '\0' && cur == 0)
		// 	break ; 
		if (piece->figp[0] > cur)
		{
			piece->figp[0] = cur;
			cur = 0;
		}	
		
	}
}

void	ft_parse_figpY(t_piece *piece)
{
	int	i;
	int j;

	i = -1;
	piece->figp[1] = -1;
	while (++i < piece->size[0])
	{
		j = 0;
		while (piece->data[i][j] != '\0')
		{
			if (piece->data[i][j] == '*')
			{
				piece->figp[1] = i;
				break ;
			}
			j++;
		}
		if (piece->figp[1] != -1)
			break ; 
	}
}
