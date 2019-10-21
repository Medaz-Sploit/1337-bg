#include "libft.h"

int main(void)
{
	char	*str;
	char *pouet = "z";
	char *lolzer = (char *)&pouet[2];
	lolzer = "aaaaaaaaaa";
	str = ft_memchr(pouet, 'a', 50);
	if (!str)
		printf("NULL");
	else
	{
		printf("%s\n", str);
	}
}
