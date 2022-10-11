/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldias-fe <ldias-fe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 23:45:07 by ldias-fe          #+#    #+#             */
/*   Updated: 2022/10/12 00:33:00 by ldias-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	if (c > 127)
		c %= 256;
	while (s[i] != '\0' && s[i] != c)
		i++;
	if (s[i] == c)
		return ((char *)&s[i]);
	return (0);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*mrg;
	int		size;
	int		i;
	int		j;

	size = ft_strlen((char *)s1) + ft_strlen((char *)s2);
	mrg = malloc((size + 1) * sizeof(char));
	if (!mrg)
		return (NULL);
	i = 0;
	while (s1 && s1[i] != '\0')
	{
		mrg[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j] != '\0')
		mrg[i++] = s2[j++];
	if (s1)
		free ((char *)s1);
	mrg[i] = '\0';
	return (mrg);
}
