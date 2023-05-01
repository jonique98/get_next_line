/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josumin <josumin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 21:13:12 by sumjo             #+#    #+#             */
/*   Updated: 2023/05/01 21:50:56 by josumin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stdlib.h>
# include <unistd.h>

typedef struct s_gnl_lst
{
	int					index;
	char				*buff;
	struct s_gnl_lst	*prev;
	struct s_gnl_lst	*next;
}t_gnl_lst;

typedef struct s_dummy_lst
{
	struct s_gnl_lst	*next;
}t_util_lst;

char		*get_next_line(int fd);
int			is_line_or_strlen(char *arr, int num);
char		*ft_strjoin(char *s1, char *s2);
void		*ft_memcpy(void *dst, void *src);
t_gnl_lst	*find_lst(t_gnl_lst *p, int fd);

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10

# endif
#endif