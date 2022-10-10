/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldias-fe <ldias-fe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 05:16:16 by ldias-fe          #+#    #+#             */
/*   Updated: 2022/10/10 22:22:21 by ldias-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

//se retornar null da free no storage!!! se
//ele for diferente de 0;
char	*read_fd(int fd, char *storage)
{
	int		i;
	char	*buf;

	buf = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buf)
		return (NULL);
	i = 1;
	while (i != 0)
	{
		i = read(fd, buf, BUFFER_SIZE);
		if (i == -1)
		{
			free(buf);
			return (NULL);
		}
		buf[i] = '\0';
		storage = ft_strjoin(storage, buf);
		if (ft_strchr(buf, '\n') && storage)
			break ;
	}
	free(buf);
	return (storage);
}

char	*prepare_line(char *storage)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	while (storage[i] && storage[i] != '\n')
		i++;
	if (!storage[i])
	{
		free(storage);
		return (NULL);
	}
	str = malloc(sizeof(char) * (ft_strlen(storage) - i + 1));
	if (!str)
		return (NULL);
	i++;
	j = 0;
	while (storage[i])
		str[j++] = storage[i++];
	str[j] = '\0';
	free(storage);
	return (str);
}

char	*get_line(char *storage)
{
	int		i;
	char	*str;

	i = 0;
	if (!storage[i])
		return (NULL);
	while (storage[i] && storage[i] != '\n')
		i++;
	str = malloc(sizeof(char) * (i + 2));
	if (!str)
		return (NULL);
	i = 0;
	while (storage[i] && storage[i] != '\n')
	{
		str[i] = storage[i];
		i++;
	}
	if (storage[i] && storage[i] == '\n')
	{
		str[i] = storage[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*storage;

	if (fd < 0 && BUFFER_SIZE < 1)
		return (NULL);
	storage = read_fd(fd, storage);
	if (!storage)
		return (NULL);
	line = get_line(storage);
	storage = prepare_line(storage);
	return (line);
}

int	main(void)
{
	int		fd;
	char	*s;
	int		i;

	i = 0;
	fd = open("file.txt", O_RDONLY);
	while(1)
	{
		s = get_next_line(fd);
		if (s)
		{
			printf("%s",s);
			free(s);
		}
		else
			break;
	}
	close(fd);
}
/* Este main() possui argumentos para testar na execução*/
/*int	main(int argc, char **argv)
{
	int	fd;
	char	*line;

	(void)argc;
	fd = open(argv[1], O_RDONLY);
	while (line != NULL)
	{
		line = get_next_line(fd);
		printf("%s", line);
	}
	fd = close(fd);
	return (0);
}*/