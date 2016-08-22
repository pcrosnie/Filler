/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcrosnie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/22 11:22:53 by pcrosnie          #+#    #+#             */
/*   Updated: 2016/08/22 17:14:52 by pcrosnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		ft_first_read(t_data *ptr)
{
	char *line;

	line = (char *)malloc(sizeof(char) * BUFF_SIZE + 1);
	line = ft_memset(line, '\0', BUFF_SIZE + 1);
	read(0, line, BUFF_SIZE + 1);
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

int		main(void)
{
	char *line;
	char **input;
	t_data *ptr;
	int i;

	i = 0;
	line = (char *)malloc(sizeof(char) * (BUFF_SIZE + 1));
	input = (char **)malloc(sizeof(char *) * (BUFF_SIZE + 1));
	ptr = (t_data *)malloc(sizeof(t_data));
	ptr->player = ft_first_read(ptr);
	line = ft_memset(line, '\0', BUFF_SIZE + 1);
	while (read(0, line, BUFF_SIZE))
		input[i++] = ft_strdup(line);
	ft_parse_info(input, ptr);
	ft_putnbr(ptr->map_height);
	ft_putchar('\n');
	ft_putnbr(ptr->map_width);
	return (0);
}