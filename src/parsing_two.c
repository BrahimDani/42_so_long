
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

static int	flood_fill(char **map, int x, int y, int *item)
{

}
