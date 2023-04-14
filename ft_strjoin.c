/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sumjo <sumjo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 12:31:06 by sumjo             #+#    #+#             */
/*   Updated: 2023/04/14 21:01:51 by sumjo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "get_next_line.h"
#include <stdio.h>

static void	inside(char *arr, char const *s1, char const *s2)
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

char	*ft_strjoin(char const *s1, char const *s2)
{
	char		*arr;
	size_t		len;

	if (s1 == 0 && s2 == 0)
	{
		arr = malloc(1);
		*arr = 0;
		return (arr);
	}
	else if (s1 == 0)
	{
		arr = malloc(ft_strlen(s2) + 1);
		ft_memcpy(arr, s2, ft_strlen(s2));
		return (arr);
	}
	len = ft_strlen(s1) + ft_strlen(s2);
	arr = malloc(len + 1);
	if (!(arr))
		return (0);
	inside(arr, s1, s2);
	// free(s1);
	// free(s2);
	return (arr);
}
