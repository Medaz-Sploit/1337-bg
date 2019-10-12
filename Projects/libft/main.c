#include <string.h>
#include <stdio.h> 
char    *ft_strnstr(const char *str, const char *to_find, size_t len)
{
	int i;

	if (*to_find == '\0')
		return (str);
	while (len > 0)
	{
		i = 0;
		while (*(str + i) == *(to_find + i))
		{
			if (*(to_find + i) == '\0')
				return (str);
			i++;
		}
		str++;
		len--;
	}
	return (str);
}

int main() 
{ 
		char s1[] = "GeeksforGeeks"; 
	char s2[] = "for"; 
	char* p; 
	size_t ll = 7;

	// Find first occurence of s2 in s1 
	p = ft_strnstr(s1, s2, ll); 

	// Prints the result 
	if (p) { 
		printf("String found\n"); 
		printf("First occurrence of string '%s' in '%s' is '%s'", s2, s1, p); 
	} else
		printf("String not found\n"); 

	return 0;
}
