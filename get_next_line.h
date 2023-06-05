/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lumedeir < lumedeir@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 15:11:29 by lumedeir          #+#    #+#             */
/*   Updated: 2023/06/05 13:45:04 by lumedeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

char	*get_next_line(int fd);
char	*ft_strchr(const char *str, int c);
int		ft_strlen(const char *str);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_read_line(int fd, char *str);
char	*ft_get_line(char *str);
char	*ft_next_line(char *str);
void	*ft_memcpy(void *dest, const void *src, size_t n);

#endif