/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_info.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcrosnie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/22 14:24:30 by pcrosnie          #+#    #+#             */
/*   Updated: 2016/08/23 17:42:22 by pcrosnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

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
	free(str);
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
	free(str);
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
	ptr->map = (char **)malloc(sizeof(char *) * (ptr->map_height + 3));
//	line = ft_memset(line, '\0', BUFF_SIZE + 1);
	while (i < ptr->map_height)
	{
		get_next_line(0, &line);
		ptr->map[i++] = ft_str_cut(line);
	}
	ptr->map[i] = NULL;
}

void	ft_parse_piece(char *line, t_data *ptr)
{
	int i;

	i = 0;
	ft_recup_piece_size(line, ptr);
	ptr->piece = (char **)malloc(sizeof(char *) * (ptr->piece_height + 3));
//	line = ft_memset(line, '\0', BUFF_SIZE + 1);
	while (i < ptr->piece_height)
	{
		get_next_line(0, &line);
		ptr->piece[i++] = ft_strdup(line);
	}
	ptr->piece[i] = NULL;
}
