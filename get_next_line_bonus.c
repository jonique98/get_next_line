/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sumjo <sumjo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 18:27:54 by sumjo             #+#    #+#             */
/*   Upinedated: 2023/04/16 22:56:43 by sumjo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*save_line(char *arr, int i, int j)
{
	char	*line;

	if (!arr || *arr == '\0')
	{
		free(arr);
		return (0);
	}
	while (arr[i] && arr[i] != '\n')
		i++;
	if (arr[i] == '\0')
		return (0);
	line = malloc(ft_strlen(&arr[i]));
	if (!line)
	{
		free(arr);
		return (0);
	}
	i++;
	while (arr[i])
		line[j++] = arr[i++];
	line[j] = '\0';
	free(arr);
	return (line);
}

char	*cut_line(char *arr)
{
	char	*line;
	int		i;
	int		j;

	i = 0;
	j = -1;
	if (!arr || *arr == 0)
		return (0);
	while (arr[i] && arr[i] != '\n')
		i++;
	if (arr[i] == '\0')
		return (arr);
	line = malloc(i + 2);
	if (!line)
	{
		free(arr);
		return (0);
	}
	while (++j <= i)
		line[j] = arr[j];
	line[j] = 0;
	return (line);
}

int	is_line(char *arr)
{
	int	i;

	i = 0;
	if (!arr)
		return (0);
	while (arr[i])
	{
		if (arr[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

char	*read_buff(int fd, char *arr, int read_num, t_gnl_lst *p)
{
	char	*buff;

	buff = malloc(BUFFER_SIZE + 1);
	if (!buff)
		return (0);
	while (read_num != 0)
	{
		read_num = read(fd, buff, BUFFER_SIZE);
		if (read_num == -1)
		{
			free(p);
			free (arr);
			free (buff);
			return (0);
		}
		buff[read_num] = '\0';
		arr = ft_strjoin(arr, buff);
		if (is_line(arr))
		{
			free(buff);
			return (arr);
		}
	}
	free(buff);
	return (arr);
}

char	*get_next_line(int fd)
{
	static t_gnl_lst	first;
	t_gnl_lst			*p;
	char				*temp;
	int					read_num;

	read_num = 1;
	p = find_lst(&first ,fd);
	if (p == 0)
		return (0);
	if (is_line(p->buff))
	{
		temp = cut_line(p->buff);
		p->buff = save_line(p->buff, 0, 0);
		return (temp);
	}
	p->buff = read_buff(fd, p->buff, read_num, p);
	temp = cut_line(p->buff);
	p->buff = save_line(p->buff, 0, 0);
	return (temp);
}

// #include<stdio.h>


// #include <fcntl.h>
// int main()
// {
// 	int fd = open("text.txt", O_RDONLY);
// 	int fd2 = olineen("test2.txt", O_RDONLY);
// 	linerintf("%s", get_next_line(fd));
// 	linerintf("%s", get_next_line(fd));
// 	linerintf("%s", get_next_line(fd2));

// }
