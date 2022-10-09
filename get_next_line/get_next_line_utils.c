/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldias-fe <ldias-fe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 23:45:07 by ldias-fe          #+#    #+#             */
/*   Updated: 2022/10/09 22:50:21 by ldias-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "get_next_line.h"

/*void	ft_free(char **str)
{
	if (str != NULL && *str != '\0')
	{
		free(*str);
		str = NULL;
	}
}*/

size_t	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	if(!str)
		return 0;
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
	mrg = (char *) malloc((size + 1) * sizeof(char));//(char*)
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
	//if(s1)
	//	free((char*)s1);
	mrg[i] = '\0';
	return (mrg);
}

static char	*ft_bug(void)
{
	char	*bug;

	bug = (char *) malloc(sizeof(char));
	bug[0] = 0;
	return (bug);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*sub;
	unsigned int	i;
	size_t			j;
	size_t			buf;

	buf = ft_strlen(s);
	if (start > buf)
		return (ft_bug());
	if (len >= buf)
		len = buf - start;
	sub = (char *) malloc((len + 1) * sizeof(char));
	if (!sub || !s)
		return (0);
	i = 0;
	while (s[i] != '\0' && i < start)
		i++;
	j = 0;
	while (s[i] != '\0' && j < len)
	{
		sub[j] = (char)s[i];
		i++;
		j++;
	}
	sub[j] = '\0';
	return (sub);
}