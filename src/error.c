/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brdany <brdany@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 23:15:17 by brdany            #+#    #+#             */
/*   Updated: 2025/07/08 21:18:36 by brdany           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

void    ft_perror(void)
{
	write (2, "Error\n", 7);
	perror(0);
	exit(EXIT_FAILURE);
}

void	ft_error(char *message, int choice, char **map)
{
	if (choice == 1)
		free(map);
	write (2, "Error\n", 7);
	if (message)
		write (2, message, ft_strlen(message));
	exit(EXIT_FAILURE);
}

int	ft_exit_mlx(t_ptr *ptr, int choice)
{
	int i;
	int	j;

	i = 0;
	j = 0;
	while (i < 8)
	{
		if (ptr->img[i])
			mlx_destroy_image(ptr->mlx, ptr->img[i]);
		i++;
	}
	if (choice == 1)
		write (2, "Error\n", 7);
	mlx_destroy_window(ptr->mlx, ptr->mlx_win);
	mlx_destroy_display(ptr->mlx);
	free(ptr->mlx);
	while (ptr->map[j])
		free(ptr->map[j++]);
	exit(0);
	return (0);
}
