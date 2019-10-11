#include <string.h>
#include <stdio.h>
#include <stdlib.h>
int	ft_strlcpy(void *dst, void *src, unsigned int n);
//Sample program to show that memmove() is better than memcpy() 
// when addresses overlap. 
#include <stdio.h> 
#include <string.h> 
int main(void) 
{
	char src[100] = "Geeksfor";
	printf("%s",ft_strlcpy(src, src + 2 , 6));
	return 0; 
} 
