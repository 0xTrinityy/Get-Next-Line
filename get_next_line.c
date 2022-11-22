/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbelleng <tbelleng@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 11:57:00 by tbelleng          #+#    #+#             */
/*   Updated: 2022/11/22 10:51:10 by tbelleng         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "get_next_line.h"

char	*getting_file(char *buff, int fd)
{
	char	*readed;
	int		n;

	readed = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!readed)
		return (NULL);
	n = 1;
	while (n > 0)
	{
		n = read(fd, readed, BUFFER_SIZE);
		readed[n] = 0;
		buff = ft_strjoin(buff, readed)
	}
	free(readed);
	return(buff);
}

char	*getting_line(char *buff)
{
	char	*str;
	int		i;

	i = 0;
	if (buff[i] == 0)
			return (NULL);
	while (buff[i] && buff[i] != '\n')
		i++;
	if (buff[i] == '\n')
		i++;
	str = malloc(sizeof(char) * (i + 1);
	if (!str)
		return (NULL);
	str[i + 1] = 0;
	while (i > 0)
	{
		str[i] = buff[i];
		i--;
	}
	return str;
}

char	*trimmed_buff(char *buff)
{
	char	*next_buff;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!buff)
		return (NULL);
	while (buff[i] && buff[i] != '\n')
		i++;
	if (buff[i] == '\n')
		i++;
	next_buff = malloc(sizeof(char) * (ft_strlen(buff) - i + 1));
	if (!next_buff)
		return (NULL);
	while (buff[i] != '\0')
	{
		next_buff[j] = buff[i];
		i++;
		j++;
	}
	next_buff[j] = 0;
	return (next_buff);
}

char	*get_next_line(int fd)
{
	static char	buff[BUFFER_SIZE + 1]
	char	*str;

	if (fd <= 0 || BUFFER_SIZE == 0)
		return (NULL);
	buff = getting_file(buff, fd);
	str = getting_line(buff);
	buff = trimmed_buff(buff;)
	return (str);
}

int		main()
{
	int	fp;

	fp = open("hello", O_RDONLY);
	printf("%s\n", get_next_line(fp));
	printf("%s\n", get_next_line(fp));
	printf("%s\n", get_next_line(fp));
	printf("%s\n", get_next_line(fp));
	close(fp);
}