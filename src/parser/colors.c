#include "../../include/cub3d.h"

int	ft_trans_color(char *line)
{
	char	**color_data;
	int		rgb;
	int		a;
	int		b;
	int		c;

	a = 0;
	b = 0;
	c = 0;
	rgb = 0;
	color_data = NULL;
	color_data = ft_split(line, ',');
	a = ft_atoi(color_data[0]);
	b = ft_atoi(color_data[1]);
	c = ft_atoi(color_data[2]);
	rgb = ft_get_rgba(a, b, c, 0xFF);
	return (rgb);
}

int	ft_get_rgba(int r, int g, int b, int a)
{
	return (r << 24 | g << 16 | b << 8 | a);
}
