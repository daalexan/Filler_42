/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_start.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daalexan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/25 16:18:22 by daalexan          #+#    #+#             */
/*   Updated: 2018/07/25 16:18:23 by daalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_filler.h"

t_point		ft_checksize(char *tetr, int ofset)
{
	t_point		point;
	char		arr[5];
	int			i;
	int			j;

	j = 0;
	i = 0;
	tetr += ofset;
	while (*tetr)
	{
		if (*tetr >= '0' && *tetr <= '9' && *tetr != ' ')
		{
			arr[j] = *tetr;
			j++;
		}
		else if (*tetr == ' ')
		{
			point.x = ft_atoi(arr);
			i++;
			j = 0;
		}
		tetr++;
	}
	point.y = ft_atoi(arr);
	return (point);
}

void	ft_readfild(char *tetr, t_fild *fild, int ofset)
{
	char	*str;
	int		i;

	i = -1;
	fild->size = ft_checksize(tetr, ofset);
	fild->data = (char**)malloc((fild->size.x) * sizeof(char*));
	get_next_line(0, &str);
	while (++i < fild->size.x && get_next_line(0, &str) > -1)
		fild->data[i] = str + 4;
	ft_strdel(&str);
}

void	ft_readpiece(char *tetr, t_piece *piece, int ofset)
{
	char	*str;
	int		i;

	i = -1;
	piece->size = ft_checksize(tetr, ofset);
	piece->data = (char**)malloc((piece->size.x) * sizeof(char*));
	while (++i < piece->size.x && get_next_line(0, &str) > -1)
		piece->data[i] = str;
	ft_strdel(&str);
	ft_parse_figpX(piece);
	ft_parse_figpY(piece);
	if (piece->fig1[0] == piece->fig2[0] &&
		piece->fig1[1] == piece->fig2[1])
	{
		piece->figp[0] = piece->fig1[0];
		piece->figp[1] = piece->fig1[1];
	}
	else
	{
		piece->figp[0] = piece->fig2[0] - piece->fig1[1];
		piece->figp[1] = piece->fig2[1] - piece->fig1[0];
		piece->figp[0] = (piece->figp[0] >= 0) ? (piece->figp[0]) : (0);
		piece->figp[0] = (piece->figp[0] >= 0) ? (piece->figp[0]) : (0);
	}
}

void	ft_FillLoop(t_player *player)
{
	char	*tetr;

	while (get_next_line(0, &tetr) > -1)
	{
		if (!tetr)
			continue;
		if (!ft_strncmp(tetr, "Plateau ", 8))
		{
			ft_readfild(tetr, &player->fild, 8);
			if (!(player->fild.init))
				ft_setpos(player);
		}
		if (!ft_strncmp(tetr, "Piece ", 6))
		{
			printf("SIZE 1 x = %d y = %d\n", player->fild.size.x, player->fild.size.y);
			ft_readpiece(tetr, &player->piece, 6);
			printf("SIZE 2 x = %d y = %d\n", player->fild.size.x, player->fild.size.y);
			ft_start(player);
		}
		ft_strdel(&tetr);
	}
}

int		main(void)
{
	t_player	player;
	char		*piece;

	ft_bzero(&player, sizeof(t_player));
	piece = NULL;
	while (1)
	{
		if (get_next_line(0, &piece) && piece &&
			!ft_strncmp(piece, "$$$ exec p", 9) &&
			(piece[10] == '1' || piece[10] == '2'))
		{
			player.my = (piece[10] == '1') ? 'O' : 'X';
			player.en = (piece[10] == '2') ? 'O' : 'X';
			break ;
		}
	}
	ft_strdel(&piece);
	ft_FillLoop(&player);
	return (0);
}
