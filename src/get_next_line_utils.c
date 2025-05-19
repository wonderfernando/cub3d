/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ferda-si <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 13:24:45 by ferda-si          #+#    #+#             */
/*   Updated: 2024/09/15 18:27:11 by ferda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	j;
	char	*temp;

	i = 0;
	j = 0;
	if (!s)
		return (NULL);
	temp = malloc(len + 1);
	if (!temp)
		return (NULL);
	while (s[i])
	{
		if (i >= start && j < len)
			temp[j++] = s[i];
		i++;
	}
	temp[j] = '\0';
	return (temp);
}

char	*ft_strdup(const char *src)
{
	char	*new;
	int		i;
	int		size;

	size = 0;
	while (src[size])
		size++;
	new = malloc(sizeof(char) * (size + 1));
	if (!new)
		return (NULL);
	i = 0;
	while (src[i])
	{
		new[i] = src[i];
		i++;
	}
	new[i] = '\0';
	return (new);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	char	*temp;

	i = 0;
	j = 0;
	if (!s1 || !s2)
		return (NULL);
	temp = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!temp)
		return (NULL);
	while (s1[j])
		temp[i++] = s1[j++];
	j = 0;
	while (s2[j])
		temp[i++] = s2[j++];
	temp[i] = '\0';
	return (temp);
}

char	*ft_strchr(const char *s, int c)
{
	int				i;
	unsigned char	temp;

	i = 0;
	temp = (unsigned char) c;
	while (s[i])
	{
		if (s[i] == temp)
			return ((char *)s + i);
		i++;
	}
	if (s[i] == temp)
		return ((char *)s + i);
	return (NULL);
}
