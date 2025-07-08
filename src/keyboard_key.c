/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard_key.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brdany <brdany@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 18:50:31 by brdany            #+#    #+#             */
/*   Updated: 2025/07/08 22:25:06 by brdany           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	move_up(t_ptr *ptr)
{
	if (ptr->map[ptr->player[0] - 1][ptr->player[1]] == '1')
		return ;
		ptr->index++;
	ft_putnbr(ptr->index);
	write (1, "\n", 1);
	
	handle_collectible(ptr, ptr->player[0], ptr->player[1] - 1);
	handle_exit(ptr, ptr->player[0], ptr->player[1] - 1);
	redraw_under_player(ptr, ptr->player[0], ptr->player[1] - 1);
	redraw_old_position(ptr);
	
	ptr->player[1]--;
}

static void	move_down(t_ptr *ptr)
{
	if (ptr->map[ptr->player[0] + 1][ptr->player[1]] == '1')
		return ;
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
	if (ptr->map[ptr->player[0] - 1][ptr->player[1]] == '1')
		return ;
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
	if (ptr->map[ptr->player[0] + 1][ptr->player[1]]);
		return ;
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
{
	if (keycode == ESCAPE)
		exit_mlx(ptr);
	else if (keycode == KEY_W || keycode == ARROW_UP)
		move_up(ptr);
	else if (keycode == KEY_A || keycode == ARROW_LEFT)
		move_left(ptr);
	else if (keycode == KEY_S || keycode == ARROW_DOWN)
		move_down(ptr);
	else if (keycode == KEY_D || keycode == ARROW_RIGHT)
		move_right(ptr);
	else if (ptr->map[ptr->player[1]][ptr->player[0]] == 'c')
		ptr->map[ptr->player[1]][ptr->player[0]] = 'o';
	else if (ptr->item == 0)
		mlx_put_image_to_window(ptr->mlx, ptr->mlx_win, ptr->img[5], ptr->exit[0] * 32, ptr->exit[1] * 32);
	return (0);	
}