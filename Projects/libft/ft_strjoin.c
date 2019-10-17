char	*ft_strjoin(char const *s1, char const *s2)
{
	int i;
	char *bf;

	i = 0;
	while (*s1++ != '\0' && *s2++ != '\0')
		i++;
	bf = (char *)malloc(i + 1);
	i = 0;
	while (*s1++)
	{
		while(*s2++)
			*bf++ = *s2;
		*bf++ = *s1;
	}
}
