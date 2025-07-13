/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard_key.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brdany <brdany@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 18:50:31 by brdany            #+#    #+#             */
/*   Updated: 2025/07/14 01:47:20 by brdany           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	get_map_height(char **map)
{
	int i = 0;
	while (map[i])
		i++;
	return i;
}

int	get_map_width(char **map, int y)
{
	int i = 0;
	while (map[y][i])
		i++;
	return i;
}

int	is_inside_map(char **map, int x, int y)
{
	int height = get_map_height(map);

	if (y < 0 || y == height)
		return 0;

	int width = get_map_width(map, y);
	if (x < 0 || x >= width)
		return 0;

	return 1;
}



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
// static void	print_map(t_ptr *ptr)
// {
// 	int x,y;

// 	y = 0;
// 	while (ptr->map[y]) {
// 		x=0;
// 		while (ptr->map[y][x]) {
// 			write(1, &ptr->map[y][x], 1);	
// 			x++;
// 		}
// 		write(1, "\n", 1);
// 		y++;
// 	}
// }

static void	move_up(t_ptr *ptr)
{
	int	new_x;
	int new_y;

	new_x = ptr->player[0];
	new_y = ptr->player[1] - 1;
	
	// if (!is_inside_map(ptr->map, new_x, new_x))
	// {
	// 	printf("distance: x=%d y=%d\n", new_x, new_y);
	// 	return;
	// }
	
	// printf("move down\n");
	if (ptr->map[new_y][new_x] == '1')  {
		// print_map(ptr);
		return ;
	}
	ptr->index++;
	ft_putnbr(ptr->index);
	write (1, "\n", 1);
	
	handle_collectible(ptr, new_x, new_y);
	handle_exit(ptr, new_x, new_y);
	redraw_under_player(ptr, new_x, new_y);
	redraw_old_position(ptr);
	
	ptr->player[1] = new_y;
}

static void	move_down(t_ptr *ptr)
{
	int	new_x;
	int new_y;

	new_x = ptr->player[0];
	new_y = ptr->player[1] + 1;	

	// if (!is_inside_map(ptr->map, new_x, new_x))
	// {
	// 	printf("distance: x=%d y=%d\n", new_x, new_x);
	// 	return;
	// }
	
	// printf("move up\n");
	if (ptr->map[new_y][new_x] == '1')  {
		// printf("move up exit\n");
		// print_map(ptr);
		return ;
	}
	ptr->index++;
	ft_putnbr(ptr->index);
	write (1, "\n", 1);
	
	handle_collectible(ptr, new_x, new_y);
	handle_exit(ptr, new_x, new_y);
	redraw_under_player(ptr, new_x, new_y);
	redraw_old_position(ptr);
	
	ptr->player[1] = new_y;
}

static void	move_left(t_ptr *ptr)
{
	int	new_x;
	int new_y;

	new_x = ptr->player[0] - 1;
	new_y = ptr->player[1];
	
	// if (!is_inside_map(ptr->map, new_x, new_x))
	// {
	// 	printf("distance: x=%d y=%d\n", new_x, new_y);
	// 	return;
	// }
	// printf("movr left\n");
	if (ptr->map[new_y][new_x] == '1')  {
		// print_map(ptr);
		// printf("movr left exit\n");
		return ;
	}
	ptr->index++;
	ft_putnbr(ptr->index);
	write (1, "\n", 1);
	
	handle_collectible(ptr, new_x, new_y);
	handle_exit(ptr, new_x, new_y);
	redraw_under_player(ptr, new_x, new_y);
	redraw_old_position(ptr);

	ptr->player[0] = new_x;
}

static void	move_right(t_ptr *ptr)
{
	int new_x;
	int new_y;

	new_x = ptr->player[0] + 1;
	new_y = ptr->player[1];
	
	// if (!is_inside_map(ptr->map, new_x, new_y))
	// {
	// 	printf("distance: x=%d y=%d\n", new_x, new_y);
	// 	return;
	// }
	//printf("move right\n");
	if (ptr->map[new_y][new_x] == '1')
	{
		//print_map(ptr);
		return ;
	}
	ptr->index++;
	ft_putnbr(ptr->index);
	write (1, "\n", 1);
	
	handle_collectible(ptr, new_x, new_y);
	handle_exit(ptr, new_x, new_y);
	redraw_under_player(ptr, new_x, new_y);
	redraw_old_position(ptr);

	ptr->player[0] = new_x;
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
}