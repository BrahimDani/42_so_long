/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brdany <brdany@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 22:39:57 by brdany            #+#    #+#             */
/*   Updated: 2025/07/15 22:40:13 by brdany           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	is_valid_tile(char tile)
{
	return (tile != '1' && tile != 'o' && tile != 'c' && tile != 'e');
}

void	mark_tile(char **map, int x, int y,int *items)
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

int	flood_fill_check_path(char **map, int x, int y, int *item)
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