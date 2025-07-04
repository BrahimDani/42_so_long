#ifndef SO_LONG_H
# define SO_LONG_H
# include "../mlx/mlx.h"
# include <errno.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_ptr
{
	char	**map;
	void	*mlx;
	void	*mlx_win;
	void	*img[8];
	int		exit[2];
	int		player[2];
	int		next[2];
	int		item;
	size_t	index;
	size_t	size_map;
}			t_ptr;

int				ft_strlen(char *str);
void			ft_perror(void);
void			ft_error(char *message, int choice, char **map);
static size_t	size_maps(char **argv);
static void		put_map(char **argv, char **map, int size);
char			**creat_map(char **argv, size_t *size);

#endif