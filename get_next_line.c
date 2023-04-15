/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sumjo <sumjo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 18:27:54 by sumjo             #+#    #+#             */
/*   Updated: 2023/04/15 22:17:19 by sumjo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*save_line(char *arr, int i, int j)
{
	char	*p;

	if (!arr || *arr == '\0')
	{
		free(arr);
		return (0);
	}
	while (arr[i] && arr[i] != '\n')
		i++;
	if (arr[i] == '\0')
		return (0);
	p = malloc(ft_strlen(&arr[i]));
	if (!p)
	{
		free(arr);
		return (0);
	}
	i++;
	while (arr[i])
		p[j++] = arr[i++];
	p[j] = '\0';
	free(arr);
	return (p);
}

static char	*cut_line(char *arr)
{
	char	*p;
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
	p = malloc(i + 2);
	if (!p)
	{
		free(arr);
		return (0);
	}
	while (++j <= i)
		p[j] = arr[j];
	p[j] = 0;
	return (p);
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
	static char		*arr;
	char			*temp;
	int				read_num;

	read_num = 1;
	if (fd < 0 || BUFFER_SIZE < 0)
		return (0);
	if (is_line(arr))
	{
		temp = cut_line(arr);
		arr = save_line(arr, 0, 0);
		return (temp);
	}
	arr = read_buff(fd, arr, read_num);
	temp = cut_line(arr);
	arr = save_line(arr, 0, 0);
	return (temp);
}

// int main()
// {
// 	int fd = open("test.txt", O_RDONLY);
// 	printf("%s", get_next_line(fd));
// 	printf("%s", get_next_line(fd));
// // 	// get_next_line(fd);
// // 	// get_next_line(fd);
// // 	// get_next_line(fd);

//  	system("leaks a.out");
// }