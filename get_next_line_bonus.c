/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josumin <josumin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 21:50:17 by josumin           #+#    #+#             */
/*   Updated: 2023/05/01 22:03:58 by josumin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*save_line(char *arr, int i, int j)
{
	char		*line;

	if (!arr || *arr == '\0')
	{
		free(arr);
		return (0);
	}
	while (arr[i] && arr[i] != '\n')
		i++;
	if (arr[i] == '\0')
		return (0);
	line = malloc(is_line_or_strlen(&arr[i], 2));
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

void	free_lst(t_gnl_lst **first, t_gnl_lst *p)
{
	if (!(p->prev))
	{
		*first = p->next;
		if (p->next)
			p->next->prev = 0;
	}
	else
	{
		p->prev->next = p->next;
		if (p->next)
			p->next->prev = p->prev;
	}
	free(p);
}

char	*read_buff(int fd, char *arr, int read_num)
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
			free(arr);
			free (buff);
			return (0);
		}
		buff[read_num] = '\0';
		arr = ft_strjoin(arr, buff);
		if (is_line_or_strlen(arr, 1))
			break;
	}
	free(buff);
	return (arr);
}

char	*get_next_line(int fd)
{
	static t_gnl_lst	*first;
	t_gnl_lst			*p;
	char				*line;
	int					read_num;

	read_num = 1;
	if (fd < 0)
		return (0);
	if (!first)
	{
		first = malloc(sizeof(t_gnl_lst));
		first->index = -1;
	}
	p = find_lst(first, fd);
	if (p == 0)
		return (0);
	p->buff = read_buff(fd, p->buff, read_num);
	line = cut_line(p->buff);
	p->buff = save_line(p->buff, 0, 0);
	if (p->buff == 0)
		free_lst(&first, p);
	return (line);
}

// #include<stdio.h>
// #include <fcntl.h>
// int main()
// {
// 	int fd1 = open("test.txt", O_RDONLY);
// 	int fd2 = open("test2.txt", O_RDONLY);
// 	// int fd3 = open("test3.txt", O_RDONLY);
// 	printf("%s", get_next_line(fd1));
// 	printf("%s", get_next_line(fd1));
// 	printf("%s", get_next_line(fd1));
// 	printf("%s", get_next_line(fd1));
// 	printf("%s", get_next_line(fd1));
// 	printf("%s", get_next_line(fd1));
// 	printf("%s", get_next_line(fd2));
// }