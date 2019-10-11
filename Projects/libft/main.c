#include <string.h>
#include <stdio.h>
#include <stdlib.h>
int	ft_strlcpy(char *dst, char *src, unsigned int n);
//Sample program to show that memmove() is better than memcpy() 
// when addresses overlap. 
#include <stdio.h> 
#include <string.h> 
int main(void) 
{
	char src[100] = "Geeksfor";
	//ret = strlcpy(src, src + 2 , 3);
	printf("%lu\n",strlcpy(src, src +2 , 3));
	printf("%s\n",src);
	return 0; 
} 
