/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_allocated.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrujill <atrujill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 20:16:15 by atrujill          #+#    #+#             */
/*   Updated: 2023/02/10 11:40:39 by atrujill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_print_error(int error_number)
{
	ft_putendl_fd("Error", 2);
	if (error_number == 0)
		ft_putendl_fd("Memory was not allocated.", 2);
	else if (error_number == 1)
		ft_putendl_fd("Invalid file descriptor.", 2);
	else if (error_number == 2)
		ft_putendl_fd("Map is not rectangular.", 2);
	else if (error_number == 3)
		ft_putendl_fd("The map is not surrounded by walls.", 2);
	else if (error_number == 4)
		ft_putendl_fd("An unknown character has been read.", 2);
	else if (error_number == 5)
	{
		ft_putstr_fd("There is more than one player ", 2);
		ft_putstr_fd("or one exit, ", 2);
		ft_putendl_fd("or no collectibles.", 2);
	}
	else if (error_number == 6)
		ft_putendl_fd("the map is cannot end", 2);
	else if (error_number == 7)
		ft_putendl_fd("the player does not exist", 2);
}

void	ft_free_data(t_data *data, int error_number)
{
	free(data);
	ft_print_error(error_number);
	exit(EXIT_FAILURE);
}

void	ft_free_map_data(t_data *data, int error_number)
{
	if (data->map_copy)
		free(data->map_copy);
	free(data->map);
	ft_free_data(data, error_number);
}

void	ft_free_map_and_close(t_data *data, int fd, char *line,
		int error_number)
{
	close(fd);
	free(line);
	if (data->map)
		ft_free_map_data(data, error_number);
	else
		ft_free_data(data, error_number);
}

void	ft_free_all(t_data *data)
{
	ft_delete_images(data);
	mlx_terminate(data->mlx);
	free(data->map);
	free(data);
}
