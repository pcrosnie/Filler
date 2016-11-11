/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcrosnie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/22 11:22:53 by pcrosnie          #+#    #+#             */
/*   Updated: 2016/11/11 10:33:35 by pcrosnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

int		ft_first_read(t_data *ptr)
{
	char *line;

	line = (char *)malloc(sizeof(char) * BUFF_SIZE + 1);
	line = ft_memset(line, '\0', BUFF_SIZE + 1);
	get_next_line(0, &line);
	if (ft_strstr(line, "exec p1 :") != NULL)
	{
		free(line);
		ptr->c = 'O';
		return (1);
	}
	if (ft_strstr(line, "exec p2 :") != NULL)
	{
		free(line);
		ptr->c = 'X';
		return (2);
	}
	free(line);
	return (0);
}

char	**ft_read(char **map)
{
	char *line;
	int i;

	i = 0;
	while (get_next_line(0, &line) && i < 30)
	{
//		ft_putstr("INPUT :");
		map[i++] = ft_strdup(line);
//		ft_putendl(line);
		ft_putstr("12 4\n");
	}
//	ft_putstr("ENDINPUT\n");
	map[i] = NULL;
	return (map);
}

void	ft_free_dat(t_data *ptr)
{
	int i;

	i = 0;
	while (i < ptr->map_height)
		free(ptr->map[i++]);
	free(ptr->map);
	i = 0;
	while (i < 2)
		free(ptr->piece[i++]);
	free(ptr->piece);
//	free(ptr->possible_positions[0]);
//	free(ptr->possible_positions[1]);
//	free(ptr->possible_positions);
}

void	ft_output(int a, int b)
{
	if (a > 0)
		ft_putnbr(a);
	else
		ft_putnbr(0);
	ft_putchar(' ');
	ft_putnbr(b);
	ft_putchar('\n');
}

void	ft_print_values(char **tab, t_data *ptr)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i < 2)
	{
		j = 0;
		while (j < ptr->nb_sol)
		{
			ft_putnbr(tab[i][j]);
			ft_putchar(' ');
			j++;
		}
		ft_putchar('\n');
		i++;
	}
}

int		main(void)
{
	char *line;
	t_data *ptr;
	int i;
	int check;

	i = 0;
	check = 0;
	line = (char *)malloc(sizeof(char) * (BUFF_SIZE + 2));
	ptr = (t_data *)malloc(sizeof(t_data) * 100);
	ptr->a = 0;
	ptr->b = 0;
	ptr->c = 0;
	ptr->map_height = 0;
	ptr->map_width = 0;
	ptr->piece_height = 0;
	ptr->piece_width = 0;
	ptr->my_quart = 0;
	ptr->strat = 0;
	ptr->nb_sol = 0;
//	ptr->player = ft_first_read(ptr);
	line = ft_memset(line, '\0', BUFF_SIZE + 1);
	while (get_next_line(0, &line))
	{
		if (ft_strstr(line, "$$$") != NULL)
			ft_parse_player(line, ptr);
		if (ft_strstr(line, "Plateau") != NULL)
		{
			ft_parse_map(line, ptr);
//			ft_print_char_tab(ptr->map);
		}
		if (ft_strstr(line, "Piece") != NULL)
		{
			ft_parse_piece(line, ptr);
//			ft_print_char_tab(ptr->piece);
			ft_check_possible_positions(ptr);
			ft_putnbr(ptr->first_posx);
			ft_putchar('\n');
			ft_putnbr(ptr->first_posx);
//			ft_print_values(ptr->possible_positions, ptr);
			ptr->nb_sol = 0;
//			ft_algo(ptr);
			ft_free_dat(ptr);
		}
	}
	return (0);
}
