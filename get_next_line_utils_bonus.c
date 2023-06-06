/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lumedeir < lumedeir@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 13:32:23 by lumedeir          #+#    #+#             */
/*   Updated: 2023/06/05 13:37:35 by lumedeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_strchr(const char *str, int c)
{
	int		count;
	char	*str2;

	count = 0;
	str2 = (char *)str;
	if (str == NULL)
		return (NULL);
	while (str2[count] != '\0')
	{
		if (str2[count] == (char)c)
		{
			return (&str2[count]);
		}
		count++;
	}
	if (str2[count] == c)
		return (&str2[count]);
	return (0);
}

int	ft_strlen(const char *str)
{
	int	count;

	count = 0;
	if (!str)
		return (0);
	while (str[count])
		count++;
	return (count);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*new_str;
	size_t	count;
	size_t	aux;

	if (!s1)
	{
		s1 = (char *)malloc(1 * sizeof(char));
		s1[0] = '\0';
	}
	if (!s1 || !s2)
		return (NULL);
	new_str = malloc(sizeof(char) * ((ft_strlen(s1) + ft_strlen(s2) + 1)));
	if (new_str == NULL)
		return (NULL);
	count = -1;
	aux = 0;
	if (s1)
		while (s1[++count] != '\0')
			new_str[count] = s1[count];
	while (s2[aux] != '\0')
		new_str[count++] = s2[aux++];
	new_str[count] = '\0';
	free(s1);
	return (new_str);
}

char	*ft_get_line(char *str)
{
	int		count;
	int		index;
	char	*line;

	count = -1;
	index = 0;
	if (!str)
		return (NULL);
	while (str[index] && str[index] != '\n')
		index++;
	line = malloc((index + 2) * sizeof(char));
	if (!line)
		return (NULL);
	while (++count <= index)
		line[count] = str[count];
	count--;
	if (line[count] == '\n')
		line[count] = '\n';
	count++;
	line[count] = '\0';
	return (line);
}

char	*ft_next_line(char *str)
{
	int		count;
	int		shift;
	char	*nline;

	shift = 0;
	count = -1;
	while (str[shift] && str[shift] != '\n')
		shift++;
	nline = malloc((ft_strlen(str) - shift + 2) * sizeof(char));
	if (!nline)
		return (NULL);
	while (str[shift])
		nline[++count] = str[++shift];
	nline[++count] = '\0';
	free (str);
	str = NULL;
	return (nline);
}
