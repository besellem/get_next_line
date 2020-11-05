/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: besellem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 22:20:45 by besellem          #+#    #+#             */
/*   Updated: 2020/11/04 22:25:50 by besellem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

/*
** -- INCLUDES --
*/
#include <stdlib.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>

/*
** Check if the BUFFER_SIZE macro exist when compiling, otherwise, create it.
*/
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 4096
# endif

/*
** -- PROTOTYPES --
** List
*/
typedef	struct	s_line
{
	int				read;
	struct s_line	*next;
}				t_line;

/*
** Functions
*/
int				get_next_line(int fd, char **line);

#endif
