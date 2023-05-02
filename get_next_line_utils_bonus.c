/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sumjo <sumjo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 21:50:13 by josumin           #+#    #+#             */
/*   Updated: 2023/05/02 20:46:25 by sumjo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"get_next_line_bonus.h"

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

int	ft_strlen(char *arr)
{
	int	i;

	i = 0;
	if (!arr)
		return (0);
	while (arr[i])
		i++;
	return (i);
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

char	*ft_strjoin(char *s1, char *s2, int i, int j)
{
	char		*arr;

	if (s1 == 0 && s2 == 0)
		return (0);
	arr = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!arr)
	{
		free(s1);
		return (0);
	}
	if (!s1)
	{
		arr = ft_memcpy(arr, s2);
		return (arr);
	}
	while (s1 != 0 && s1[i])
	{
		arr[i] = s1[i];
		i++;
	}
	while (s2 != 0 && s2[j])
		arr[i++] = s2[j++];
	arr[i] = '\0';
	free(s1);
	return (arr);
}

t_gnl_lst	*find_lst(t_gnl_lst *p, int fd)
{
	if (p->index == -1)
	{
		p->index = fd;
		p->prev = 0;
		p->buff = 0;
		p->next = 0;
		return (p);
	}
	while (p)
	{
		if (p->index == fd)
			return (p);
		else if (p->next == 0)
		{
			p->next = malloc(sizeof(t_gnl_lst));
			if(!p)
				return (0);
			p->next->prev = p;
			p->next->index = fd;
			p->next->next = 0;
			p->next->buff = 0;
			return (p->next);
		}
		p = p->next;
	}
	return (0);
}
