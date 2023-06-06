/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lumedeir < lumedeir@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 15:27:04 by lumedeir          #+#    #+#             */
/*   Updated: 2023/06/05 14:32:53 by lumedeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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
	static char	*fildes;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, NULL, 0))
		return (NULL);
	fildes = ft_read_line(fd, fildes);
	if (!fildes || ft_strlen(fildes) == 0)
		return (NULL);
	line = ft_get_line(fildes);
	fildes = ft_next_line(fildes);
	return (line);
}

// int main(void)
// {
//     int fd;
//     char    *line;

//     fd = open("test.txt", O_RDONLY);
//     while ((line = get_next_line(fd)) != NULL)
//     {
//         printf("%s",line);
//         free(line);
//     }
//     close(fd);
//     return (0);
// }
