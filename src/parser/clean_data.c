#include "../../include/cub3d.h"

int	ft_count_valid_lines(char **data)
{
	int	i;
	int	j;
	int	only_spaces;
	int	new_line_count;

	new_line_count = 0;
	i = 0;
	while (data[i])
	{
		only_spaces = 1;
		j = 0;
		while (data[i][j])
		{
			if (data[i][j] != ' ' && data[i][j] != '\t')
			{
				only_spaces = 0;
				break ;
			}
			j++;
		}
		if (!only_spaces)
			new_line_count++;
		i++;
	}
	return (new_line_count);
}

char	**ft_create_clean_data_array(int new_line_count)
{
	char	**new_data;

	new_data = (char **)ft_calloc(new_line_count + 1, sizeof(char *));
	return (new_data);
}

int	ft_is_valid_line(char *line)
{
	int	j;
	int	only_spaces;

	only_spaces = 1;
	j = 0;
	while (line[j])
	{
		if (line[j] != ' ' && line[j] != '\t')
		{
			only_spaces = 0;
			break ;
		}
		j++;
	}
	return (!only_spaces);
}

char	**ft_copy_valid_lines(char **data, char **new_data)
{
	int	i;
	int	k;

	i = 0;
	k = 0;
	while (data[i])
	{
		if (ft_is_valid_line(data[i]))
		{
			new_data[k] = ft_strdup(data[i]);
			if (!new_data[k])
			{
				while (k >= 0)
				{
					free(new_data[k]);
					k--;
				}
				free(new_data);
				return (NULL);
			}
			k++;
		}
		i++;
	}
	return (new_data);
}

char	**ft_clean_data_copy(char **data)
{
	int		new_line_count;
	char	**new_data;

	new_line_count = ft_count_valid_lines(data);
	new_data = ft_create_clean_data_array(new_line_count);
	if (!new_data)
		return (NULL);
	new_data = ft_copy_valid_lines(data, new_data);

	return (new_data);
}
