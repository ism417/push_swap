/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eismail <eismail@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 11:39:27 by eismail           #+#    #+#             */
/*   Updated: 2024/04/01 15:40:57 by eismail          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort(int *tab, int size)
{
	int	i;
	int	j;
	int	ntemp;

	i = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (tab[i] > tab[j])
			{
				ntemp = tab[i];
				tab[i] = tab[j];
				tab[j] = ntemp;
			}
			j++;
		}
		i++;
	}
}

void	push_back(t_node **a, t_node **b)
{
	int	max;

	while ((*b) != NULL)
	{
		max = find_max(*b);
		if ((*b)->nbr == max)
			pa(a, b);
		else if ((*b != NULL) && ((*b)->next != NULL)
			&& (((*b)->next)->nbr == max))
			sb(b);
		else if (*b != NULL && ft_last(*b)->nbr == max)
			rrb(b);
		else
		{
			if (ft_optimize2(*b, max) == 1)
				rb(b);
			else if (ft_optimize2(*b, max) == 0)
				rrb(b);
		}
	}
}

void	free_split(char **split_str)
{
	int	i;

	i = 0;
	while (split_str[i])
	{
		free(split_str[i]);
		i++;
	}
	free(split_str);
}

int	find_min(t_node *lst)
{
	t_node	*temp;
	t_node	*min;

	temp = lst;
	min = lst;
	if (!lst)
		return (0);
	while (temp != NULL)
	{
		if (min->nbr > temp->nbr)
			min = temp;
		temp = temp->next;
	}
	return (min->nbr);
}

int	find_max(t_node *lst)
{
	t_node	*temp;
	t_node	*max;

	temp = lst;
	max = lst;
	while (temp != NULL)
	{
		if (max->nbr < temp->nbr)
			max = temp;
		temp = temp->next;
	}
	return (max->nbr);
}
