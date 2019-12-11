#include <stdio.h>
#include <fcntl.h>
#include <strings.h>
#include <unistd.h>
#include <stdlib.h>
#include "../libft/libft.h"

int	get_next_line(int fd, char **line)
{
	int i;
	char *buff;
	char	*str;
	static int byte_readed;
	int flag;
	static int j;

	str = (char*)malloc(BUFFER_SIZE + 1);
	i = 0;
	flag = 1;
	buff = (char*)malloc(BUFFER_SIZE + 1);

	while (flag && (byte_readed = read(fd, buff, BUFFER_SIZE)) > 0)
	{
		buff[byte_readed] = '\0';
		str = ft_strjoin(str, buff);
		if (((char)strchr(str, '\n')) == '\n')	
			flag = 0;
	}
	while (str[i] && str[i] != '\n')
		i++;
	*line = ft_substr(str, j, i);
	j = i;
	//printf("%s\n", buff);
	//strncpy(dst, buff, strlen(buff));
	//printf("%s\n", dst);
//	i = strlen((const char*)buff);
//	line = (char**)malloc(i + 1 * sizeof(char));
//	printf("%zu\n", i);
	return (0);
}

int main(void)
{
	int fd;
	char *line;
//	int	returned;

	line = NULL;
	fd = open("kalul", O_RDONLY);
	get_next_line(fd, &line);
	printf("%s\n", line);
	return (0);
}
