/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sumjo <sumjo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 05:52:46 by sumjo             #+#    #+#             */
/*   Updated: 2023/04/27 23:07:23 by sumjo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(char	*s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

void	inside(char *arr, char *s1, char *s2)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s1[i])
	{
		arr[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		arr[i] = s2[j];
		i++;
		j++;
	}
	arr[i] = '\0';
}

char	*ft_strjoin(char *s1, char *s2)
{
	char		*arr;

	if (s1 == 0 && s2 == 0)
		return (0);
	else if (s1 == 0)
	{
		arr = malloc(ft_strlen(s2) + 1);
		if (!arr)
		{
			free(s1);
			return (0);
		}
		ft_memcpy(arr, s2);
		return (arr);
	}
	arr = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!arr)
	{
		free(s1);
		return (0);
	}
	inside(arr, s1, s2);
	free(s1);
	return (arr);
}

void	*ft_memcpy(void *dst, void *src)
{
	size_t				i;
	const unsigned char	*s;
	unsigned char		*d;

	d = dst;
	s = src;
	i = 0;
	if (!dst && !src)
		return (0);
	while (s[i])
	{
		d[i] = s[i];
		i++;
	}
	d[i] = '\0';
	return (d);
}

t_gnl_lst	*find_lst(t_gnl_lst *p, int fd)
{
	while (p)
	{
		if (p->index == fd)
			return (p);
		else if (p->next == 0)
		{
			p->next = malloc(sizeof(t_gnl_lst));
			if (!p)
				return (0);
			p->next->prev = p;
			p = p->next;
			p->index = fd;
			p->buff = 0;
			p->next = 0;
			return (p);
		}
		p = p->next;
	}
	return (0);
}
