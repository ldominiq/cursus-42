#include "mlx/mlx.h"
#include <unistd.h>
#include "libft/libft.h"

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_lenght;
	int		endian;
}			t_data;

typedef struct s_vars
{
	void	*mlx;
	void	*mlx_win;
}			t_vars;

void	ft_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_lenght + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

// utiliser put_nbr pour voir quelle touche
int	key_input(int key)
{
	ft_putnbr_fd(key, 1);
	//mlx_pixel_put(mlx, mlx_win);
	return (0);
}

void	print_square(t_data img, int size, int x_pos, int y_pos, int color)
{
	int	x;
	int	y;

	x = x_pos;
	y = y_pos;
	while (x_pos < size + x)
	{
		ft_mlx_pixel_put(&img, x_pos, y_pos, color);
		x_pos++;
	}
	while (y_pos < size + y)
	{
		ft_mlx_pixel_put(&img, x_pos, y_pos, color);
		y_pos++;
	}
	while (x_pos > x)
	{
		ft_mlx_pixel_put(&img, x_pos, y_pos, color);
		x_pos--;
	}
	while (y_pos > y)
	{
		ft_mlx_pixel_put(&img, x_pos, y_pos, color);
		y_pos--;
	}
}

void	print_triangle(t_data img, int size, int x_pos, int y_pos, int color)
{
	int	x;
	int	y;

	x = x_pos;
	y = y_pos;
	while (x_pos < size + x)
	{
		ft_mlx_pixel_put(&img, x_pos, y_pos, color);
		x_pos++;
		y_pos++;
	}
	while (x_pos > x)
	{
		ft_mlx_pixel_put(&img, x_pos, y_pos, color);
		x_pos--;
	}
	while (y_pos > y)
	{
		ft_mlx_pixel_put(&img, x_pos, y_pos, color);
		y_pos--;
	}
}

int	main(void)
{
	t_vars	vars;
	t_data	img;

	vars.mlx = mlx_init();
	vars.mlx_win = mlx_new_window(vars.mlx, 1920, 1080, "Hello World");
	img.img = mlx_new_image(vars.mlx, 1920, 1080);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_lenght,
			&img.endian);
	//ft_mlx_pixel_put(&img, 5, 5, 0x00FF0000);
	mlx_key_hook(vars.mlx_win, key_input, &vars);
	print_square(img, 50, 5, 5, 0x00FF0000);
	print_triangle(img, 50, 100, 5, 0x00FF0000);
	mlx_put_image_to_window(vars.mlx, vars.mlx_win, img.img, 0, 0);
	mlx_loop(vars.mlx);
}
