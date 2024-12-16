/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_sprites.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrujill <atrujill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 18:40:16 by atrujill          #+#    #+#             */
/*   Updated: 2023/02/10 11:40:35 by atrujill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_delete_images(t_data *data)
{
	mlx_delete_image(data->mlx, data->wall_img);
	mlx_delete_image(data->mlx, data->bg_img);
	mlx_delete_image(data->mlx, data->player_img);
	mlx_delete_image(data->mlx, data->exit_img);
	mlx_delete_image(data->mlx, data->collect_img);
}

void	init_sprites(t_data *data)
{
	mlx_texture_t	*sprite_texture;

	sprite_texture = mlx_load_png("./assets/images/wall.png");
	data->wall_img = mlx_texture_to_image(data->mlx, sprite_texture);
	mlx_delete_texture(sprite_texture);
	sprite_texture = mlx_load_png("./assets/images/background.png");
	data->bg_img = mlx_texture_to_image(data->mlx, sprite_texture);
	mlx_delete_texture(sprite_texture);
	sprite_texture = mlx_load_png("./assets/images/collectable.png");
	data->collect_img = mlx_texture_to_image(data->mlx, sprite_texture);
	mlx_delete_texture(sprite_texture);
	sprite_texture = mlx_load_png("./assets/images/exit.png");
	data->exit_img = mlx_texture_to_image(data->mlx, sprite_texture);
	mlx_delete_texture(sprite_texture);
	sprite_texture = mlx_load_png("./assets/images/player_front.png");
	data->player_img = mlx_texture_to_image(data->mlx, sprite_texture);
	mlx_delete_texture(sprite_texture);
}
