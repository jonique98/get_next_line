/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sumjo <sumjo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 18:27:54 by sumjo             #+#    #+#             */
/*   Updated: 2023/05/05 22:28:35 by sumjo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdio.h>
#include "get_next_line.h"

char	*save_line(char **backup, char *arr, int i, int j)
{
	char		*line;

	if (!arr || *arr == '\0')
		return (free_arr(backup));
	while (*arr && *arr != '\n')
		arr++;
	if (*arr == 0)
		return (free_arr(backup));
	line = malloc(ft_strlen(arr));
	if (!line || ft_strlen(arr) == 0)
		return (free_arr(backup));
	i++;
	while (arr[i])
		line[j++] = arr[i++];
	line[j] = '\0';
	free_arr(backup);
	return (line);
}

char	*cut_line(char **backup, char *arr, char *brr)
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
	{
		free(brr);
		return (free_arr(backup));
	}
	while (j <= i)
	{
		line[j] = arr[j];
		j++;
	}
	line[j] = 0;
	return (line);
}

char	*read_buff(int fd, char **backup, char *arr, int read_num)
{
	char	*buff;

	buff = malloc(BUFFER_SIZE + 1);
	if (!buff) {
		printf("here");
		return (free_arr(backup));
	}
	while (read_num != 0)
	{
		read_num = read(fd, buff, BUFFER_SIZE);
		if (read_num == -1)
		{
		printf("here1");
			free (buff);
			return (free_arr(backup));
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
	static char		*arr;
	char			*temp;
	int				read_num;

	read_num = 1;
	temp = 0;
	if (fd < 0 || BUFFER_SIZE < 0)
		return (0);
	arr = read_buff(fd, &arr, arr, read_num);
	if (!arr)
		return (0);
	temp = cut_line(&arr, arr, temp);
	arr = save_line(&arr, arr, 0, 0);
	return (temp);
}

#include<fcntl.h>

int main()
{
	// int fd = open("test.txt",O_RDONLY);
	printf("%s",get_next_line(1));
	// printf("%s",get_next_line(1));
	// printf("%s",get_next_line(fd));
	// printf("%s",get_next_line(fd));
	// printf("%s",get_next_line(fd));
	// printf("%s",get_next_line(fd));
	// printf("%s",get_next_line(fd));
	// printf("%s",get_next_line(fd));
	// printf("%s",get_next_line(fd));
}

