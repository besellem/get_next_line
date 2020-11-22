/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: besellem <besellem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 00:14:58 by besellem          #+#    #+#             */
/*   Updated: 2020/11/22 19:03:22 by besellem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

/*
** -- Includes --
*/
# include <unistd.h>
# include <stdlib.h>

/*
** -- Defines --
** Limit on how many fds may be opened at the same time
*/
# ifndef FD_LIMIT
#  define FD_LIMIT 256
# endif

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 4096
# endif

/*
** -- Prototypes --
** Utils
*/
size_t	ft_strlen(const char *s);
char	*ft_strdup(const char *s1);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strchr(const char *s, int c);

/*
** get_next_line
*/
int		get_next_line(int fd, char **line);

#endif
