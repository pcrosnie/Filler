/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcrosnie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/22 11:22:53 by pcrosnie          #+#    #+#             */
/*   Updated: 2016/08/23 12:16:31 by pcrosnie         ###   ########.fr       */
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
	ptr = (t_data *)malloc(sizeof(t_data) * 100);
	ptr->player = ft_first_read(ptr);
	line = ft_memset(line, '\0', BUFF_SIZE + 1);
		read(0, line, BUFF_SIZE + 1);
	//	ft_parse_info(line, ptr);
		ft_putstr("12 14\n");
	//	ft_putstr("PARSE OK\n");
		//ft_algo(ptr);
		line = ft_memset(line, '\0', BUFF_SIZE + 1);
	return (0);
}
