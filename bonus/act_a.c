/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   act_a.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eismail <eismail@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 11:34:21 by eismail           #+#    #+#             */
/*   Updated: 2024/04/03 17:59:48 by eismail          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	sa(t_node **lst)
{
	t_node	*temp;

	temp = *lst;
	if (ft_stacksize(*lst) <= 1)
		return ;
	*lst = (*lst)->next;
	temp->next = (*lst)->next;
	(*lst)->next = temp;
}

void	ra(t_node **lst)
{
	t_node	*lst_temp;
	t_node	*temp;

	temp = *lst;
	if (ft_stacksize(*lst) <= 1)
		return ;
	*lst = (*lst)->next;
	lst_temp = ft_last(*lst);
	lst_temp->next = temp;
	temp->next = NULL;
}

void	rra(t_node **lst)
{
	t_node	*last;
	t_node	*temp;

	temp = *lst;
	if (ft_stacksize(*lst) <= 1)
		return ;
	last = ft_last(*lst);
	while (temp->next != last)
		temp = temp->next;
	temp->next = NULL;
	last->next = *lst;
	*lst = last;
}

void	pa(t_node **a, t_node **b)
{
	t_node	*tempb;

	tempb = *b;
	if (!*b || !b)
		return ;
	*b = (*b)->next;
	tempb->next = *a;
	*a = tempb;
}
