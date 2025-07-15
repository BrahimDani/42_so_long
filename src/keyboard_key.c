/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard_key.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brdany <brdany@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 18:50:31 by brdany            #+#    #+#             */
/*   Updated: 2025/07/15 22:31:10 by brdany           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	move_up(t_ptr *ptr)
{
	int	new_x;
	int new_y;

	new_x = ptr->player[0];
	new_y = ptr->player[1] - 1;
	if (ptr->map[new_y][new_x] == '1')
		return ;
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
	if (ptr->map[new_y][new_x] == '1')
		return ;
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
	if (ptr->map[new_y][new_x] == '1')
		return ;
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
	if (ptr->map[new_y][new_x] == '1')
		return ;
	ptr->index++;
	ft_putnbr(ptr->index);
	write (1, "\n", 1);
	
	handle_collectible(ptr, new_x, new_y);
	handle_exit(ptr, new_x, new_y);
	redraw_under_player(ptr, new_x, new_y);
	redraw_old_position(ptr);

	ptr->player[0] = new_x;
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