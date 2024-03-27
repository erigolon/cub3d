#include "../../include/cub3d.h"

int	check_extension(const char *fn)
{
	int	i;

	i = ft_strlen(fn) - 1;
	if (fn[i] != 'b' || fn[i - 1] != 'u'
		|| fn[i - 2] != 'c'
		|| fn[i - 3] != '.')
		return (1);
	return (0);
}
