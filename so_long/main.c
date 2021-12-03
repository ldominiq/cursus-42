#include "mlx/mlx.h"
#include <unistd.h>

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_lenght;
	int		endian;
}			t_data;

typedef struct s_mlx_data
{
	void	*mlx;
	void	*mlx_win;
}			t_mlx_data;

void	ft_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_lenght + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

// utiliser put_nbr pour voir quelle touche
int	key_input(int key, void *param)
{
	ft_putchar('X');
	//mlx_pixel_put(mlx, mlx_win);
	return (0);
}

void	print_square(t_data img, int size, int x_pos, int y_pos, int color)
{
	int	x;
	int	y;

	x = x_pos;
	y = y_pos;
	while (x_pos++ < size + x)
		ft_mlx_pixel_put(&img, x_pos, y_pos, color);
	while (y_pos++ < size + y)
		ft_mlx_pixel_put(&img, x_pos, y_pos, color);
	while (x_pos-- > x)
		ft_mlx_pixel_put(&img, x_pos, y_pos, color);
	while (y_pos-- > y)
		ft_mlx_pixel_put(&img, x_pos, y_pos, color);
}

int	main(void)
{
	t_mlx_data	mlx;
	t_data		img;

	mlx.mlx = mlx_init();
	mlx.mlx_win = mlx_new_window(mlx.mlx, 1920, 1080, "Hello World");
	img.img = mlx_new_image(mlx.mlx, 1920, 1080);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_lenght,
			&img.endian);
	//ft_mlx_pixel_put(&img, 5, 5, 0x00FF0000);
	//mlx_key_hook(mlx.mlx_win, key_input, (void *)&img);
	print_square(img, 50, 5, 5, 0x00FF0000);
	mlx_put_image_to_window(mlx.mlx, mlx.mlx_win, img.img, 0, 0);
	mlx_loop(mlx.mlx);
}
