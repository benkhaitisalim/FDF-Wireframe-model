/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsalim <bsalim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 15:34:36 by bsalim            #+#    #+#             */
/*   Updated: 2025/03/10 02:59:17 by bsalim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*get_line_from_buffer(int fd, char *left_c, char *buffer);
static char	*set_line(char *line_buffer);
static char	*ft_strrchr(const char *s, int c);

char	*get_next_line(int fd)
{
	static char	*left_c = NULL;
	char		*line;
	char		*buffer;

	if ((fd < 0 || BUFFER_SIZE <= 0) || read(fd, 0, 0) < 0)
	{
		free(left_c);
		left_c = NULL;
		return (NULL);
	}
	buffer = ft_calloc((BUFFER_SIZE + 1), sizeof(char));
	if (!buffer)
		return (NULL);
	line = get_line_from_buffer(fd, left_c, buffer);
	left_c = set_line(line);
	free(buffer);
	buffer = NULL;
	if (!line)
		return (NULL);
	return (line);
}

static char	*ft_strrchr(const char *s, int c)
{
	char	*str;
	int		i;
	char	charachter;

	if(!s)
		return NULL;;
	str = (char *)s;
	charachter = (char)c;
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == charachter)
		{
			return (&str[i]);
		}
		i++;
	}
	if (charachter == '\0')
		return (&str[i]);
	return (NULL);
}

static char	*get_line_from_buffer(int fd, char *left_c, char *buffer)
{
	ssize_t	b_read;
	char	*temporary;

	b_read = 1;
	if (!buffer)
		return (NULL);
	while (b_read > 0) 
	{
		b_read = read(fd, buffer, BUFFER_SIZE);
		if (b_read == -1)
			return (left_c);
		else if (b_read == 0 && !left_c)
			break ;
		buffer[b_read] = '\0';
		if (!left_c)
			left_c = ft_strdup("");
		temporary = left_c;
		left_c = ft_strjoin(temporary, buffer);
		free(temporary);
		temporary = NULL;
		if (ft_strrchr(buffer, '\n'))
			break ;
	}
	return (left_c);
}

static char	*set_line(char *line_buffer)
{
	char	*line;
	int		index;

	index = 0;
	if (line_buffer)
	{
		while (line_buffer[index] != '\n' && line_buffer[index] != '\0')
			index++;
		if (line_buffer[index] == '\0')
			return (NULL);
		line = ft_strdup((line_buffer) + (index + 1));
		if (!line)
			return (NULL);	
		if (*line == '\0')
		{
			free(line);
			line = NULL;
		}
		line_buffer[index] = '\n';
		line_buffer[index + 1] = '\0';
		return (line);
	}
	return (NULL);
}
// int main(void)
// {
//     int fd = open("test.txt", O_RDONLY);
//     if (! fd)
//         return (1);
//     printf("%s", get_next_line(fd));
//         printf("%s", get_next_line(fd));
//         printf("%s", get_next_line(fd));
//         printf("%s", get_next_line(fd));
//     return 0;
// }