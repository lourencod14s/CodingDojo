/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldias-fe <ldias-fe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 23:45:13 by ldias-fe          #+#    #+#             */
/*   Updated: 2022/10/07 01:33:43 by ldias-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
#ifndef BUFFER_SIZE
# define BUFFER_SIZE 14
#endif

char 		*get_next_line(int fd);
ssize_t 	read(int fd, void *buf, size_t count);
char		*ft_strjoin(char const *s1, char const *s2);
char		*ft_strdup(const char *s);
size_t		ft_strlen(const char *str);
char		*ft_strchr(const char *s, int c);
char		*ft_substr(char const *s, unsigned int start, size_t len);

#endif