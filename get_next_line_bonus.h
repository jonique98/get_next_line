/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sumjo <sumjo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 21:13:12 by sumjo             #+#    #+#             */
/*   Updated: 2023/04/16 22:45:52 by sumjo            ###   ########.fr       */
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
	struct s_gnl_lst	*next;
}t_gnl_lst;

char		*get_next_line(int fd);
size_t		ft_strlen(char *s);
char		*ft_strjoin(char *s1, char *s2);
void		*ft_memcpy(void *dst, void *src);
t_gnl_lst	*find_lst(t_gnl_lst *p, int fd);

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10

# endif
#endif