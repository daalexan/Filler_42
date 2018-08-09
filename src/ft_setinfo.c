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
	int	i;
	int	j;

	i = 0;
	while (i < player->fild.size.x)
	{
		j = 0;
		while (player->fild.data[i][j] != '\0')
		{
			if (player->fild.data[i][j] == player->my)
			{
				player->fild.startP[0] = i;
				player->fild.startP[1] = j;
			}
			if (player->fild.data[i][j] == player->en)
			{
				player->fild.startE[0] = i;
				player->fild.startE[1] = j;
			}
			j++;
		}
		i++;
	}
	player->fild.init = 1;
}

void	ft_parse_figwhX(t_piece *piece)
{
	int	i;
	int	j;

	i = piece->size.y;
	piece->figwh[0] = -1;
	while (--i > 0)
	{
		j = piece->size.x;
		while (--j >= 0)
		{
			if (piece->data[j][i] == '*')
			{
				piece->figwh[0] = i;
				break ;
			}
		}
		if (piece->figwh[0] != -1)
			break ;
	}
}

void	ft_parse_figwhY(t_piece *piece)
{
	int	i;
	int j;

	i = piece->size.x;
	piece->figwh[1] = -1;
	while (--i > 0)
	{
		j = piece->size.y;
		while (j >= 0)
		{
			if (piece->data[i][j] == '*')
			{
				piece->figwh[1] = i;
				break ;
			}
			j--;
		}
		if (piece->figwh[1] != -1)
			break ; 
	}
}

void	ft_parse_figpY(t_piece *piece)
{
	int	i;
	int	j;

	i = -1;
	piece->figp[1] = -1;
	while (++i < piece->size.y)
	{
		j = -1;
		while (++j < piece->size.x)
		{
			if (piece->data[j][i] == '*')
			{
				piece->figp[1] = i;
				break ;
			}
		}
		if (piece->figp[1] != -1)
			break ; 
	}
	ft_parse_figwhX(piece);
}

void	ft_parse_figpX(t_piece *piece)
{
	int	i;
	int	j;

	i = -1;
	piece->figp[0] = -1;
	while (++i < piece->size.x)
	{
		j = 0;
		while (piece->data[i][j] != '\0')
		{
			if (piece->data[i][j] == '*')
			{
				piece->figp[0] = i;
				break ;
			}
			j++;
		}
		if (piece->figp[0] != -1)
			break ; 
	}
	ft_parse_figwhY(piece);
}
