/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_info.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcrosnie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/22 14:24:30 by pcrosnie          #+#    #+#             */
/*   Updated: 2016/11/12 13:25:04 by pcrosnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

void	ft_recup_piece_size(char *input, t_data *ptr)
{
	int i;
	int j;
	char *str;

	i = 6;
	j = 0;
	str = (char *)malloc(sizeof(char) * 10);
	while (ft_isdigit(input[i]) == 1)
		str[j++] = input[i++];
	str[j] = '\0';
	j = 0;
	ptr->piece_height = ft_atoi(str);
	str = ft_memset(str, '\0', 10);
	i++;
	while (ft_isdigit(input[i]) == 1)
		str[j++] = input[i++];
	str[j] = '\0';
	ptr->piece_width = ft_atoi(str);
//	free(str);
}

char	*ft_str_cut(char *input)
{
	int i;
	int j;
	char *str;

	if (!input)
		return (NULL);
	str = (char *)malloc(sizeof(char) * (ft_strlen(input)));
	i = 4;
	j = 0;
	while (input[i])
	{
		str[j++] = input[i++];
	}
	str[j] = '\0';
	return (str);
}

void	ft_recup_map_size(char *input, t_data *ptr)
{
	int i;
	int j;
	char *str;

	i = 8;
	j = 0;
	str = (char *)malloc(sizeof(char) * 10);
	while (ft_isdigit(input[i]) == 1)
		str[j++] = input[i++];
	str[j] = '\0';
	j = 0;
	ptr->map_height = ft_atoi(str);
	str = ft_memset(str, '\0', 10);
	i++;
	while (ft_isdigit(input[i]) == 1)
		str[j++] = input[i++];
	str[j] = '\0';
	ptr->map_width = ft_atoi(str);
//	free(str);
}

void	ft_parse_player(char *line, t_data *ptr)
{
	if (ft_strstr(line, "exec p1 :") != NULL)
		ptr->c = 'O';
	if (ft_strstr(line, "exec p2 :") != NULL)
		ptr->c = 'X';
}

void	ft_parse_map(char *line, t_data *ptr)
{
	int i;

	i = 0;
	ft_recup_map_size(line, ptr);
	get_next_line(0, &line);
	if (!ptr->map)
		ptr->map = (char **)malloc(sizeof(char *) * (ptr->map_height + 2));
	while (i < ptr->map_height)
	{
		get_next_line(0, &line);
		ptr->map[i++] = ft_str_cut(line);
	}
	ptr->map[i] = NULL;
}

int		ft_set_relative_coord(t_data *ptr, char *line, int i, int res_index)
{
	int j;

	j = 0;
	while (j < ptr->piece_width)
	{
		if (res_index == 0 && line[j] == '*')
		{
			ptr->first_posx = j;
			ptr->first_posy = i;
		}
		if (line[j] == '*')
		{
			ptr->piece[0][res_index] = (char)j - (char)ptr->first_posx;
			ptr->piece[1][res_index] = (char)i - (char)ptr->first_posy;
			res_index++;
		}
		j++;
	}
	return (res_index);
}

void	ft_parse_piece(char *line, t_data *ptr)
{
	int i;

	i = 0;
	ptr->res_index = 0;
	ft_recup_piece_size(line, ptr);
	if (!ptr->piece)
	{
		ptr->piece = (char **)ft_memalloc(sizeof(char *) * 2);
		ptr->piece[0] = (char *)ft_memalloc(sizeof(char) * 100);
		ptr->piece[1] = (char *)ft_memalloc(sizeof(char) * 100);
	}
//	ptr->piece[0] = ft_memset(ptr->piece[0], '\0', 100);
//	ptr->piece[1] = ft_memset(ptr->piece[1], '\0', 100);
//	ptr->piece[2] = NULL;
	while (i < ptr->piece_height)
	{
		get_next_line(0, &line);
		ptr->res_index = ft_set_relative_coord(ptr, line, i, ptr->res_index);
		i++;
	}
//	ptr->piece[i + 1] = NULL;
}
