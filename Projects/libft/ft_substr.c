#include <stdlib.h>
#include "ft_strlcpy.c"
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char *sub;
	
	sub = (char) malloc((ft_strlen(s) - start)*sizeof(char));
	ft_strlcpy(sub, (const char)(s + start), len);
	return (sub);
}
