#include "../../include/cub3d.h"

/*
	Función que obtiene el número de columnas del archivo(mapa) y info texturas parte 2
*/
int	ft_num_col_file(int fd)
{
	int		col;
	char	*line;

	col = 0;
	line = get_next_line(fd);
	if (!line)
		return (0);
	while (line)
	{
		free(line);
		line = get_next_line(fd);
		col++;
	}
	return (col);
}

/*
	Función que obtiene el número de columnas del archivo(mapa) y de texturas parte 1
*/
int	ft_size_file(char *path)
{
	int	num_col_file;
	int	fd;

	num_col_file = 0;
	fd = open(path, O_RDONLY);
	if (fd < 0)
		ft_perror("fd don't open");
	num_col_file = ft_num_col_file(fd);
	close(fd);
	return (num_col_file);
}

/*
	Función que carga el contenido del archivo(mapa) y texturas en un array de strings
*/
void	ft_charge_file_data(char **data, int fd, int num_col)
{
	int		i;
	char	*row_files;

	i = 0;
	row_files = get_next_line(fd);
	if (row_files)
		data[i++] = row_files;
	while (i < num_col && row_files)
	{
		row_files = get_next_line(fd);
		if (row_files)
			data[i++] = row_files;
	}
	data[i] = NULL;
}
/*
	Comprobamos si el archivo se abrió correctamente
*/
char	**ft_read_fd(char *path, int num_col_file)
{
	char	**file_data;
	int		fd;

	fd = open(path, O_RDONLY);
	if (fd < 0)
		return (NULL);
	file_data = malloc(sizeof(char *) * (num_col_file + 1));
	if (!file_data)
	{
		close(fd);
		ft_perror("FILE malloc problem");
	}
	ft_charge_file_data(file_data, fd, num_col_file);
	return (file_data);
}


/*
	Función principal de obtencion de mapa
	1. Obtiene el tamaño del archivo
	2. Lee el archivo y carga el contenido en un array de strings
	3. Retorna el array de strings
*/
char	**ft_get_file(char *path)
{
	char	**data;
	int		num_col_file;
	//hay que obtener primero valores texturas y colores
	num_col_file = ft_size_file(path);
	if (num_col_file == 0)
		ft_perror("fd is empty");
	data = ft_read_fd(path, num_col_file);
	return (data);
}

char	**ft_read_fd(char *path)
{
	char	**file_data;
	int		fd;

	fd = open(path, O_RDONLY);
	if (fd < 0)
		return (NULL);
	file_data = malloc(sizeof(char *) * (num_col + 1));
	if (!file_data)
	{
		close(fd);
		ft_perror("FILE malloc problem");
	}
	ft_charge_file_data(file_data, fd, num_col);
	return (file_data);
}
/*
vamos a localizar los datos previos de 
*/
