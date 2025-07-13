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


//GET NEXT LINE
char	*ft_join_free(char *stash, char *buffer);
char	*read_fd(int fd, char *stash);
char	*extract_line(char *stash);
char	*clean_line(char *stash);
char	*get_next_line(int fd);
char	*ft_strjoin(char const *s1, char const *s2);
void	*ft_calloc(size_t num, size_t size);
size_t	ft_conststrlen(const char *str);
char	*ft_strchr(const char *s, int c);
void	ft_bzero(void *s, size_t n);


#endif