/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcrosnie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/23 10:39:08 by pcrosnie          #+#    #+#             */
/*   Updated: 2016/08/24 16:52:44 by pcrosnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		ft_check_valid_pos(int i, int j, t_data *ptr)
{
	int a;
	int b;
	int nb_sup;

	a = 0;
	b = 0;
	nb_sup = 0;
	while (a < ptr->piece_height && (i + ptr->a + a) < ptr->map_height)
	{
		b = 0;
		while (b < ptr->piece_width && (j + ptr->b + b) < ptr->map_width)
		{
			if (i + ptr->a + a < 0 || j + ptr->b + b < 0 || !(ptr->map[i + ptr->a + a][j + ptr->b + b]))
				return (0);
			if (!(ptr->map[i + ptr->a + a][j + ptr->b + b]))
				return (0);
			if (ptr->piece[a][b] == '*' && ptr->map[i + ptr->a + a][j + ptr->b + b] == ptr->c)
				nb_sup++;
			else if (ptr->map[i + ptr->a + a][j + ptr->b + b] != '.' && ptr->map[i + ptr->a + a][j + ptr->b + b] != ptr->c)
				return (0);
			b++;
		}
		a++;
	}
	if (nb_sup == 1)
		return (1);
	return (0);
}

int		ft_set_poss_pos(int i, int j, t_data *ptr)
{
	int a;

	a = 0;
/*	while (ptr->possible_positions[0][a] && a < BUFF_SIZE)*/
	while (a < ptr->nb_sol)
	{
		if (ptr->possible_positions[0][a] == i + ptr->a && ptr->possible_positions[1][a] == j + ptr->b)
			return (0);
		a++;
	}
	ptr->nb_sol++;
	ptr->possible_positions[0][a] = i + ptr->a;
	ptr->possible_positions[1][a] = j + ptr->b;
	return (0);
}

void	ft_check_pos_for_piece(int i, int j, t_data *ptr)
{
	ptr->a = 0;
	if (i < 0)
		i = 0;
	if (j < 0)
		j = 0;
	while (ptr->a < ptr->piece_height * 2 + 1 && ptr->a + i < ptr->map_height)
	{
		ptr->b = 0;
		while (ptr->b < ptr->piece_width * 2 + 1 && ptr->b + j < ptr->map_width)
		{
			if (ptr->b + j + ptr->piece_width > ptr->map_width || ptr->a + i + ptr->piece_height > ptr->map_width)
				break;
			if (ptr->b + j + ptr->piece_width < 0 || ptr->a + i + ptr->piece_height < 0)
				break;
			if (ft_check_valid_pos(i, j, ptr) == 1)
				ft_set_poss_pos(i, j, ptr);
			ptr->b++;
		}
		ptr->a++;
	}
}

void	ft_check_possible_positions(t_data *ptr)
{
	int i;
	int j;

	i = 0;
	ptr->possible_positions = (char **)malloc(sizeof(char *) * 2);
	ptr->possible_positions[0] = (char *)malloc(sizeof(char) * (ptr->map_height * ptr->map_width));
	ptr->possible_positions[1] = (char *)malloc(sizeof(char) * (ptr->map_height * ptr->map_width));
	ptr->possible_positions[0][0] = '\0';
	ptr->possible_positions[1][0] = '\0';
	while (i < ptr->map_height)
	{
		j = 0;
		while (j < ptr->map_width)
		{
			if (ptr->map[i][j] == ptr->c)
				ft_check_pos_for_piece(i - ptr->piece_height, j - ptr->piece_width, ptr);
			j++;
		}
		i++;
	}
}

void	ft_algo(t_data *ptr)
{
	int i;

	i = 0;
	ft_check_possible_positions(ptr);
//	ft_strat(ptr);
	
	while (i < ptr->nb_sol)
	{
		if (ptr->possible_positions[0][i] - 1 > 0)
		ft_putnbr(ptr->possible_positions[0][i] - 1);
		else
			ft_putnbr(0);
		ft_putchar(' ');
		ft_putnbr(ptr->possible_positions[1][i]);
		ft_putchar('\n');
		i++;
	}
}
