/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sumjo <sumjo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 18:27:54 by sumjo             #+#    #+#             */
/*   Updated: 2023/04/28 00:21:44 by sumjo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

// size_t	ft_strlen(char	*s)
// {
// 	int	i;

// 	i = 0;
// 	while (s[i])
// 		i++;
// 	return (i);
// }

// void	inside(char *arr, char *s1, char *s2)
// {
// 	int	i;
// 	int	j;

// 	i = 0;
// 	j = 0;
// 	while (s1[i])
// 	{
// 		arr[i] = s1[i];
// 		i++;
// 	}
// 	while (s2[j])
// 	{
// 		arr[i] = s2[j];
// 		i++;
// 		j++;
// 	}
// 	arr[i] = '\0';
// }

// char	*ft_strjoin(char *s1, char *s2)
// {
// 	char		*arr;

// 	if (s1 == 0 && s2 == 0)
// 		return (0);
// 	else if (s1 == 0)
// 	{
// 		arr = malloc(ft_strlen(s2) + 1);
// 		if (!arr)
// 		{
// 			free(s1);
// 			return (0);
// 		}
// 		ft_memcpy(arr, s2);
// 		return (arr);
// 	}
// 	arr = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
// 	if (!arr)
// 	{
// 		free(s1);
// 		return (0);
// 	}
// 	inside(arr, s1, s2);
// 	free(s1);
// 	return (arr);
// }

// void	*ft_memcpy(void *dst, void *src)
// {
// 	size_t				i;
// 	const unsigned char	*s;
// 	unsigned char		*d;

// 	d = dst;
// 	s = src;
// 	i = 0;
// 	if (!dst && !src)
// 		return (0);
// 	while (s[i])
// 	{
// 		d[i] = s[i];
// 		i++;
// 	}
// 	d[i] = '\0';
// 	return (d);
// }

// t_gnl_lst	*find_lst(t_gnl_lst **first, int fd)
// {
// 	t_gnl_lst *p;

// 	p = *first;
// 	while (p)
// 	{
// 		if (p->index == fd)
// 			return (p);
// 		else if (p->next == 0)
// 		{
// 			p->next = malloc(sizeof(t_gnl_lst));
// 			if (!p)
// 				return (0);
// 			p->next->prev = p;
// 			p = p->next;
// 			p->index = fd;
// 			p->buff = 0;
// 			p->next = 0;
// 			return (p);
// 		}
// 		p = p->next;		
// 	}
// 	return (0);
// }

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
	static t_gnl_lst	*first;
	t_gnl_lst			*p;
	char				*line;
	int					read_num;

	read_num = 1;
	if (fd < 0 || fd > 1048575)
		return (0);
	if (!first)
	{
		first = malloc(sizeof(t_gnl_lst));
		first->index = fd;
		first->buff = 0;
		first->prev = 0;
		first->next = 0;
	}	
	p = find_lst(first, fd);
	if (p == 0)
		return (0);
	p->buff = read_buff(fd, p->buff, read_num);
	line = cut_line(p->buff);
	p->buff = save_line(p->buff, 0, 0);
	if (p->buff == 0)
	{
		if (p->prev)
		{
			p->prev->next = p->next;
			p->next->prev = p->prev;
		}
		else
			first = p->next;
		free(p);
	}
	return (line);
}

// #include<stdio.h>
// #include <fcntl.h>
// int main()
// {
// 	int fd = open("test.txt", O_RDONLY);
// 	// int fd2 = open("test2.txt", O_RDONLY);
// 	// int fd3 = open("test3.txt", O_RDONLY);
// 	printf("%s", get_next_line(fd));
// 	printf("%s", get_next_line(fd));
// 	printf("%s", get_next_line(fd));
// 	printf("%s", get_next_line(fd));
// 	printf("%s", get_next_line(fd));
// 	printf("%s", get_next_line(fd));
	
// system("leaks a.out");
// }
