/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brdany <brdany@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 22:18:03 by brdany            #+#    #+#             */
/*   Updated: 2025/07/02 23:17:35 by brdany           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

size_t  size_maps(char **argv)
{
	int fd;
	size_t size;
	char *tmp;
	
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		ft_perror(); //fonction pour ecrire error
	size = 0;
	while (1)
	{
		tmp = get_next_line(fd);
		if (!tmp)
			break;
		size++;
		free(tmp);
		close(fd);
	}
	if (size >= 3)
		return (size);
	write (1, "maps is empty", 13);
	return (0);
}

char	**creat_map()
{
	// recup size_maps 
	// malloc la maps
	// put map (imprimer la map)
	// tester tout le block (si les caractere sont ok (0 / 1 / C / P / E))
	// check dupplicate (verif si y'a plusieur P ou E)
	// int item (si y'a pas C ou de P) boucle (find_point(map, 'P' point))
	//if item == 0 
	//if player == 0
	// flood_fill
	// return (map);
}