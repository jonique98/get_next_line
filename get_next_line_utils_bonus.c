/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josumin <josumin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 21:50:13 by josumin           #+#    #+#             */
/*   Updated: 2023/05/01 22:10:44 by josumin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"get_next_line_bonus.h"

int	is_line_or_strlen(char *arr, int num)
{
	int	i;

	i = 0;
	if (num == 1)
	{
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
	else if (num == 2)
	{
		while (arr[i])
			i++;
		return (i);
	}
	return (0);
}

void	inside(char *arr, char *s1, char *s2)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s1 && s1[i])
	{
		arr[i] = s1[i];
		i++;
	}
	while (s2 && s2[j])
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
		arr = malloc(is_line_or_strlen(s2, 2) + 1);
		if (!arr)
		{
			free(s1);
			return (0);
		}
		ft_memcpy(arr, s2);
		return (arr);
	}
	arr = malloc(is_line_or_strlen(s1, 2) + is_line_or_strlen(s2, 2) + 1);
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
	if (p->index == -1)
	{
		p->index = fd;
		p->prev = 0;
		p->next = 0;
		p->buff = 0;
		return (p);
	}
	while (1)
	{
		if (p->index == fd)
			return (p);
		else if (p->next == 0)
		{
			p->next = malloc(sizeof(t_gnl_lst));
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
