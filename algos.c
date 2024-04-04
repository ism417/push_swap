/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algos.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eismail <eismail@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 22:15:14 by eismail           #+#    #+#             */
/*   Updated: 2024/04/01 13:12:50 by eismail          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_two(t_node **a)
{
	if ((*a)->nbr > ((*a)->next)->nbr)
		sa(a);
}

void	ft_three(t_node **a)
{
	int	last;
	int	mid;

	last = (((*a)->next)->next)->nbr;
	mid = ((*a)->next)->nbr;
	if (((*a)->nbr > mid) && (mid < last) && ((*a)->nbr < last))
		sa(a);
	else if (((*a)->nbr > mid) && (mid > last) && ((*a)->nbr > last))
	{
		sa(a);
		rra(a);
	}
	else if (((*a)->nbr > mid) && (mid < last) && ((*a)->nbr > last))
		ra(a);
	else if (((*a)->nbr < mid) && (mid > last) && ((*a)->nbr < last))
	{
		sa(a);
		ra(a);
	}
	else if (((*a)->nbr < mid) && (mid > last) && ((*a)->nbr > last))
		rra(a);
}

void	ft_four(t_node **a, t_node **b)
{
	int	i;
	int	min;

	i = 0;
	while (i < 1)
	{
		min = find_min(*a);
		if ((*a)->nbr == min)
		{
			pb(a, b);
			i++;
		}
		else
		{
			if (ft_optimize2(*a, min) == 1)
				ra(a);
			else if (ft_optimize2(*a, min) == 0)
				rra(a);
		}
	}
	ft_three(a);
	pa(a, b);
}

void	ft_five(t_node **a, t_node **b)
{
	int		i;
	int		min;

	i = 0;
	while (i < 2)
	{
		min = find_min(*a);
		if ((*a)->nbr == min)
		{
			pb(a, b);
			i++;
		}
		else
		{
			if (ft_optimize2(*a, min) == 1)
				ra(a);
			else if (ft_optimize2(*a, min) == 0)
				rra(a);
		}
	}
	ft_three(a);
	pa(a, b);
	pa(a, b);
}

void	else_sort(t_node **a, t_node **b, int rang)
{
	int	start;

	start = 0;
	set_indext(a);
	while (*a != NULL)
	{
		if ((*a)->index >= start && (*a)->index <= (start + rang) 
			&& (start++ >= 0))
			pb(a, b);
		else if ((*a)->index < start)
		{
			pb(a, b);
			rb(b);
			start++;
		}
		else
		{
			if (ft_optimize(*a, start, (start + rang)) == 1)
				ra(a);
			else if (ft_optimize(*a, start, (start + rang)) == 0)
				rra(a);
		}
	}
	push_back(a, b);
}
