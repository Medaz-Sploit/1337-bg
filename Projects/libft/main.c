#include <string.h>
#include <stdio.h>
#include <stdlib.h>
int	ft_strlcpy(char *dst, char *src, unsigned int n);
//Sample program to show that memmove() is better than memcpy() 
// when addresses overlap. 
int main(void) 
{
	int ret;
	char src[20] = "Geeksfor";

	ret = ft_strlcpy(src + 3, src, 13);
	printf("%d\n", ret);
	printf("%s\n",src);
	return 0; 
} 
