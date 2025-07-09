#include "so_long.h"


static void *choose_img(char block, t_ptr *ptr)
{
	if (block == '1')
		return (ptr->img[0]);
	else if (block == 'o' || block == '0')
		return (ptr->img[1]);
	else if (block == 'c')
		return (ptr->img[2]);
	else if (block == 'P')
		return (ptr->img[3]);
	else if (block == 'e')
		return (ptr->img[4]);
	return (0);
}

static void	receive_image(t_ptr *ptr)
{
	int	i[2];
	int	j;

	// pour les murs
	ptr->img[0] = mlx_xpm_file_to_image(ptr->mlx, "texture/wall.xpm", &i[0], &i[1]);
	// pour le sol
	ptr->img[1] = mlx_xpm_file_to_image(ptr->mlx, "texture/floor.xmp", &i[0], &i[1]);
	// pour les items
	ptr->img[2] = mlx_xpm_file_to_image(ptr->mlx, "texture/item.xpm", &i[0], &i[1]);
	// pour le player
	ptr->img[3] = mlx_xpm_file_to_image(ptr->mlx, "texture/player.xpm", &i[0], &i[1]);
	// pour les portes fermer
	ptr->img[4] = mlx_xpm_file_to_image(ptr->mlx, "texture/c_door.xpm", &i[0], &i[1]);
	// porte ouverte 
	ptr->img[5] = mlx_xpm_file_to_image(ptr->mlx, "texture/o_door.xpm", &i[0], &i[1]);
	// pour le player sur la porte qui est fermer 
	ptr->img[6] = mlx_xpm_file_to_image(ptr->mlx, "texture/player_door.xpm", &i[0], &i[1]);
	// pour le sol apres le passage du player
	ptr->img[7] = mlx_xpm_file_to_image(ptr->mlx, "texture/player_floor.xpm", &i[0], &i[1]);

	j = 0;
	while (j < 8 && ptr->img[j])
		j++;
	if (j != 8)
		exit_mlx(ptr, 1);
}

void	insert_map(t_ptr *ptr)
{
	int	x;
	int	y;

	y = 0;
	receive_image(ptr);
	while (ptr->map[y])
	{
		x = 0;
		while (ptr->map[y][x])
		{
			mlx_put_image_to_window(ptr->mlx, ptr->mlx_win,
				choose_img(ptr->map[y][x], ptr), x * 32, y * 32);
			x++;
		}
		y++;
	}
}

int	exit_mlx(t_ptr *ptr, int choice)
{
	int	i;

	i = 0;
	while (i < 8)
	{
		if (ptr->img[i])
			mlx_destroy_image(ptr->mlx, ptr->img[i]);
		i++;
	}
	if (choice == 1)
		write (1, "Error\n", 7);
	mlx_destroy_window(ptr->mlx, ptr->mlx_win);
	mlx_destroy_display(ptr->mlx);
	free(ptr->mlx);
	free_map(ptr->map);
	exit(0);
	return (0);
}

void	free_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}