/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eismail <eismail@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 12:07:59 by eismail           #+#    #+#             */
/*   Updated: 2024/04/04 22:02:31 by eismail          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include "./libft/libft.h"

typedef struct t_node
{
	int				nbr;
	int				index;
	struct t_node	*next;
}					t_node;

void	sa(t_node **lst);
void	ra(t_node **lst);
void	rra(t_node **lst);
void	pa(t_node **a, t_node **b);
void	sb(t_node **lst);
void	rb(t_node **lst);
void	rrb(t_node **lst);
void	pb(t_node **a, t_node **b);
void	ft_three(t_node **a);
void	ft_five(t_node **a, t_node **b);
t_node	*ft_last(t_node *lst);
void	ft_add(t_node **head, t_node *new);
int		ft_creat(t_node **head, char *str);
t_node	*ft_last(t_node *lst);
void	ft_add(t_node **head, t_node *new);
void	free_list(t_node **head);
int		find_min(t_node *lst);
int		num_check(char *str);
int		ft_stacksize(t_node *lst);
void	push_back(t_node **a, t_node **b);
void	else_sort(t_node **a, t_node **b, int rang);
int		find_max(t_node *lst);
int		check_sort(t_node *stack);
void	ft_two(t_node **a);
void	ft_four(t_node **a, t_node **b);
void	free_split(char **split_str);
int		check_sort(t_node *stack);
int		dep_check(t_node *stack);
int		ft_optimize(t_node *lst, int start, int end);
int		ft_optimize2(t_node *lst, long extrema);
void	set_indext(t_node **stack);
void	ft_sort(int *tab, int size);
#endif