/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard_key_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brdany <brdany@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 21:08:38 by brdany            #+#    #+#             */
/*   Updated: 2025/07/15 22:51:31 by brdany           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_putnbr(int nbr)
{
	if (nbr > 9)
		ft_putnbr(nbr / 10);
	write (1, &"0123456789"[nbr % 10], 1);
}
void	handle_collectible(t_ptr *ptr, int x, int y)
{
	if (ptr->map[y][x] == 'c')
	{
		ptr->item--;
		ptr->map[y][x] = 'o';
	}
}

void	handle_exit(t_ptr *ptr, int x, int y)
{
	if (ptr->map[y][x] == 'e' && ptr->item == 0)
		exit_mlx(ptr, 0);
}

void	redraw_under_player(t_ptr *ptr, int x, int y)
{
	void	*img;

	if (ptr->map[y][x] == 'c' || ptr->map[y][x] == 'o')
		img = ptr->img[3];
	else if (ptr->map[y][x] == 'e')
		img = ptr->img[6];
	else
		img = ptr->img[1];

	mlx_put_image_to_window(ptr->mlx, ptr->mlx_win, img, x * 48, y * 48);
}

void	redraw_old_position(t_ptr *ptr)
{
	int x;
	int y;

	x = ptr->player[0];
	y = ptr->player[1];

	if (x == ptr->exit[0] && y == ptr->exit[1])
		mlx_put_image_to_window(ptr->mlx, ptr->mlx_win, ptr->img[4], x * 48, y * 48);
	else
		mlx_put_image_to_window(ptr->mlx, ptr->mlx_win, ptr->img[7], x * 48, y * 48);
}