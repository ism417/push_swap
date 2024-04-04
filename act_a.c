/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   act_a.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eismail <eismail@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 11:34:21 by eismail           #+#    #+#             */
/*   Updated: 2024/04/01 12:46:12 by eismail          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_node **lst)
{
	t_node	*temp;

	temp = *lst;
	*lst = (*lst)->next;
	temp->next = (*lst)->next;
	(*lst)->next = temp;
	write(1, "sa\n", 3);
}

void	ra(t_node **lst)
{
	t_node	*lst_temp;
	t_node	*temp;

	temp = *lst;
	*lst = (*lst)->next;
	lst_temp = ft_last(*lst);
	lst_temp->next = temp;
	temp->next = NULL;
	write(1, "ra\n", 3);
}

void	rra(t_node **lst)
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
	write(1, "rra\n", 4);
}

void	pa(t_node **a, t_node **b)
{
	t_node	*tempb;

	tempb = *b;
	*b = (*b)->next;
	tempb->next = *a;
	*a = tempb;
	write(1, "pa\n", 3);
}
