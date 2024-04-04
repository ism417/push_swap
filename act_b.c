/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   act_b.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eismail <eismail@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 19:20:25 by eismail           #+#    #+#             */
/*   Updated: 2024/04/01 12:48:23 by eismail          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sb(t_node **lst)
{
	t_node	*temp;

	temp = *lst;
	*lst = (*lst)->next;
	temp->next = (*lst)->next;
	(*lst)->next = temp;
	write(1, "sb\n", 3);
}

void	rb(t_node **lst)
{
	t_node	*lst_temp;
	t_node	*temp;

	temp = *lst;
	*lst = (*lst)->next;
	lst_temp = ft_last(*lst);
	lst_temp->next = temp;
	temp->next = NULL;
	write(1, "rb\n", 3);
}

void	rrb(t_node **lst)
{
	t_node	*last;
	t_node	*temp;

	temp = *lst;
	last = ft_last(*lst);
	while (temp->next != last)
		temp = temp->next;
	temp->next = NULL;
	last->next = *lst;
	*lst = last;
	write(1, "rrb\n", 4);
}

void	pb(t_node **a, t_node **b)
{
	t_node	*tempa;

	tempa = *a;
	*a = (*a)->next;
	tempa->next = *b;
	*b = tempa;
	write(1, "pb\n", 3);
}
