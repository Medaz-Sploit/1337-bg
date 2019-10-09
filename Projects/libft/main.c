#include <string.h>
#include <stdio.h>

void	*ft_memset(void *b, int c, size_t len);

int main()
{
	char str[30] = "geeks is for programmers";
	printf("before %s\n", str);
	bzero()
	printf("after memset    %s\n", str);
	ft_memset(str + 2, '.', 5*sizeof(char));
	printf("after ft_memset %s\n", str);	
}
