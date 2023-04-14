/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sumjo <sumjo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 18:27:54 by sumjo             #+#    #+#             */
/*   Updated: 2023/04/14 22:33:17 by sumjo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

#define BUFF_SIZE 10

char *cut_line(char **brr, char *arr, int index)
{
	char *p;
	int i;
	int j;

	i = 0;
	j = 0;
	while (arr[i])
	{
		if (arr[i] == '\n')
			break;
		i++;
	}
	p = malloc(i + 1);
	while (j < i)
	{
		p[j] = arr[j];
		j++;
	}
	p[j] = '\0';
	*brr = (arr + index + 1);
	return (p);
}

static int	is_line(char *arr)
{
	int	i;

	i = 0;
	while (arr[i] && arr[i] != '\0')
	{
		if (arr[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

char	*get_next_line(int fd)
{
	char			buff[BUFF_SIZE + 1];
	static char 	*arr;
	int				read_num;
	static int		cnt;

	if (cnt > 0)
	{
		if (is_line(arr) != -1)
			return (cut_line(&arr, arr, is_line(arr)));
	}
	while ((read_num = read(fd, buff, BUFF_SIZE)) > 0)
	{
		cnt++;
		arr = ft_strjoin(arr, buff);
		if (is_line(arr) != -1)
			return (cut_line(&arr, arr, is_line(arr)));
	}
	return 0;
}



int main()
{
	int fd = open("test.txt", O_RDONLY);
	// printf("%s 첫번째출력 \n", get_next_line(fd));
	// printf("%s 두번쨰출력 \n", get_next_line(fd));
	printf("%s\n", get_next_line(fd));
	printf("%s\n", get_next_line(fd));
	printf("%s\n", get_next_line(fd));
	// get_next_line(fd);
	// get_next_line(fd);
}
