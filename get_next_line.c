/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sumjo <sumjo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 18:27:54 by sumjo             #+#    #+#             */
/*   Updated: 2023/05/02 22:35:26 by sumjo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*save_line(char *arr, int i, int j)
{
	char		*line;

	if (!arr)
		return (0);
	else if (*arr == '\0')
	{
		free(arr);
		return (0);
	}
	while (arr[i] && arr[i] != '\n')
		i++;
	if (arr[i] == '\0')
	{	
		free(arr);
		return (0);
	}
	line = malloc(ft_strlen(&arr[i]));
	if (!line)
		return (0);
	i++;
	while (arr[i])
		line[j++] = arr[i++];
	line[j] = '\0';
	free(arr);
	return (line);
}

char	*cut_line(char *arr, char *brr)
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
	if (arr[i] == 0)
		i--;
	line = malloc(i + 2);
	if (!line)
	{
		free(brr);
		return (0);
	}
	while (++j <= i)
		line[j] = arr[j];
	line[j] = 0;
	return (line);
}

static int	is_line(char *arr)
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
			free (arr);
			free (buff);
			return (0);
		}
		buff[read_num] = '\0';
		arr = ft_strjoin(arr, buff);
		if (is_line(arr))
			break ;
	}
	free(buff);
	return (arr);
}

char	*get_next_line(int fd)
{
	static char		*arr;
	char			*temp;
	int				read_num;

	read_num = 1;
	temp = 0;
	if (fd < 0 || BUFFER_SIZE < 0)
		return (0);
	arr = read_buff(fd, arr, read_num);
	if (!arr)
		return (0);
	temp = cut_line(arr, temp);
	arr = save_line(arr, 0, 0);
	return (temp);
}

// #include<stdio.h>
// #include <fcntl.h>
// #include<time.h>
// int main()
// {
// 	clock_t start = clock();	
// 	int fd1 = open("test.txt", O_RDONLY);
// 	int fd2 = open("test2.txt", O_RDONLY);
// 	// int fd3 = open("test3.txt", O_RDONLY);
// 	printf("%s", get_next_line(fd1));
// 	printf("%s", get_next_line(fd1));
// 	printf("%s", get_next_line(fd1));
// 	printf("%s", get_next_line(fd1));
// 	printf("%s", get_next_line(fd1));
// 	printf("%s", get_next_line(fd1));
// 	printf("%s", get_next_line(fd1));
// 	printf("%s", get_next_line(fd1));
// 	printf("%s", get_next_line(fd1));
// 	printf("%s", get_next_line(fd1));
// 	printf("%s", get_next_line(fd2));
// 	clock_t end = clock();
// 	printf("소요시간 %lf\n", (double)(end - start) / CLOCKS_PER_SEC);
// }