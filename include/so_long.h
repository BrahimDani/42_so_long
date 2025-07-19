#ifndef SO_LONG_H
# define SO_LONG_H
# include "../mlx/mlx.h"
# include <errno.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 20
# endif

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

# define ON_KEYDOWN 2
# define ON_DESTROY 17
# define ESCAPE 65307
# define KEY_W 119
# define KEY_A 97
# define KEY_S 115
# define KEY_D 100
# define ARROW_UP 65362
# define ARROW_DOWN 65364
# define ARROW_LEFT 65361
# define ARROW_RIGHT 65363


int				ft_strlen(char *str);
void			ft_perror(void);
void			ft_error(char *message, int choice, char **map);
char			**creat_map(char **argv, size_t *size);
int				find_point(char **map, char to_find, int point[2]);
void			check_dupplicate(char **map);
int				find_point(char **map, char to_find, int point[2]);
int 			ft_event(int keycode, t_ptr *ptr);
void			ft_putnbr(int nbr);
void			insert_map(t_ptr *ptr);
int				exit_mlx(t_ptr *ptr, int choice);
void			free_map(char **map);
void			choice_key(int keycode, t_ptr *ptr);

// TEST 
void	handle_collectible(t_ptr *ptr, int x, int y);
void	handle_exit(t_ptr *ptr, int x, int y);
void	redraw_under_player(t_ptr *ptr, int x, int y);
void	redraw_old_position(t_ptr *ptr);
int	flood_fill_check_path(char **map, int x, int y, int *item);
void	mark_tile(char **map, int x, int y,int *items);
int	is_valid_tile(char tile);

//GET NEXT LINE
char	*ft_strdup(char *s);
void	ft_bzero(char *s, size_t n);
int	ft_strchr(char *s, int c);
char	*ft_strjoin(char *s1, char *s2);
char	*get_next_line(int fd);

#endif