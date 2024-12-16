/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrujill <atrujill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 19:35:54 by atrujill          #+#    #+#             */
/*   Updated: 2023/02/10 12:12:25 by atrujill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "/Users/atrujill/Desktop/MLX42/include/MLX42/MLX42.h"
# include "../get_next_line/get_next_line.h"
# include "../libft/libft.h"
# include <fcntl.h>

typedef struct s_data
{
	mlx_t		*mlx;
	mlx_image_t	*player_img;
	mlx_image_t	*bg_img;
	mlx_image_t	*wall_img;
	mlx_image_t	*collect_img;
	mlx_image_t	*exit_img;
	char		*map;
	int			map_height;
	int			map_width;
	char		*map_copy;
	int			nbr_collect;
	int			nbr_players;
	int			nbr_exits;
	int			player_moves;
	int			player_pos;
}				t_data;

void			ft_check_map(t_data *data, char *name);
void			init_sprites(t_data *data);
void			ft_delete_images(t_data *data);
void			ft_make_map(t_data *data, int img_size);
void			press_button(mlx_key_data_t keydata, void *data);
int				check_exit(t_data *data, char next_position);
void			ft_free_map_and_close(t_data *data, int fd, char *line,
					int error_number);
void			ft_free_data(t_data *data, int error_number);
void			ft_free_map_data(t_data *data, int error_number);
void			ft_free_all(t_data *data);
void			ft_swap_and_free(t_data *data, char *line);
void			ft_print_error(int error_number);
void			set_player_position_and_map_copy(t_data *data);
void			check_path(t_data *data, int pos, char object);
int				path_finding(t_data *data, int player_pos, int objetive,
					char object);

#endif
