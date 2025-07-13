/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard_key.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brdany <brdany@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 18:50:31 by brdany            #+#    #+#             */
/*   Updated: 2025/07/13 19:46:08 by brdany           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


static void	handle_collectible(t_ptr *ptr, int x, int y)
{
	if (ptr->map[y][x] == 'c')
	{
		ptr->item--;
		ptr->map[y][x] = 'o';
	}
}

static void	handle_exit(t_ptr *ptr, int x, int y)
{
	if (ptr->map[y][x] == 'e' && ptr->item == 0)
		exit_mlx(ptr, 0);
}

static void	redraw_under_player(t_ptr *ptr, int x, int y)
{
	void	*img;

	if (ptr->map[y][x] == 'c' || ptr->map[y][x] == 'o')
		img = ptr->img[3];
	else if (ptr->map[y][x] == 'e')
		img = ptr->img[6];
	else
		img = ptr->img[1];

	mlx_put_image_to_window(ptr->mlx, ptr->mlx_win, img, x * 32, y * 32);
}

static void	redraw_old_position(t_ptr *ptr)
{
	int x;
	int y;

	x = ptr->player[0];
	y = ptr->player[1];

	if (x == ptr->exit[0] && y == ptr->exit[1])
		mlx_put_image_to_window(ptr->mlx, ptr->mlx_win, ptr->img[4], x * 32, y * 32);
	else
		mlx_put_image_to_window(ptr->mlx, ptr->mlx_win, ptr->img[7], x * 32, y * 32);
}


// TEST !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
static void	print_map(t_ptr *ptr)
{
	int x,y;

	y = 0;
	while (ptr->map[y]) {
		x=0;
		while (ptr->map[y][x]) {
			write(1, &ptr->map[y][x], 1);
			
			x++;
		}
		write(1, "\n", 1);
		y++;
	}
}

static void	move_down(t_ptr *ptr)
{
	printf("move down\n");
	if (ptr->map[ptr->player[0] - 1][ptr->player[1]] == '1')  {
		print_map(ptr);
		return ;
	}
	ptr->index++;
	ft_putnbr(ptr->index);
	write (1, "\n", 1);
	
	handle_collectible(ptr, ptr->player[0], ptr->player[1] - 1);
	handle_exit(ptr, ptr->player[0], ptr->player[1] - 1);
	redraw_under_player(ptr, ptr->player[0], ptr->player[1] - 1);
	redraw_old_position(ptr);
	
	ptr->player[1]--;
}

static void	move_up(t_ptr *ptr)
{
	printf("move up\n");
	if (ptr->map[ptr->player[0] + 1][ptr->player[1]] == '1')  {
		printf("move up exit\n");
		print_map(ptr);
		return ;
	}
	ptr->index++;
	ft_putnbr(ptr->index);
	write (1, "\n", 1);
	
	handle_collectible(ptr, ptr->player[0], ptr->player[1] + 1);
	handle_exit(ptr, ptr->player[0], ptr->player[1] + 1);
	redraw_under_player(ptr, ptr->player[0], ptr->player[1] + 1);
	redraw_old_position(ptr);
	
	ptr->player[1]++;
}

static void	move_left(t_ptr *ptr)
{
	printf("movr left\n");
	if (ptr->map[ptr->player[0] - 1][ptr->player[1]] == '1')  {
		print_map(ptr);
		printf("movr left exit\n");
		return ;
	}
	ptr->index++;
	ft_putnbr(ptr->index);
	write (1, "\n", 1);
	
	handle_collectible(ptr, ptr->player[0] - 1, ptr->player[1]);
	handle_exit(ptr, ptr->player[0] - 1, ptr->player[1]);
	redraw_under_player(ptr, ptr->player[0] - 1, ptr->player[1]);
	redraw_old_position(ptr);

	ptr->player[0]--;
}

static void	move_right(t_ptr *ptr)
{
	printf("move right\n");
	if (ptr->map[ptr->player[0] + 1][ptr->player[1]])  {
		print_map(ptr);
		return ;
	}
	ptr->index++;
	ft_putnbr(ptr->index);
	write (1, "\n", 1);
	
	handle_collectible(ptr, ptr->player[0] + 1, ptr->player[1]);
	handle_exit(ptr, ptr->player[0] + 1, ptr->player[1]);
	redraw_under_player(ptr, ptr->player[0] + 1, ptr->player[1]);
	redraw_old_position(ptr);

	ptr->player[0]++;
}


int ft_event(int keycode, t_ptr *ptr)
{	if (keycode == ESCAPE)
		exit_mlx(ptr, 0);
	choice_key(keycode, ptr);
	if (ptr->map[ptr->player[1]][ptr->player[0]] == 'c')
		ptr->map[ptr->player[1]][ptr->player[0]] = 'o';
	else if (ptr->item == 0)
		mlx_put_image_to_window(ptr->mlx, ptr->mlx_win, ptr->img[5], ptr->exit[0] * 32, ptr->exit[1] * 32);
	return (0);	
}

void	choice_key(int keycode, t_ptr *ptr)
{
	if (keycode == KEY_W || keycode == ARROW_UP)
		move_up(ptr);
	else if (keycode == KEY_A || keycode == ARROW_LEFT)
		move_left(ptr);
	else if (keycode == KEY_S || keycode == ARROW_DOWN)
		move_down(ptr);
	else if (keycode == KEY_D || keycode == ARROW_RIGHT)
		move_right(ptr);
	printf("debug keycode %d\n", keycode);
}