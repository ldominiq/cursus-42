#ifndef SO_LONG_H
# define SO_LONG_H

# include "../mlx/mlx.h"
# include "../libft/libft.h"
# include "get_next_line.h"
# include <unistd.h>
# include <fcntl.h>

# ifndef ANIMATION_FRAMES
#  define ANIMATION_FRAMES 10
# endif

/* vector with an x and y */
typedef struct	s_vector
{
	int	x;
	int	y;
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

typedef struct	s_map
{
	char	*map;
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
	t_map		map;
	t_sprite    ground_sprite;
	t_sprite    player_sprite;
}				t_program;

t_window	ft_new_window(void *mlx, int width, int height, char *name);
t_image     ft_new_sprite(void *mlx, char *path);
int         ft_close();
int	        ft_input(int key, void *param);
int	        ft_update (void *param);
void        ft_create_ground(t_program *program);
int			open_file(char *file_name);
void		read_map(int fd);
int			ft_errors(int argc);

#endif