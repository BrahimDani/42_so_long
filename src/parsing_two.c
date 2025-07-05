
#include "so_long.h"

int	find_point(char **map, char to_find, int point[2])
{
	int	x;
	int	y;
	int count;

	x = 0;
	y = 0;
	count = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == to_find && count == 0)
			{
				point[0] = x;
				point[1] = y;
				count++;
			}
			else if (map[y][x] == to_find)
				count++;
				x++;
		}
		y++;
	}
	return (count);
}

static int	is_valid_tile(char tile)
{
	return (tile != '1' && tile != 'o' && tile != 'c' && tile != 'e');
}

static void	mark_tile(char **map, int x, int y,int *items)
{
	if (map[y][x] == '0')
		map[y][x] = 'o';
	else if (map[y][x] == 'C')
		map[y][x] = 'c';
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
