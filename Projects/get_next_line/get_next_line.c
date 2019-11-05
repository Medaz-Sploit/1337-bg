/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazoukni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/31 18:44:15 by mazoukni          #+#    #+#             */
/*   Updated: 2019/11/05 21:55:59 by mazoukni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <string.h>
#include "../libft/libft.h"

int	get_next_line(int fd, char **line)
{
	int i = 0;
	int ret = 0; 
	static char *str;
	static int j;

	if (!str)
		str = ft_strdup("");
	char *buff; 
	buff = (char*)malloc(BUFFER_SIZE + 1); 
	ret = read(fd, buff, BUFFER_SIZE - 1);
	while(ret > 0) 
	{	
		buff[ret] = '\0'; 
		str = ft_strjoin(str, buff); 
 		str[strlen(str)] = '\1';
		if (((char)ft_strchr(str, '\n')) == '\n') 
			break ;
	}
	while (str[i] && (str[i] != '\n'))
		i++;
	*line = ft_substr(str, j , i);
	j = i;
	return (1);
} 


int main(void)
{
	int fd;
	char	*line;
	fd = open("txt.txt", O_RDONLY);
	if (fd < 0)
	{
		printf("ERROR\n");
		return  0;
	}
	get_next_line(fd, &line);
	printf("%s", line);
	return (0);
}
