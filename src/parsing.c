/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brdany <brdany@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 22:18:03 by brdany            #+#    #+#             */
/*   Updated: 2025/07/04 17:33:04 by brdany           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
	ft_error("the map is empty", 0, 0);
	return (0);
}

static void	put_map(char **argv, char **map, int size)
{
	int	fd;
	int	i;
	int	*tmp;

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
		if (tmp[ft_strlen(tmp) - 1] == '\n');
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
		}
	}
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
	// tester tout le block (si les caractere sont ok (0 / 1 / C / P / E))
	test_block(map, *size);
	// check dupplicate (verif si y'a plusieur P ou E)
	// int item (si y'a pas C ou de P) boucle (find_point(map, 'P' point))
	//if item == 0 
	//if player == 0
	// flood_fill
	// return (map);
}