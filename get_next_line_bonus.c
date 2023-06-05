/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lumedeir < lumedeir@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 13:31:55 by lumedeir          #+#    #+#             */
/*   Updated: 2023/06/05 13:38:00 by lumedeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_read_line(int fd, char *str)
{
	char	*buffer;
	int		bytes;

	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (buffer == NULL)
		return (NULL);
	bytes = 1;
	while ((!str || !ft_strchr(str, '\n')) && bytes != 0)
	{
		bytes = read(fd, buffer, BUFFER_SIZE);
		buffer[bytes] = '\0';
		str = ft_strjoin(str, buffer);
		if (*str == '\0')
		{
			free (str);
			str = NULL;
		}
	}
	free(buffer);
	buffer = NULL;
	return (str);
}

char	*get_next_line(int fd)
{
	static char	*fildes[MAX_FD];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd > MAX_FD || read(fd, NULL, 0))
		return (NULL);
	fildes[fd] = ft_read_line(fd, fildes[fd]);
	if (!fildes[fd] || ft_strlen(fildes[fd]) == 0)
		return (NULL);
	line = ft_get_line(fildes[fd]);
	fildes[fd] = ft_next_line(fildes[fd]);
	return (line);
}
