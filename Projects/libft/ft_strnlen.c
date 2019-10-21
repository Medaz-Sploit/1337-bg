#include "libft.h"

size_t	ft_strnlen(const char *str, size_t size)
{
	unsigned char	*s;
	size_t i;

	i = 0;	
	s = (unsigned char*)str;
	while(i < size)
	{
		if (!*s)
			break ;
		i++;
		s++;
	}
	return (i);
}
