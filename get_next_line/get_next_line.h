/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsalim <bsalim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 15:20:22 by bsalim            #+#    #+#             */
/*   Updated: 2024/12/14 06:16:28 by bsalim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>

char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strdup(const char *string);
char	*get_next_line(int fd);
void	*ft_calloc(size_t count, size_t size);
size_t	ft_strlen(const char *str);

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

#endif