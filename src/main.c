/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brdany <brdany@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 10:56:06 by brdany            #+#    #+#             */
/*   Updated: 2025/07/04 16:51:42 by brdany           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	is_not_ber(char *argv)
{
	int	len;

	len = ft_strlen(argv);
	if (!argv)
		return (1);
	if (len <= 4)
		return (1);
	if (argv[len - 4] == '.' &&
		argv[len - 3] == 'b' &&
		argv[len - 2] == 'e' &&
		argv[len - 1] == 'r')
		return (0);
	return (1);
}

int	main(int argc, char **argv)
{
	t_ptr	ptr;
	
	if (argc != 2 || !argv[1] || is_not_ber(argv[1]))
		ft_error("wrong input\n", 0, 0);
	ptr.map = creat_map(argv, &ptr.size_map);
	ptr.index = 0;
	// find idem point (fonction find_point(ptr, map, 'c', ptr.exit)
	// find exit point
	// find player point
	// lunch mlx (mlx_new_window)
		
}