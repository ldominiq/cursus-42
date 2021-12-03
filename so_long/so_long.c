#include "mlx/mlx.h"

typedef struct	s_data {
	void	*img;
	void	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void	square(t_data img, int x, int y, int color)
{
	int	i;

	i = 0;
	while (i < 25)
	{
		my_mlx_pixel_put(&img, x, y, color);
		x++;
		y++;
		i++;
	}
	i = 0;
	while (i < 20)
	{
		my_mlx_pixel_put(&img, x, y, color);
		y++;
		i++;
	}
	i = 0;
	x = x + 8;
	while (i < 27)
	{
		my_mlx_pixel_put(&img, x, y, color);
		y--;
		i++;
	}
	i = 0;
	while (i < 22)
	{
		my_mlx_pixel_put(&img, x, y, color);
		y -= 2;
		x++;
		i++;
	}
}

void	aaa(t_data img, int x, int y, int color)
{
	int	i;
	int	r;
	int	l;

	i = 0;
	r = x;
	l = x;
	my_mlx_pixel_put(&img, x, y, color);
	my_mlx_pixel_put(&img, ++r, y, color);
	my_mlx_pixel_put(&img, --l, y, color);
	my_mlx_pixel_put(&img, --l, ++y, color);
	my_mlx_pixel_put(&img, ++r, y, color);
	my_mlx_pixel_put(&img, ++r, y, color);
	my_mlx_pixel_put(&img, --l, y, color);
	while (i++ < 45)
	{
		r++;
		l--;
		y++;
		my_mlx_pixel_put(&img, r, y, color);
		my_mlx_pixel_put(&img, l, y, color);
	}
	i = 0;
	while (i++ < 300)
	{
		y++;
		my_mlx_pixel_put(&img, r, y, color);
		my_mlx_pixel_put(&img, l, y, color);
	}
	i = 0;
	while (i++ < 40)
	{
		y++;
		r += 2;
		l -= 2;
		my_mlx_pixel_put(&img, r, y, color);
		my_mlx_pixel_put(&img, l, y, color);
	}
	i = 0;
	while (i++ < 80)
	{
		y++;
		my_mlx_pixel_put(&img, r, y, color);
		my_mlx_pixel_put(&img, l, y, color);
	}
	i = 0;
	while (i++ < 90)
	{
		r--;
		l++;
		my_mlx_pixel_put(&img, r, y, color);
		my_mlx_pixel_put(&img, l, y, color);
	}
	i = 0;
	while (i++ < 30)
	{
		y--;
		r--;
		l++;
		my_mlx_pixel_put(&img, r, y, color);
		my_mlx_pixel_put(&img, l, y, color);
	}
	i = 0;
	while (i++ < 15)
	{
		r--;
		l++;
		my_mlx_pixel_put(&img, r, y, color);
		my_mlx_pixel_put(&img, l, y, color);
	}
	i = 0;
	y += 12;
	r = r + 60;
	l = l - 45;
	while (i++ < 18)
	{
		y++;
		my_mlx_pixel_put(&img, r, y, 0x000000FF);
		my_mlx_pixel_put(&img, l, y, 0x000000FF);
	}
	i = 0;
	y = y - 7;
	r = r + 40;
	l = l - 55;
	while (i++ < 18)
	{
		y++;
		my_mlx_pixel_put(&img, r, y, 0x000000FF);
		my_mlx_pixel_put(&img, l, y, 0x000000FF);
	}
}


int	main(void)
{
	t_data	img;
	void	*mlx;
	void	*mlx_win;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1000, 600, "zZZ");
	img.img = mlx_new_image(mlx, 1000, 600);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	square(img, 470, 50, 0x00FFFF00);
	aaa(img, 500, 90, 0x00FF0000);
	//my_mlx_pixel_put(&img, 10, 10, 0x09FE9000);
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
}
