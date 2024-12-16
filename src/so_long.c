/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrujill <atrujill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 18:23:47 by atrujill          #+#    #+#             */
/*   Updated: 2023/02/10 11:50:43 by atrujill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	ft_check_type(t_data *data, char *name)
{
	int	len;

	len = ft_strlen(name);
	if (len > 4 && name[len - 4] == '.' && name[len - 3] == 'b' && name[len
			- 2] == 'e' && name[len - 1] == 'r')
		return ;
	ft_free_data(data, 0);
}

static void	init_data(t_data *data, char *map_name)
{
	data->player_moves = 0;
	ft_check_type(data, map_name);
	data->map = ft_calloc(1, sizeof(char));
	if (!(data->map))
		ft_free_data(data, 0);
	ft_check_map(data, map_name);
}

int	main(int argc, char **argv)
{
	t_data	*data;

	if (argc == 2)
	{
		data = ft_calloc(1, sizeof(t_data));
		if (!data)
		{
			ft_print_error(0);
			exit(EXIT_FAILURE);
		}
		init_data(data, argv[1]);
		data->mlx = mlx_init(64 * (data->map_width - 1),
				64 * (data->map_height - 1), "so_long", true);
		if (!(data->mlx))
			ft_free_map_data(data, 0);
		init_sprites(data);
		ft_make_map(data, 64);
		mlx_key_hook(data->mlx, &press_button, data);
		mlx_loop(data->mlx);
		ft_free_all(data);
		exit(EXIT_SUCCESS);
	}
	ft_putendl_fd("Invalid number of arguments.", 1);
	exit(EXIT_FAILURE);
}
