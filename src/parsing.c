/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brdany <brdany@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 22:18:03 by brdany            #+#    #+#             */
/*   Updated: 2025/07/14 01:17:54 by brdany           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	is_valid_tile(char tile)
{
	return (tile != '1' && tile != 'o' && tile != 'c' && tile != 'e');
}

static void	mark_tile(char **map, int x, int y,int *items)
{
	if (map[y][x] == '0')
		map[y][x] = 'o';
	else if (map[y][x] == 'C')
	{
		(*items)--;
		map[y][x] = 'c';
	}
	else if (map[y][x] == 'E')
		map[y][x] = 'e';
}

static int	flood_fill_check_path(char **map, int x, int y, int *item)
{
	if (!is_valid_tile(map[y][x]))
		return (0);
	mark_tile(map, x, y, item);
	
	if (map[y][x] == 'e')
		return (
			flood_fill_check_path(map, x - 1, y, item) +
			flood_fill_check_path(map, x + 1, y, item) +
			flood_fill_check_path(map, x, y - 1, item) +
			flood_fill_check_path(map, x, y + 1, item) + 1
		);
	return (
		flood_fill_check_path(map, x - 1, y, item) +
		flood_fill_check_path(map, x + 1, y, item) +
		flood_fill_check_path(map, x, y - 1, item) +
		flood_fill_check_path(map, x, y + 1, item)
	);
}

static size_t  size_maps(char **argv)
{
	int fd;
	size_t size;
	char *tmp;
	
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		ft_perror();
	size = 0;
	while (1)
	{
		tmp = get_next_line(fd);
		if (!tmp)
			break;
		size++;
		free(tmp);
	}
	close(fd);
	if (size >= 3)
		return (size);
	ft_error("the map is empty\n", 0, 0);
	return (0);
}

static void	put_map(char **argv, char **map, int size)
{
	int		fd;
	int		i;
	char	*tmp;

	i = 0;
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		free(map);
		ft_perror();
	}
	while (i < size)
	{
		tmp = get_next_line(fd);
		if (!tmp)
			break;
		if (tmp[ft_strlen(tmp) - 1] == '\n')
			tmp[ft_strlen(tmp) - 1] = '\0';
		map[i] = tmp;
		i++;
	}
	close(fd);
}

static void	test_block(char **map, int size)
{
	int	i;
	int	j;
	int	x;

	i = 0;
	x = ft_strlen(map[0]);
	while (map[i])
	{
		if (ft_strlen(map[i]) != x)
			ft_error("this is not a rectangular map\n", 1, map);
		j = 0;
		while (map[i][j])
		{
			if ((i == 0 || i == (size - 1)) && map[i][j] != '1')
				ft_error("wrong map given\n", 1, map);
			if ((j == 0 || j == x - 1) && map[i][j] != '1')
				ft_error("wrong map given\n", 1, map);
			if (map[i][j] != '0' && map[i][j] != '1' && map[i][j] != 'C' && map[i][j] != 'E' && map[i][j] != 'P')
				ft_error("wrong map given\n", 1, map);
			j++;
		}
		i++;
	}
}

void	check_dupplicate(char **map)
{
	int	i;
	int	j;
	int pt_p;
	int	pt_e;


	i = 0;
	pt_p = 0;
	pt_e = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'E')
				pt_e++;
			else if (map[i][j] == 'P')
				pt_p++;
			j++;
		}
		i++;
	}
	if (pt_e != 1 || pt_p != 1)
		ft_error("wrong map given\n", 1, map);
}

char	**creat_map(char **argv, size_t *size)
{
	char	**map;
	int		item;
	int		point[2];
	
	*size = size_maps(argv);
	map = malloc(sizeof(char *) * (*size + 1));
	if (!map)
		ft_error("error malloc\n", 0, 0);
	map[*size] = NULL;
	put_map(argv, map, *size);
	test_block(map, *size);
	check_dupplicate(map);
	item = (find_point(map, 'C', point));
	if (item == 0 || find_point(map, 'P', point) == 0)
		ft_error("this isn't a possible map\n", 1, map);
	if (flood_fill_check_path(map, point[0], point[1], &item) == 0 || item != 0)
		ft_error("this isn't a possible map\n", 1, map);
	return (map);
}
