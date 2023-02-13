/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhovhan <suhovhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 18:27:00 by suhovhan          #+#    #+#             */
/*   Updated: 2022/11/30 19:00:20 by suhovhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BONUS_H
# define BONUS_H

# include "push_swap.h"
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

char	*get_next_line(int fd);
char	*ft_read_to_left_str(int fd, char *left_str);
int		ft_strncmp(char *s1, char *s2, int len);
char	*ft_strjoin2(char *left_str, char *buff);
void	*ft_memchr(const void *s, int c, size_t n);
void	*ft_memcpy(void *dst, const void *src, size_t n);
size_t	ft_strlen2(char *s);
char	*ft_get_line(char *left_str);
char	*ft_new_left_str(char *left_str);
int		check_line(char *line);
int		check_args(t_checker_args data, t_stack **stack_a);
int		check_algo(char **matrix, t_stack **stack_a, t_stack **stack_b);
void	free_error_exit(t_stack **stack_a, t_stack **stack_b, char **matrix);
int		free_matrix(char **matrix);

#endif
