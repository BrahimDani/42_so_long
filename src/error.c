/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brdany <brdany@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 23:15:17 by brdany            #+#    #+#             */
/*   Updated: 2025/07/02 23:42:19 by brdany           ###   ########.fr       */
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