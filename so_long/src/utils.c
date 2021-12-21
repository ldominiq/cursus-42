#include "so_long.h"

void	init_keys(int *keys)
{
	keys[0] = KEY_ESC;
	keys[1] = KEY_W;
	keys[2] = KEY_A;
	keys[3] = KEY_S;
	keys[4] = KEY_D;
	keys[5] = KEY_UP;
	keys[6] = KEY_RIGHT;
	keys[7] = KEY_DOWN;
	keys[8] = KEY_LEFT;
}

int	ft_search_key(int key)
{
	int			i;
	static int	keys[8];

	if (!keys[0])
		init_keys(keys);
	i = -1;
	while (++i <= 8)
	{
		if (keys[i] == key)
			return (1);
	}
	return (0);
}