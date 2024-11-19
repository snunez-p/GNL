/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snunez-p <snunez-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 15:10:20 by snunez-p          #+#    #+#             */
/*   Updated: 2024/11/15 15:39:01 by snunez-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s && s[i] != '\0')
		i++;
	return (i);
}

void	*ft_calloc(size_t count, size_t size)
{
	char	*aux;
	size_t	len;

	len = count * size;
	aux = malloc(len);
	if (!aux)
		return (0);
	while (len--)
		aux[len] = 0;
	return (aux);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	int	i;

	i = 0;
	while (dstsize > 1 && src[i] != '\0')
	{
		dst[i] = src[i];
		i++;
		dstsize--;
	}
	if (dstsize > 0)
		dst[i] = '\0';
	return (ft_strlen(src));
}

char	*ft_strdup(const char *s1)
{
	char	*res;
	int		i;

	i = 0;
	res = ft_calloc(sizeof(char), (ft_strlen(s1) + 1));
	if (!res)
		return (0);
	while (*s1 != '\0')
		res[i++] = (char)*s1++;
	return (res);
}

char	*ft_strchr(const char *s, int c)
{
	char	*aux;

	aux = (char *)s;
	while (*aux != '\0')
	{
		if (*aux == (char)c)
			return (aux);
		aux++;
	}
	if (*aux == (char)c)
		return (aux);
	return (0);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*result;
	size_t	n1;
	size_t	n2;

	if (!s1 || !s2)
		return ((void *)0);
	n1 = ft_strlen(s1);
	n2 = ft_strlen(s2);
	result = (char *)malloc((n1 + n2 + 1) * sizeof(char));
	if (!result)
		return (result);
	ft_strlcpy(result, s1, n1 + 1);
	ft_strlcat(result, s2, n1 + n2 + 1);
	return (result);
}
