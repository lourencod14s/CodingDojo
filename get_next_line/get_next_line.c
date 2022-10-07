/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldias-fe <ldias-fe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 23:42:22 by ldias-fe          #+#    #+#             */
/*   Updated: 2022/10/07 01:37:59 by ldias-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "get_next_line.h"

char *get_next_line(int fd)
{
	static char	*storage;
	char		*buff;
	char		*tmp;
	char		*line;
	int			i;
	int 		j;
	
	buff = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buff)
		return (0);
	i = read(fd, buff, BUFFER_SIZE);
	if (i == -1)
		{
			free(buff);
			return (NULL);
		}
	line = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	while (i > 0)
	{
		buff[i] = '\0';
		if (!storage)
			storage = ft_strdup(buff);
		else
		{
			tmp = ft_strjoin(storage, buff);
			free (storage);
			storage = tmp;
		}
		if (ft_strchr(storage, '\n'))
		{
			j = 0;
			while (storage[j] != '\n')
				j++;
			line = ft_substr(storage, 0, j + 1);
			storage = ft_strdup(ft_strchr(storage, '\n') + 1);
			free(tmp);
			break ;
		}
		i = read(fd, buff, BUFFER_SIZE);
	}
	return (line);
}

int	main(void)
{
	int		fd;
	char	*s;
	int		i;

	i = 0;
	fd = open("file.txt", O_RDONLY);
	while(i < 7)
	{
		s = get_next_line(fd);
		printf("%s", s);
		free(s);
		i++;
	}
}

// valgrind --leak-check=full --show-leak-kinds=all gcc -g