/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrujill <atrujill@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 13:37:46 by atrujill          #+#    #+#             */
/*   Updated: 2023/02/03 12:13:58 by atrujill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

char	*get_next_line(int fd);
char	*ft_next_substr(char *s, unsigned int start, size_t len);
char	*ft_next_strdup(char *str);
void	ft_next_strjoin(char **str1, char *str2, size_t s2len);
size_t	ft_next_strlen(char *str);
void	*ft_next_calloc(size_t count, size_t size);
#endif
