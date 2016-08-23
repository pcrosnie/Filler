/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcrosnie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/22 11:22:53 by pcrosnie          #+#    #+#             */
/*   Updated: 2016/08/23 17:38:05 by pcrosnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

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
	while (i < ptr->piece_height)
		free(ptr->piece[i++]);
	free(ptr->piece);
	free(ptr->possible_positions[0]);
	free(ptr->possible_positions[1]);
	free(ptr->possible_positions);
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
//	ptr->player = ft_first_read(ptr);
	line = ft_memset(line, '\0', BUFF_SIZE + 1);
	while (get_next_line(0, &line))
	{
		if (ft_strstr(line, "$$$") != NULL)
			ft_parse_player(line, ptr);
		if (ft_strstr(line, "Plateau") != NULL)
			ft_parse_map(line, ptr);
		if (ft_strstr(line, "Piece") != NULL)
		{
			ft_parse_piece(line, ptr);
			ft_algo(ptr);
			ft_free_dat(ptr);
		}
	}
	return (0);
}
