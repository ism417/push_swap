/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eismail <eismail@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 22:50:02 by eismail           #+#    #+#             */
/*   Updated: 2024/04/01 14:57:24 by eismail          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*creat_arry(t_node *stack)
{
	int		i;
	int		*arry;
	t_node	*temp;

	i = 0;
	temp = stack;
	arry = malloc(ft_stacksize(stack) * sizeof(int));
	if (!arry)
		return (0);
	while (temp != NULL)
	{
		arry[i++] = temp->nbr;
		temp = temp->next;
	}
	return (arry);
}

void	set_indext(t_node **stack)
{
	int		i;
	int		*arry;
	t_node	*temp;

	i = 0;
	temp = *stack;
	arry = creat_arry(*stack);
	ft_sort(arry, ft_stacksize(*stack));
	while (temp != NULL)
	{
		i = 0;
		while (i < ft_stacksize(*stack) && i++ >= 0)
		{
			if (arry[i] == temp->nbr)
				temp->index = i;
		}
		temp = temp->next;
	}
	free (arry);
}

int	*ft_reverse(t_node *lst)
{
	int		*arry ;
	int		len;
	t_node	*temp;

	len = ft_stacksize(lst);
	arry = malloc(len * sizeof(int));
	if (!arry)
		return (NULL);
	temp = lst;
	while (--len >= 0)
	{
		arry[len] = temp->nbr;
		temp = temp->next;
	}
	return (arry);
}

int	ft_optimize(t_node *lst, int start, int end)
{
	t_node	*temp;
	int		*reverse_temp;
	int		i;
	int		j;

	reverse_temp = ft_reverse(lst);
	temp = lst;
	i = 0;
	j = 0;
	while ((temp != NULL) && (temp->index < start
			&& temp->index > end) && (i++ >= 0))
		temp = temp->next;
	while ((j < ft_stacksize(lst)) && (reverse_temp[j] < start
			&& reverse_temp[j] > end))
		j++;
	free (reverse_temp);
	if (i < j)
		return (1);
	else if ((i == j) && (i == ft_stacksize(lst)))
		return (2);
	else
		return (0);
}

int	ft_optimize2(t_node *lst, long extrema)
{
	t_node	*temp;
	int		*reverse_temp;
	int		i;
	int		j;

	reverse_temp = ft_reverse(lst);
	temp = lst;
	i = 0;
	j = 0;
	while ((temp != NULL) && (temp->nbr != extrema) && (i++ >= 0))
		temp = temp->next;
	while (j < ft_stacksize(lst) && (reverse_temp[j] != extrema))
		j++;
	free (reverse_temp);
	if (i < j)
		return (1);
	else if ((i == j) && (i == ft_stacksize(lst)))
		return (2);
	else
		return (0);
}
