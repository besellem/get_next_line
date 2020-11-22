/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: besellem <besellem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 00:17:16 by besellem          #+#    #+#             */
/*   Updated: 2020/11/22 15:20:31 by besellem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
		++i;
	return (i);
}

char	*ft_strdup(const char *s1)
{
	char	*cpy;
	size_t	i;

	if (!(cpy = (char *)malloc(sizeof(char) * (ft_strlen(s1) + 1))))
		return (NULL);
	i = 0;
	while (s1[i])
	{
		cpy[i] = s1[i];
		++i;
	}
	cpy[i] = '\0';
	return (cpy);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	i;

	if (!s)
		return (NULL);
	if (!(str = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	i = 0;
	while (i < len && ft_strlen(s) >= start)
	{
		str[i] = s[start + i];
		++i;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_strchr(const char *s, int c)
{
	int i;

	if (!s)
		return (NULL);
	if (!(char)c)
		return ((char *)(s + ft_strlen(s)));
	i = -1;
	while (s[++i])
		if (s[i] == (char)c)
			return ((char *)(s + i));
	return (NULL);
}
