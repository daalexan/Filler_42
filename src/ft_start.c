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

void		ft_readfild(char *tetr, t_fild *fild, int ofset)
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

void		ft_readpiece(char *tetr, t_piece *piece, int ofset)
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
}

int			ft_fill_loop(t_player *player)
{
	char	*tetr;
	int		res;

	while ((res = get_next_line(0, &tetr)) > -1)
	{
		if (!tetr)
			continue;
		if (!ft_strncmp(tetr, "Plateau ", 8))
		{
			ft_readfild(tetr, &player->fild, 8);
			if (!(player->fild.init))
			{
				ft_setpos(player);
				ft_find_way(player);
			}
		}
		if (!ft_strncmp(tetr, "Piece ", 6))
		{
			ft_readpiece(tetr, &player->piece, 6);
			ft_start(player);
		}
		ft_strdel(&tetr);
	}
	return (res);
}

int			main(void)
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
			player.en = (piece[10] == '1') ? 'X' : 'O';
			break ;
		}
	}
	ft_strdel(&piece);
	ft_fill_loop(&player);
	return (0);
}
