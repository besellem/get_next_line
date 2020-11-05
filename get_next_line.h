/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: besellem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 21:37:46 by besellem          #+#    #+#             */
/*   Updated: 2020/11/04 22:33:59 by besellem         ###   ########.fr       */
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
** -- PROTOTYPES --
** List
*/
typedef	struct	s_buffer
{
	char			*buf;
	struct s_line	*next;
}				t_buffer;

/*
** Functions
*/
int				get_next_line(int fd, char **line);

#endif
