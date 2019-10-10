#include <string.h>
#include <stdio.h>

void	*ft_memmove(void *dst, void *src, int n);

int main() 
{ 
	char csrc[100] = "Geeksfor"; 
	ft_memmove(csrc+5, csrc, strlen(csrc)+1); 
	printf("%s", csrc); 
	return 0; 
} 
