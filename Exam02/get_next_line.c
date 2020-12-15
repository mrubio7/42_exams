/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrubio <mrubio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/15 16:23:47 by mrubio            #+#    #+#             */
/*   Updated: 2020/12/15 16:51:56 by mrubio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./get_next_line.h"

/*#include <stdio.h>


int		main(void)
{
	char *line;
	int n;

	while ((n = get_next_line(&line)) > 0)
	{
		printf("%s\n", line);
		free(line);
		line = NULL;
	}
	printf("%s\n", line);
	free(line);
	line = NULL;
}
*/

char	*ft_freemem(char *fri, char *ret)
{
	if (fri)
		free(fri);
	return (ret);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*str;
	int		x;
	int		z;

	x = 0;
	while (s1[x])
		x++;
	str = (char *)malloc(x + 2);
	x = 0;
	z = 0;
	while (s1[x])
		str[z++] = s1[x++];
	str[z++] = s2[0];
	str[z] = '\0';
	return (str);
}

int		get_next_line(char **line)
{
	char	*temp;
	char	*buff;
	int		nbytes;

	if (!(buff = (char *)malloc(sizeof(char)* 2)) || !(*line = (char *)malloc(sizeof(char)* 1)))
		return (-1);
	(*line)[0] = '\0';
	while ((nbytes = read(0, buff, 1)) > 0)
	{
		buff[nbytes] = '\0';
		if (buff[0] == '\n' || buff[0] == '\0')
			break ;
		temp = ft_strjoin(*line, buff);
		*line = ft_freemem(*line, temp);
	}
	buff = ft_freemem(buff, NULL);
	return (nbytes);
}
