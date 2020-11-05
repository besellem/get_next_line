/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: besellem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 21:37:27 by besellem          #+#    #+#             */
/*   Updated: 2020/11/05 01:03:10 by besellem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#include <stdio.h>

size_t	ft_strlen(const char *s)
{
	size_t i;

	i = 0;
	while (s[i])
		++i;
	return (i);
}

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	size_t len;
	size_t i;

	len = ft_strlen(s1);
	i = 0;
	while (s2[i] && i < n)
	{
		s1[len + i] = s2[i];
		++i;
	}
	s1[len + i] = '\0';
	return (s1);
}

int	find_eol(char *buf, int len, int *check)
{
	int i;

	*check = 0;
	if (!buf)
		*check = -1;
	i = 0;
	while (buf[i])
	{
		if (buf[i] == '\n')
		{
			*check = 1;
			break ;
		}
		++i;
	}
	if (i < len && !buf[i])
		*check = -1;
	printf("i => [%d], len => [%d], check => [%+d]\n", i, len, *check);
	return (i);
}

void	add_to_buffer(char **ret, char *str, size_t len)
{
	char	*new;
	size_t	ret_size;

	ret_size = *ret ? ft_strlen(*ret) : 0;
	if (!(new = (char *)malloc(sizeof(char) * (ret_size + len + 1))))
		return ;
	*new = '\0';
	if (*ret)
		ft_strncat(new, *ret, ft_strlen(*ret));
	ft_strncat(new, str, len);
	if (*ret)
		free(*ret);
	*ret = new;
}

int	get_next_line(int fd, char **line)
{
	static int	i = 0;
	char		buf[BUFFER_SIZE];
	int			r;
	int			check;
	int			len;

	read(fd, buf, i);
	printf("\n# STATIC I => [%d], FRST_BUF => [%s]\n\n", i, buf);
	while ((r = read(fd, buf, BUFFER_SIZE)))
	{
		buf[r] = '\0';
		len = find_eol(buf, r, &check);
		printf("i => [%.3d], len => [%d], buf => [%s]\n", i, len, buf);
		add_to_buffer(line, buf, len);
		i += len + 1;
		if (check == -1)
			return (0);
		else if (check == 1)
		{
			printf("# line: [%s]\n", *line);
			return (1);
		}
	}
	return (-1);
}

#include <fcntl.h>
int	main(int ac, char **av)
{
	int		fd;
	char	*ret;

	if (ac != 2)
	{
		dprintf(2, "%s: argument error\n", av[0]);
		return (1);
	}
	if ((fd = open(av[1], O_RDWR)) == -1)
		return (1);
	while (get_next_line(fd, &ret) == 1)
	{
		printf("### ret: [%s]\n", ret);
	}
	close(fd);
	return (0);
}
