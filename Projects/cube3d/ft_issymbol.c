#include "cub3d.h"

int	ft_issymbol(int c)
{
	if ((c >= 33 && c <= 43) || (c >= 45 && c <= 47) || (c >= 91 && c <= 96) || (c >= 123 && c <= 127))
		return (1);
	return (0);
}
