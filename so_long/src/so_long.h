#ifndef SO_LONG_H
# define SO_LONG_H

# include "../mlx/mlx.h"
# include "../libft/libft.h"
# include "get_next_line.h"
# include <unistd.h>
# include <fcntl.h>

# define SPRITE_SIZE 64

# ifndef ANIMATION_FRAMES
#  define ANIMATION_FRAMES 10
# endif

/* vector with an x and y */
typedef struct	s_vector
{
	int	        x;
	int	        y;
}				t_vector;

/* A pointer to the window and its size */
typedef struct	s_window
{
	void		*reference;
	t_vector	size;
}				t_window;

/* all info needed for an image */
typedef struct	s_image
{
	void		*reference;
	t_vector	size;
	char		*pixels;
	int			bits_per_pixel;
	int			line_size;
	int			endian;
}				t_image;

typedef struct  s_player
{
    t_vector    *player_pos;
}               t_player;

typedef struct	s_map
{
	char	    *map;
}				t_map;

typedef struct s_sprite
{
    t_image		sprite;
	t_vector	sprite_position;
}               t_sprite;

typedef struct	s_program
{
	void		*mlx;
	t_window	window;
	t_map		*map;
    t_player    *player;
}				t_program;

int	        ft_new_window(int width, int height, char **map);
int         ft_close();
int			ft_input(int key, t_program *program);
void        ft_init_map(t_program *program);
int			open_file(char *file_name);
void	    read_map(int fd, char **map);
int			ft_errors(int argc);
void        ft_init(t_program *program);
void		ft_new_sprite(t_program *program, char *sprite_path, int type);
void		ft_init_sprite(char *path, int x, int y, t_program *program);
void		ft_add_player(t_program *program);
int			ft_strchr_pos(const char *s, int c);
void		ft_move_right(t_program *program);
void		ft_move_left(t_program *program);
void		ft_move_up(t_program *program);
void		ft_move_down(t_program *program);

#endif