/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eismail <eismail@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 22:19:47 by eismail           #+#    #+#             */
/*   Updated: 2024/04/03 15:29:51 by eismail          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

# include "../push_swap.h"

char	*get_next_line(int fd);
size_t	ft_strlen(const char *s);
char	*sub_buf(char *s, size_t start, size_t end);
char	*add_buffer(char *s1, char *s2);
int		find_line(char *s);
char	*re_line(char **s);
char	*ft_free(char *cup_buffer, char **s);
void	free_list(t_node **head);

#endif