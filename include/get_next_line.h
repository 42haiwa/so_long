/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjouenne <cjouenne@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 00:47:10 by cjouenne          #+#    #+#             */
/*   Updated: 2023/11/01 18:20:24 by cjouenne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

typedef struct s_list_2
{
	char			*data;
	struct s_list	*next;
}	t_list_2;

void	alloc_line(t_list_2 *list, char **line);
int		is_line(t_list_2 *list);
t_list	*get_last_block(t_list_2 *list);
void	dealloc_list(t_list_2 *list);
size_t	_ft_strlen(const char *s);

void	_get_line(t_list_2 *list, char **line);
void	read_and_stack(t_list_2 **list, int *read_return, int fd);
void	clear_list(t_list_2 **list);
char	*get_next_line(int fd);
#endif
