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

#include "filler.h"

t_point		ft_get_size(char *str)
{
	t_point size;

	str = ft_strchr(str, ' ');
	str++;
	size.x = ft_atoi(str);
	str = ft_strchr(str, ' ');
	size.y = ft_atoi(str);
	return (size);
}

void		ft_readfild(char *tetr, t_fild *fild, int ofset)
{
	int		i;

	i = 0;
	free_mem_fild(fild, ofset);
	fild->size = ft_get_size(tetr);
	get_next_line(0, &tetr);
	ft_strdel(&tetr);
	fild->data = (char**)malloc((fild->size.x) * sizeof(char *));
	while (i < fild->size.x)
	{
		get_next_line(0, &tetr);
		fild->data[i] = tetr + ofset;
		i++;
	}
}

void		ft_readpiece(char *tetr, t_piece *piece, int ofset)
{
	int		i;

	i = 0;
	free_mem_piece(piece, ofset);
	piece->size = ft_get_size(tetr);
	piece->data = (char**)malloc((piece->size.x) * sizeof(char*));
	while (i < piece->size.x)
	{
		get_next_line(0, &tetr);
		piece->data[i] = tetr + ofset;
		i++;
	}
}

void		ft_fill_loop(t_player *player)
{
	char	*tetr;

	while (get_next_line(0, &tetr) > -1)
	{
		if (!tetr)
			continue;
		if (!ft_strncmp(tetr, "Plateau ", 8))
		{
			ft_readfild(tetr, &player->fild, 4);
			if (!(player->fild.init))
				ft_setpos(player);
		}
		if (!ft_strncmp(tetr, "Piece ", 6))
		{
			ft_readpiece(tetr, &player->piece, 0);
			ft_setpiece(player);
		}
		ft_strdel(&tetr);
	}
}

int			main(void)
{
	t_player	player;
	char		*piece;

	ft_bzero(&player, sizeof(t_player));
	piece = NULL;
	get_next_line(0, &piece);
	if (!piece || (piece[10] != '1' && piece[10] != '2'))
		return (1);
	player.my = (piece[10] == '1' ? 'O' : 'X');
	if (player.my == 'O')
		player.en = 'X';
	else
		player.en = 'O';
	ft_strdel(&piece);
	ft_fill_loop(&player);
	return (0);
}
