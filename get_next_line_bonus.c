/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sumjo <sumjo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 21:50:17 by josumin           #+#    #+#             */
/*   Updated: 2023/05/05 22:34:13 by sumjo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*save_line(char **backup, char *arr)
{
	char		*line;
	int			i;
	int			j;

	i = 0;
	j = 0;
	if (!arr || *arr == '\0')
		return (free_lst(0, 0, backup));
	while (*arr && *arr != '\n')
		arr++;
	if (*arr == 0)
		return (free_lst(0, 0, backup));
	line = malloc(ft_strlen(arr));
	if (!line || ft_strlen(arr) == 0)
		return (free_lst(0, 0, backup));
	i++;
	while (arr[i])
		line[j++] = arr[i++];
	line[j] = '\0';
	free_lst(0, 0, backup);
	return (line);
}

char	*cut_line(char **backup, char *arr)
{
	char	*line;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!arr || *arr == 0)
		return (0);
	while (arr[i] && arr[i] != '\n')
		i++;
	if (arr[i] == 0)
		i--;
	line = malloc(i + 2);
	if (!line)
		return (free_lst(0, 0, backup));
	while (j <= i)
	{
		line[j] = arr[j];
		j++;
	}
	line[j] = 0;
	return (line);
}

char	*read_buff(int fd, char **backup, char *arr)
{
	char	*buff;
	int		read_num;

	read_num = 1;
	buff = malloc(BUFFER_SIZE + 1);
	if (!buff)
		return (free_lst(0, 0, backup));
	while (read_num != 0)
	{
		read_num = read(fd, buff, BUFFER_SIZE);
		if (read_num == -1)
		{
			free (buff);
			return (free_lst(0, 0, backup));
		}
		buff[read_num] = '\0';
		arr = ft_strjoin(arr, buff, 0, 0);
		if (is_line(arr))
			break ;
	}
	free(buff);
	return (arr);
}

char	*get_next_line(int fd)
{
	static t_gnl_lst	*first;
	t_gnl_lst			*p;
	char				*line;

	if (fd < 0 || BUFFER_SIZE < 0)
		return (0);
	if (!first)
	{
		first = malloc(sizeof(t_gnl_lst));
		if (!first)
			return (0);
		first->index = -1;
		first->prev = 0;
		first->next = 0;
		first->buff = 0;
	}
	p = find_lst(first, fd);
	if (p == 0)
		return (0);
	p->buff = read_buff(fd, &(p->buff), p->buff);
	line = cut_line(&(p->buff), p->buff);
	p->buff = save_line(&(p->buff), p->buff);
	if (p->buff == 0)
		free_lst(&first, p, &(p->buff));
	return (line);
}

#include<fcntl.h>
#include<stdio.h>

int main()
{
	int fd = open("test.txt",O_RDONLY);
	int fd2 = open("test2.txt",O_RDONLY);
	int fd3 = open("test3.txt",O_RDONLY);
	int fd4 = open("test4.txt",O_RDONLY);
	printf("%s",get_next_line(fd));
	printf("%s",get_next_line(fd2));
	printf("%s",get_next_line(fd));
	printf("%s",get_next_line(fd2));
	printf("%s",get_next_line(fd4));
	printf("%s",get_next_line(fd3));
	printf("%s",get_next_line(fd4));
	printf("%s",get_next_line(fd4));
	printf("%s",get_next_line(fd3));
	printf("%s",get_next_line(fd4));
	printf("%s",get_next_line(fd4));
	printf("%s",get_next_line(fd));
	
}