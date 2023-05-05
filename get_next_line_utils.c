/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sumjo <sumjo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 05:52:46 by sumjo             #+#    #+#             */
/*   Updated: 2023/05/05 21:39:39 by sumjo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(char	*s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
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

char	*free_arr(char **original)
{
	free((*original));
	*original = 0;
	return (0);
}
