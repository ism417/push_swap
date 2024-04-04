/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   act_b.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eismail <eismail@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 19:20:25 by eismail           #+#    #+#             */
/*   Updated: 2024/04/03 17:59:36 by eismail          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	sb(t_node **lst)
{
	t_node	*temp;

	temp = *lst;
	if (ft_stacksize(*lst) <= 1)
		return ;
	*lst = (*lst)->next;
	temp->next = (*lst)->next;
	(*lst)->next = temp;
}

void	rb(t_node **lst)
{
	t_node	*lst_temp;
	t_node	*temp;

	temp = *lst;
	*lst = (*lst)->next;
	if (ft_stacksize(*lst) <= 1)
		return ;
	lst_temp = ft_last(*lst);
	lst_temp->next = temp;
	temp->next = NULL;
}

void	rrb(t_node **lst)
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

void	pb(t_node **a, t_node **b)
{
	t_node	*tempa;

	tempa = *a;
	if (!*a || !a)
		return ;
	*a = (*a)->next;
	tempa->next = *b;
	*b = tempa;
}
