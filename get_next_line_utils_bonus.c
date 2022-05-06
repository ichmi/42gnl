/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frosa-ma <frosa-ma@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 14:49:34 by frosa-ma          #+#    #+#             */
/*   Updated: 2022/05/06 17:48:30 by frosa-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
		i++;
	return (i);
}

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*p;

	p = s;
	while (n--)
		*p++ = (unsigned char)c;
	return (s);
}

char	*ft_strchr(const char *s, int c)
{
	if (!s)
		return (NULL);
	while (*s)
	{
		if ((unsigned char)*s == (unsigned char)c)
			return ((char *)s);
		s++;
	}
	if ((unsigned char)c == '\0')
		return ((char *)s);
	return (NULL);
}

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*pd;
	unsigned char	*ps;

	pd = dest;
	ps = (unsigned char *)src;
	while (n--)
		*pd++ = *ps++;
	return (dest);
}

char	*ft_strdup(const char *s)
{
	char	*buff;
	char	*pb;

	buff = (char *)malloc((ft_strlen(s) + 1) * sizeof(char));
	if (!buff)
		return (NULL);
	pb = buff;
	while (*s)
		*buff++ = *(char *)s++;
	*buff = '\0';
	return (pb);
}
