/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: besellem <besellem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 00:14:36 by besellem          #+#    #+#             */
/*   Updated: 2020/11/23 00:07:26 by besellem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_mcat(char *s1, char *s2)
{
	char	*new;
	int		i;
	int		j;

	if (!(new = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1)))
		return (NULL);
	i = -1;
	while (s1[++i])
		new[i] = s1[i];
	j = -1;
	while (s2[++j])
		new[i + j] = s2[j];
	new[i + j] = '\0';
	return (new);
}

static char	*ft_realloc_str(char *str, char **line, int *check)
{
	char			*new;
	unsigned int	i;

	new = NULL;
	if (str)
	{
		i = 0;
		while (str[i] && str[i] != '\n')
			++i;
		*line = ft_substr(str, 0, i);
		if (str && str[i] == '\n')
		{
			new = ft_strdup(str + i + 1);
			*check = 1;
		}
		else if (str)
			new = ft_strdup(str + i);
		free(str);
	}
	return (new);
}

static char	*ft_read_line(int fd, char *str, char **line, int *check)
{
	char	buffer[BUFFER_SIZE + 1];
	char	*tmp;
	int		r;

	while ((r = read(fd, buffer, BUFFER_SIZE)) > 0)
	{
		buffer[r] = '\0';
		if (!str)
			str = ft_strdup(buffer);
		else
		{
			tmp = str;
			str = ft_mcat(str, buffer);
			free(tmp);
		}
		if (ft_strchr(str, '\n'))
			break ;
	}
	return (ft_realloc_str(str, line, check));
}

int			get_next_line(int fd, char **line)
{
	static char	*strs[FD_LIMIT];
	int			check;

	if (read(fd, strs[fd], 0) || fd >= FD_LIMIT || BUFFER_SIZE <= 0 || !line)
		return (-1);
	check = 0;
	if (strs[fd] && ft_strchr(strs[fd], '\n'))
	{
		strs[fd] = ft_realloc_str(strs[fd], line, &check);
		return (check);
	}
	if (!strs[fd])
		strs[fd] = ft_strdup("");
	strs[fd] = ft_read_line(fd, strs[fd], line, &check);
	return (check);
}