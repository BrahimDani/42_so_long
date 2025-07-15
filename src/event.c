/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brdany <brdany@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 22:29:57 by brdany            #+#    #+#             */
/*   Updated: 2025/07/15 22:50:53 by brdany           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int ft_event(int keycode, t_ptr *ptr)
{	if (keycode == ESCAPE)
		exit_mlx(ptr, 0);
	choice_key(keycode, ptr);
	if (ptr->map[ptr->player[1]][ptr->player[0]] == 'c')
		ptr->map[ptr->player[1]][ptr->player[0]] = 'o';
	else if (ptr->item == 0)
		mlx_put_image_to_window(ptr->mlx, ptr->mlx_win, ptr->img[5], ptr->exit[0] * 48, ptr->exit[1] * 48);
	return (0);	
}
