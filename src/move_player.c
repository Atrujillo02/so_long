/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrujill <atrujill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 20:17:32 by atrujill          #+#    #+#             */
/*   Updated: 2023/02/10 11:39:46 by atrujill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	go_up(t_data *data)
{
	int		i;
	int		up;
	char	*moves;

	i = 0;
	while (data->map[i] != 'P')
		i++;
	up = i - data->map_width;
	if (data->map[up] != '1' && !check_exit(data, data->map[up]))
	{
		data->player_moves++;
		if (data->map[up] == 'C')
			data->nbr_collect--;
		data->map[i] = '0';
		data->map[up] = 'P';
		moves = ft_itoa(data->player_moves);
		ft_putendl_fd(moves, 1);
		free(moves);
	}
	ft_make_map(data, 64);
}

static void	go_left(t_data *data)
{
	int		i;
	int		left;
	char	*moves;

	i = 0;
	while (data->map[i] != 'P')
		i++;
	left = i - 1;
	if (data->map[left] != '1' && !check_exit(data, data->map[left]))
	{
		data->player_moves++;
		if (data->map[left] == 'C')
			data->nbr_collect--;
		data->map[i] = '0';
		data->map[left] = 'P';
		moves = ft_itoa(data->player_moves);
		ft_putendl_fd(moves, 1);
		free(moves);
	}
	ft_make_map(data, 64);
}

static void	go_down(t_data *data)
{
	int		i;
	int		down;
	char	*moves;

	i = 0;
	while (data->map[i] != 'P')
		i++;
	down = i + data->map_width;
	if (data->map[down] != '1' && !check_exit(data, data->map[down]))
	{
		data->player_moves++;
		if (data->map[down] == 'C')
			data->nbr_collect--;
		data->map[i] = '0';
		data->map[down] = 'P';
		moves = ft_itoa(data->player_moves);
		ft_putendl_fd(moves, 1);
		free(moves);
	}
	ft_make_map(data, 64);
}

static void	go_right(t_data *data)
{
	int		i;
	int		right;
	char	*moves;

	i = 0;
	while (data->map[i] != 'P')
		i++;
	right = i + 1;
	if (data->map[right] != '1' && !check_exit(data, data->map[right]))
	{
		data->player_moves++;
		if (data->map[right] == 'C')
			data->nbr_collect--;
		data->map[i] = '0';
		data->map[right] = 'P';
		moves = ft_itoa(data->player_moves);
		ft_putendl_fd(moves, 1);
		free(moves);
	}
	ft_make_map(data, 64);
}

void	press_button(mlx_key_data_t keydata, void *game_data)
{
	t_data	*data;

	(void)keydata;
	data = game_data;
	if (mlx_is_key_down(data->mlx, MLX_KEY_ESCAPE))
	{
		ft_free_all(data);
		exit(EXIT_SUCCESS);
	}
	else if (mlx_is_key_down(data->mlx, MLX_KEY_W))
		go_up(data);
	else if (mlx_is_key_down(data->mlx, MLX_KEY_A))
		go_left(data);
	else if (mlx_is_key_down(data->mlx, MLX_KEY_S))
		go_down(data);
	else if (mlx_is_key_down(data->mlx, MLX_KEY_D))
		go_right(data);
}
