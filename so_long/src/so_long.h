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

# define KEY_ESC 53
# define KEY_W 13
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2
# define KEY_UP 126
# define KEY_RIGHT 124
# define KEY_DOWN 125
# define KEY_LEFT 123

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
	int			steps;
	int			balls;
}               t_player;

typedef struct	s_balls
{
	int			amount;
}				t_balls;

typedef struct	s_map
{
	char	    *map;
	t_balls		*balls;
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
int			ft_search_key(int key);
void		count_balls(t_program *program);
void		ft_collect(t_program *program, int ball_pos);
void		ft_free(t_program *program);
void		ft_escape(t_program *program, int next_sprite);
void		ft_free_ptr(char **ptr);
int			check_map_name(char *str);
void		check_map_shape(int width, char *line, char **save);
int			check_map_validity(char **result);
int			check_map_border(char **map, int width);

#endif